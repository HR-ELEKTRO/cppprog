import std;
using namespace std;

int main() {
    vector v {1, 5, 4, 5, 4, 5, 9, 3};
    println("{}", v);
    // vector van voor naar achter doorzoeken
    auto eerste_vijf {find(v.begin(), v.end(), 5)};
    if (eerste_vijf != v.end()) {
        *eerste_vijf = 7;
    }
    println("{}", v);
    // vector van achter naar voor doorzoeken
    auto laatste_vijf {find(v.rbegin(), v.rend(), 5)};
    if (laatste_vijf != v.rend()) {
        *laatste_vijf = 7;
    }
    println("{}", v);
}
