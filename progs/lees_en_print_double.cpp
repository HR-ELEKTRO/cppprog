import std;
using namespace std;

int main() {
    print("Type een foating point getal in: ");
    double d;
    cin >> d;
    print("Hoeveel decimalen wil je afdrukken?: ");
    int aantal_decimalen;
    cin >> aantal_decimalen;
    println("d = {:.{}f}", d, aantal_decimalen);
}