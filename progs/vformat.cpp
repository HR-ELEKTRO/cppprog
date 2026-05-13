import std;
using namespace std;

int main() {
    double x;
    println("Voer een floating point getal in: ");
    cin >> x;
    print("Hoeveel decimalen wil je zien? ");
    int decimalen;
    cin >> decimalen;
    println("Welk format wil je gebruiken ('a', 'A', 'e', 'E', 'f', 'g' of 'G')? ");
    char format_letter;
    cin >> format_letter;
    string format_specifier {format("{{:.{}{}}}", decimalen, format_letter)};
    println("{}", vformat(format_specifier, make_format_args(x)));
}
