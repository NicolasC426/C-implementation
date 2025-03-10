#ifndef SIMPLELIST_H
#define SIMPLELIST_H

#include <iostream>
#include <iterator>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class SimpleList {
private:
    Node<T>* head;

public:
    SimpleList() : head(nullptr) {}

    void insert(T data) {
        if (isEmpty()) {
            head = new Node<T>(data);
        } else {
            Node<T>* auxHead = head;
            while (auxHead->next != nullptr) {
                auxHead = auxHead->next;
            }
            auxHead->next = new Node<T>(data);
        }
    }

    bool exist(T data) {
        for (auto it = begin(); it != end(); ++it) {
            if (*it == data) {
                return true;
            }
        }
        return false;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void show() {
        if (isEmpty()) {
            std::cout << "Lista vacía" << std::endl;
            return;
        }
        for (auto it = begin(); it != end(); ++it) {
            std::cout << *it << " ~ ";
        }
        std::cout << "Null" << std::endl;
    }

    bool remove(T data) {
        if (isEmpty()) return false;

        Node<T>* prev = nullptr;
        Node<T>* current = head;

        for (auto it = begin(); it != end(); ++it) {
            if (*it == data) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }

    int size() {
        int count = 0;
        Node<T>* aux = head;
        while (aux != nullptr) {
            count++;
            aux = aux->next;
        }
        return count;
    }

    T get(int index) {
        if (index < 0 || index >= size()) {
            throw std::out_of_range("Índice fuera de rango");
        }
        Node<T>* aux = head;
        for (int i = 0; i < index; i++) {
            aux = aux->next;
        }
        return aux->data;
    }

    class Iterator {
    private:
        Node<T>* current;
    public:
        Iterator(Node<T>* start) : current(start) {}

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

        T& operator*() {
            return current->data;
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};

#endif
