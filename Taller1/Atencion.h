#pragma once
#include <string>
using namespace std; 

class Atencion {

    private: 
        std::string nombrePaciente;
        int edad;
        std::string departamento;

    public:
        Atencion(std::string nombre, int edad, std::string depto);
        ~Atencion();

        std::string getNombrePaciente();
        int getEdadPaciente();
        std::string getDepartamento();
};