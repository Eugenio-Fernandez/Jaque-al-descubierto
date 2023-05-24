#pragma once
#include "Pieza.h"

class Alfil :public Pieza
{
public:
	Alfil(Coordenada posicion_, int color_, int casilla_);
	~Alfil();
	void dibuja();
	int getColor() { return color; }
	void movimientovalido(int origen, int destino, bool &b);
};

