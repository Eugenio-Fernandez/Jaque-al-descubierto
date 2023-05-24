#pragma once
#include "Pieza.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Peon.h"
#include "Reina.h"
#include "Rey.h"
#include "Torre.h"

#define MAX_PIEZAS 32

class ListaPiezas
{
private:
	int n;
	Pieza* lista[MAX_PIEZAS];
public:
	ListaPiezas();
	bool agregar(Pieza* t);
	void dibuja();
	int getNum() { return n; }
	//void inicializa();
};

