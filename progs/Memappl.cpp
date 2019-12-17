// Seperate compilation: Een programma verdeeld over meerdere files
// Dit is file Memappl.cpp
#include <iostream>
#include "Memcell.h"
using namespace std;

int main() {
    MemoryCell M;
    M.Write(5);
    cout << "Cell contents are " << M.Read() << endl;
//  ...
    cin.get();
    return 0;
}
