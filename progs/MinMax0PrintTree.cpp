#include <iostream>
#include <iomanip>
using namespace std;

int value(int pos);
int chooseComputerMove(int pos);
int chooseHumanMove(int pos);
void printTree(int pos = 0, int level = 0);
void printCalculatedTree(int pos = 0, int level = 0);

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

void printTree(int pos, int level) {
    if (level != 5) {
        printTree(2 * pos + 2, level + 1);
        cout << setw(level * 5) << pos << ":" << value(pos) << endl;
        printTree(2 * pos + 1, level + 1);
    }
}

void printCalculatedTree(int pos, int level) {
    if (level != 5) {
        printCalculatedTree(2 * pos + 2, level + 1);
        cout << setw(level * 5) << pos << ":" << (level % 2 == 0 ? chooseComputerMove(pos) : chooseHumanMove(pos)) << endl;
        printCalculatedTree(2 * pos + 1, level + 1);
    }
}

int main() {
    printTree();
    cin.get();
    cout << endl;
    printCalculatedTree();
    cin.get();
    cout << endl;
    cout << "Maximaal te behalen waarde = " << chooseComputerMove(0) << endl;
    cin.get();
}
