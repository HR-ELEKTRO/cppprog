import std;
using namespace std;

auto samengestelde_interest(float startkapitaal, float rente_per_jaar, int aantal_jaar) {
    float eindkapitaal {startkapitaal};
    for (int jaar {1}; jaar <= aantal_jaar; ++jaar) {
        eindkapitaal = eindkapitaal * (1 + rente_per_jaar);
    }
    return eindkapitaal;
}

double samengestelde_interest_2(float startkapitaal, float rente_per_jaar, int aantal_jaar) {
    return startkapitaal * pow((1 + rente_per_jaar), aantal_jaar);
}

int main() {
    println("100000000 euro tegen 1,35% vast voor 10 jaar levert {} euro op.", samengestelde_interest(100'000'000, 0.0135, 10));
    println("100000000 euro tegen 1,35% vast voor 10 jaar levert {} euro op.", samengestelde_interest_2(100'000'000, 0.0135, 10));
}
