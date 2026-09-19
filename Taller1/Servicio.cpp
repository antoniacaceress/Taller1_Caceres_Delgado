#include "Servicio.h"
#include <iostream>

Servicio::Servicio(std::string nombreServ) {
    this->nombreServicio = nombreServ;
}

Servicio::~Servicio() {
    while (!this->listaPacientes.isEmpty()) {
        Paciente* p = this->listaPacientes.getFirst();
        delete p;
        this->listaPacientes.remove(0);
    }
}

std::string Servicio::getNombreServicio() {
    return this->nombreServicio;
}

void Servicio::agregarPaciente(Paciente* paciente) {
    this->listaPacientes.insertLast(paciente);
}