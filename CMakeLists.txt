cmake_minimum_required(VERSION 3.10)
project(Taller1_Caceres_Delgado)

set(CMAKE_CXX_STANDARD 14)

include_directories(Taller1)

configure_file(Prueba.txt Prueba.txt COPYONLY)

add_executable(Taller1_Caceres_Delgado
        Taller1/Atencion.cpp
        Taller1/Atencion.h
        Taller1/Hospital.cpp
        Taller1/Hospital.h
        Taller1/ListaPrincipal.h
        Taller1/main.cpp
        Taller1/NodoPorPaciente.h
        Taller1/Paciente.cpp
        Taller1/Paciente.h
        Taller1/Persona.cpp
        Taller1/Persona.h
        Taller1/Queue.h
        Taller1/Servicio.cpp
        Taller1/Servicio.h
        Taller1/Stack.h
        Prueba.txt)
