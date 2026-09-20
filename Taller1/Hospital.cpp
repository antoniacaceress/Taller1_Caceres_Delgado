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

void Hospital::mostrarDatos(Paciente* paciente) {
    std::cout << "ID: " << paciente->getId() << std::endl;
    std::cout << "Nombre: " << paciente->getNombre() << std::endl;
    std::cout << "Edad: " << paciente->getEdad() << std::endl;
    std::cout << "Servicio: " << paciente->getServicio() << std::endl;
}

int Hospital::cantidadPendientes() {
    return this->pendientes.size();
}

void Hospital::mostrarPendientes() {
    std::cout << "=== PACIENTES EN ESPERA ===" << std::endl;
    if (this->pendientes.isEmpty()) {
        std::cout << "No hay pacientes en espera" << std::endl;
        return;
    }

    int total = this->pendientes.size();
    for (int i = 0; i < total; i++) {
        Paciente* p = this->pendientes.front();
        this->pendientes.pop();
        std::cout << (i + 1) << ". " << p->getId() << " - " << p->getNombre() << std::endl;
        this->pendientes.push(p);
    }
}

void Hospital::atenderPacientes(int cantidad) {
    if (this->pendientes.isEmpty()) {
        std::cout << "No hay pacientes en espera" << std::endl;
        return;
    }
    if (cantidad <= 0) {
        std::cout << "La cantidad debe ser mayor a 0" << std::endl;
        return;
    }
    if (cantidad > this->pendientes.size()) {
        std::cout << "Solo hay " << this->pendientes.size() << " pacientes en espera, se atenderan todos" << std::endl;
        cantidad = this->pendientes.size();
    }

    std::cout << "=== ATENDIENDO PACIENTES ===" << std::endl;
    for (int i = 0; i < cantidad; i++) {
        Paciente* p = this->pendientes.front();
        this->pendientes.pop();

        Servicio* servicio = this->buscarServicio(p->getServicio());
        servicio->agregarPaciente(p);
        this->historial.push(Atencion(p->getNombre(), p->getEdad(), p->getServicio()));

        this->mostrarDatos(p);
        std::cout << std::endl;
        std::cout << "Paciente enviado a " << servicio->getNombreServicio() << "." << std::endl;
        std::cout << std::endl;
    }
}

void Hospital::mostrarServicios() {
    std::cout << "=== DEPARTAMENTOS/SERVICIOS ===" << std::endl;
    int total = this->servicios.size();
    for (int i = 0; i < total; i++) {
        std::cout << (i + 1) << ". " << this->servicios.get(i)->getNombreServicio() << std::endl;
    }
}

void Hospital::mostrarDepartamento(int numero) {
    if (numero < 1 || numero > this->servicios.size()) {
        std::cout << "Opcion invalida" << std::endl;
        return;
    }

    Servicio* servicio = this->servicios.get(numero - 1);
    std::cout << "=== ESTADO " << servicio->getNombreServicio() << " ===" << std::endl;
    servicio->mostrarPacientes();
}

void Hospital::mostrarHistorial() {
    std::cout << "=== HISTORIAL DE ULTIMAS ATENCIONES DEL HOSPITAL ===" << std::endl;
    std::cout << std::endl;
    if (this->historial.isEmpty()) {
        std::cout << "Todavia no se ha atendido a nadie" << std::endl;
        return;
    }

    Stack<Atencion> auxiliar;
    while (!this->historial.isEmpty()) {
        Atencion atencion = this->historial.top();
        atencion.mostrar();
        auxiliar.push(atencion);
        this->historial.pop();
    }
    while (!auxiliar.isEmpty()) {
        this->historial.push(auxiliar.top());
        auxiliar.pop();
    }
}

void Hospital::buscarPaciente(std::string id) {
    int totalServicios = this->servicios.size();
    for (int i = 0; i < totalServicios; i++) {
        Servicio* servicio = this->servicios.get(i);
        Paciente* p = servicio->buscarPaciente(id);
        if (p != nullptr) {
            std::cout << "Paciente atendido, esta en " << servicio->getNombreServicio() << std::endl;
            this->mostrarDatos(p);
            return;
        }
    }

    Paciente* encontrado = nullptr;
    int totalPendientes = this->pendientes.size();
    for (int i = 0; i < totalPendientes; i++) {
        Paciente* p = this->pendientes.front();
        this->pendientes.pop();
        if (p->getId() == id) {
            encontrado = p;
        }
        this->pendientes.push(p);
    }

    if (encontrado != nullptr) {
        std::cout << "Paciente en espera de atencion" << std::endl;
        this->mostrarDatos(encontrado);
    } else {
        std::cout << "No se encontro ningun paciente con el ID " << id << std::endl;
    }
}
