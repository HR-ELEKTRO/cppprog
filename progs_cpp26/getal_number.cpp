import std;
using namespace std;

int main() {
    char taal;
    do {
        print("Nederlands (N) / English (E): ");
        cin >> taal;
    } while (taal != 'N' && taal != 'E');
/* Werkt maar code wordt herhaald:
    if (taal == 'N') {
        print("Geef een getal: ");
        int getal;
        cin >> getal;
        println("Je hebt het getal {} ingevoerd.", getal);
    } else {
        print("Enter a number: ");
        int getal;
        cin >> getal;
        println("You have entered the number {}.", getal);
    }
*/
    int index {taal == 'N'? 0 : 1};
    array vraag {"Geef een getal: ", "Enter a number: "};
    array antwoord {"Je hebt het getal {} ingevoerd.", "You have entered the number {}."};
    print("{}", vraag[index]);
    int getal;
    cin >> getal;
//  In de C++26 standaard is runtime_format hernoemd naar dynamic_format, zie: \url{https://en.cppreference.com/cpp/utility/format/dynamic_format}.
    println(runtime_format(antwoord[index]), getal);
//  println(dynamic_format(antwoord[index]), getal);
}
