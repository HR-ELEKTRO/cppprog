// Een Rij met een willekeurig aantal plaatsen van een willekeurig type T

#include <iostream>
using namespace std;

template<typename T, int N> class Rij {
public:
    void zetIn(int index, const T& waarde);
    const T& leesUit(int index) const;
    int aantalPlaatsen() const;
private:
    T data[N];
};

template<typename T, int N> void Rij<T, N>::zetIn(int index, const T& waarde) {
    if (index >= 0 && index < N) data[index] = waarde;
}

template<typename T, int N> const T& Rij<T, N>::leesUit(int index) const {
    if (index < 0) index = 0;
    if (index > N - 1) index = N - 1;
    return data[index];
}

template<typename T, int N> int Rij<T, N>::aantalPlaatsen() const {
    return N;
}

template<typename T, int N>  
ostream& operator<<(ostream& o, const Rij<T, N>& r) {
    o << r.leesUit(0);
    for (int i = 1; i < N; ++i)
        o << ", " << r.leesUit(i);
    return o;
}

int main() {
    Rij<int, 10> kwad;
    for (int i = 0; i < kwad.aantalPlaatsen(); ++i)
        kwad.zetIn(i, i * i);
    cout << "kwad = " << kwad << endl;

    Rij<char, 26> alfabet;
    for (int i = 0; i < alfabet.aantalPlaatsen(); ++i)
        alfabet.zetIn(i, 'A' + i);
    cout << "alfabet = " << alfabet << endl;
    cout << "de derde letter van alfabet is " << alfabet.leesUit(2) << endl;
    cout << "de honderste letter van alfabet is " << alfabet.leesUit(99) << endl;

    cin.get();
    return 0;
}
