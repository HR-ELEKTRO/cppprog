import std;
using namespace std;
using namespace std::placeholders;

int main() {
    vector<int> w;
    for (int i {0}; i < 10; ++i) {
        w.push_back(i * i);
    }
    println("Na initialisatie: {}", w);
//  verwijder alle even elementen:
    w.erase(ranges::remove_if(w, bind(equal_to(), bind(modulus(), _1, 2), 0)).begin(), w.end());
    println("Na remove: {}", w);
}
