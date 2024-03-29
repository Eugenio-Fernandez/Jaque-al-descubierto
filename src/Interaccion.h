#pragma once
#include "Pieza.h"
#include "Tablero.h"


class Interaccion
{
	bool jaque_mate_partida=FALSE;
	bool accion;
	int turno = 0;
	bool jaque_negro = FALSE;
	bool jaque_blanco = FALSE;
	bool corona_peon=FALSE;
	int index_peon;
public:
	Interaccion();
	~Interaccion(){}
	void mover_pieza(Selector selector, ListaPiezas &piezas);
	bool pieza_saltada(ListaPiezas& piezas, int origen, int destino);
	void setAccion();
	bool getAccion();
	bool jaque_a_enemigo(ListaPiezas& piezas, int origen, int destino, Pieza *p);
	bool jaque_propio(ListaPiezas& piezas, int origen, int destino, Pieza* p, bool pieza_enemiga);
	void jaque_mate(ListaPiezas& piezas, bool color, bool enemiga);
	int getTurno() { return turno; }
	void corona(Selector selector, ListaPiezas& piezas, int index);
	void setCorona() { corona_peon = TRUE; }
	bool getCorona() { return corona_peon; }
	int getIndexpeon() { return index_peon; }

	bool getJaquenegro() { return jaque_negro; }
	bool getJaqueblanco() { return jaque_blanco; }
};

