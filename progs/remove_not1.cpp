import std;
using namespace std;
using namespace std::placeholders;

int main() {
    vector<int> w;
    for (int i {0}; i < 10; ++i) {
        w.push_back(i * i);
    }
    println("{}", w);
        
//  verwijder alle even elementen:
//  bind2nd is deprecated in C++11 (en niet meer gedefinieerd in C++17)
    w.erase(remove_if(w.begin(), w.end(), not1(bind2nd(modulus(), 2))), w.end());
//  bind werkt niet omdat die geen argument_type definieert. 
//  w.erase(remove_if(w.begin(), w.end(), not1(bind(modulus<int>(), _1, 2))), w.end());
    println("{}", w);
}
