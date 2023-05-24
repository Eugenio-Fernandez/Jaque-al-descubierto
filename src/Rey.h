#pragma once
#include "Pieza.h"
class Rey:public Pieza
{
public:
	Rey(Coordenada posicion_, int color_, int casilla_);
	~Rey();
	void dibuja();
	int getColor() { return color; }
	void movimientovalido(int origen, int destino, bool& b);
};

