#include <iostream>
#include <iomanip>
using namespace std;

int position_value(int pos);
int value_move_computer(int pos, int alpha, int beta);
int value_move_human(int pos, int alpha, int beta);

int position_value(int pos) {
    static const int value[16] = { 4, 5, 3, 2, 6, 7, 8, 9, 1, 10, 2, 11, 12, 13, 14, 14 };
    return pos >= 15 && pos <= 31 ? value[pos - 15] : -1;
}

int value_move_computer(int pos, int alpha, int beta) {
    cout << "pos = " << setw(2) << pos << " alpha = " << setw(2) << alpha << " beta = " << setw(2) << beta << '\n';
    int value = position_value(pos);
    if (value != -1) {
        return value;
    }
    int pos_l = 2 * pos + 1;
    int pos_r = 2 * pos + 2;
    int value_l = value_move_human(pos_l, alpha, beta);
    if (value_l > alpha) {
        alpha = value_l;
        if (alpha >= beta) {
            cout << "snoei node " << pos_r << '\n';
            return alpha;
        }
    }
    int value_r = value_move_human(pos_r, alpha, beta);
    return value_r > alpha ? value_r : alpha;
}

int value_move_human(int pos, int alpha, int beta) {
    cout << "pos = " << setw(2) << pos << " alpha = " << setw(2) << alpha << " beta = " << setw(2) << beta << '\n';
    int value = position_value(pos);
    if (value != -1) {
        return value;
    }
    int pos_l = 2 * pos + 1;
    int pos_r = 2 * pos + 2;
    int value_l = value_move_computer(pos_l, alpha, beta);
    if (value_l < beta) {
        beta = value_l;
        if (beta <= alpha) {
            cout << "snoei node " << pos_r << '\n';
            return beta;
        }
    }
    int value_r = value_move_computer(pos_r, alpha, beta);
    return value_r < beta ? value_r : beta;
}


int main() {
    int value = value_move_computer(0, 0, 15);
    cout << "Minimaal te behalen Maximale waarde = " << value << '\n';
}
