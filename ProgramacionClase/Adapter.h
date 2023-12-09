// Evita la inclusi�n m�ltiple del mismo archivo de encabezado
#pragma once

// Incluye el archivo de encabezado que contiene las dependencias necesarias
#include "Prerequisites.h"

// Clase de interfaz vieja (deprecada)
class InterfazVieja {
public:
    // M�todo de interfaz vieja
    virtual void OldMethod() {
        // Imprime un mensaje indicando que el m�todo viejo ha sido llamado
        cout << "Metodo viejo llamado." << endl;
    }
};

// Clase de interfaz nueva (objetivo)
class InterfazNueva {
public:
    // M�todo de interfaz nueva
    virtual void NewMethod() {
        // Imprime un mensaje indicando que el m�todo nuevo ha sido llamado
        cout << "Metodo nuevo llamado." << endl;
    }
};

// Clase de adaptador que hereda de la interfaz nueva
class Adapter : public InterfazNueva {
public:
    // Constructor que recibe un puntero a la interfaz vieja
    Adapter(InterfazVieja* _vieja) : m_interfazVieja(_vieja) {}

    // Implementaci�n del m�todo de la interfaz nueva
    void NewMethod() override {
        // Imprime un mensaje indicando que el adaptador ha llamado al m�todo nuevo
        cout << "Adaptador llamado al metodo nuevo." << endl;
        // Llama al m�todo de la interfaz vieja dentro del adaptador
        m_interfazVieja->OldMethod();
    }

private:
    InterfazVieja* m_interfazVieja; // Puntero a la interfaz vieja
};
