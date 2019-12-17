#include <iostream>
#include <iomanip>
using namespace std;

int positionValue(int pos);
int valueMoveComputer(int pos, int alpha, int beta);
int valueMoveHuman(int pos, int alpha, int beta);

int positionValue(int pos) {
    static const int value[16] = { 4, 5, 3, 2, 6, 7, 8, 9, 1, 10, 2, 11, 12, 13, 14, 14 };
    return pos >= 15 && pos <= 31 ? value[pos - 15] : -1;
}

int valueMoveComputer(int pos, int alpha, int beta) {
    cout << "pos = " << setw(2) << pos << " alpha = " << setw(2) << alpha << " beta = " << setw(2) << beta << endl;
    int value = positionValue(pos);
    if (value != -1) {
        return value;
    }
    int posL = 2 * pos + 1;
    int posR = 2 * pos + 2;
    int valueL = valueMoveHuman(posL, alpha, beta);
    if (valueL > alpha) {
        alpha = valueL;
        if (alpha >= beta) {
            cout << "snoei node " << posR << endl;
            return alpha;
        }
    }
    int valueR = valueMoveHuman(posR, alpha, beta);
    return valueR > alpha ? valueR : alpha;
}

int valueMoveHuman(int pos, int alpha, int beta) {
    cout << "pos = " << setw(2) << pos << " alpha = " << setw(2) << alpha << " beta = " << setw(2) << beta << endl;
    int value = positionValue(pos);
    if (value != -1) {
        return value;
    }
    int posL = 2 * pos + 1;
    int posR = 2 * pos + 2;
    int valueL = valueMoveComputer(posL, alpha, beta);
    if (valueL < beta) {
        beta = valueL;
        if (beta <= alpha) {
            cout << "snoei node " << posR << endl;
            return beta;
        }
    }
    int valueR = valueMoveComputer(posR, alpha, beta);
    return valueR < beta ? valueR : beta;
}


int main() {
    int value = valueMoveComputer(0, 0, 15);
    cout << "Minimaal te behalen Maximale waarde = " << value << endl;
    cin.get();
}
