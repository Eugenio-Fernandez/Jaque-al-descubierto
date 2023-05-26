#pragma once
#include "Torre.h"

Torre::Torre(Coordenada posicion_, int color_, int casilla_)
{
	conf_modo();

	if (modo == 1)
		sprite6.setSize(0.25, 0.25);
	if (modo == 2)
		sprite6_1.setSize(1.0, 1.0);

	if (modo == 1)
		sprite12.setSize(0.25, 0.25);
	if (modo == 2)
		sprite12_1.setSize(1.0, 1.0);

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

		if (modo == 1)
			sprite6.setCenter((float)posicion.x, (float)posicion.y);
		if (modo == 2)
			sprite6_1.setCenter((float)posicion.x + 0.3775, (float)posicion.y + 0.3775);

		glPushMatrix();

		if (modo == 1)
			sprite6.draw();
		if (modo == 2)
			sprite6_1.draw();

		glPopMatrix();
	}
	if (color == 1) {

		if (modo == 1)
			sprite12.setCenter((float)posicion.x, (float)posicion.y);
		if (modo == 2)
			sprite12_1.setCenter((float)posicion.x + 0.3775, (float)posicion.y + 0.3775);

		glPushMatrix();

		if (modo == 1)
			sprite12.draw();
		if (modo == 2)
			sprite12_1.draw();

		glPopMatrix();
	}
}

void Torre::movimientovalido(int origen, int destino, bool& b) {
	int dif = destino - origen;
	if ((dif % 8 == 0)||((dif > -8) && (dif < 8) && ((((7 - origen % 8) >= dif) && (dif > 0)) || (((origen % 8) >= -dif) && (dif < 0))))) {
		b = TRUE;
		ETSIDI::play("sonidos/mov.wav");
	}
	else {
		b= FALSE;
	}
}
