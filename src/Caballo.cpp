#include "Caballo.h"
#include <iostream>

Caballo::Caballo(Coordenada posicion_, int color_, int casilla_)
{
	conf_modo();

	if (modo == 1)
		sprite2.setSize(0.25, 0.25);
	if (modo == 2)
		sprite2_1.setSize(0.25, 0.25);

	if (modo == 1)
		sprite8.setSize(0.25, 0.25);
	if (modo == 2)
		sprite8_1.setSize(0.25, 0.25);

	posicion.x = posicion_.x;
	posicion.y = posicion_.y;
	color = color_;
	casilla = casilla_;
	tipo = 2;
}

Caballo::~Caballo()
{

}

void Caballo::dibuja() {

	if (color == 0) {

		if (modo == 1)
			sprite2.setCenter((float)posicion.x, (float)posicion.y);
		if (modo == 2)
			sprite2_1.setCenter((float)posicion.x, (float)posicion.y);

		glPushMatrix();

		if (modo == 1)
			sprite2.draw();
		if (modo == 2)
			sprite2_1.draw();

		glPopMatrix();
	}
	if (color == 1) {

		if (modo == 1)
			sprite8.setCenter((float)posicion.x, (float)posicion.y);
		if (modo == 2)
			sprite8_1.setCenter((float)posicion.x, (float)posicion.y);

		glPushMatrix();

		if (modo == 1)
			sprite8.draw();
		if (modo == 2)
			sprite8_1.draw();

		glPopMatrix();
	}
}

void Caballo::movimientovalido(int origen, int destino, bool& b) {
	int dif = destino - origen;
	if (((dif%10==0)||(dif%17==0)||(dif%15==0)||(dif%6==0))&&(dif<18)&&(dif>-18)) {
		 b = TRUE;
		ETSIDI::play("sonidos/mov.wav");
	}
	else {
		b = FALSE;
	}
}
