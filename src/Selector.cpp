#include "Selector.h"
#include "freeglut.h"

//Constructor del selector
Selector::Selector() {
	fila = 4;
	columna = 4;
}

//Funcion para inicializar el selector
void Selector::inicializa() {
	Selector selector;
}

//Funcion para realizar el movimiento del selector por las casillas del tablero
void Selector::mover(unsigned char key) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		if (columna > 0)
			columna--;
		break;
	case GLUT_KEY_DOWN:
		if (fila > 0)
			fila--;
		break;
	case GLUT_KEY_RIGHT:
		if (columna < 7)
			columna++;
		break;
	case GLUT_KEY_UP:
		if (fila < 7)
			fila++;
		break;
	}
}

//Funcion que devuleve la fila
int Selector::getFila()
{
	return fila;
}

//Funcion que devuelve la columa
int Selector::getColumna()
{
	return columna;
}

//Funcion que devuelve el selector a su posicion incial



void Selector::setOrigen(){
	casilla_anterior = (fila ) * 8 + columna;
}

void Selector::mover_con_raton(int x, int y) {
	int x_raton, y_raton;
	int cambio_y=700-y;
	int aux_x, aux_y;
	aux_x = x % 90;
	aux_y = cambio_y % 90;

	x_raton = x - aux_x;
	y_raton = cambio_y - aux_y;

	fila = y_raton / 90;
	columna = x_raton / 90;
}

int Selector::getCasilla_actual(){
	return (fila) * 8 + columna;
}