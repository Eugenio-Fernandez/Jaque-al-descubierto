#include "Alfil.h"

Alfil::Alfil(Coordenada posicion_, int color_, int casilla_)
{
	conf_modo();

	if (modo == 1)
		sprite1.setSize(0.25, 0.25);
	if (modo == 2)
		sprite1_1.setSize(0.25, 0.25);

	if (modo == 1)
		sprite7.setSize(0.25, 0.25);
	if (modo == 2)
		sprite7_1.setSize(0.25, 0.25);

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

		if (modo == 1)
			sprite1.setCenter((float)posicion.x, (float)posicion.y);
		if (modo == 2)
			sprite1_1.setCenter((float)posicion.x, (float)posicion.y);

		glPushMatrix();

		if (modo == 1)
			sprite1.draw();
		if (modo == 2)
			sprite1_1.draw();

		glPopMatrix();
	}
	if (color == 1) {

		if (modo == 1)
			sprite7.setCenter((float)posicion.x, (float)posicion.y);
		if (modo == 2)
			sprite7_1.setCenter((float)posicion.x, (float)posicion.y);

		glPushMatrix();

		if (modo == 1)
			sprite7.draw();
		if (modo == 2)
			sprite7_1.draw();

		glPopMatrix();
	}
}
void Alfil::movimientovalido(int origen, int destino, bool &b) {
	int dif = destino - origen;
	if ((dif % 7 == 0) || (dif % 9 == 0)) {
		b = TRUE;
		ETSIDI::play("sonidos/mov.wav");
	}
	else {
		b = FALSE;
	}
}
