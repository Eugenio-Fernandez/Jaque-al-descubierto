#pragma once
#include "Pieza.h"

class Caballo :public Pieza
{
public:
	Caballo(Coordenada posicion_, int color_, int casilla_);
	~Caballo();
	void dibuja();
	int getColor() { return color; }
	void movimientovalido(int origen, int destino, bool& b);
};

