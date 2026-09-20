#include "Hospital.h"
#include <iostream>
#include <fstream>

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

bool Hospital::existeId(std::string id) {
    int totalServicios = this->servicios.size();
    for (int i = 0; i < totalServicios; i++) {
        if (this->servicios.get(i)->buscarPaciente(id) != nullptr) {
            return true;
        }
    }

    // La cola no se puede recorrer, asi que se saca cada paciente y se vuelve a
    // meter al final. Al terminar la vuelta completa queda en el mismo orden.
    bool encontrado = false;
    int totalPendientes = this->pendientes.size();
    for (int i = 0; i < totalPendientes; i++) {
        Paciente* p = this->pendientes.front();
        this->pendientes.pop();
        if (p->getId() == id) {
            encontrado = true;
        }
        this->pendientes.push(p);
    }
    return encontrado;
}

bool Hospital::separarLinea(std::string linea, std::string campos[4]) {
    const char* p = linea.c_str();
    const char* inicioCampo = p;
    int cantidad = 0;

    while (true) {
        if (*p == ';' || *p == '\0') {
            if (cantidad == 4) {
                return false;
            }
            campos[cantidad] = std::string(inicioCampo, p - inicioCampo);
            cantidad++;
            if (*p == '\0') {
                break;
            }
            inicioCampo = p + 1;
        }
        p++;
    }
    return cantidad == 4;
}

bool Hospital::esNumero(std::string texto) {
    if (texto.empty() || texto.size() > 3) {
        return false;
    }
    int largo = texto.size();
    for (int i = 0; i < largo; i++) {
        if (texto[i] < '0' || texto[i] > '9') {
            return false;
        }
    }
    return true;
}

bool Hospital::cargarPacientes(std::string ruta) {
    std::ifstream archivo(ruta.c_str());
    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo " << ruta << std::endl;
        return false;
    }

    std::string linea;
    int numeroLinea = 0;
    int cargados = 0;
    int ignoradas = 0;

    while (std::getline(archivo, linea)) {
        numeroLinea++;

        if (!linea.empty() && linea[linea.size() - 1] == '\r') {
            linea.erase(linea.size() - 1);
        }
        if (linea.empty()) {
            continue;
        }

        std::string campos[4];
        if (!this->separarLinea(linea, campos)) {
            std::cout << "Error en la linea " << numeroLinea << ": formato incorrecto" << std::endl;
            ignoradas++;
            continue;
        }

        std::string id = campos[0];
        std::string nombre = campos[1];
        std::string servicio = campos[3];

        if (id.empty() || nombre.empty()) {
            std::cout << "Error en la linea " << numeroLinea << ": falta el ID o el nombre" << std::endl;
            ignoradas++;
            continue;
        }
        int edad = -1;
        if (this->esNumero(campos[2])) {
            edad = std::stoi(campos[2]);
        }
        if (edad < 0 || edad > 120) {
            std::cout << "Error en la linea " << numeroLinea << ": edad incorrecta" << std::endl;
            ignoradas++;
            continue;
        }
        if (this->buscarServicio(servicio) == nullptr) {
            std::cout << "Error en la linea " << numeroLinea << ": el servicio " << servicio << " no existe" << std::endl;
            ignoradas++;
            continue;
        }
        if (this->existeId(id)) {
            std::cout << "Error en la linea " << numeroLinea << ": el ID " << id << " ya existe" << std::endl;
            ignoradas++;
            continue;
        }

        this->pendientes.push(new Paciente(id, nombre, edad, servicio));
        cargados++;
    }
    archivo.close();

    std::cout << "Se cargaron " << cargados << " pacientes" << std::endl;
    std::cout << "Lineas con error: " << ignoradas << std::endl;
    return true;
}
