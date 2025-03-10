#ifndef TEST_H
#define TEST_H

#include <iostream>
#include "MyStack.h"

class Test {
public:
    static void run() {
        std::cout << "Iniciando pruebas de MyStack..." << std::endl;

        MyStack<int> stack;

        std::cout << "¿La pila está vacía? " << (stack.isEmpty() ? "Sí" : "No") << std::endl;

        std::cout << "Insertando elementos en la pila: 10, 20, 30" << std::endl;
        stack.push(10);
        stack.push(20);
        stack.push(30);

        std::cout << "Tamaño de la pila: " << stack.size() << std::endl;
        std::cout << "Elemento en la cima: " << stack.peek() << std::endl;

        std::cout << "Extrayendo elementos..." << std::endl;
        std::cout << "Elemento eliminado: " << stack.pop() << std::endl;
        std::cout << "Elemento eliminado: " << stack.pop() << std::endl;

        std::cout << "Elemento en la cima después de extracciones: " << stack.peek() << std::endl;
        std::cout << "Tamaño de la pila ahora: " << stack.size() << std::endl;

        std::cout << "¿La pila está vacía? " << (stack.isEmpty() ? "Sí" : "No") << std::endl;

        std::cout << "Prueba completada." << std::endl;
    }
};

#endif
