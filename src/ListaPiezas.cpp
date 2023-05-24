#include "ListaPiezas.h"

ListaPiezas::ListaPiezas()
{
	n = 0;
	for (int i = 0; i < MAX_PIEZAS; i++)
		lista[i] = 0;
}

//Funcion para agregar una nueva pieza a la lista (develve TRUE si hay espacio en la lista)
bool ListaPiezas::agregar(Pieza* t)
{
	if (n < MAX_PIEZAS) {
		lista[n++] = t;// último puesto sin rellenar
	}
	else
		return false; // capacidad máxima alcanzada
	return true;
}

//Funcion que nos permite dibujar las distintas piezas
void ListaPiezas::dibuja()
{
	for (int i = 0; i < n; i++) {
		lista[i]->dibuja();
	}

}
/*
void ListaPiezas::inicializa() {
	Coordenada pos = {0,0};
	Torre* aux = new Torre(pos);
	lista[0]->agregar(aux);
}*/

