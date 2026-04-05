// Dit programma laat zien hoe je constanten kunt definiëren
// die door alle objecten van een class gedeeld worden.
// Dit kan op 3 manieren:
// - als static constexpr datamembers ==> zie Manier1
// - als static const datamembers     ==> zie Manier2
// - als een anoniem enumeratietype   ==> zie Manier3

import std;
using namespace std;

namespace Manier1 {

class Color {
public:
    Color();
    Color(int c);
    int get_value() const;
    void set_value(int c);
//  constanten:
    static constexpr int BLACK {0x00000000};
    static constexpr int RED {0x00FF0000};
    static constexpr int YELLOW {0x00FFFF00};
    static constexpr int GREEN {0x0000FF00};
    static constexpr int LIGHTBLUE {0x0000FFFF};
    static constexpr int BLUE {0x000000FF};
    static constexpr int PURPER {0x00FF00FF};
    static constexpr int WHITE {0x00FFFFFF};
//  ...
private:
    int value;
};

ostream& operator<<(ostream& out, Color c) {
    return out << setw(6) << setfill('0') << hex << c.get_value();
}

Color::Color(): value{BLACK} {
}

Color::Color(int v): value{v} {
}

int Color::get_value() const {
    return value;
}

void Color::set_value(int v) {
    value = v;
}

}
namespace Manier2 {

class Color {
public:
    Color();
    Color(int c);
    int get_value() const;
    void set_value(int c);
//  constanten:
    static const int BLACK {0x00000000};
    static const int RED {0x00FF0000};
    static const int YELLOW {0x00FFFF00};
    static const int GREEN {0x0000FF00};
    static const int LIGHTBLUE {0x0000FFFF};
    static const int BLUE {0x000000FF};
    static const int PURPER {0x00FF00FF};
    static const int WHITE {0x00FFFFFF};
//  ...
private:
    int value;
};

ostream& operator<<(ostream& out, Color c) {
    return out << setw(6) << setfill('0') << hex << c.get_value();
}

Color::Color(): value{BLACK} {
}

Color::Color(int v): value{v} {
}

int Color::get_value() const {
    return value;
}

void Color::set_value(int v) {
    value = v;
}

}
namespace Manier3 {
    
class Color {
public:
    Color();
    Color(int c);
    int get_value() const;
    void set_value(int c);
//  constanten:
    enum {
        BLACK = 0x00000000, RED = 0x00FF0000,
        YELLOW = 0x00FFFF00, GREEN = 0x0000FF00,
        LIGHTBLUE = 0x0000FFFF, BLUE = 0x000000FF,
        PURPER = 0x00FF00FF, WHITE = 0x00FFFFFF
//  ...
    };
private:
    int value;
};

ostream& operator<<(ostream& out, Color c) {
    return out << setw(6) << setfill('0') << hex << c.get_value();
}

Color::Color(): value{BLACK} {
}

Color::Color(int v): value{v} {
}

int Color::get_value() const {
    return value;
}

void Color::set_value(int v) {
    value = v;
}

}

template<>
struct std::formatter<Manier1::Color>: public formatter<string> {
    auto format(const Manier1::Color& color, auto& context) const {
        ostringstream ss;
        ss << color;
        return formatter<string>::format(ss.str(), context);
    }
};

template<>
struct std::formatter<Manier2::Color>: public formatter<string> {
    auto format(const Manier2::Color& color, auto& context) const {
        ostringstream ss;
        ss << color;
        return formatter<string>::format(ss.str(), context);
    }
};

template<>
struct std::formatter<Manier3::Color>: public formatter<string> {
    auto format(const Manier3::Color& color, auto& context) const {
        ostringstream ss;
        ss << color;
        return formatter<string>::format(ss.str(), context);
    }
};

int main() {
{
    using namespace Manier1;
    Color c {Color::YELLOW};
    println("c = {}", c);
    c.set_value(Color::BLUE);
    println("c = {}", c);
}
{
    using namespace Manier2;
    Color c {Color::YELLOW};
    println("c = {}", c);
    c.set_value(Color::BLUE);
    println("c = {}", c);
}
{
    using namespace Manier3;
    Color c {Color::YELLOW};
    println("c = {}", c);
    c.set_value(Color::BLUE);
    println("c = {}", c);
}
}