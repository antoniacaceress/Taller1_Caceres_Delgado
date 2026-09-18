#include <iostream>
#include <string>
using namespace std;


void menuPrincipal() {
    int opcion;
    while (opcion != 4) {
        cout<< "=== HOSPITAL MARMAJA ===" <<endl;
        cout<< "1. Atender pacientes" << endl;
        cout<< "2. Ver departamento" << endl;
        cout<< "3. Revisar historial de atencion" << endl;
        cout<< "4. Salir" << endl;
        cout<< "Seleccionar opcion: ";
        cin >> opcion;
    }


};

int main() {
    menuPrincipal();


}