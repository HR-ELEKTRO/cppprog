import std;
using namespace std;

template <floating_point T> constexpr T tau = atan(static_cast<T>(1)) * 8;

int main() {
    auto f{tau<float>}; // f is float
    auto d{tau<double>}; // d is double
    auto l{tau<long double>}; // d is long double
    println("f = {:.50f}", f);
    println("d = {:.50f}", d);
    println("l = {:.50f}", l);
    println("τ = 6.28318530717958647692528676655900576839433879875021");
}
