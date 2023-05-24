#pragma once
#include "Coordenada.h"

class Selector
{
private:
	int fila, columna, casilla_anterior;
public:
	Selector();
	void inicializa();
	void mover(unsigned char key);
	int getFila();
	int getColumna();
	int getCasilla() { return casilla_anterior; }
	void setOrigen();
	void mover_con_raton(int x, int y);
	int getCasilla_actual();

};

