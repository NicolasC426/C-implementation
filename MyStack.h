#ifndef MYSTACK_H
#define MYSTACK_H

#include "SimpleList.h"
#include <stdexcept>

template <typename T>
class MyStack {
private:
    SimpleList<T> stack;
    
public:
    MyStack() : stack() {}

    void push(T data) {
        stack.insert(data);
    }

    T pop() {
        if (stack.isEmpty()) {
            throw std::out_of_range("Pila vacía");
        }
        T last = stack.get(stack.size() - 1);
        stack.remove(last);
        return last;
    }

    T peek() {
        if (stack.isEmpty()) {
            throw std::out_of_range("Pila vacía");
        }
        return stack.get(stack.size() - 1);
    }

    bool isEmpty() {
        return stack.isEmpty();
    }

    int size() {
        return stack.size();
    }
};

#endif