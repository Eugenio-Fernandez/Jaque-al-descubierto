#pragma once
#include "Pieza.h"
class ListaPiezas
{
	int numero;
	Pieza* lista[32];

public:
	ListaPiezas();
	virtual ~ListaPiezas();

	void dibuja();
	void eliminar(Pieza* p);
	void eliminar(int index);
	int getNumeropiezas() { return numero; }
	void eliminarContenido();

};