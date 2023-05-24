#include "Caballo.h"
#include <iostream>

Caballo::Caballo(Coordenada posicion_, int color_, int casilla_)
{
	sprite2.setSize(0.25, 0.25);
	sprite8.setSize(0.25, 0.25);
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
		sprite2.setCenter((float)posicion.x, (float)posicion.y);
		glPushMatrix();
		sprite2.draw();
		glPopMatrix();
	}
	if (color == 1) {
		sprite8.setCenter((float)posicion.x, (float)posicion.y);
		glPushMatrix();
		sprite8.draw();
		glPopMatrix();
	}
}

void Caballo::movimientovalido(int origen, int destino, bool& b) {
	int dif = destino - origen;
	if (((dif%10==0)||(dif%17==0)||(dif%15==0)||(dif%6==0))&&(dif<18)&&(dif>-18)) {
		 b = TRUE;
	}
	else {
		b = FALSE;
	}
}