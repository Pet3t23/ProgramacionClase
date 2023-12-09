// Evita la inclusi�n m�ltiple del mismo archivo de encabezado
#pragma once

// Incluye el archivo de encabezado que contiene las dependencias necesarias
#include "Prerequisites.h"

// Interfaz base - Componente
class Component {
public:
	virtual void operacion() = 0; // M�todo virtual puro para la operaci�n del componente
};

// Clase concreta que implementa la interfaz Component
class ConcreteComponent : public Component {
public:
	void operacion() override {
		cout << "Operacion del Componente Concreto" << endl; // Implementaci�n de la operaci�n en el componente concreto
	}
};

// Decorador base
class Decorator : public Component {
public:
	Decorator(Component* _component) : m_component(_component) {} // Constructor que recibe un componente para decorar
	virtual void operacion() override {
		m_component->operacion(); // Llama a la operaci�n del componente que est� decorando
	}

private:
	Component* m_component; // Puntero al componente que se va a decorar
};

// Decorador concreto A
class ConcreteDecoratorA : public Decorator {
public:
	ConcreteDecoratorA(Component* _component) : Decorator(_component) {} // Constructor que recibe un componente para decorar
	void operacion() override {
		Decorator::operacion(); // Llama a la operaci�n del componente decorado por el decorador base
		cout << "Operacion del Decorador A" << endl; // Agrega funcionalidad espec�fica del decorador A
	}
};

// Otro decorador concreto B
class ConcreteDecoratorB : public Decorator {
public:
	ConcreteDecoratorB(Component* _component) : Decorator(_component) {} // Constructor que recibe un componente para decorar
	void operacion() override {
		Decorator::operacion(); // Llama a la operaci�n del componente decorado por el decorador base
		cout << "Operacion del Decorador B" << endl; // Agrega funcionalidad espec�fica del decorador B
	}
};