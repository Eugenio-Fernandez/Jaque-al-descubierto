#include "Peon.h"
#include<iostream>

Peon::Peon(Coordenada posicion_, int color_, int casilla_)
{
	sprite3.setSize(0.25, 0.25);
	sprite9.setSize(0.25, 0.25);
	posicion.x = posicion_.x;
	posicion.y = posicion_.y;
	color = color_;
	casilla = casilla_;
}

Peon::~Peon()
{

}

void Peon::dibuja() {
	
	if (color == 0) {
		sprite3.setCenter((float)posicion.x, (float)posicion.y);
		glPushMatrix();
		sprite3.draw();
		glPopMatrix();
	}
	if (color == 1) {
		sprite9.setCenter((float)posicion.x, (float)posicion.y);
		glPushMatrix();
		sprite9.draw();
		glPopMatrix();
	}
}

void Peon::movimientovalido(int origen, int destino, bool& b) {
	int dif = destino - origen;
	std::cout << origen << endl;
	std::cout << dif << endl;

	if (
		(dif % 8 == 0) && ((dif < 10) && (dif > -10)) && (((dif > 0) && (color == 0)) || ((dif < 0) && (color == 1)))
		||
		((dif % 16 == 0) && ((origen >= 8) && (origen <= 15)) || ((origen >= 48) && (origen <= 55)))
		) {
		b = TRUE;
	}
	else {
		b = FALSE;

	}
}
