#pragma once
#include<string>
#include "Persona.h"

class Paciente : public Persona {
    private:
        std::string ID;
        std::string Servicio;

    public:
        Paciente(std::string id, std::string nombre, int edad, std::string servicio);
        ~Paciente();
        std::string getId();
        std::string getServicio();
};

