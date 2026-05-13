import std;
using namespace std;

// Check which locales are available on your Linux or WSL system with the following command in the terminal:
// locale -a
// if en_US.utf8 and nl_NL.utf8 are not listed, you can enable them with the following command:
// sudo nano /etc/locale.gen
// Uncomment the lines for en_US.UTF-8 and nl_NL.UTF-8, then run the following command to generate the locales:
// sudo locale-gen

int main() {
    char taal;
    do {
        print("Nederlands (N) / English (E): ");
        cin >> taal;
    } while (taal != 'N' && taal != 'E');
    int index {taal == 'N'? 0 : 1};
    auto loc {taal == 'N'? locale{"nl_NL.utf8"} : locale{"en_US.utf8"}};
    array vraag {"Geef een groot getal: ", "Enter a big number: "};
    array antwoord {"Je hebt het getal {} ingevoerd.", "You have entered the number {}."};
    print("{}", vraag[index]);
    int getal;
    cin >> getal;
    string getal_als_string {format(loc, "{:L}", getal)};
    println("{}", vformat(antwoord[index], make_format_args(getal_als_string)));
}
