#include <iostream>
#include <iomanip>
using namespace std;

constexpr int UNDECIDED {-1};

int value(int pos) {
    static const int value[16] {4, 5, 3, 2, 6, 7, 8, 9, 1, 10, 2, 11, 12, 13, 14, 14};
    if (pos >= 15 && pos < 31)
        return value[pos - 15]; // return known value
    return UNDECIDED; 
}

// alles in 1 routine is minder duidelijk en ook minder snel!

enum Side {HUMAN, COMPUTER};

int choose_move(Side s, int pos) {
    int best_value {value(pos)};
    if (best_value == UNDECIDED) {
        best_value = s == COMPUTER ? 0 : 15;
        for (int i {1}; i < 3; ++i) {
            int value {choose_move(s == COMPUTER ? HUMAN : COMPUTER, 2 * pos + i)};
            if ((s == COMPUTER && value > best_value) || (s == HUMAN && value < best_value)) {
                best_value = value;
            }
        }
    }
    return best_value;
}

int main() {
    int value {choose_move(COMPUTER, 0)};
    cout << "Minimaal te behalen Maximale waarde = " << value << '\n';
}
