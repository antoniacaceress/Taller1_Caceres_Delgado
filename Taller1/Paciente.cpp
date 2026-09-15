#include "Paciente.h"
#include <string>
using namespace std;

Paciente::Paciente(std::string id, std::string nombre, int edad, std::string servicio) : Persona(nombre, edad) {
    this->ID = id;
    this->Servicio = servicio;
}

Paciente::~Paciente() {}

std::string Paciente:: getId() {
    return this->ID;
}

std::string Paciente:: getServicio() {
    return this->Servicio;
}