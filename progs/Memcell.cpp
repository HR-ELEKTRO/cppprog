// Seperate compilation: Een programma verdeeld over meerdere files
// Dit is file Memcell.cpp
#include "Memcell.h"

int Memory_cell::read() const {
    return stored_value;
}

void Memory_cell::write(int x) {
    stored_value = x;
}
