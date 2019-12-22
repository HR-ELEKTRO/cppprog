// Dit is file Memcell.h
#ifndef _Memcell_
#define _Memcell_ // prevent multiple inclusion.
class Memory_cell {
public:
    int read() const;
    void write(int x);
private:
    int stored_value;
};
#endif
