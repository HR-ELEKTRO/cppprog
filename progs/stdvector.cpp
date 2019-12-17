#include <iostream>
#include <vector>
using namespace std;

// Afdrukken van een vector door middel van indexering.
void print1(const vector<int>& vec) {
    cout << "De inhoud van de vector is:" << endl;
    for (vector<int>::size_type index = 0; index != vec.size(); ++index) {
        cout << vec[index] << " ";
    }
    cout << endl;
}


// Afdrukken van een vector door middel van indexering met decltype.
void print2(const vector<int>& vec) {
    cout << "De inhoud van de vector is:" << endl;
    for (decltype(vec.size()) index = 0; index != vec.size(); ++index) {
        cout << vec[index] << " ";
    }
    cout << endl;
}

// Afdrukken van een vector door middel van iterator.
void print3(const vector<int>& vec) {
    cout << "De inhoud van de vector is:" << endl;
    for (vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

// Afdrukken van een vector door middel van iterator met auto.
void print4(const vector<int>& vec) {
    cout << "De inhoud van de vector is:" << endl;
    for (auto iter = vec.cbegin(); iter != vec.cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

// Afdrukken van een vector door middel van range-based for.
void print5(const vector<int>& vec) {
    cout << "De inhoud van de vector is:" << endl;
    for (auto elm : vec) {
        cout << elm << " ";
    }
    cout << endl;
}

// Berekenen van het gemiddelde door middel van iterator met auto.
double gem1(const vector<int>& vec) {
    if (vec.empty()) {
        return 0;
    }
    double som = 0.0;
    for (auto iter = vec.cbegin(); iter != vec.cend(); ++iter) {
        som += *iter;
    }
    return som / vec.size();
}

// Berekenen van het gemiddelde door middel van van range-based for.
double gem2(const vector<int>& vec) {
    if (vec.empty()) {
        return 0;
    }
    double som = 0.0;
    for (auto elm : vec) {
        som += elm;
    }
    return som / vec.size();
}

int main() {
    vector<int> v;
    int i;
    cout << "Geef een aantal getallen (afgesloten door een 0):" << endl;
    cin >> i;
    while (i != 0) {
        v.push_back(i);
        cin >> i;
    }
    print1(v);
    print2(v);
    print3(v);
    print4(v);
    print5(v);
    cout << "Het gemiddelde is: " << gem1(v) << endl;
    cout << "Het gemiddelde is: " << gem2(v) << endl;
    cout << "Nu wordt een deel van de vector bewerkt." << endl;
    if (v.size() >= 4) {
        for (auto iter = v.begin() + 2; iter != v.begin() + 4; ++iter) {
            *iter *= 2;
        }
    }
    print3(v);
    cout << "Nu wordt de vorige bewerking weer teruggedraaid." << endl;
    if (v.size() >= 4) {
        for (decltype(v.size()) i = 2; i < 4; ++i) {
            v[i] /= 2;
        }
    }
    print5(v);
    cin.get();
    cin.get();
    return 0;
}
