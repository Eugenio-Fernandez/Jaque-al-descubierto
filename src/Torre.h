#pragma once
#include "Pieza.h"

class Torre:public Pieza
{
public:
	Torre(Coordenada posicion_, int color_, int casilla_);
	~Torre();
	void dibuja();
	int getColor() { return color; }
	void movimientovalido(int origen, int destino, bool& b);
};

