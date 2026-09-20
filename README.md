# Taller 1 – Hospital Marmaja

Estructura de Datos · II Semestre 2026

Programa de consola en C++ para gestionar la llegada de pacientes a un hospital. Los pacientes
se leen desde un archivo de texto y entran a una cola. Al atenderlos, salen de la cola en el
mismo orden en que llegaron, se envían al servicio que les corresponde y cada atención queda
guardada en un historial.

La cola, las listas enlazadas (servicios y pacientes de cada servicio) y la pila del historial
están hechas a mano con nodos y punteros, sin usar contenedores de la STL.

## Integrantes

Antonia Cáceres, RUT 22.050.742-4, usuario de GitHub antoniacaceress, carrera ICCI.

Benjamin Delgado, RUT 22.223.703-3, usuario de GitHub zomvr2, carrera ICCI.

## Compilar

Hace falta un compilador con C++14. Desde la carpeta raíz del repositorio:

```
g++ -std=c++14 -Wall Taller1/main.cpp Taller1/Atencion.cpp Taller1/Hospital.cpp Taller1/Paciente.cpp Taller1/Persona.cpp Taller1/Servicio.cpp -o hospital
```

O con CMake:

```
cmake -S . -B build
cmake --build build
```

## Ejecutar

El programa lee los pacientes desde `Prueba.txt`, que debe estar en la carpeta desde la
que se ejecuta:

```
./hospital
```

Si se compiló con CMake el ejecutable queda en `build/` y `Prueba.txt` se copia ahí
automáticamente. En Windows termina en `.exe`.

## Archivo de entrada

Una línea por paciente, con los campos separados por `;`:

```
ID;Nombre;Edad;Servicio
```

Por ejemplo:

```
001;Juan Perez;25;Cardiologia
002;Maria Soto;67;Urgencias
003;Pedro Rojas;43;Cirugia
```

Las líneas con formato inválido, servicios que no existen o IDs repetidos se ignoran y se
informan por pantalla.
