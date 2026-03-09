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
    auto format(const Point& point, format_context& context) const {
        return formatter<pair<int, int>>::format({point.x, point.y}, context);
    }
};

template<>
struct std::formatter<Breuk>: public formatter<string> {
    auto format(const Breuk& breuk, format_context& context) const {
        return formatter<string>::format(to_string(breuk.teller) + "/" + to_string(breuk.noemer), context);;
    }
};

int main() {
    println("π = {:.5f}", numbers::pi);
    for (auto i: {3, 6, 9, 12, 15}) {
        println("π met {0:2} decimalen: {1:.{0}f}", i, numbers::pi, i);
    }
    vector v = {1, 2, 3, 4, 5};
    println("vector v = {}", v);
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
    // println("Point point = {::x}", point);
    // met : als seperator
    println("Point point = {:m}", point);
    Breuk breuk{31, 71};
    println("Breuk breuk = {:>10}", breuk);
}