#include "Paciente.h"
#include <string>
using namespace std;

Paciente::Paciente(string id, string nombre, int edad, string servicio) : Persona(nombre, edad) {
    this->ID = id;
    this->Servicio = servicio;
}

Paciente::~Paciente() {}

string Paciente:: getId() {
    return this->ID;
}

string Paciente:: getServicio() {
    return this->Servicio;
}