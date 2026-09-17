#include <string>
#include "Paciente.h"
using namespace std;

class NodoPorPaciente {
    private: 
        Paciente* pacienteActual;
        NodoPorPaciente* next;
    public:
        NodoPorPaciente(Paciente* siguientePaciente);

        Paciente* getPaciente();
        NodoPorPaciente* getNext();

        void setPaciente(Paciente* pacienteActual);
        void setNext(NodoPorPaciente* next);

        ~NodoPorPaciente();
};

