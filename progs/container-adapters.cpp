import std;
using namespace std;

template <typename S> void stack_test(S& s) {
    println("stack_test voor: {}", typeid(S).name());
    for (auto e: {1, 3, 2}) {
        s.push(e);
    }
    println("{}", s);
}

template <typename Q> void queue_test(Q& q) {
    println("queue_test voor: {}", typeid(Q).name());
    for (auto e: {1, 3, 2}) {
        q.push(e);
    }
    println("{}", q);
}

template <typename P> void priority_queue_test(P& p) {
    println("priority_queue_test voor: {}", typeid(P).name());
    for (auto e: {1, 3, 2}) {
        p.push(e);
    }
    println("{}", p);
}

int main() {
    stack<int, vector<int>> s1;                 // stack implemented with vector
    stack_test(s1);
    stack<int, deque<int>> s2;                  // stack implemented with deque
    stack_test(s2);
    stack<int, list<int>> s3;                   // stack implemented with list
    stack_test(s3);
//  stack<int, forward_list<int>> s4;           // stack can not be implemented with forward_list
//  stack_test(s4);
//  error: 'class std::forward_list<int>' has no member named 'push_back'
    stack<int> s5;                              // using deque by default
    stack_test(s5);
    
//  queue<int, vector<int>> q1;                 // queue can not be implemented with vector
//  queue_test(q1);
//  error: 'class std::vector<int>' has no member named 'pop_front'
    queue<int, deque<int>> q2;                  // queue implemented with deque
    queue_test(q2);
    queue<int, list<int>> q3;                   // queue implemented with list
    queue_test(q3);
//  queue<int, forward_list<int>> q4;           // queue can not be implemented with forward_list
//  queue_test(q4);
//  error: 'class std::forward_list<int>' has no member named 'push_back'
    queue<int> q5;                              // using deque by default
    queue_test(q5);
    
    priority_queue<int, vector<int>> p1;       // priority_queue implemented with vector
    priority_queue_test(p1);
    priority_queue<int, deque<int>> p2;        // priority_queue implemented with deque
    priority_queue_test(p2);
//  priority_queue<int, list<int>> p3;         // priority_queue can not be implemented with list
//  priority_queue_test(p3);
//  error: no match for 'operator-'
//  priority_queue<int, forward_list<int>> p4; // priority_queue can not be implemented with forward_list
//  priority_queue_test(p4);
//  error: no match for 'operator-'
    priority_queue<int> p5;                    // using vector by default
    priority_queue_test(p5);
}