#ifndef _TISD_Bd_StackWithList_
#define _TISD_Bd_StackWithList_

#include <iostream>
#include <cstdlib>
#include "stack.h"
//#define VERBOSE
#ifdef VERBOSE
#include <iostream>
#endif

template <typename T> class StackWithList: public Stack<T> {
public:
    StackWithList();
    virtual ~StackWithList() throw();
    virtual void push(const T& t) override;
    virtual void pop() override;
    virtual const T& top() const override;
    virtual bool empty() const override;
    virtual bool full() const override;
private:
    class Node {
    public:
        Node(const T& t, Node* n);
        T data;
        Node* next;
    };
    Node* p; // pointer naar de Node aan de top van de stack
};

template <typename T> StackWithList<T>::StackWithList(): p(0) {
}

template <typename T> StackWithList<T>::~StackWithList() throw() {
#ifdef VERBOSE
    std::cerr << "StackWithList<T>::~StackWithList() called" << std::endl; 
#endif
    while (!empty())
        pop();
}

template <typename T> void StackWithList<T>::push(const T& t) {
    p = new Node(t, p);
}

template <typename T> void StackWithList<T>::pop() {
    if (empty())
        std::cerr << "Can't pop from an empty stack" << std::endl;
    else {
        Node* old(p);
        p = p->next;
        delete old;
    }
}

template <typename T> const T& StackWithList<T>::top() const {
    if (empty()) {
        std::cerr << "Can't top from an empty stack" << std::endl;
        std::cin.get();
        std::cin.get();
        std::exit(-1);
        // no valid return possible
    }
    return p->data;
}

template <typename T> bool StackWithList<T>::empty() const {
    return p == 0;
}

template <typename T> bool StackWithList<T>::full() const {
    return false;
}

template <typename T> StackWithList<T>::Node::Node(const T& t, Node* n):
         data(t), next(n) {
}

#endif
