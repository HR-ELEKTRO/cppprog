#ifndef _TISD_Bd_StackWithArray_
#define _TISD_Bd_StackWithArray_

#include <iostream>
#include <cstdlib>
#include "stack.h"

template <typename T> class StackWithArray: public Stack<T> {
public:
    explicit StackWithArray(size_t size);
    ~StackWithArray();
    virtual void push(const T& t) override;
    virtual void pop() override;
    virtual const T& top() const override;
    virtual bool empty() const override;
    virtual bool full() const override;
private:
    T* a;     // pointer naar de array
    size_t s; // size van a (max aantal elementen op de stack)
    size_t i; // index in a van eerste vrije plaats op de stack
};

template <typename T> StackWithArray<T>::StackWithArray(size_t size): a(0), s(size), i(0) {
    if (s == 0) {
        std::cerr << "Stack size should be >0" << std::endl;
        s = 0;
    }
    else {
        a = new T[s];
    }
}

template <typename T> StackWithArray<T>::~StackWithArray() {
    delete[] a;
}

template <typename T> void StackWithArray<T>::push(const T& t) {
    if (full()) {
        std::cerr << "Can't push on an full stack" << std::endl;
    }
    else {
        a[i++] = t;
    }
}

template <typename T> void StackWithArray<T>::pop() {
    if (empty()) {
        std::cerr << "Can't pop from an empty stack" << std::endl;
    }
    else {
        --i;
    }
}

template <typename T> const T& StackWithArray<T>::top() const {
    if (empty()) {
        std::cerr << "Can't top from an empty stack" << std::endl;
        std::exit(-1);
        // no valid return possible
    }
    return a[i - 1];
}

template <typename T> bool StackWithArray<T>::empty() const {
    return i == 0;
}

template <typename T> bool StackWithArray<T>::full() const {
    return i == s;
}

#endif
