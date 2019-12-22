#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
#include "Matrix.h"

// print number of moves considered, time used and map size
#define ANALYSE
#ifdef ANALYSE
#include <chrono>
#endif

class Tic_tac_toe {
public:
    enum Side { EMPTY, HUMAN, COMPUTER };
    enum Value { HUMAN_WINS = -1, DRAW, COMPUTER_WINS, UNDECIDED };
    using Board = matrix<Side, 3, 3>;
    using Row = Board::size_type;
    using Column = Board::size_type;
    Tic_tac_toe()
#ifdef ANALYSE
        : moves_considered{0}
#endif
    {
        fill(board.begin(), board.end(), EMPTY);
    }
    Value choose_computer_move(Row& best_row, Column& best_column, Value alpha = HUMAN_WINS, Value beta = COMPUTER_WINS, int depth = 1);
    Value choose_human_move(Row& best_row, Column& best_column, Value alpha = HUMAN_WINS, Value beta = COMPUTER_WINS, int depth = 1);
    Side side(Row row, Column column) const;
    bool is_undecided() const;
    bool play_move(Side s, Row row, Column column);
    bool board_is_full() const;
    bool is_awin(Side s) const;
#ifdef ANALYSE
    int get_and_reset_moves_considered() {
        int i{moves_considered};
        moves_considered = 0;
        return i;
    }
    int get_map_size() const {
        return boards.size();
    }
#endif
private:
    Board board;
    Value value() const;
    class Board_wrapper {
    public:
        Board_wrapper(const Board& b): board(b) {
        }
        bool operator<(const Board_wrapper& rhs) const;
    private:
        Board board;
    };
    class Value_and_best_move {
    public:
        Value_and_best_move() = default;
        Value_and_best_move(Value v, int r, int c) : value(v), best_row(r), best_column(c) {
        }
        Value value;
        int best_row;
        int best_column;
    };
    map<Board_wrapper, Value_and_best_move> boards;
#ifdef ANALYSE
    int moves_considered;
#endif
};

class Console_tttgame {
public:
    explicit Console_tttgame(bool computer_goes_first);
    void play();
private:
    void print_board() const;
    void do_computer_move();
    Tic_tac_toe t;
    char computer_symbol;
    char human_symbol;
};

Tic_tac_toe::Value Tic_tac_toe::value() const {
    return is_awin(COMPUTER) ? COMPUTER_WINS : is_awin(HUMAN) ? HUMAN_WINS : board_is_full() ? DRAW : UNDECIDED;
}

Tic_tac_toe::Value Tic_tac_toe::choose_computer_move(Row& best_row, Column& best_column, Value alpha, Value beta, int depth) {
#ifdef ANALYSE
    ++moves_considered;
#endif
    auto itr = boards.find(Board_wrapper(board));
    if (itr != boards.end()) {
        best_row = itr->second.best_row;
        best_column = itr->second.best_column;
        return itr->second.value;
    }
    Value best_value{value()};
    if (best_value == UNDECIDED) {
        for (Row row{0}; alpha < beta && row < 3; ++row) {
            for (Column column{0}; alpha < beta && column < 3; ++column) {
                if (board(row, column) == EMPTY) {
                    board(row, column) = COMPUTER;
                    Row dummy_row;
                    Column dummy_column;
                    Value value{choose_human_move(dummy_row, dummy_column, alpha, beta)};
                    board(row, column) = EMPTY;
                    if (value > alpha) {
                        alpha = value;
                        best_row = row;
                        best_column = column;
                    }
                }
            }
        }
        best_value = alpha;
    }
    boards[board_wrapper(board)] = Value_and_best_move(best_value, best_row, best_column);
    return best_value;
}

Tic_tac_toe::Value Tic_tac_toe::choose_human_move(Row& best_row, Column& best_column, Value alpha, Value beta, int depth) {
#ifdef ANALYSE
    ++moves_considered;
#endif
    auto itr = boards.find(Board_wrapper(board));
    if (itr != boards.end()) {
        best_row = itr->second.best_row;
        best_column = itr->second.best_column;
        return itr->second.value;
    }
    Value best_value{value()};
    if (best_value == UNDECIDED) {
        for (Row row{0}; beta > alpha && row < 3; ++row) {
            for (Column column{0}; beta > alpha && column < 3; ++column) {
                if (board(row, column) == EMPTY) {
                    board(row, column) = HUMAN;
                    Row dummy_row;
                    Column dummy_column;
                    Value value{choose_computer_move(dummy_row, dummy_column, alpha, beta, depth + 1)};
                    board(row, column) = EMPTY;
                    if (value < beta) {
                        beta = value;
                        best_row = row;
                        best_column = column;
                    }
                }
            }
        }
        best_value = beta;
    }
    boards[board_wrapper(board)] = Value_and_best_move(best_value, best_row, best_column);
    return best_value;
}

Tic_tac_toe::Side Tic_tac_toe::side(Row row, Column column) const {
    return board(row, column);
}

bool Tic_tac_toe::is_undecided() const {
    return value() == UNDECIDED;
}

bool Tic_tac_toe::play_move(Side s, Row row, Column column) {
    if (row < 0 || row >= 3 || column < 0 || column >= 3 || board(row, column) != EMPTY)
        return false;
    board(row, column) = s;
    return true;
}

bool Tic_tac_toe::board_is_full() const {
    return none_of(board.cbegin(), board.cend(), [](Side s) {
        return s == EMPTY;
    });
}

bool Tic_tac_toe::is_awin(Side s) const {
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

bool Tic_tac_toe::Board_wrapper::operator<(const Board_wrapper& rhs) const {
    for (Row r{0}; r < 3; ++r) {
        for (Column c{0}; c < 3; ++c) {
            if (board(r, c) != rhs.board(r, c)) {
                return board(r, c) < rhs.board(r, c);
            }
        }
    }
    return false;
}

Console_tttgame::Console_tttgame(bool computer_goes_first) :
computer_symbol(computer_goes_first ? 'x' : 'o'), human_symbol(computer_goes_first ? 'o' : 'x') {
    if (computer_goes_first) {
        do_computer_move();
        cout << '\n';
    }
}

void Console_tttgame::print_board() const {
    string streep(3, '-');
    cout << streep << '\n';
    for (Tic_tac_toe::Row row{0}; row < 3; ++row) {
        for (Tic_tac_toe::Column column{0}; column < 3; ++column)
        if (t.side(row, column) == Tic_tac_toe::COMPUTER)
            cout << computer_symbol;
        else if (t.side(row, column) == Tic_tac_toe::HUMAN)
            cout << human_symbol;
        else
            cout << ' ';
        cout << '\n';
    }
    cout << streep << '\n';
}

void Console_tttgame::do_computer_move() {
    Tic_tac_toe::Row best_row;
    Tic_tac_toe::Column best_column;
#ifdef ANALYSE
    auto start{chrono::high_resolution_clock::now()};
#endif
    t.choose_computer_move(best_row, best_column);
#ifdef ANALYSE
    auto stop{chrono::high_resolution_clock::now()};
    auto duration{chrono::duration_cast<chrono::microseconds>(stop - start).count()};
    cout << "Calculation time: " << duration << " us\n";
    cout << "Map size is: " << t.get_map_size() << '\n';
    cout << "Moves considered: " << t.get_and_reset_moves_considered() << '\n';
#endif
    cout << "Computer plays: ROW = " << best_row << " COLUMN = " << best_column << '\n';
    t.play_move(Tic_tac_toe::COMPUTER, best_row, best_column);
}

void Console_tttgame::play() {
    do {
        Tic_tac_toe::Row row;
        Tic_tac_toe::Column column;
        do {
            print_board();
            cout << '\n' << "Enter row and column (starts at 0): ";
            cin >> row >> column;
        } while (!t.play_move(Tic_tac_toe::HUMAN, row, column));
        cout << '\n';
        if (t.is_undecided()) {
            print_board();
            cout << '\n';
            do_computer_move();
            cout << '\n';
        }
    } while (t.is_undecided());
    print_board();
    if (t.is_awin(Tic_tac_toe::COMPUTER)) {
        cout << "Computer wins!!\n";
    }
    else if (t.is_awin(Tic_tac_toe::HUMAN)) {
        cout << "Human wins!!\n";
    }
    else {
        cout << "Draw!!\n";
    }
}

int main() {
    cout << "Welcome to TIC-TAC-TOE\n";
    bool computer_goes_first{true};
    char again;
    do {
        Console_tttgame game{computer_goes_first};
        game.play();
        do {
            cout << "Play again (y/n)? ";
            cin >> again;
        } while (again != 'y' && again != 'Y' && again != 'n' && again != 'N');
        computer_goes_first = !computer_goes_first;
        cout << '\n';
    } while (again != 'n' && again != 'N');
}
