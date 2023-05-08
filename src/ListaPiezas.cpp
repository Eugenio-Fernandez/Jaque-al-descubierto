#include "ListaPiezas.h"
ListaPiezas::~ ListaPiezas()
{
}
ListaPiezas::ListaPiezas()
{
	numero = 0;
	for (int i = 0; i < 32; i++)
		lista[i] = 0;
}

void ListaPiezas::dibuja()
{
	for (int i = 0; i < numero; i++) {

		lista[i]->dibuja();
	}

}


void ListaPiezas::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

//Funcion que evalua si debe eliminar una pieza y llama a la funcion eliminar que las elimina
void ListaPiezas::eliminar(Pieza* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			ETSIDI::play("sonidos/impacto.wav");
			return;
		}
}

//Funcion para eliminar el contenido de las piezas
void ListaPiezas::eliminarContenido() {
	for (int i = 0; i < 32; i++) //eliminacion de las piezas
		lista[i] = 0;
	numero = 0;
}
