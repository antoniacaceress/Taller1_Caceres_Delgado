#include <string>
#pragma once
using namespace std;

class Persona {
    private: 
        std::string Nombre;
        int Edad; 

    public:
        Persona(std::string nombre, int edad);
        virtual ~Persona();
        std::string getNombre();
        int getEdad();
        void setNombre(std::string nombre);
        void setEdad(int edad);

};