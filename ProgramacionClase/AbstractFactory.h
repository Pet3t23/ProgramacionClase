// Evita la inclusi�n m�ltiple del mismo archivo de encabezado
#pragma once

// Incluye el archivo de encabezado que contiene las dependencias necesarias
#include "Prerequisites.h"

// Clase base para productos A
class ProductA {
public:
    virtual void operationA() = 0; // M�todo virtual puro para la operaci�n A
};

// Clase base para productos B
class ProductB {
public:
    virtual void operationB() = 0; // M�todo virtual puro para la operaci�n B
};

// Clase abstracta para la f�brica abstracta
class AbstractFactory {
public:
    // M�todo virtual puro para crear ProductoA
    virtual ProductA* crearProductoA() = 0;

    // M�todo virtual puro para crear ProductoB
    virtual ProductB* crearProductoB() = 0;
};

// Clase concreta para productos A
class ProductA1 : public ProductA {
public:
    void operationA() override {
        // Implementaci�n de la operaci�n A para ProductA1
        cout << "Operaci�n A en ProductoA1" << endl;
    }
};

// Clase concreta para productos B
class ProductB1 : public ProductB {
public:
    void operationB() override {
        // Implementaci�n de la operaci�n B para ProductB1
        cout << "Operaci�n B en ProductoB1" << endl;
    }
};

// Clase concreta para la f�brica abstracta
class ConcreteAbstractFactory : public AbstractFactory {
public:
    // Implementaci�n para crear ProductoA
    ProductA* crearProductoA() override {
        // Crear una instancia de ProductA1
        return new ProductA1();
    }

    // Implementaci�n para crear ProductoB
    ProductB* crearProductoB() override {
        // Crear una instancia de ProductB1
        return new ProductB1();
    }
};

