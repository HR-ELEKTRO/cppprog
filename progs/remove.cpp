import std;
using namespace std;

int main() {
    vector<int> v;
    for (int i {0}; i < 10; ++i) {
        v.push_back(i * i);
    }
    vector w {v};

//  code om te laten zien hoe remove werkt:
    println("Na initialisatie: {}", v);
    auto end_range {ranges::remove_if(v, [](auto i) {
            return i % 2 == 0;
        })
    };
    println("Na remove (tot returned iterator): {}", end_range);
    println("Na remove (hele vector): {}", v);
    v.erase(end_range.cbegin(), v.cend());
    println("Na erase (hele vector): {}", v);

//  in de praktijk gebruiken we een remove altijd binnen een erase:
    w.erase(ranges::remove_if(w, [](auto i) {
        return i % 2 == 0;
    }).cbegin(), w.cend());
    println("Na remove binnen erase: {}", w);
}
