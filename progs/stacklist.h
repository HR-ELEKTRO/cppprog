#ifndef _HR_BroJZ_Stack_with_list_
#define _HR_BroJZ_Stack_with_list_

#include <iostream>
#include <cstdlib>
#include "stack.h"
//#define VERBOSE
#ifdef VERBOSE
#include <iostream>
#endif

template <typename T> class Stack_with_list: public Stack<T> {
public:
    Stack_with_list();
    virtual ~Stack_with_list() throw();
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

template <typename T> Stack_with_list<T>::Stack_with_list(): p(0) {
}

template <typename T> Stack_with_list<T>::~Stack_with_list() throw() {
#ifdef VERBOSE
    std::cerr << "Stack_with_list<T>::~Stack_with_list() called" << std::endl; 
#endif
    while (!empty())
        pop();
}

template <typename T> void Stack_with_list<T>::push(const T& t) {
    p = new Node(t, p);
}

template <typename T> void Stack_with_list<T>::pop() {
    if (empty())
        std::cerr << "Can't pop from an empty stack" << std::endl;
    else {
        Node* old(p);
        p = p->next;
        delete old;
    }
}

template <typename T> const T& Stack_with_list<T>::top() const {
    if (empty()) {
        std::cerr << "Can't top from an empty stack" << std::endl;
        std::cin.get();
        std::cin.get();
        std::exit(-1);
        // no valid return possible
    }
    return p->data;
}

template <typename T> bool Stack_with_list<T>::empty() const {
    return p == 0;
}

template <typename T> bool Stack_with_list<T>::full() const {
    return false;
}

template <typename T> Stack_with_list<T>::Node::Node(const T& t, Node* n):
         data(t), next(n) {
}

#endif
