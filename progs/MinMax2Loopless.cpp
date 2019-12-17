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
ValueNextPos valueMoveComputer(int pos);
ValueNextPos valueMoveHuman(int pos);

int positionValue(int pos) {
    static const int value[16] = { 4, 5, 3, 2, 6, 7, 8, 9, 1, 10, 2, 11, 12, 13, 14, 14 };
    return pos >= 15 && pos <= 31 ? value[pos - 15] : -1;
}

ValueNextPos valueMoveComputer(int pos) {
    int value = positionValue(pos);
    if (value != -1) {
        return ValueNextPos(value, pos);
    }
    int posL = 2 * pos + 1;
    int posR = 2 * pos + 2;
    ValueNextPos moveL = valueMoveHuman(posL);
    ValueNextPos moveR = valueMoveHuman(posR);
    return moveL.value() > moveR.value() ? ValueNextPos(moveL.value(), posL) : ValueNextPos(moveR.value(), posR);
}

ValueNextPos valueMoveHuman(int pos) {
    int value = positionValue(pos);
    if (value != -1) {
        return ValueNextPos(value, pos);
    }
    int posL = 2 * pos + 1;
    int posR = 2 * pos + 2;
    ValueNextPos moveL = valueMoveComputer(posL);
    ValueNextPos moveR = valueMoveComputer(posR);
    return moveL.value() < moveR.value() ? ValueNextPos(moveL.value(), posL) : ValueNextPos(moveR.value(), posR);
}

int main() {
    int pos = 0;
    while (pos < 15) {
        ValueNextPos res = valueMoveComputer(pos);
        cout << "Minimaal te behalen Maximale waarde = " << res.value() << endl;
        pos = res.nextPos();
        cout << "Computer kiest positie: " << pos << endl;
        int posL = 2 * pos + 1;
        int posR = 2 * pos + 2;
        if (pos < 15) {
            cout << "Je kunt kiezen voor positie " << posL << " of positie " << posR << endl;
            cout << "Pssst, " << valueMoveHuman(pos).nextPos() << " is de beste keuze." << endl;
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
