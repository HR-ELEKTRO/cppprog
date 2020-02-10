#ifndef _HR_BROJZ_Stack_with_array_
#define _HR_BROJZ_Stack_with_array_

#include <exception>
#include "stack.h"

template <typename T> class Stack_with_array: public Stack<T> {
public:
    explicit Stack_with_array(size_t size);
    ~Stack_with_array() override;
    void push(const T& t) override;
    void pop() override;
    const T& top() const override;
    bool empty() const override;
    bool full() const override;
private:
    T* a;     // pointer naar de array
    size_t s; // size van a (max aantal elementen op de stack)
    size_t i; // index in a van eerste vrije plaats op de stack
};

template <typename T> Stack_with_array<T>::Stack_with_array(size_t size): a{0}, s{size}, i{0} {
    if (s == 0) 
        throw std::domain_error {"Stack size should be >0\n"};
    a = new T[s];
}

template <typename T> Stack_with_array<T>::~Stack_with_array() {
    delete[] a;
}

template <typename T> void Stack_with_array<T>::push(const T& t) {
    if (full()) 
        throw std::overflow_error {"Can't push on an full stack\n"};
    a[i++] = t;
}

template <typename T> void Stack_with_array<T>::pop() {
    if (empty())
        throw std::underflow_error {"Can't pop from an empty stack\n"};
    --i;
}

template <typename T> const T& Stack_with_array<T>::top() const {
    if (empty())
        throw std::underflow_error {"Can't top from an empty stack\n"};
    return a[i - 1];
}

template <typename T> bool Stack_with_array<T>::empty() const {
    return i == 0;
}

template <typename T> bool Stack_with_array<T>::full() const {
    return i == s;
}

#endif
