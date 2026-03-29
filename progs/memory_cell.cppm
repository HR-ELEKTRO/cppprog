// Dit is file Memcell.cppm
export module memcell;

export class Memory_cell {
public:
    int read() const;
    void write(int x);
private:
    int stored_value;
};
