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

    public:
        Hospital();
        ~Hospital();

        Servicio* buscarServicio(std::string nombre);
};
