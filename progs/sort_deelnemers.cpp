import std;
using namespace std;

class Score {
public:
    Score(string_view n, int p);
    int punten() const;
    string naam() const;
private:
    string nm;
    int pnt;
};

Score::Score(string_view n, int p): nm{n}, pnt{p} {
}
int Score::punten() const {
    return pnt;
}
string Score::naam() const {
    return nm;
}

int main() {
    vector scores {
        Score {"Theo", 300},
        Score {"Marie-louise", 300},
        Score {"Koen", 300},
        Score {"Linda", 300},
        Score {"Marie-louise", 400},
        Score {"Anne", 300},
        Score {"Marie-louise", 50}
    };
    sort(scores.begin(), scores.end(), [](const auto& d1, const auto& d2) {
        return d1.naam() < d2.naam();
    });
    stable_sort(scores.begin(), scores.end(), [](const auto& d1, const auto& d2) {
        return d1.punten() > d2.punten();
    });
    println("Scores van hoog naar laag:");
    for (const auto& s: scores) {
        println("{:>5} {}", s.punten(), s.naam());
    }
}
