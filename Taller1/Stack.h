#pragma once
#include <iostream>
#include "NodoPorPaciente.h"
template <typename T>

class Stack {
    private:
        NodoPorPaciente<T>* principio;
        int contador;
    public:
        Stack() {
            this->principio = nullptr;
            this->contador = 0;
        }

        ~Stack() {
            this->clear();
        }

        bool isEmpty() {
            return this->principio == nullptr;
        }

        void push(T valor) {
            NodoPorPaciente<T>* nuevo = new NodoPorPaciente<T>(valor);
            nuevo->setNext(this->principio);
            this->principio = nuevo;
            this->contador++;
        }

        void pop() {
            if (this->isEmpty()) return;

            NodoPorPaciente<T>* toDel = this->principio;
            this->principio = this->principio->getNext();
            delete toDel;
            this->contador--;
        }

        T top() {
            if (this->isEmpty()) throw 0;
            return this->principio->getPaciente();
        }

        void clear() {
            while (!this->isEmpty()) {
                this->pop();
            }
        }

        int size() {
            return this->contador;
        }
};