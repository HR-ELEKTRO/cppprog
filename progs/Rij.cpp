// Een Rij met een willekeurig aantal plaatsen van een willekeurig type T

#include <iostream>
using namespace std;

template<typename T, size_t N> class Rij {
public:
    void zet_in(size_t index, const T& waarde);
    const T& lees_uit(size_t index) const;
    size_t aantal_plaatsen() const;
private:
    T data[N];
};

template<typename T, size_t N> void Rij<T, N>::zet_in(size_t index, const T& waarde) {
    if (index >= 0 && index < N)
        data[index] = waarde;
}

template<typename T, size_t N> const T& Rij<T, N>::lees_uit(size_t index) const {
    if (index < 0) 
        index = 0;
    if (index > N - 1) 
        index = N - 1;
    return data[index];
}

template<typename T, size_t N> size_t Rij<T, N>::aantal_plaatsen() const {
    return N;
}

template<typename T, size_t N>  
ostream& operator<<(ostream& o, const Rij<T, N>& r) {
    o << r.lees_uit(0);
    for (size_t i = 1; i < N; ++i)
        o << ", " << r.lees_uit(i);
    return o;
}

int main() {
    Rij<int, 10> kwad;
    for (size_t i = 0; i < kwad.aantal_plaatsen(); ++i)
        kwad.zet_in(i, i * i);
    cout << "kwad = " << kwad << '\n';

    Rij<char, 26> alfabet;
    for (size_t i = 0; i < alfabet.aantal_plaatsen(); ++i)
        alfabet.zet_in(i, 'A' + i);
    cout << "alfabet = " << alfabet << '\n';
    cout << "de derde letter van alfabet is " << alfabet.lees_uit(2) << '\n';
    cout << "de honderste letter van alfabet is " << alfabet.lees_uit(99) << '\n';
}
