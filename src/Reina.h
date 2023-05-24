#pragma once
#include "Pieza.h"
class Reina:public Pieza
{
public:
	Reina(Coordenada posicion_, int color_, int casilla_);
	~Reina();
	void dibuja();
	int getColor() { return color; }
	void movimientovalido(int origen, int destino, bool& b);
};

