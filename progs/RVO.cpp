// Code om te zien of de compiler return value optimization (RVO) toepast.
import std;
using namespace std;

class Int {
public:
    Int(int i): value{i} {
        println("Int met waarde {} wordt aangemaakt.", value);
    }
    ~Int() {
        println("Int met waarde {} wordt verwijderd.", value);
    }
    Int(const Int& r): value{r.value} {
        println("Int met waarde {} wordt gekopieerd.", value);
    }
    int get_value() const {
        return value;
    }
private:
    int value;
};

Int maak_Int(int i) {
    Int result {i};
    return result;
}

int main() {
    Int local {maak_Int(42)};
    println("De waarde van local is {}.", local.get_value());
}
