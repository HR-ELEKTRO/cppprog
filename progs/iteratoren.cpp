import std;
using namespace std;

int main() {
    set<string> namen;
    ifstream inf {"namen.txt"};
    if (inf) {
        copy(istream_iterator<string> {inf}, istream_iterator<string> {}, inserter(namen, namen.begin()));
        copy(namen.crbegin(), namen.crend(), ostream_iterator<string> {cout, "\n"});
    }
}
