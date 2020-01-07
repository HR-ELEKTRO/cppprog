#include <iostream>
#include <iomanip>
using namespace std;

int value(int pos);
int choose_computer_move(int pos, int& best_next_pos, int alpha = 0, int beta = 15);
int choose_human_move(int pos, int& best_next_pos, int alpha = 0, int beta = 15);

const int UNDECIDED = -1;

int value(int pos) {
    static const int value[16] = { 4, 5, 3, 2, 6, 7, 8, 9, 1, 10, 2, 11, 12, 13, 14, 14 };
    if (pos >= 15 && pos < 31)
        return value[pos - 15]; // return known value
    return UNDECIDED;
}

int choose_computer_move(int pos, int& best_next_pos, int alpha, int beta) {
    int best_value = value(pos);
    if (best_value == UNDECIDED) {
        for (int i = 1; alpha < beta && i < 3; ++i) {
            int dummy_pos;
            int value = choose_human_move(2 * pos + i, dummy_pos, alpha, beta);
            if (value > alpha) {
                alpha = value;
                best_next_pos = 2 * pos + i;
            }
        }
        best_value = alpha;
    }
    return best_value;
}

int choose_human_move(int pos, int& best_next_pos, int alpha, int beta) {
    int best_value = value(pos);
    if (best_value == UNDECIDED) {
        for (int i = 1; alpha < beta && i < 3; ++i) {
            int dummy_pos;
            int value = choose_computer_move(2 * pos + i, dummy_pos, alpha, beta);
            if (value < beta) {
                beta = value;
                best_next_pos = 2 * pos + i;
            }
        }
        best_value = beta;
    }
    return best_value;
}

int main() {
    int pos = 0, best_next_pos, best_value;
    while (pos < 15) {
        best_value = choose_computer_move(pos, best_next_pos);
        cout << "Minimaal te behalen Maximale waarde = " << best_value << '\n';
        pos = best_next_pos;
        cout << "Computer kiest positie: " << pos << '\n';
        int pos_l = 2 * pos + 1;
        int pos_r = 2 * pos + 2;
        if (pos < 15) {
            cout << "Je kunt kiezen voor positie " << pos_l << " of positie " << pos_r << '\n';
            choose_human_move(pos, best_next_pos);
            cout << "Pssst, " << best_next_pos << " is de beste keuze.\n";
            do {
                cout << "Maak je keuze: ";
                cin >> pos;
            } while (pos != pos_l && pos != pos_r);
        }
    }
    cout << "Behaalde waarde = " << value(pos) << '\n';
}
