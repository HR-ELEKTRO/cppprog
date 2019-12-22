#include <vector>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
using namespace std;

class Score {
public:
    Score(const string& n, int p);
    int punten() const;
    const string& naam() const;
private:
    string nm;
    int pnt;
};

Score::Score(const string& n, int p): nm{n}, pnt{p} {
}
int Score::punten() const {
    return pnt;
}
const string& Score::naam() const {
    return nm;
}

ostream& operator<<(ostream& left, const Score& d) {
    return left << setw(5) << d.punten() << " " << d.naam();
}

int main() {
    vector<Score> scores{
        Score("Theo", 300),
        Score("Marie-louise", 300),
        Score("Koen", 300),
        Score("Linda", 300),
        Score("Marie-louise", 400),
        Score("Anne", 300),
        Score("Marie-louise", 50)
    };
    sort(scores.begin(), scores.end(), [](const Score& d1, const Score& d2) {
        return d1.naam() < d2.naam();
    });
    stable_sort(scores.begin(), scores.end(), [](const Score& d1, const Score& d2) {
        return d1.punten() > d2.punten();
    });
    ostream_iterator<Score> iout{cout, "\n"};
    copy(scores.begin(), scores.end(), iout);
}
