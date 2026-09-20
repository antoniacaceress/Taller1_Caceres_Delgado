#pragma once
#include <string>
#include "ListaPrincipal.h"
#include "Queue.h"
#include "Stack.h"
#include "Paciente.h"
#include "Servicio.h"
#include "Atencion.h"

class Hospital {
    private:
        ListaPrincipal<Servicio*> servicios;
        Queue<Paciente*> pendientes;
        Stack<Atencion> historial;

        bool separarLinea(std::string linea, std::string campos[4]);
        bool esNumero(std::string texto);

    public:
        Hospital();
        ~Hospital();

        Servicio* buscarServicio(std::string nombre);
        bool existeId(std::string id);
        bool cargarPacientes(std::string ruta);
};
