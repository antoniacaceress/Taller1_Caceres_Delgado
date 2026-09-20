#include <iostream>
#include <string>
#include "Hospital.h"
using namespace std;

int leerNumero() {
    int numero;
    while (!(cin >> numero)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ingrese un numero valido: ";
    }
    return numero;
}

void menuPrincipal(Hospital& hospital) {
    int opcion = 0;
    while (opcion != 4) {
        cout << endl;
        cout << "=== HOSPITAL MARMAJA ===" << endl;
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver departamento" << endl;
        cout << "3. Revisar historial de atencion" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccionar opcion: ";
        opcion = leerNumero();
        cout << endl;

        if (opcion == 1) {
            hospital.mostrarPendientes();
            if (hospital.cantidadPendientes() > 0) {
                cout << endl;
                cout << "Indique la cantidad de pacientes a atender: ";
                int cantidad = leerNumero();
                cout << endl;
                hospital.atenderPacientes(cantidad);
            }
        } else if (opcion == 2) {
            hospital.mostrarServicios();
            cout << "9. Buscar paciente por ID" << endl;
            cout << endl;
            cout << "Seleccionar opcion: ";
            int numero = leerNumero();
            cout << endl;
            if (numero == 9) {
                string id;
                cout << "Ingrese el ID del paciente: ";
                cin >> id;
                cout << endl;
                hospital.buscarPaciente(id);
            } else {
                hospital.mostrarDepartamento(numero);
            }
        } else if (opcion == 3) {
            hospital.mostrarHistorial();
        } else if (opcion == 4) {
            cout << "Hasta luego :D." << endl;
        } else {
            cout << "Opcion invalida" << endl;
        }
    }
}

int main() {
    Hospital hospital;
    if (!hospital.cargarPacientes("Prueba.txt")) {
        return 1;
    }

    menuPrincipal(hospital);
    return 0;
}
