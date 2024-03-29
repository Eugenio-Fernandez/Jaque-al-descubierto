#include "Reina.h"
#include<iostream>

Reina::Reina(Coordenada posicion_, int color_, int casilla_)
{

	conf_modo();

	if (modo == 1)
		sprite4.setSize(0.25, 0.25);
	if (modo == 2)
		sprite4_1.setSize(0.25, 0.25);

	if (modo == 1)
		sprite10.setSize(0.25, 0.25);
	if (modo == 2)
		sprite10_1.setSize(0.25, 0.25);

	posicion.x = posicion_.x;
	posicion.y = posicion_.y;
	color = color_;
	casilla = casilla_;
	tipo = 3;
}

Reina::~Reina()
{

}

void Reina::dibuja() {
	if (color == 0) {

		if (modo == 1)
			sprite4.setCenter((float)posicion.x, (float)posicion.y);
		if (modo == 2)
			sprite4_1.setCenter((float)posicion.x, (float)posicion.y);

		glPushMatrix();

		if (modo == 1)
			sprite4.draw();
		if (modo == 2)
			sprite4_1.draw();

		glPopMatrix();
	}
	if (color == 1) {

		if (modo == 1)
			sprite10.setCenter((float)posicion.x, (float)posicion.y);
		if (modo == 2)
			sprite10_1.setCenter((float)posicion.x, (float)posicion.y);

		glPushMatrix();

		if (modo == 1)
			sprite10.draw();
		if (modo == 2)
			sprite10_1.draw();

		glPopMatrix();
	}
}
void Reina::movimientovalido(int origen, int destino, bool& b) {
	int dif = destino - origen;
	
	
	if (
		(dif%7==0)
		||
		(dif%8==0)
		||
		(dif%9==0)
		||
		((((dif > -8) && (dif < 8)) && ((((7 - origen % 8) >= dif) && (dif > 0)) || (((origen % 8) >= -dif) && (dif < 0)))))
		) {
		b= TRUE;
		ETSIDI::play("sonidos/mov.wav");
	}
	else {
		b= FALSE;
	}
}

