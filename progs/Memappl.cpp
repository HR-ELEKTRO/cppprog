// Seperate compilation: Een programma verdeeld over meerdere files
// Dit is file Memappl.cpp
#include <iostream>
#include "Memcell.h"
using namespace std;

int main() {
    Memory_cell m;
    m.write(5);
    cout << "Cell content is " << m.read() << '\n';
//  ...
}
