// Een Rij met een willekeurig aantal plaatsen van een willekeurig type T

#include <iostream>
using namespace std;

template<typename T, size_t N> class Rij {
public:
    void zetIn(size_t index, const T& waarde);
    const T& leesUit(size_t index) const;
    size_t aantalPlaatsen() const;
private:
    T data[N];
};

template<typename T, size_t N> void Rij<T, N>::zetIn(size_t index, const T& waarde) {
    if (index >= 0 && index < N)
        data[index] = waarde;
}

template<typename T, size_t N> const T& Rij<T, N>::leesUit(size_t index) const {
    if (index < 0) 
        index = 0;
    if (index > N - 1) 
        index = N - 1;
    return data[index];
}

template<typename T, size_t N> size_t Rij<T, N>::aantalPlaatsen() const {
    return N;
}

template<typename T, size_t N>  
ostream& operator<<(ostream& o, const Rij<T, N>& r) {
    o << r.leesUit(0);
    for (size_t i = 1; i < N; ++i)
        o << ", " << r.leesUit(i);
    return o;
}

int main() {
    Rij<int, 10> kwad;
    for (size_t i = 0; i < kwad.aantalPlaatsen(); ++i)
        kwad.zetIn(i, i * i);
    cout << "kwad = " << kwad << '\n';

    Rij<char, 26> alfabet;
    for (size_t i = 0; i < alfabet.aantalPlaatsen(); ++i)
        alfabet.zetIn(i, 'A' + i);
    cout << "alfabet = " << alfabet << '\n';
    cout << "de derde letter van alfabet is " << alfabet.leesUit(2) << '\n';
    cout << "de honderste letter van alfabet is " << alfabet.leesUit(99) << '\n';
}
