// Dit is file memory_cell.cpp
module memcell;

int Memory_cell::read() const {
    return stored_value;
}

void Memory_cell::write(int x) {
    stored_value = x;
}
