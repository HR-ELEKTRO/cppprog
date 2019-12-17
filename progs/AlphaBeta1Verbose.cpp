#include <iostream>
#include <iomanip>
using namespace std;

int value(int pos);
int chooseComputerMove(int pos, int alpha = 0, int beta = 15);
int chooseHumanMove(int pos, int alpha = 0, int beta = 15);

const int UNDECIDED = -1;

int value(int pos) {
    static const int value[16] = { 4, 5, 3, 2, 6, 7, 8, 9, 1, 10, 2, 11, 12, 13, 14, 14 };
    if (pos >= 15 && pos < 31)
        return value[pos - 15]; // return known value
    return UNDECIDED;
}

int chooseComputerMove(int pos, int alpha, int beta) {
    int bestValue = value(pos);
    if (bestValue == UNDECIDED) {
        int i;
        for (i = 1; alpha < beta && i < 3; ++i) {
            int value = chooseHumanMove(2 * pos + i, alpha, beta);
            if (value > alpha) {
                alpha = value;
            }
        }
        if (alpha >= beta && i < 3) {
            cout << "snoei node " << 2 * pos + i << endl;
        }
        bestValue = alpha;
    }
    return bestValue;
}

int chooseHumanMove(int pos, int alpha, int beta) {
    int bestValue = value(pos);
    if (bestValue == UNDECIDED) {
        int i;
        for (i = 1; alpha < beta && i < 3; ++i) {
            int value = chooseComputerMove(2 * pos + i, alpha, beta);
            if (value < beta) {
                beta = value;
            }
        }
        if (alpha >= beta && i < 3) {
            cout << "snoei node " << 2 * pos + i << endl;
        }
        bestValue = beta;
    }
    return bestValue;
}

int main() {
    int value = chooseComputerMove(0);
    cout << "Minimaal te behalen Maximale waarde = " << value << endl;
    cin.get();
}
