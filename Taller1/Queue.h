#pragma once
#include <string>
#include <iostream>
#include "NodoPorPaciente.h"
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
            bool verificador = false;
            if (this-> inicio == nullptr) {
                    verificador = true;
            }
            return verificador;
        }

        void push(T paciente) {
            NodoPorPaciente<T>* nuevoPaciente = new NodoPorPaciente<T>(paciente);

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
                std::cout << "La fila está vacía";
                return;
            }

            NodoPorPaciente<T>* datoInicial = this-> inicio;
            NodoPorPaciente<T>* siguiente = datoInicial->getNext();
            this->inicio = siguiente;

            if (siguiente==nullptr) {
                this-> final = nullptr;
            }

            delete datoInicial;
            this-> contador--;
        }

        T front() {
            if (isEmpty()) throw 0;
            return this->inicio->getPaciente();
        }

        int size() {
            return this-> contador;
        }

        void clear() {
            while (!this->isEmpty()) {
                this->pop();
            }
        }

        ~Queue() {
            this->clear();
        }

};
