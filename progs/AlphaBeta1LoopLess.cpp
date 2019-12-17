#include <iostream>
#include <iomanip>
using namespace std;

class ValueNextPos{
public:
    ValueNextPos(int v, int p) : val(v), nPos(p) {
    }
    int value() const {
        return val;
    }
    int nextPos() const {
        return nPos;
    }
private:
    int val;
    int nPos;
};

int positionValue(int pos);
ValueNextPos valueMoveComputer(int pos, int alpha, int beta);
ValueNextPos valueMoveHuman(int pos, int alpha, int beta);

int positionValue(int pos) {
    static const int value[16] = { 4, 5, 3, 2, 6, 7, 8, 9, 1, 10, 2, 11, 12, 13, 14, 14 };
    return pos >= 15 && pos <= 31 ? value[pos - 15] : -1;
}

ValueNextPos valueMoveComputer(int pos, int alpha, int beta) {
    int value = positionValue(pos);
    if (value != -1)
        return ValueNextPos(value, pos);
    int posL = 2 * pos + 1;
    int posR = 2 * pos + 2;
    ValueNextPos moveL = valueMoveHuman(posL, alpha, beta);
    if (moveL.value() > alpha) {
        alpha = moveL.value();
        if (alpha >= beta) {
            return ValueNextPos(alpha, posL);
        }
    }
    ValueNextPos moveR = valueMoveHuman(posR, alpha, beta);
    return moveR.value() > alpha ? ValueNextPos(moveR.value(), posR) : ValueNextPos(alpha, posL);
}

ValueNextPos valueMoveHuman(int pos, int alpha, int beta) {
    int value = positionValue(pos);
    if (value != -1) {
        return ValueNextPos(value, pos);
    }
    int posL = 2 * pos + 1;
    int posR = 2 * pos + 2;
    ValueNextPos moveL = valueMoveComputer(posL, alpha, beta);
    if (moveL.value() < beta) {
        beta = moveL.value();
        if (beta <= alpha) {
            return ValueNextPos(beta, posL);
        }
    }
    ValueNextPos moveR = valueMoveComputer(posR, alpha, beta);
    return moveR.value() < beta ? ValueNextPos(moveR.value(), posR) : ValueNextPos(beta, posL);
}

int main() {
    int pos = 0;
    while (pos < 15) {
        ValueNextPos res = valueMoveComputer(pos, 0, 15);
        cout << "Minimaal te behalen Maximale waarde = " << res.value() << endl;
        pos = res.nextPos();
        cout << "Computer kiest positie: " << pos << endl;
        int posL = 2 * pos + 1;
        int posR = 2 * pos + 2;
        if (pos < 15) {
            cout << "Je kunt kiezen voor positie " << posL << " of positie " << posR << endl;
            cout << "Pssst, " << valueMoveHuman(pos, 0, 15).nextPos() << " is de beste keuze." << endl;
            do {
                cout << "Maak je keuze: ";
                cin >> pos;
            } while (pos != posL && pos != posR);
        }
    }
    cout << "Behaalde waarde = " << positionValue(pos) << endl;
    cin.get();
    cin.get();
}
