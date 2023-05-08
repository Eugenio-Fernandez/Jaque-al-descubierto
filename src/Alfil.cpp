#include "Alfil.h"
#include <math.h>

bool Alfil::mueve(struct jugada& movimiento)
{
	bool error;

	Casilla aux = movimiento.destino - movimiento.origen;
	
	if (abs(aux.x) == abs(aux.y))
		error = Pieza::mueve(movimiento);
	error = 0;
	return error;
}
Alfil::~Alfil()
{
}
