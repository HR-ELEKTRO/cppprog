import std;
using namespace std;

// generieke verdubbel met behulp van een range van twee iteratoren
// met deze functie kun je ook een DEEL van een container verdubbelen

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

template <typename Iter> void verdubbel(Iter begin, Iter end)
requires Number<typename Iter::value_type> && output_iterator<Iter, typename Iter::value_type> {
    for (Iter iter {begin}; iter != end; ++iter) {
        *iter *= 2;
    }
}

int main() {
    vector<int> v;
    list<double> l;
    for (int i {1}; i <= 10; ++i) {
        v.push_back(i);
        l.push_back(1.0 / i);
    }
    println("v = {}", v);
    verdubbel(v.begin(), v.end());
    println("v = {}", v);
    verdubbel(v.begin() + 1, v.end() - 1);
    println("v = {}", v);
    println("l = {::.3f}", l);
    verdubbel(l.begin(), l.end());
    println("l = {::.3f}", l);
    // vector<string> vs {"a", "b", "c"};
    // println("vs = {}", vs);
    // verdubbel(vs);
    // error: no matching function for call to 'verdubbel(vector<__cxx11::basic_string<char> >&)'
    // note: template argument deduction/substitution failed
    // note: constraints not satisfied
    // println("vs = {}", vs);
    // string s {"HALLO"};
    // println("s = {}", s);
    // verdubbel(s);
    // error: no matching function for call to 'verdubbel(std::string&)'
    // note: template argument deduction/substitution failed
    // note: constraints not satisfied
    // println("s = {}", s);
    // const vector cv1 {1, 2, 3};
    // verdubbel(cv1.begin(), cv1.end());
    // error: no matching function for call to 'verdubbel(std::vector<int>::const_iterator, std::vector<int>::const_iterator)'
    // note: template argument deduction/substitution failed:
    // note: constraints not satisfied
    // Een vector met constanten is so-wie-so niet toegestaan.
    // vector<const int> cv2 {1, 2, 3};
    // error: static assertion failed: std::vector must have a non-const, non-volatile value_type
}
