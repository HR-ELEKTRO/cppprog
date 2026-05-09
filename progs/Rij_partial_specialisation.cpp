// Een Rij met een willekeurig aantal plaatsen van een willekeurig type T

import std;
using namespace std;

template<typename T, size_t N> class Rij {
public:
    void zet_in(size_t index, const T& waarde);
    const T& lees_uit(size_t index) const;
    constexpr size_t aantal_plaatsen();
private:
    T data[N];
};

template<typename T, size_t N> void Rij<T, N>::zet_in(size_t index, const T& waarde) {
    if (index < N)
        data[index] = waarde;
}

template<typename T, size_t N> const T& Rij<T, N>::lees_uit(size_t index) const {
    if (index > N - 1) 
        index = N - 1;
    return data[index];
}

template<typename T, size_t N> constexpr size_t Rij<T, N>::aantal_plaatsen() {
    return N;
}

// Een partial class template specialisatie van een Rij met maar 1 element:

template<typename T> class Rij<T, 1> {
public:
    void zet_in(size_t index, const T& waarde);
    const T& lees_uit(size_t index) const;
    constexpr size_t aantal_plaatsen();
private:
    T data;
};

template<typename T> void Rij<T, 1>::zet_in(size_t index, const T& waarde) {
    if (index < 1)
        data = waarde;
}

template<typename T> const T& Rij<T, 1>::lees_uit(size_t) const {
    return data;
}

template<typename T> constexpr size_t Rij<T, 1>::aantal_plaatsen() {
    return 1;
}

template<typename T, size_t N> string naar_string(const Rij<T, N>& r) {
    string s {format("{}", r.lees_uit(0))};
    for (size_t i {1}; i < N; ++i)
        s += format(", {}", r.lees_uit(i));
    return s;
}

int main() {
    Rij<int, 10> kwad;
    for (size_t i {0}; i < kwad.aantal_plaatsen(); ++i)
        kwad.zet_in(i, i * i);
    println("kwad = {}", naar_string(kwad));

    Rij<char, 26> alfabet;
    for (size_t i {0}; i < alfabet.aantal_plaatsen(); ++i)
        alfabet.zet_in(i, 'A' + i);
    println("alfabet = {}", naar_string(alfabet));
    println("de derde letter van alfabet is {}", alfabet.lees_uit(2));
    println("de honderste letter van alfabet is {}", alfabet.lees_uit(99));
    Rij<double, kwad.aantal_plaatsen()> wortels;
    for (size_t i {0}; i < wortels.aantal_plaatsen(); ++i)
        wortels.zet_in(i, sqrt(i));
    println("wortels = {}", naar_string(wortels));

    Rij<int, 1> kampioen_schappen_Sparta;
    kampioen_schappen_Sparta.zet_in(0, 1959);
    println("Sparta was landskampioen in {}", kampioen_schappen_Sparta.lees_uit(0));
    println("kampioen_schappen_Sparta = {}", naar_string(kampioen_schappen_Sparta));
}
