import std;
using namespace std;

// Verdubbel elementen van een vector<int> door middel van indexering.
void verdubbel1(vector<int>& vec) {
    for (vector<int>::size_type index {0}; index != vec.size(); ++index) {
        vec[index] *= 2;
    }
}

// Verdubbel elementen van een vector<int> door middel van indexering met decltype.
void verdubbel2(vector<int>& vec) {
    for (decltype(vec.size()) index {0}; index != vec.size(); ++index) {
        vec[index] *= 2;
    }
}

// Verdubbel elementen van een vector<int> door middel van iterator.
void verdubbel3(vector<int>& vec) {
    for (vector<int>::iterator iter {vec.begin()}; iter != vec.end(); ++iter) {
        *iter *= 2;
    }
}

// Verdubbel elementen van een vector<int> door middel van iterator met auto.
void verdubbel4(vector<int>& vec) {
    for (auto iter {vec.begin()}; iter != vec.end(); ++iter) {
        *iter *= 2;
    }
}

// Verdubbel elementen van een vector<int> door middel van range-based for.
void verdubbel5(vector<int>& vec) {
    for (auto& elm: vec) {
        elm *= 2;
    }
}

// Berekenen van het gemiddelde door middel van iterator met auto.
double gem1(const vector<int>& vec) {
    if (vec.empty()) {
        return 0;
    }
    double som {0.0};
    for (auto iter {vec.cbegin()}; iter != vec.cend(); ++iter) {
        som += *iter;
    }
    return som / vec.size();
}

// Berekenen van het gemiddelde door middel van van range-based for.
double gem2(const vector<int>& vec) {
    if (vec.empty()) {
        return 0;
    }
    double som {0.0};
    for (auto elm: vec) {
        som += elm;
    }
    return som / vec.size();
}

int main() {
    vector<int> v;
    int i;
    print("Geef een aantal getallen (afgesloten door een 0): ");
    cin >> i;
    while (i != 0) {
        v.push_back(i);
        cin >> i;
    }
    println("v = {}", v);
    verdubbel1(v);
    println("v = {}", v);
    verdubbel2(v);
    println("v = {}", v);
    verdubbel3(v);
    println("v = {}", v);
    verdubbel4(v);
    println("v = {}", v);
    verdubbel5(v);
    println("v = {}", v);
    println("Het gemiddelde is: {:.3f}", gem1(v));
    println("Het gemiddelde is: {:.3f}", gem2(v));
}
