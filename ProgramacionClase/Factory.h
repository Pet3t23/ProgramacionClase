#pragma once
// Evita la inclusi�n m�ltiple del mismo archivo de encabezado
#pragma once

// Incluye el archivo de encabezado que contiene las dependencias necesarias
#include "Prerequisites.h"

// Clase encargada de ser el objeto base de los productos que se crear�n
class Product {
public:
    virtual void operacion() = 0; // M�todo virtual puro para la operaci�n del producto
};

// Clase que es el objeto base que sirve para crear las instancias de cada producto con la funci�n "crearProducto()"
class Factory {
public:
    virtual Product* crearProducto() = 0; // M�todo virtual puro para crear productos
};

// Clase usada para realizar operaciones tras recibir el producto
class ConcreteProduct : public Product {
public:
    void operacion() override {
        cout << "Ac� se realiza una operaci�n" << endl; // Implementaci�n de la operaci�n en el producto concreto
    }
};

//Clase usada para crear nuevos productos
class ConcreteFactory : public Factory {
public:
    Product* crearProducto() override {
        return new ConcreteProduct(); // Crea una instancia del producto concreto
    }
};

// ACTVIDAD FACTORY

class Vehiculo {
public:
    virtual void descripcion() {
        cout << "Hola, soy un veh�culo" << endl; // Descripci�n predeterminada para un veh�culo
    }
};

class ConcreteCoche : public Vehiculo {
public:
    void descripcion() override {
        cout << "Hola, soy un coche" << endl; // Descripci�n espec�fica para un coche
    }
};

class ConcreteBicicleta : public Vehiculo {
public:
    void descripcion() override {
        cout << "Hola, soy una bicicleta" << endl; // Descripci�n espec�fica para una bicicleta
    }
};

class FactoryVehiculos {
public:
    virtual Vehiculo* crearVehiculo() = 0; // M�todo virtual puro para crear veh�culos
};

class ConcreteFactoryCoche : public FactoryVehiculos {
public:
    Vehiculo* crearVehiculo() override {
        return new ConcreteCoche(); // Crea una instancia de un coche
    }
};

class ConcreteFactoryBicicleta : public FactoryVehiculos {
public:
    Vehiculo* crearVehiculo() override {
        return new ConcreteBicicleta(); // Crea una instancia de una bicicleta
    }
};