#pragma once
// Evita la inclusi�n m�ltiple del mismo archivo de encabezado
// El uso de #pragma once es suficiente para evitar la inclusi�n m�ltiple, no es necesario repetirlo.

// Incluye el archivo de encabezado que contiene las dependencias necesarias
#include "Prerequisites.h"

// Clase para el producto B que se va a construir
class BProduct {
public:
	// Agrega una parte al producto
	void agregarParte(const string& _parte) {
		m_partes.push_back(_parte);
	}

	// Imprime las partes del producto
	void print() {
		cout << "Partes del producto: ";
		for (int i = 0; i < m_partes.size(); ++i) {
			cout << m_partes[i] << " ";
		}
		cout << endl; // Agregado para imprimir un salto de l�nea al final
	}

private:
	vector<string> m_partes; // Almacena las partes del producto
};

// Clase abstracta para el Builder
class Builder {
public:
	// M�todo virtual puro para construir parte A
	virtual void buildParteA() = 0;

	// M�todo virtual puro para construir parte B
	virtual void buildParteB() = 0;

	// M�todo virtual puro para obtener el producto final
	virtual BProduct* obtenerProducto() = 0;
};

// Clase concreta para el Builder
class BuilderConcreto : public Builder {
public:
	BuilderConcreto() {
		m_producto = new BProduct(); // Inicializa el producto en el constructor
	}

	// Implementaci�n de la construcci�n de parte A
	void buildParteA() override {
		m_producto->agregarParte("Parte A");
	}

	// Implementaci�n de la construcci�n de parte B
	void buildParteB() override {
		m_producto->agregarParte("Parte B");
	}

	// Implementaci�n para obtener el producto final
	BProduct* obtenerProducto() override {
		return m_producto;
	}

private:
	BProduct* m_producto; // Almacena el producto en construcci�n
};

// Clase Director que coordina la construcci�n del producto a trav�s del Builder
class Director {
public:
	// Constructor que toma un puntero al Builder
	Director(Builder* _builder) : m_builder(_builder) { }

	// M�todo que inicia la construcci�n del producto utilizando el Builder
	void build() {
		m_builder->buildParteA();
		m_builder->buildParteB();
	}

private:
	Builder* m_builder; // Almacena el Builder utilizado para la construcci�n
};
