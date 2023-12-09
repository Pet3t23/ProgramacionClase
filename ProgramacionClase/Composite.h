#pr// Evita la inclusi�n m�ltiple del mismo archivo de encabezado
#pragma once

// Incluye el archivo de encabezado que contiene las dependencias necesarias
#include "Prerequisites.h"

// Clase abstracta para Component2
class Component2 {
public:
    virtual void operacion() = 0; // M�todo virtual puro para la operaci�n
};

// Clase hoja que hereda de Component2
class Leaf : public Component2 {
    void operacion() override {
        cout << "Operacion en hoja" << endl; // Implementaci�n de la operaci�n en la hoja
    }
};

// Clase composite que hereda de Component2
class Composite : public Component2 {
public:
    void operacion() override {
        cout << "Operacion en composite. Contiene: "
            << m_leafs.size() << " leafs." << endl; // Implementaci�n de la operaci�n en el composite

        for (auto hoja : m_leafs) {
            hoja->operacion(); // Llama a la operaci�n en cada hoja contenida en el composite
        }
    }

    void addLeaf(Component2* _leaf) {
        m_leafs.push_back(_leaf); // Agrega una hoja al composite
    }

private:
    vector<Component2*> m_leafs; // Almacena las hojas contenidas en el composite
};