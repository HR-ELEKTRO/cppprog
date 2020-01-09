#include <iostream>
#include <iomanip>
using namespace std;

class Value_next_pos{
public:
    Value_next_pos(int v, int p) : val(v), n_pos(p) {
    }
    int value() const {
        return val;
    }
    int next_pos() const {
        return n_pos;
    }
private:
    int val;
    int n_pos;
};

int position_value(int pos);
Value_next_pos value_move_computer(int pos, int alpha, int beta);
Value_next_pos value_move_human(int pos, int alpha, int beta);

int position_value(int pos) {
    static const int value[16] = { 4, 5, 3, 2, 6, 7, 8, 9, 1, 10, 2, 11, 12, 13, 14, 14 };
    return pos >= 15 && pos <= 31 ? value[pos - 15] : -1;
}

Value_next_pos value_move_computer(int pos, int alpha, int beta) {
    int value = position_value(pos);
    if (value != -1)
        return Value_next_pos(value, pos);
    int pos_l = 2 * pos + 1;
    int pos_r = 2 * pos + 2;
    Value_next_pos move_l = value_move_human(pos_l, alpha, beta);
    if (move_l.value() > alpha) {
        alpha = move_l.value();
        if (alpha >= beta) {
            return Value_next_pos(alpha, pos_l);
        }
    }
    Value_next_pos move_r = value_move_human(pos_r, alpha, beta);
    return move_r.value() > alpha ? Value_next_pos(move_r.value(), pos_r) : Value_next_pos(alpha, pos_l);
}

Value_next_pos value_move_human(int pos, int alpha, int beta) {
    int value = position_value(pos);
    if (value != -1) {
        return Value_next_pos(value, pos);
    }
    int pos_l = 2 * pos + 1;
    int pos_r = 2 * pos + 2;
    Value_next_pos move_l = value_move_computer(pos_l, alpha, beta);
    if (move_l.value() < beta) {
        beta = move_l.value();
        if (beta <= alpha) {
            return Value_next_pos(beta, pos_l);
        }
    }
    Value_next_pos move_r = value_move_computer(pos_r, alpha, beta);
    return move_r.value() < beta ? Value_next_pos(move_r.value(), pos_r) : Value_next_pos(beta, pos_l);
}

int main() {
    int pos {0};
    while (pos < 15) {
        Value_next_pos res = value_move_computer(pos, 0, 15);
        cout << "Minimaal te behalen Maximale waarde = " << res.value() << '\n';
        pos = res.next_pos();
        cout << "Computer kiest positie: " << pos << '\n';
        int pos_l = 2 * pos + 1;
        int pos_r = 2 * pos + 2;
        if (pos < 15) {
            cout << "Je kunt kiezen voor positie " << pos_l << " of positie " << pos_r << '\n';
            cout << "Pssst, " << value_move_human(pos, 0, 15).next_pos() << " is de beste keuze.\n";
            do {
                cout << "Maak je keuze: ";
                cin >> pos;
            } while (pos != pos_l && pos != pos_r);
        }
    }
    cout << "Behaalde waarde = " << position_value(pos) << '\n';
}
