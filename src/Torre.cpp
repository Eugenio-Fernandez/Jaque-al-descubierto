#pragma once
#include "Torre.h"

Torre::Torre(Coordenada posicion_, int color_, int casilla_)
{
	sprite6.setSize(0.25, 0.25);
	sprite12.setSize(0.25, 0.25);
	posicion.x = posicion_.x;
	posicion.y = posicion_.y;
	color = color_;
	casilla = casilla_;
	tipo = 6;
}

Torre::~Torre()
{

}

void Torre::dibuja() {
	if (color == 0) {
		sprite6.setCenter((float)posicion.x, (float)posicion.y);
		glPushMatrix();
		sprite6.draw();
		glPopMatrix();
	}
	if (color == 1) {
		sprite12.setCenter((float)posicion.x, (float)posicion.y);
		glPushMatrix();
		sprite12.draw();
		glPopMatrix();
	}
}

void Torre::movimientovalido(int origen, int destino, bool& b) {
	int dif = destino - origen;
	if ((dif % 8 == 0)||((dif > -8) && (dif < 8) && ((((7 - origen % 8) >= dif) && (dif > 0)) || (((origen % 8) >= -dif) && (dif < 0))))) {
		b = TRUE;
	}
	else {
		b= FALSE;
	}
}