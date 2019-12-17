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
        bestValue = alpha;
        for (int i = 1; bestValue < beta && i < 3; ++i) {
            int value = chooseHumanMove(2 * pos + i, alpha, beta);
            if (value > bestValue) {
                bestValue = value;
                alpha = bestValue;
            }
        }
    }
    return bestValue;
}

int chooseHumanMove(int pos, int alpha, int beta) {
    int bestValue = value(pos);
    if (bestValue == UNDECIDED) {
        bestValue = beta;
        for (int i = 1; bestValue > alpha && i < 3; ++i) {
            int value = chooseComputerMove(2 * pos + i, alpha, beta);
            if (value < bestValue) {
                bestValue = value;
                beta = bestValue;
            }
        }
    }
    return bestValue;
}

int main() {
    int value = chooseComputerMove(0);
    cout << "Minimaal te behalen Maximale waarde = " << value << endl;
    cin.get();
}
