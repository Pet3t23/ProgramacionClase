// Evita la inclusi�n m�ltiple del mismo archivo de encabezado
#pragma once

// Incluye el archivo de encabezado que contiene las dependencias necesarias
#include "Prerequisites.h"

// Clase principal que representa una tienda de caf�
class CoffeeShop {
public:
    // M�todo virtual para preparar caf�
    virtual void prepareCoffee() {
        cout << "Coffee prepared" << endl;
    }
};

// Clase abstracta para los condimentos del caf�
class CoffeeCondiment {
public:
    // M�todo virtual puro para agregar condimento al caf�
    virtual void addCondiment() = 0;
};

// Clase concreta para la leche como condimento
class Milk : public CoffeeCondiment {
public:
    // Constructor que recibe una instancia de la tienda de caf�
    Milk(CoffeeShop* coffee) : m_coffee(coffee) {}

    // Implementaci�n del m�todo para agregar leche al caf�
    virtual void addCondiment() override {
        m_coffee->prepareCoffee(); // Llama al m�todo de preparaci�n de caf� en la tienda
        cout << "Milk added" << endl; // Agrega leche al caf�
    }

private:
    CoffeeShop* m_coffee; // Puntero a la tienda de caf�
};

// Clase concreta para el az�car como condimento
class Sugar : public CoffeeCondiment {
public:
    // Constructor que recibe una instancia de la tienda de caf�
    Sugar(CoffeeShop* coffee) : m_coffee(coffee) {}

    // Implementaci�n del m�todo para agregar az�car al caf�
    virtual void addCondiment() override {
        m_coffee->prepareCoffee(); // Llama al m�todo de preparaci�n de caf� en la tienda
        cout << "Sugar added" << endl; // Agrega az�car al caf�
    }

private:
    CoffeeShop* m_coffee; // Puntero a la tienda de caf�
};
