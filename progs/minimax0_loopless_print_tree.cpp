#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int position_value(int pos);
void print_tree(int pos = 0, int level = 0);
void print_calculated_tree(int pos = 0, int level = 0);
int value_move_computer(int pos);
int value_move_human(int pos);

int position_value(int pos) {
    static const int value[16] {4, 5, 3, 2, 6, 7, 8, 9, 1, 10, 2, 11, 12, 13, 14, 14};
    return pos >= 15 && pos <= 31 ? value[pos - 15]: -1;
}

void print_tree(int pos, int level) {
    if (level != 5) {
        print_tree(2 * pos + 2, level + 1);
        cout << setw(level * 5) << pos << ":" << position_value(pos) << '\n';
        print_tree(2 * pos + 1, level + 1);
    }
}

void print_calculated_tree(int pos, int level) {
    if (level != 5) {
        print_calculated_tree(2 * pos + 2, level + 1);
        cout << setw(level * 5) << pos << ":" << (level % 2 == 0 ? value_move_computer(pos) : value_move_human(pos)) << '\n';
        print_calculated_tree(2 * pos + 1, level + 1);
    }
}

int value_move_computer(int pos) {
    int value {position_value(pos)};
    return value != -1 ? value : max(value_move_human(2 * pos + 1), value_move_human(2 * pos + 2));
}

int value_move_human(int pos) {
    int value {position_value(pos)};
    return value != -1 ? value : min(value_move_computer(2 * pos + 1), value_move_computer(2 * pos + 2));
}

int main() {
    print_tree();
    cin.get();
    cout << '\n';
    print_calculated_tree();
    cin.get();
    cout << '\n';
    cout << "Maximaal te behalen waarde = " << value_move_computer(0) << '\n';
}
