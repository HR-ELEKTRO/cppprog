#include <iostream>
#include <iomanip>
using namespace std;

const int UNDECIDED = -1;

int value(int pos) {
    static const int value[16] = {4, 5, 3, 2, 6, 7, 8, 9, 1, 10, 2, 11, 12, 13, 14, 14};
    if (pos >= 15 && pos < 31)
        return value[pos - 15]; // return known value
    return UNDECIDED; 
}

// alles in 1 routine is minder duidelijk en ook minder snel!

enum Side {HUMAN, COMPUTER};

int chooseMove(Side s, int pos) {
    int bestValue = value(pos);
    if (bestValue == UNDECIDED) {
        bestValue = s == COMPUTER ? 0 : 15;
        for (int i = 1; i < 3; ++i) {
            int value = chooseMove(s == COMPUTER ? HUMAN : COMPUTER, 2 * pos + i);
            if (s == COMPUTER && value > bestValue || s == HUMAN && value < bestValue) {
                bestValue = value;
            }
        }
    }
    return bestValue;
}

int main() {
    int value = chooseMove(COMPUTER, 0);
    cout << "Minimaal te behalen Maximale waarde = " << value << endl;
    cin.get();
}
