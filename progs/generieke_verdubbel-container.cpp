import std;
using namespace std;

// generieke verdubbel m.b.v. iterator
// kan gebruikt worden voor ALLE containers waarvan de elementen verdubbeld kunnen worden

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

template <typename T>
concept Const = is_const_v<T>;

template<typename C> void verdubbel(C& c) 
requires Number<typename C::value_type> && !Const<C> && output_iterator<typename C::iterator, typename C::value_type> {
    for (auto iter {c.begin()}; iter != c.end(); ++iter) {
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
    verdubbel(v);
    println("v = {}", v);
    println("l = {::.3f}", l);
    verdubbel(l);
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
    // const vector<int> cv1 {1, 2, 3};
    // verdubbel(cv1);
    // vector<const int> cv2 {1, 2, 3};
    // verdubbel(cv2);
    deque<complex<double>> d {4.0 + 7i, 5.0 + 6i};
    verdubbel(d);
}
