#pragma once
#include "Atencion.h"
#include <iostream>

Atencion::Atencion(std::string nombre, int edadPaciente, std::string departamento) {
    this->nombrePaciente = nombrePaciente;
    this->edad = edadPaciente;
    this->departamento = departamento;
}

Atencion::~Atencion() {}

std::string Atencion::getNombrePaciente() {
    return this->nombrePaciente;
}

int Atencion::getEdadPaciente() {
    return this->edad;
}

std::string Atencion::getDepartamento() {
    return this->departamento;
}

