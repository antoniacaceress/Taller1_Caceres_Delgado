#include "Hospital.h"

Hospital::Hospital() {
    std::string nombres[8] = {
        "Urgencias", "Medicina General", "Cardiologia", "Neurologia",
        "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"
    };

    for (int i = 0; i < 8; i++) {
        this->servicios.insertLast(new Servicio(nombres[i]));
    }
}

Hospital::~Hospital() {
    while (!this->servicios.isEmpty()) {
        delete this->servicios.getFirst();
        this->servicios.remove(0);
    }

    while (!this->pendientes.isEmpty()) {
        delete this->pendientes.front();
        this->pendientes.pop();
    }
}

Servicio* Hospital::buscarServicio(std::string nombre) {
    int total = this->servicios.size();

    for (int i = 0; i < total; i++) {
        Servicio* actual = this->servicios.get(i);
        if (actual->getNombreServicio() == nombre) {
            return actual;
        }
    }
    return nullptr;
}
