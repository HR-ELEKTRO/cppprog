#include <iostream>
#include <chrono>
#include <array>
#include <numeric>
using namespace std;

void f() {
    for (volatile long long int i {100'000'000}; i > 0; --i);
}

int main() {
    array<chrono::microseconds::rep, 10> meting;
    for (auto& m: meting) {
        auto start {chrono::high_resolution_clock::now()};
        f();
        auto stop {chrono::high_resolution_clock::now()};
        auto duration {chrono::duration_cast<chrono::microseconds>(stop - start).count()};
        cout << "Calculation time: " << duration << " us\n";
        m = duration;
    }
    auto total{accumulate(meting.begin(), meting.end(), 0)};
    cout << "Average duration time: " << total/10 << " us\n";
}