#include "Alfil.h"

Alfil::Alfil(Coordenada posicion_, int color_, int casilla_)
{
	sprite1.setSize(0.25, 0.25);
	sprite7.setSize(0.25, 0.25);
	posicion.x = posicion_.x;
	posicion.y = posicion_.y;
	color = color_;
	casilla = casilla_;
	tipo = 1;
}

Alfil::~Alfil()
{

}

void Alfil::dibuja() {
	if (color == 0) {
		sprite1.setCenter((float)posicion.x, (float)posicion.y);
		glPushMatrix();
		sprite1.draw();
		glPopMatrix();
	}
	if (color == 1) {
		sprite7.setCenter((float)posicion.x, (float)posicion.y);
		glPushMatrix();
		sprite7.draw();
		glPopMatrix();
	}
}

void Alfil::movimientovalido(int origen, int destino, bool &b) {
	int dif = destino - origen;
	if ((dif % 7 == 0) || (dif % 9 == 0)) {
		b = TRUE;
	}
	else {
		b = FALSE;
	}
}