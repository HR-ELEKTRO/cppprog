import std;
using namespace std;

int main() {
    vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    println("De som van alle getallen in v = {}", accumulate(v.cbegin(), v.cend(), 0));
    println("De som van alle even getallen in v = {}", accumulate(v.cbegin(), v.cend(), 0, [](auto som_tot_nu_toe, auto elm) {
        return elm % 2 == 0 ? som_tot_nu_toe + elm : som_tot_nu_toe;
    }));
}