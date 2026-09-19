#pragma once
#include <string>

class Atencion {

    private: 
        std::string nombrePaciente;
        int edad;
        std::string departamento;

    public:
        Atencion(std::string nombre, int edad, std::string departamento);
        ~Atencion();

        std::string getNombrePaciente();
        int getEdadPaciente();
        std::string getDepartamento();
};