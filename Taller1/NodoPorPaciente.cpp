#include "NodoPorPaciente.h"
#include <string>
using namespace std;

NodoPorPaciente::NodoPorPaciente(Paciente* siguientePaciente) {
    this-> pacienteActual = siguientePaciente;
    this-> next = nullptr;
}

Paciente* NodoPorPaciente::getPaciente() {
    return this-> pacienteActual;
}

NodoPorPaciente* NodoPorPaciente::getNext() {
    return this-> next;
}

void NodoPorPaciente::setPaciente(Paciente* paciente) {
    this-> pacienteActual = paciente;
}

void NodoPorPaciente::setNext(NodoPorPaciente* nextPaciente) {
    this-> next = nextPaciente;
}

NodoPorPaciente::~NodoPorPaciente() {}


