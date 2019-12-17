// Seperate compilation: Een programma verdeeld over meerdere files
// Dit is file Memcell.cpp
#include "Memcell.h"

int MemoryCell::Read() const {
    return StoredValue;
}

void MemoryCell::Write(int x) {
    StoredValue = x;
}
