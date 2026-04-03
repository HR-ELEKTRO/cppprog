import std;
using namespace std;

int main() {
    vector<int> kwadraten;
    int n {0};
    generate_n(back_inserter(kwadraten), 10, [&n]() {
        ++n; return n * n;
    });
    println("De eerste 10 kwadraten: {:n}", kwadraten); 
}