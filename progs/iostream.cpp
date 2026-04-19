import std;
using namespace std;

int main() {
    cout << "Type een foating point getal in: ";
    double d;
    cin >> d; // lees d in vanaf toetsenbord
    cout << "d = " << fixed << setprecision(3) << d << '\n'; // druk d af op scherm met drie decimalen achter de punt ga naar het begin van de volgende regel
}
