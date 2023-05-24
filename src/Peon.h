#pragma once
#include "Pieza.h"

class Peon:public Pieza
{
public:
	Peon(Coordenada posicion_, int color_, int casilla_);
	~Peon();
	void dibuja();
	
	int getColor() { return color; }
	void movimientovalido(int origen, int destino, bool& b);
};

