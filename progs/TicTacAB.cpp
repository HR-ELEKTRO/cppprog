#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#include "Matrix.h"

// print number of moves considered and time used
#define ANALYSE
#ifdef ANALYSE
#include <chrono>
#endif

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
    Value chooseComputerMove(Row& bestRow, Column& bestColumn, Value alpha = HUMAN_WINS, Value beta = COMPUTER_WINS);
    Value chooseHumanMove(Row& bestRow, Column& bestColumn, Value alpha = HUMAN_WINS, Value beta = COMPUTER_WINS);
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
#endif
private:
    Board board;
    Value value() const;
#ifdef ANALYSE
    int movesConsidered;
#endif
};

class ConsoleTTTGame {
public:
    explicit ConsoleTTTGame(bool computerGoesFirst);
    void play();
private:
    void printBoard() const;
    void doComputerMove();
    TicTacToe t;
    char computerSymbol;
    char humanSymbol;
};

TicTacToe::Value TicTacToe::value() const {
    return isAWin(COMPUTER) ? COMPUTER_WINS : isAWin(HUMAN) ? HUMAN_WINS : boardIsFull() ? DRAW : UNDECIDED;
}

TicTacToe::Value TicTacToe::chooseComputerMove(Row& bestRow, Column& bestColumn, Value alpha, Value beta) {
#ifdef ANALYSE
    ++movesConsidered;
#endif
    Value bestValue{value()};
    if (bestValue == UNDECIDED) {
        for (Row row{0}; alpha < beta && row < 3; ++row) {
            for (Column column{0}; alpha < beta && column < 3; ++column) {
                if (board(row, column) == EMPTY) {
                    board(row, column) = COMPUTER;
                    Row dummyRow;
                    Column dummyColumn;
                    Value value{chooseHumanMove(dummyRow, dummyColumn, alpha, beta)};
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
    return bestValue;
}

TicTacToe::Value TicTacToe::chooseHumanMove(Row& bestRow, Column& bestColumn, Value alpha, Value beta) {
#ifdef ANALYSE
    ++movesConsidered;
#endif
    Value bestValue{value()};
    if (bestValue == UNDECIDED) {
        for (Row row{0}; beta > alpha && row < 3; ++row) {
            for (Column column{0}; beta > alpha && column < 3; ++column) {
                if (board(row, column) == EMPTY) {
                    board(row, column) = HUMAN;
                    Row dummyRow;
                    Column dummyColumn;
                    Value value{chooseComputerMove(dummyRow, dummyColumn, alpha, beta)};
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

ConsoleTTTGame::ConsoleTTTGame(bool computerGoesFirst) :
computerSymbol(computerGoesFirst ? 'x' : 'o'), humanSymbol(computerGoesFirst ? 'o' : 'x') {
    if (computerGoesFirst) {
        doComputerMove();
        cout << '\n';
    }
}

void ConsoleTTTGame::printBoard() const {
    string streep(3, '-');
    cout << streep << '\n';
    for (TicTacToe::Row row{0}; row < 3; ++row) {
        for (TicTacToe::Column column{0}; column < 3; ++column)
        if (t.side(row, column) == TicTacToe::COMPUTER)
            cout << computerSymbol;
        else if (t.side(row, column) == TicTacToe::HUMAN)
            cout << humanSymbol;
        else
            cout << ' ';
        cout << '\n';
    }
    cout << streep << '\n';
}

void ConsoleTTTGame::doComputerMove() {
    TicTacToe::Row bestRow;
    TicTacToe::Column bestColumn;
#ifdef ANALYSE
    auto start{chrono::high_resolution_clock::now()};
#endif
    t.chooseComputerMove(bestRow, bestColumn);
#ifdef ANALYSE
    auto stop{chrono::high_resolution_clock::now()};
    auto duration{chrono::duration_cast<chrono::microseconds>(stop - start).count()};
    cout << "Calculation time: " << duration << " us\n";
    cout << "Moves considered: " << t.getAndResetMovesConsidered() << '\n';
#endif
    cout << "Computer plays: ROW = " << bestRow << " COLUMN = " << bestColumn << '\n';
    t.playMove(TicTacToe::COMPUTER, bestRow, bestColumn);
}

void ConsoleTTTGame::play() {
    do {
        TicTacToe::Row row;
        TicTacToe::Column column;
        do {
            printBoard();
            cout << '\n' << "Enter row and column (starts at 0): ";
            cin >> row >> column;
        } while (!t.playMove(TicTacToe::HUMAN, row, column));
        cout << '\n';
        if (t.isUndecided()) {
            printBoard();
            cout << '\n';
            doComputerMove();
            cout << '\n';
        }
    } while (t.isUndecided());
    printBoard();
    if (t.isAWin(TicTacToe::COMPUTER)) {
        cout << "Computer wins!!\n";
    }
    else if (t.isAWin(TicTacToe::HUMAN)) {
        cout << "Human wins!!\n";
    }
    else {
        cout << "Draw!!\n";
    }
}

int main() {
    cout << "Welcome to TIC-TAC-TOE\n";
    bool computerGoesFirst{true};
    char again;
    do {
        ConsoleTTTGame game{computerGoesFirst};
        game.play();
        do {
            cout << "Play again (y/n)? ";
            cin >> again;
        } while (again != 'y' && again != 'Y' && again != 'n' && again != 'N');
        computerGoesFirst = !computerGoesFirst;
        cout << '\n';
    } while (again != 'n' && again != 'N');
}
