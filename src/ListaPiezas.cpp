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


Pieza ListaPiezas::getPieza(int index){
	return *lista[index];
}

Pieza* ListaPiezas::getPiezap(int index) {
	return lista[index];
}

void ListaPiezas::eliminar(int index){
	if ((index < 0) || (index >= n))
		return;
	delete lista[index];
	n--;
	for (int i = index; i < n; i++)
		lista[i] = lista[i + 1];
}



void ListaPiezas::eliminarContenido() {
	for (int i = 0; i < MAX_PIEZAS; i++) //eliminacion de las piezas
		lista[i] = 0;
	n = 0;
}