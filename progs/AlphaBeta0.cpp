#include <iostream>
#include <iomanip>
using namespace std;

int value(int pos);
int choose_computer_move(int pos, int alpha = 0, int beta = 15);
int choose_human_move(int pos, int alpha = 0, int beta = 15);

const int UNDECIDED = -1;

int value(int pos) {
    static const int value[16] = { 4, 5, 3, 2, 6, 7, 8, 9, 1, 10, 2, 11, 12, 13, 14, 14 };
    if (pos >= 15 && pos < 31)
        return value[pos - 15]; // return known value
    return UNDECIDED;
}

int choose_computer_move(int pos, int alpha, int beta) {
    int best_value = value(pos);
    if (best_value == UNDECIDED) {
        best_value = alpha;
        for (int i = 1; best_value < beta && i < 3; ++i) {
            int value = choose_human_move(2 * pos + i, alpha, beta);
            if (value > best_value) {
                best_value = value;
                alpha = best_value;
            }
        }
    }
    return best_value;
}

int choose_human_move(int pos, int alpha, int beta) {
    int best_value = value(pos);
    if (best_value == UNDECIDED) {
        best_value = beta;
        for (int i = 1; best_value > alpha && i < 3; ++i) {
            int value = choose_computer_move(2 * pos + i, alpha, beta);
            if (value < best_value) {
                best_value = value;
                beta = best_value;
            }
        }
    }
    return best_value;
}

int main() {
    int value = choose_computer_move(0);
    cout << "Minimaal te behalen Maximale waarde = " << value << '\n';
}
