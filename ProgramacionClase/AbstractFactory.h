// Evita la inclusión múltiple del mismo archivo de encabezado
#pragma once

// Incluye el archivo de encabezado que contiene las dependencias necesarias
#include "Prerequisites.h"

// Clase base para productos A
class ProductA {
public:
    virtual void operationA() = 0; // Método virtual puro para la operación A
};

// Clase base para productos B
class ProductB {
public:
    virtual void operationB() = 0; // Método virtual puro para la operación B
};

// Clase abstracta para la fábrica abstracta
class AbstractFactory {
public:
    // Método virtual puro para crear ProductoA
    virtual ProductA* crearProductoA() = 0;

    // Método virtual puro para crear ProductoB
    virtual ProductB* crearProductoB() = 0;
};

// Clase concreta para productos A
class ProductA1 : public ProductA {
public:
    void operationA() override {
        // Implementación de la operación A para ProductA1
        cout << "Operación A en ProductoA1" << endl;
    }
};

// Clase concreta para productos B
class ProductB1 : public ProductB {
public:
    void operationB() override {
        // Implementación de la operación B para ProductB1
        cout << "Operación B en ProductoB1" << endl;
    }
};

// Clase concreta para la fábrica abstracta
class ConcreteAbstractFactory : public AbstractFactory {
public:
    // Implementación para crear ProductoA
    ProductA* crearProductoA() override {
        // Crear una instancia de ProductA1
        return new ProductA1();
    }

    // Implementación para crear ProductoB
    ProductB* crearProductoB() override {
        // Crear una instancia de ProductB1
        return new ProductB1();
    }
};

