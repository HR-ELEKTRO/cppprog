import std;
using namespace std;

struct Breuk {
    int teller, noemer;
};

struct Point {
    int x, y;
};

template<>
struct std::formatter<Point>: public formatter<pair<int, int>> {
    auto format(const Point& point, auto& context) const {
        return formatter<pair<int, int>>::format({point.x, point.y}, context);
    }
};

template<>
struct std::formatter<Breuk>: public formatter<string> {
    auto format(const Breuk& breuk, auto& context) const {
        return formatter<string>::format(to_string(breuk.teller) + "/" + to_string(breuk.noemer), context);
    }
};

int main() {
	int i {42};
	int j {666};
	println("i = {}, j = {}", i, j);
	println("j = {1}, i = {0}", i, j);
    println("i = {:>4}\nj = {:>4}", i, j);
    println("i = {:0>4}\nj = {:0>4}", i, j);
    println("decimaal {0} is gelijk aan hexadecimaal {0:X}", i);

    println("π = {:.5f}", numbers::pi);
    for (auto i: {3, 6, 9, 12, 15}) {
        println("π met {0:2} decimalen: {1:.{0}f}", i, numbers::pi, i);
    }

    vector v = {11, 12, 13, 14, 15};
    println("vector v = {}", v);
    println("vector v = {:>40}", v);
    println("vector v = {:*^40:#X}", v);
    println("vector v = {:*^40:_^4}", v);

    complex c = {3, 4};
    cout << "complex c = " << c << '\n';
    // Waarom werkt dit niet?
    // println("complex c = {}", c);

    Point point{31, 71};
    println("Point point = {:>10}", point);
    // zonder haakjes
    println("Point point = {:n}", point);
    // als hex getallen
    // Waarom werkt dit niet?
    // println("Point point = {::#x}", point);

    pair p = {31, 71};
    println("pair p = {}", p);
    println("pair p = {:>10}", p);
    // zonder haakjes
    println("pair p = {:n}", p);
    // met : als seperator
    println("pair p = {:m}", p);
    // Werkt ook niet voor pair
    // println("pair p = {::#x}", p);
    // met : als seperator
    println("Point point = {:m}", point);

    Breuk breuk{31, 71};
    println("Breuk breuk = {:>10}", breuk);
}