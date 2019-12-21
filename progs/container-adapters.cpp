#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <iostream>
#include <typeinfo>
using namespace std;

template <typename S> void stackTest(S& s) {
    cout << "stackTest voor: " << typeid(S).name() << '\n';
    vector<int> v{1, 3, 2};
    for (auto e: v) {
        s.push(e);
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << '\n';
}

template <typename Q> void queueTest(Q& q) {
    cout << "queueTest voor: " << typeid(Q).name() << '\n';
    vector<int> v{1, 3, 2};
    for (auto e: v) {
        q.push(e);
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << '\n';
}

template <typename P> void priority_queueTest(P& p) {
    cout << "priority_queueTest voor: " << typeid(P).name() << '\n';
    vector<int> v{1, 3, 2};
    for (auto e: v) {
        p.push(e);
    }
    while (!p.empty()) {
        cout << p.top() << " ";
        p.pop();
    }
    cout << '\n';
}

int main() {
    stack<int, vector<int>> s1;                 // stack implemented with vector
    stackTest(s1);
    stack<int, deque<int>> s2;                  // stack implemented with deque
    stackTest(s2);
    stack<int, list<int>> s3;                   // stack implemented with list
    stackTest(s3);
//  stack<int, forward_list<int>> s4;           // stack can not be implemented with forward_list
//  stackTest(s4);
//  error: 'class std::forward_list<int>' has no member named 'push_back'
    stack<int> s5;                              // using deque by default
    stackTest(s5);
    
//  queue<int, vector<int>> q1;                 // queue can not be implemented with vector
//  queueTest(q1);
//  error: 'class std::vector<int>' has no member named 'pop_front'
    queue<int, deque<int>> q2;                  // queue implemented with deque
    queueTest(q2);
    queue<int, list<int>> q3;                   // queue implemented with list
    queueTest(q3);
//  queue<int, forward_list<int>> q4;           // queue can not be implemented with forward_list
//  queueTest(q4);
//  error: 'class std::forward_list<int>' has no member named 'push_back'
    queue<int> q5;                              // using deque by default
    queueTest(q5);
    
    priority_queue<int, vector<int>> p1;       // priority_queue implemented with vector
    priority_queueTest(p1);
    priority_queue<int, deque<int>> p2;        // priority_queue implemented with deque
    priority_queueTest(p2);
//  priority_queue<int, list<int>> p3;         // priority_queue can not be implemented with list
//  priority_queueTest(p3);
//  error: no match for 'operator-'
//  priority_queue<int, forward_list<int>> p4; // priority_queue can not be implemented with forward_list
//  priority_queueTest(p4);
//  error: no match for 'operator-'
    priority_queue<int> p5;                    // using vector by default
    priority_queueTest(p5);
}