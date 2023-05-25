#pragma once
#include "Coordenada.h"
#include "ETSIDI.h"
#include "Selector.h"
#include "ListaPiezas.h"

using ETSIDI::SpriteSequence;

class Punto
{
	SpriteSequence sprite_punto{ "imagenes/Punto.png",5 };
public:
	Punto();
	void dibuja_punto(Coordenada coordenada);
	void setCoord();
	Coordenada getCoord(int casilla);
	Coordenada coordPunto[64];
	void mover_punto(Selector selector, ListaPiezas& piezas);
	friend class Tablero;
};