#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
    // queue
    queue<int> pq0;
    pq0.push(3);
    pq0.push(1);
    pq0.push(2);
    while (!pq0.empty()) {
        cout << pq0.front() << " ";
        pq0.pop();
    }
    cout << '\n';
    // output: 3 1 2
    
    // priority_queue default order: sort with < (top = greatest element)
    priority_queue<int> pq1;
    pq1.push(3);
    pq1.push(1);
    pq1.push(2);
    while (!pq1.empty()) {
        cout << pq1.top() << " ";
        pq1.pop();
    }
    cout << '\n';
    // output: 3 2 1
    
    // priority_queue sort with > (std::greater)
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(3);
    pq2.push(1);
    pq2.push(2);
    while (!pq2.empty()) {
        cout << pq2.top() << " ";
        pq2.pop();
    }
    cout << '\n';
    // output: 1 2 3
    
    // priority_queue sort with > (lambda)
    auto comp{[](int a, int b) {
            return a > b;
        }
    };
    priority_queue<int, vector<int>, decltype(comp)> pq3{comp};
    pq3.push(3);
    pq3.push(1);
    pq3.push(2);
    while (!pq3.empty()) {
        cout << pq3.top() << " ";
        pq3.pop();
    }
    cout << '\n';
    // output: 1 2 3
}