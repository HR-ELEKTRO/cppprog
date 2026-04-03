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
    auto end {remove_if(v.begin(), v.end(), [](auto i) {
            return i % 2 == 0;
        })
    };
    println("Na remove (tot returned iterator): {}", ranges::subrange{v.begin(), end});
    println("Na remove (hele vector): {}", v);
    v.erase(end, v.end());
    println("Na erase (hele vector): {}", v);

//  in de praktijk gebruiken we een remove altijd binnen een erase:
    w.erase(remove_if(w.begin(), w.end(), [](auto i) {
        return i % 2 == 0;
    }), w.end());
    println("Na remove binnen erase: {}", w);
}
