#pragma once
// Evita la inclusi�n m�ltiple del mismo archivo de encabezado
#pragma once

// Incluye el archivo de encabezado que contiene las dependencias necesarias
#include "Prerequisites.h"

// Clase que representa un c�rculo
class Circle {
public:
	// M�todo para dibujar un c�rculo
	void drawCircle() {
		cout << "   *   \n";
		cout << " *   * \n";
		cout << "*     *\n";
		cout << " *   * \n";
		cout << "   *   \n";
	}
};

// Clase que representa un cuadrado
class Square {
public:
	// M�todo para dibujar un cuadrado
	void drawSquare() {
		cout << "* * * * *\n";
		cout << "*       *\n";
		cout << "*       *\n";
		cout << "*       *\n";
		cout << "* * * * *\n";
	}
};

// Interfaz Drawable que define el m�todo de dibujo
class Drawable {
public:
	virtual void draw() {
		cout << "Drawable called." << endl;
	}
};

// Adaptador para dibujar un c�rculo usando la interfaz Drawable
class CircleAdapter : public Drawable {
public:
	// Constructor que recibe un c�rculo para adaptar
	CircleAdapter(Circle* _circle) : m_circle(_circle) {}

	// Implementaci�n del m�todo de dibujo utilizando el c�rculo
	void draw() override {
		m_circle->drawCircle();
	}

private:
	Circle* m_circle; // Puntero al c�rculo que se va a adaptar
};

// Adaptador para dibujar un cuadrado usando la interfaz Drawable
class SquareAdapter : public Drawable {
public:
	// Constructor que recibe un cuadrado para adaptar
	SquareAdapter(Square* _square) : m_square(_square) {}

	// Implementaci�n del m�todo de dibujo utilizando el cuadrado
	void draw() override {
		m_square->drawSquare();
	}

private:
	Square* m_square; // Puntero al cuadrado que se va a adaptar
};