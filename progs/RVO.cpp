// Code om te zien of de compiler return value optimization (RVO) toepast.
#include <iostream>
using namespace std;

class Int {
public:
    Int(int i): value{i} {
    	cout << "Int met waarde " << value << " wordt aangemaakt.\n";
    }
    ~Int() {
    	cout << "Int met waarde " << value << " wordt verwijderd.\n";
    }
    Int(const Int& r): value{r.value} {
    	cout << "Int met waarde " << value << " wordt gekopieerd.\n";
    }
    int getValue() const {
    	return value;
    }
private:
    int value;
};

Int maakInt(int i) {
	Int result{i};
	return result;
}

int main() {
	Int local{maakInt(42)};
	cout << "De waarde van local is " << local.getValue() << '\n';
}
