#include <iostream>
#include <iomanip>
using namespace std;

int positionValue(int pos);
int valueMoveComputer(int pos);
int valueMoveHuman(int pos);

int positionValue(int pos) {
    static const int value[16] = {4, 5, 3, 2, 6, 7, 8, 9, 1, 10, 2, 11, 12, 13, 14, 14};
    return pos >= 15 && pos <= 31 ? value[pos - 15]: -1;
}

int valueMoveComputer(int pos) {
    cout << "pos = " << setw(2) << pos << endl;
    int value = positionValue(pos);
    if (value != -1) {
        return value;
    }
    int posL = 2 * pos + 1;
    int posR = 2 * pos + 2;
    int valueL = valueMoveHuman(posL);
    int valueR = valueMoveHuman(posR);
    return valueL > valueR ? valueL : valueR;
}

int valueMoveHuman(int pos) {
    cout << "pos = " << setw(2) << pos << endl;
    int value = positionValue(pos);
    if (value != -1) {
        return value;
    }
    int posL = 2 * pos + 1;
    int posR = 2 * pos + 2;
    int valueL = valueMoveComputer(posL);
    int valueR = valueMoveComputer(posR);
    return valueL > valueR ? valueL : valueR;
}

int main() {
    int value = valueMoveComputer(0);
    cout << "Minimaal te behalen Maximale waarde = " << value << endl;
    cin.get();
}
