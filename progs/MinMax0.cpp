#include <iostream>
#include <iomanip>
using namespace std;

int value(int pos);
int chooseComputerMove(int pos);
int chooseHumanMove(int pos);

const int UNDECIDED = -1;

int value(int pos) {
    static const int value[16] = {4, 5, 3, 2, 6, 7, 8, 9, 1, 10, 2, 11, 12, 13, 14, 14};
    if (pos >= 15 && pos < 31)
        return value[pos - 15]; // return known value
    return UNDECIDED; 
}

int chooseComputerMove(int pos) {
    int bestValue = value(pos);
    if (bestValue == UNDECIDED) {
        bestValue = 0;
        for (int i = 1; i < 3; ++i) {
            int value = chooseHumanMove(2 * pos + i);
            if (value > bestValue) {
                bestValue = value;
            }
        }
    }
    return bestValue;
}

int chooseHumanMove(int pos) {
    int bestValue = value(pos);
    if (bestValue == UNDECIDED) {
        bestValue = 15;
        for (int i = 1; i < 3; ++i) {
            int value = chooseComputerMove(2 * pos + i);
            if (value < bestValue) {
                bestValue = value;
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
