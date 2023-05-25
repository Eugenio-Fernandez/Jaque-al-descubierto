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
	//bool getPeon_movido() { return peon_movido; }
	//void setPeon_movido() { peon_movido = TRUE; }
	//void setPieza_enemiga(bool pieza_enemiga_) { pieza_enemiga = pieza_enemiga_; }

};

