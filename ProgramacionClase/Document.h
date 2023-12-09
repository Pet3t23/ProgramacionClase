// Evita la inclusi�n m�ltiple del mismo archivo de encabezado
#pragma once

// Incluye el archivo de encabezado que contiene las dependencias necesarias
#include "Prerequisites.h"

// Interfaz base para el prototipo de documentos
class DocumentPrototype {
public:
	virtual DocumentPrototype* clone() = 0;               // M�todo para clonar el prototipo del documento
	virtual void configure(const string& _content) = 0;    // M�todo para configurar el contenido del documento
	virtual void print() = 0;                              // M�todo para imprimir informaci�n del documento
};

// Clase concreta que implementa la interfaz para documentos de texto
class TextDocument : public DocumentPrototype {
public:
	// M�todo para clonar el prototipo de documento de texto
	DocumentPrototype* clone() override {
		TextDocument* copy = new TextDocument();
		copy->configure(content);
		return copy;
	}

	// M�todo para configurar el contenido del documento de texto
	void configure(const string& _content) override {
		this->content = _content;
	}

	// M�todo para imprimir informaci�n del documento de texto
	void print() override {
		cout << "Text: " << content << endl;
	}

private:
	string content;  // Variable que almacena el contenido del documento de texto
};

// Clase concreta que implementa la interfaz para documentos de imagen
class ImageDocument : public DocumentPrototype {
public:
	// M�todo para clonar el prototipo de documento de imagen
	DocumentPrototype* clone() override {
		ImageDocument* copy = new ImageDocument();
		copy->configure(content);
		return copy;
	}

	// M�todo para configurar el contenido del documento de imagen
	void configure(const string& _content) override {
		this->content = _content;
	}

	// M�todo para imprimir informaci�n del documento de imagen
	void print() override {
		cout << "Image: " << content << endl;
	}

private:
	string content;  // Variable que almacena el contenido del documento de imagen
};