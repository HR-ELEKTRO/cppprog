import std;
using namespace std;
import hr.brojz.Matrix;

// print number of moves considered and time used
#define ANALYSE

class Tic_tac_toe {
public:
    enum class Side {EMPTY, HUMAN, COMPUTER};
    using enum Side;
    enum class Value {HUMAN_WINS = -1, DRAW, COMPUTER_WINS, UNDECIDED};
    using enum Value;
    using Board = matrix<Side, 3, 3>;
    using Row = Board::size_type;
    using Column = Board::size_type;
    Tic_tac_toe()
    #ifdef ANALYSE
        : moves_considered{0}
    #endif
    {
        ranges::fill(board, EMPTY);
    }
    Value choose_computer_move(Row& best_row, Column& best_column, Value alpha = HUMAN_WINS, Value beta = COMPUTER_WINS);
    Value choose_human_move(Row& best_row, Column& best_column, Value alpha = HUMAN_WINS, Value beta = COMPUTER_WINS);
    Side side(Row row, Column column) const;
    bool is_undecided() const;
    bool play_move(Side s, Row row, Column column);
    bool board_is_full() const;
    bool is_awin(Side s) const;
    #ifdef ANALYSE
    int get_and_reset_moves_considered() {
        int i {moves_considered};
        moves_considered = 0;
        return i;
    }
    #endif
private:
    Board board;
    Value value() const;
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

Tic_tac_toe::Value Tic_tac_toe::choose_computer_move(Row& best_row, Column& best_column, Value alpha, Value beta) {
#ifdef ANALYSE
    ++moves_considered;
#endif
    Value best_value {value()};
    if (best_value == UNDECIDED) {
        best_value = HUMAN_WINS;
        for (Row row {0}; alpha < beta && row < 3; ++row) {
            for (Column column {0}; alpha < beta && column < 3; ++column) {
                if (board(row, column) == EMPTY) {
                    board(row, column) = COMPUTER;
                    Row dummy_row;
                    Column dummy_column;
                    Value value {choose_human_move(dummy_row, dummy_column, alpha, beta)};
                    board(row, column) = EMPTY;
                    if (value > best_value) {
                        best_value = value;
                        best_row = row;
                        best_column = column;
                    }
                }
            }
        }
    }
    return best_value;
}

Tic_tac_toe::Value Tic_tac_toe::choose_human_move(Row& best_row, Column& best_column, Value alpha, Value beta) {
#ifdef ANALYSE
    ++moves_considered;
#endif
    Value best_value {value()};
    if (best_value == UNDECIDED) {
        best_value = COMPUTER_WINS;
        for (Row row {0}; beta > alpha && row < 3; ++row) {
            for (Column column {0}; beta > alpha && column < 3; ++column) {
                if (board(row, column) == EMPTY) {
                    board(row, column) = HUMAN;
                    Row dummy_row;
                    Column dummy_column;
                    Value value {choose_computer_move(dummy_row, dummy_column, alpha, beta)};
                    board(row, column) = EMPTY;
                    if (value < best_value) {
                        best_value = value;
                        best_row = row;
                        best_column = column;
                    }
                }
            }
        }
    }
    return best_value;
}

Tic_tac_toe::Side Tic_tac_toe::side(Row row, Column column) const {
    return board(row, column);
}

bool Tic_tac_toe::is_undecided() const {
    return value() == UNDECIDED;
}

bool Tic_tac_toe::play_move(Side s, Row row, Column column) {
    if (row >= 3 || column >= 3 || board(row, column) != EMPTY)
        return false;
    board(row, column) = s;
    return true;
}

bool Tic_tac_toe::board_is_full() const {
    return ranges::none_of(board, [](Side s) {
        return s == EMPTY;
    });
}

bool Tic_tac_toe::is_awin(Side s) const {
    for (Row r {0}; r < 3; ++r) {
        if (board(r, 0) == s && board(r, 1) == s && board(r, 2) == s) {
            return true;
        }
    }
    for (Column c {0}; c < 3; ++c) {
        if (board(0, c) == s && board(1, c) == s && board(2, c) == s) {
            return true;
        }
    }
    return (board(0, 0) == s && board(1, 1) == s && board(2, 2) == s) ||
        (board(0, 2) == s && board(1, 1) == s && board(2, 0) == s);
}

Console_tttgame::Console_tttgame(bool computer_goes_first) : 
        computer_symbol(computer_goes_first ? 'x' : 'o'), human_symbol(computer_goes_first ? 'o' : 'x') {
    if (computer_goes_first) {
        do_computer_move();
        println();
    }
}

void Console_tttgame::print_board() const {
    string streep(3, '-');
    print("{}\n", streep);
    for (Tic_tac_toe::Row row {0}; row < 3; ++row) {
        for (Tic_tac_toe::Column column {0}; column < 3; ++column)
        if (t.side(row, column) == Tic_tac_toe::COMPUTER)
            print("{}", computer_symbol);
        else if (t.side(row, column) == Tic_tac_toe::HUMAN)
            print("{}", human_symbol);
        else
            print(" ");
        println();
    }
    print("{}\n", streep);
}

void Console_tttgame::do_computer_move() {
    Tic_tac_toe::Row best_row;
    Tic_tac_toe::Column best_column;
#ifdef ANALYSE
    auto start {chrono::high_resolution_clock::now()};
#endif
    t.choose_computer_move(best_row, best_column);
#ifdef ANALYSE
    auto stop {chrono::high_resolution_clock::now()};
    auto duration {chrono::duration_cast<chrono::microseconds>(stop - start).count()};
    println("Calculation time: {} us", duration);
    println("Moves considered: {}", t.get_and_reset_moves_considered());
#endif
    println("Computer ({}) plays: ROW = {} COLUMN = {}", computer_symbol, best_row, best_column);
    t.play_move(Tic_tac_toe::COMPUTER, best_row, best_column);
}

void Console_tttgame::play() {
    do {
        Tic_tac_toe::Row row;
        Tic_tac_toe::Column column;
        do {
            print_board();
            print("\nEnter row and column (starts at 0): ");
            cin >> row >> column;
        } while (!t.play_move(Tic_tac_toe::HUMAN, row, column));
        println();
        if (t.is_undecided()) {
            print_board();
            println();
            do_computer_move();
            println();
        }
    } while (t.is_undecided());
    print_board();
    if (t.is_awin(Tic_tac_toe::COMPUTER)) {
        println("Computer wins!!");
    }
    else if (t.is_awin(Tic_tac_toe::HUMAN)) {
        println("Human wins!!");
    }
    else {
        println("Draw!!");
    }
}

int main() {
    println("Welcome to TIC-TAC-TOE\n");
    bool computer_goes_first {true};
    char again;
    do {
        Console_tttgame game {computer_goes_first};
        game.play();
        do {
            print("Play again (y/n)? ");
            cin >> again;
        } while (again != 'y' && again != 'Y' && again != 'n' && again != 'N');
        computer_goes_first = !computer_goes_first;
        println();
    } while (again != 'n' && again != 'N');
}
