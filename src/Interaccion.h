#pragma once
#include "Pieza.h"
#include "Tablero.h"


class Interaccion
{
	bool accion;
	int turno = 0;
public:
	Interaccion();
	~Interaccion(){}
	void mover_pieza(Selector selector, ListaPiezas &piezas);
	bool pieza_saltada(ListaPiezas& piezas, int origen, int destino);
	void setAccion();
	bool getAccion();
	bool jaque_a_enemigo(ListaPiezas& piezas, int origen, int destino, Pieza *p);
	bool jaque_propio(ListaPiezas& piezas, int origen, int destino, Pieza* p);

};

