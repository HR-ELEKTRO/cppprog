#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int positionValue(int pos);
void printTree(int pos = 0, int level = 0);
void printCalculatedTree(int pos = 0, int level = 0);
int valueMoveComputer(int pos);
int valueMoveHuman(int pos);

int positionValue(int pos) {
    static const int value[16] = {4, 5, 3, 2, 6, 7, 8, 9, 1, 10, 2, 11, 12, 13, 14, 14};
    return pos >= 15 && pos <= 31 ? value[pos - 15]: -1;
}

void printTree(int pos, int level) {
    if (level != 5) {
        printTree(2 * pos + 2, level + 1);
        cout << setw(level * 5) << pos << ":" << positionValue(pos) << endl;
        printTree(2 * pos + 1, level + 1);
    }
}

void printCalculatedTree(int pos, int level) {
    if (level != 5) {
        printCalculatedTree(2 * pos + 2, level + 1);
        cout << setw(level * 5) << pos << ":" << (level % 2 == 0 ? valueMoveComputer(pos) : valueMoveHuman(pos)) << endl;
        printCalculatedTree(2 * pos + 1, level + 1);
    }
}

int valueMoveComputer(int pos) {
    int value = positionValue(pos);
    return value != -1 ? value : max(valueMoveHuman(2 * pos + 1), valueMoveHuman(2 * pos + 2));
}

int valueMoveHuman(int pos) {
    int value = positionValue(pos);
    return value != -1 ? value : min(valueMoveComputer(2 * pos + 1), valueMoveComputer(2 * pos + 2));
}

int main() {
    printTree();
    cin.get();
    cout << endl;
    printCalculatedTree();
    cin.get();
    cout << endl;
    cout << "Maximaal te behalen waarde = " << valueMoveComputer(0) << endl;
    cin.get();
}
