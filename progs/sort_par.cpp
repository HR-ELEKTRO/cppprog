import std;
using namespace std;

int main() {
    {
        vector rij {1, 7, 2, 5, 8, 3};
        sort(rij.begin(), rij.end());
        println("{}", rij);
    }
    {
        vector rij {1, 7, 2, 5, 8, 3};
        sort(execution::seq, rij.begin(), rij.end());
        println("{}", rij);
    }
    {
        vector rij {1, 7, 2, 5, 8, 3};
        sort(execution::par, rij.begin(), rij.end());
        println("{}", rij);
    }
    {
        vector rij {1, 7, 2, 5, 8, 3};
        sort(execution::par_unseq, rij.begin(), rij.end());
        println("{}", rij);
    }
}
