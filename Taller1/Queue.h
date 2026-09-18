#pragma once
#include <string>
#include <iostream>
#include "NodoPorPaciente.h"
using namespace std;
template <typename T>

class Queue {
    private:
        NodoPorPaciente<T>* inicio;
        NodoPorPaciente<T>* final;
        int contador;
    public:
        Queue() {
            this->inicio = nullptr;
            this->final = nullptr;
            this->contador = 0;
        }

        bool isEmpty() {
            bool verificador = False;
            if (this-> inicio == nullptr) {
                    verificador = True;
            }
            return verificador;
        }

        void push(T paciente) {
            NodoPorPaciente<T>* nuevoPaciente = new NodoPorPaciente<T>(paciente)

            if (isEmpty()) {
                this->inicio = nuevoPaciente;
                this->final = nuevoPaciente;
            } else {
                this->final->setNext(nuevoPaciente);
                this->final = nuevoPaciente;
            }
            contador++;
        } 

        void pop() {
            if (isEmpty()) {
                cout << "La fila está vacía";
                return;
            }

            NodoPorPaciente<T>* datoInicial = this-> inicio;
            siguiente = datoInicial->getNext;

            if (siguiente==nullptr) {
                this-> final = nullptr;
            }

            delete datoInicial;
            this-> contador--;
        }

        T front() {
            return this->inicio->getPaciente();
        }

        int size() {
            return this-> contador;
        }

        void clear() {
            while (!isEmpty) {
                this->pop();
            }
        }

        ~Queue() {}

};
