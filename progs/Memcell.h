// Dit is file Memcell.h
#ifndef _Memcell_
#define _Memcell_ // prevent multiple inclusion.
class MemoryCell {
public:
    int Read() const;
    void Write(int x);
private:
    int StoredValue;
};
#endif
