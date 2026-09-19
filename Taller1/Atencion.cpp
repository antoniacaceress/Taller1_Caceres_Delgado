#include "Atencion.h"
#include <iostream>
using namespace std;

Atencion::Atencion(string nombre, int edad, string departamento) {
    this->nombrePaciente = nombre;
    this->edad = edad;
    this->departamento = departamento;
}

Atencion::~Atencion() {}

string Atencion::getNombrePaciente() {
    return this->nombrePaciente;
}

int Atencion::getEdadPaciente() {
    return this->edad;
}

string Atencion::getDepartamento() {
    return this->departamento;
}

void Atencion::mostrar() {
    cout << "Nombre: " << this->nombrePaciente
         << " | Edad: " << this->edad
         << " | Departamento: " << this->departamento << endl;
}

