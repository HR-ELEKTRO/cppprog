#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <string>
#include <array>
using namespace std;
#include "Matrix.h"

// print number of moves considered, time used and map size
#define ANALYSE
#ifdef ANALYSE
#include <chrono>
#endif    

// This program determines the optimal value for MAX_TABLE_DEPTH

// Define VERBOSE to show all measurements
#define VERBOSE

int MAX_DEPTH = 2;

class TicTacToe {
public:
    enum Side { EMPTY, HUMAN, COMPUTER };
    enum Value { HUMAN_WINS = -1, DRAW, COMPUTER_WINS, UNDECIDED };
    using Board = matrix<Side, 3, 3>;
    using Row = Board::size_type;
    using Column = Board::size_type;
    TicTacToe()
#ifdef ANALYSE
        : movesConsidered{0}
#endif
    {
        fill(board.begin(), board.end(), EMPTY);
    }
    Value chooseComputerMove(Row& bestRow, Column& bestColumn, Value alpha = HUMAN_WINS, Value beta = COMPUTER_WINS, int depth = 1);
    Value chooseHumanMove(Row& bestRow, Column& bestColumn, Value alpha = HUMAN_WINS, Value beta = COMPUTER_WINS, int depth = 1);
    Side side(Row row, Column column) const;
    bool isUndecided() const;
    bool playMove(Side s, Row row, Column column);
    bool boardIsFull() const;
    bool isAWin(Side s) const;
#ifdef ANALYSE
    int getAndResetMovesConsidered() {
        int i{movesConsidered};
        movesConsidered = 0;
        return i;
    }
    int getMapSize() const {
        return boards.size();
    }
#endif
private:
    Board board;
    Value value() const;
    class BoardWrapper {
    public:
        BoardWrapper(const Board& b) : board(b) {
        }
        bool operator<(const BoardWrapper& rhs) const;
    private:
        Board board;
    };
    class ValueAndBestMove {
    public:
        ValueAndBestMove() = default;
        ValueAndBestMove(Value v, int r, int c) : value(v), bestRow(r), bestColumn(c) {
        }
        Value value;
        int bestRow;
        int bestColumn;
    };
    map<BoardWrapper, ValueAndBestMove> boards;
#ifdef ANALYSE
    int movesConsidered;
#endif
};

TicTacToe::Value TicTacToe::value() const {
    return isAWin(COMPUTER) ? COMPUTER_WINS : isAWin(HUMAN) ? HUMAN_WINS : boardIsFull() ? DRAW : UNDECIDED;
}

TicTacToe::Value TicTacToe::chooseComputerMove(Row& bestRow, Column& bestColumn, Value alpha, Value beta, int depth) {
#ifdef ANALYSE
    ++movesConsidered;
#endif
    if (depth >= 3 && depth <= MAX_DEPTH) {
        auto itr = boards.find(BoardWrapper(board));
        if (itr != boards.end()) {
            bestRow = itr->second.bestRow;
            bestColumn = itr->second.bestColumn;
            return itr->second.value;
        }
    }
    Value bestValue{value()};
    if (bestValue == UNDECIDED) {
        for (Row row{0}; alpha < beta && row < 3; ++row) {
            for (Column column{0}; alpha < beta && column < 3; ++column) {
                if (board(row, column) == EMPTY) {
                    board(row, column) = COMPUTER;
                    Row dummyRow;
                    Column dummyColumn;
                    Value value{chooseHumanMove(dummyRow, dummyColumn, alpha, beta, depth + 1)};
                    board(row, column) = EMPTY;
                    if (value > alpha) {
                        alpha = value;
                        bestRow = row;
                        bestColumn = column;
                    }
                }
            }
        }
        bestValue = alpha;
    }
    if (depth >= 3 && depth <= MAX_DEPTH) {
        boards[BoardWrapper(board)] = ValueAndBestMove(bestValue, bestRow, bestColumn);
    }
    return bestValue;
}

TicTacToe::Value TicTacToe::chooseHumanMove(Row& bestRow, Column& bestColumn, Value alpha, Value beta, int depth) {
#ifdef ANALYSE
    ++movesConsidered;
#endif
    if (depth >= 3 && depth <= MAX_DEPTH) {
        auto itr = boards.find(BoardWrapper(board));
        if (itr != boards.end()) {
            bestRow = itr->second.bestRow;
            bestColumn = itr->second.bestColumn;
            return itr->second.value;
        }
    }
    Value bestValue{value()};
    if (bestValue == UNDECIDED) {
        for (Row row{0}; beta > alpha && row < 3; ++row) {
            for (Column column{0}; beta > alpha && column < 3; ++column) {
                if (board(row, column) == EMPTY) {
                    board(row, column) = HUMAN;
                    Row dummyRow;
                    Column dummyColumn;
                    Value value{chooseComputerMove(dummyRow, dummyColumn, alpha, beta, depth + 1)};
                    board(row, column) = EMPTY;
                    if (value < beta) {
                        beta = value;
                        bestRow = row;
                        bestColumn = column;
                    }
                }
            }
        }
        bestValue = beta;
    }
    if (depth >= 3 && depth <= MAX_DEPTH) {
        boards[BoardWrapper(board)] = ValueAndBestMove(bestValue, bestRow, bestColumn);
    }
    return bestValue;
}

TicTacToe::Side TicTacToe::side(Row row, Column column) const {
    return board(row, column);
}

bool TicTacToe::isUndecided() const {
    return value() == UNDECIDED;
}

bool TicTacToe::playMove(Side s, Row row, Column column) {
    if (row < 0 || row >= 3 || column < 0 || column >= 3 || board(row, column) != EMPTY)
        return false;
    board(row, column) = s;
    return true;
}

bool TicTacToe::boardIsFull() const {
    return none_of(board.cbegin(), board.cend(), [](Side s) {
        return s == EMPTY;
    });
}

bool TicTacToe::isAWin(Side s) const {
    for (Row r{0}; r < 3; ++r) {
        if (board(r, 0) == s && board(r, 1) == s && board(r, 2) == s) {
            return true;
        }
    }
    for (Column c{0}; c < 3; ++c) {
        if (board(0, c) == s && board(1, c) == s && board(2, c) == s) {
            return true;
        }
    }
    return (board(0, 0) == s && board(1, 1) == s && board(2, 2) == s) ||
        (board(0, 2) == s && board(1, 1) == s && board(2, 0) == s);
}

bool TicTacToe::BoardWrapper::operator<(const BoardWrapper& rhs) const {
    for (Row r{0}; r < 3; ++r) {
        for (Column c{0}; c < 3; ++c) {
            if (board(r, c) != rhs.board(r, c)) {
                return board(r, c) < rhs.board(r, c);
            }
        }
    }
    return false;
}

void seekOptimal() {
    TicTacToe::Row bestRow;
    TicTacToe::Column bestColumn;
    map<int, chrono::microseconds::rep> results;
    for (MAX_DEPTH = 2; MAX_DEPTH <= 9; ++MAX_DEPTH) {
        cout << "MAX_DEPTH: " << MAX_DEPTH << '\n';
        // repeat every measurement N times to lower error
        constexpr int N{10};
        array<chrono::microseconds::rep, N> time;
        for (auto& t: time) {
            TicTacToe ttt;
            auto start{chrono::high_resolution_clock::now()};
            // calculate the first move
            ttt.chooseComputerMove(bestRow, bestColumn);
            auto stop{chrono::high_resolution_clock::now()};
            auto duration{chrono::duration_cast<chrono::microseconds>(stop - start).count()};
            t = duration;
#ifdef VERBOSE
            if (&t == &time[0]) {
                cout << "Map size is: " << ttt.getMapSize() << '\n';
                cout << "Moves considered: " << ttt.getAndResetMovesConsidered() << '\n';
            }
            cout << "Executiom time: " << duration << " us\n";
#endif
        }
        results[MAX_DEPTH] = accumulate(time.begin(), time.end(), 0) / N;
#ifdef VERBOSE
        cout << "Avarage execution time: " << results[MAX_DEPTH] << " us\n";
#endif
    }
    auto min = min_element(results.begin(), results.end(), [](pair<int, chrono::microseconds::rep> p1, pair<int, chrono::microseconds::rep> p2) {
        return p1.second < p2.second;
    });
    cout << "Optimal value for MAX_DEPTH = " << min->first << '\n';
}

int main() {
    seekOptimal();
}
