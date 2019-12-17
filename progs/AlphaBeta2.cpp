#include <iostream>
#include <iomanip>
using namespace std;

int value(int pos);
int chooseComputerMove(int pos, int& bestNextPos, int alpha = 0, int beta = 15);
int chooseHumanMove(int pos, int& bestNextPos, int alpha = 0, int beta = 15);

const int UNDECIDED = -1;

int value(int pos) {
    static const int value[16] = { 4, 5, 3, 2, 6, 7, 8, 9, 1, 10, 2, 11, 12, 13, 14, 14 };
    if (pos >= 15 && pos < 31)
        return value[pos - 15]; // return known value
    return UNDECIDED;
}

int chooseComputerMove(int pos, int& bestNextPos, int alpha, int beta) {
    int bestValue = value(pos);
    if (bestValue == UNDECIDED) {
        for (int i = 1; alpha < beta && i < 3; ++i) {
            int dummyPos;
            int value = chooseHumanMove(2 * pos + i, dummyPos, alpha, beta);
            if (value > alpha) {
                alpha = value;
                bestNextPos = 2 * pos + i;
            }
        }
        bestValue = alpha;
    }
    return bestValue;
}

int chooseHumanMove(int pos, int& bestNextPos, int alpha, int beta) {
    int bestValue = value(pos);
    if (bestValue == UNDECIDED) {
        for (int i = 1; alpha < beta && i < 3; ++i) {
            int dummyPos;
            int value = chooseComputerMove(2 * pos + i, dummyPos, alpha, beta);
            if (value < beta) {
                beta = value;
                bestNextPos = 2 * pos + i;
            }
        }
        bestValue = beta;
    }
    return bestValue;
}

int main() {
    int pos = 0, bestNextPos, bestValue;
    while (pos < 15) {
        bestValue = chooseComputerMove(pos, bestNextPos);
        cout << "Minimaal te behalen Maximale waarde = " << bestValue << endl;
        pos = bestNextPos;
        cout << "Computer kiest positie: " << pos << endl;
        int posL = 2 * pos + 1;
        int posR = 2 * pos + 2;
        if (pos < 15) {
            cout << "Je kunt kiezen voor positie " << posL << " of positie " << posR << endl;
            chooseHumanMove(pos, bestNextPos);
            cout << "Pssst, " << bestNextPos << " is de beste keuze." << endl;
            do {
                cout << "Maak je keuze: ";
                cin >> pos;
            } while (pos != posL && pos != posR);
        }
    }
    cout << "Behaalde waarde = " << value(pos) << endl;
    cin.get();
    cin.get();
}
