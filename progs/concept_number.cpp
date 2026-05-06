import std;
using namespace std;

// concept Number = integral<T> || floating_point<T>;
// Geen goed idee
// static_assert(Number<complex<double>>); // FAALT
// template <typename T>
// concept Number = integral<T> || floating_point<T>;

// template<class T> concept Number = is_arithmetic_v<T>;
// Idem

template <typename T>
concept Arithmetic = requires(T x, T y) {
    x=x;
    x+y; x-y; x*y; x/y;
    x+=y; x-=y; x*=y; x/=y;
};

template <typename T>
concept Character = 
    same_as<T, char> ||
    same_as<T, signed char> ||
    same_as<T, unsigned char> ||
    same_as<T, wchar_t> ||
    same_as<T, char8_t> ||
    same_as<T, char16_t> ||
    same_as<T, char32_t>;

template<typename T>
concept Number = Arithmetic<T> && !Character<T> && !same_as<T, bool>;

// bool moet uitgesloten worden omdat een bool automatisch naar een int kan worden geconverteerd.

template <typename TLeft, typename TRight>
concept MixedArithmetic = requires(TLeft x, TRight y) {
    x=x;
    x+y; x-y; x*y; x/y;
    {x+=y}  -> std::convertible_to<TLeft>;
    {x-=y}  -> std::convertible_to<TLeft>;
    {x*=y}  -> std::convertible_to<TLeft>;
    {x/=y}  -> std::convertible_to<TLeft>;
};

// dummy Breuk:
class Breuk {
public:
    Breuk(int teller=0, int noemer = 1);
    Breuk(float d) =delete;
    Breuk(double d) =delete;
    Breuk(long double d) =delete;
    Breuk& operator+=(const Breuk& b);
    Breuk& operator-=(const Breuk& b);
    Breuk& operator*=(const Breuk& b);
    Breuk& operator/=(const Breuk& b);
};

Breuk operator+(const Breuk& left, const Breuk& right);
Breuk operator-(const Breuk& left, const Breuk& right);
Breuk operator*(const Breuk& left, const Breuk& right);
Breuk operator/(const Breuk& left, const Breuk& right);

int main() {
    static_assert(Arithmetic<int>);
    static_assert(Arithmetic<double>);
    static_assert(Arithmetic<complex<double>>);
    static_assert(Arithmetic<Breuk>);
    static_assert(!Arithmetic<vector<int>>);
    // Dit is misschien verrassend:
    static_assert(Arithmetic<bool>);
    static_assert(Arithmetic<char>);

    println("Arithmetic<int> = {}", Arithmetic<int>);
    println("Arithmetic<double> = {}", Arithmetic<double>);
    println("Arithmetic<complex<double>> = {}", Arithmetic<complex<double>>);
    println("Arithmetic<Breuk> = {}", Arithmetic<Breuk>);
    println("Arithmetic<vector<int>> = {}", Arithmetic<vector<int>>);
    // Dit is misschien verrassend:
    println("Arithmetic<bool> = {}", Arithmetic<bool>);
    println("Arithmetic<char> = {}", Arithmetic<char>);
    
    static_assert(MixedArithmetic<int, double>);
    static_assert(MixedArithmetic<double, int>);
    static_assert(MixedArithmetic<complex<double>, double>);
    static_assert(!MixedArithmetic<double, complex<double>>);
    static_assert(MixedArithmetic<Breuk, int>);
    static_assert(!MixedArithmetic<int, Breuk>);
    static_assert(!MixedArithmetic<Breuk, double>);
    static_assert(!MixedArithmetic<double, Breuk>);
    
    static_assert(MixedArithmetic<float, double>);
    static_assert(MixedArithmetic<double, float>);
    
    static_assert(Number<int>);
    static_assert(Number<double>);
    static_assert(Number<complex<double>>);
    static_assert(Number<Breuk>);
    static_assert(!Number<char>);
    static_assert(!Number<bool>);
    static_assert(!Number<vector<int>>);

    println("Number<int> = {}", Number<int>);
    println("Number<double> = {}", Number<double>);
    println("Number<complex<double>> = {}", Number<complex<double>>);
    println("Number<Breuk> = {}", Number<Breuk>);
    println("Number<char> = {}", Number<char>);
    println("Number<bool> = {}", Number<bool>);
    println("Number<vector<int>> = {}", Number<vector<int>>);
}