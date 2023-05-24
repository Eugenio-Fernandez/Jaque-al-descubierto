#include "Rey.h"

Rey::Rey(Coordenada posicion_, int color_, int casilla_)
{
	sprite5.setSize(0.25, 0.25);
	sprite11.setSize(0.25, 0.25);
	posicion.x = posicion_.x;
	posicion.y = posicion_.y;
	color = color_;
	casilla = casilla_;
	tipo = 5;
}

Rey::~Rey()
{

}

void Rey::dibuja() {
	if (color == 0) {
		sprite5.setCenter((float)posicion.x, (float)posicion.y);
		glPushMatrix();
		sprite5.draw();
		glPopMatrix();
	}
	if (color == 1) {
		sprite11.setCenter((float)posicion.x, (float)posicion.y);
		glPushMatrix();
		sprite11.draw();
		glPopMatrix();
	}
}

void Rey::movimientovalido(int origen, int destino, bool& b) {
	int dif = destino - origen;
	if (((dif % 7 == 0) || (dif % 8 == 0) || (dif % 9 == 0)||(dif==1)||(dif==-1))&&(dif<10)&&(dif>-10)) {
		b=TRUE;
	}
	else {
		b=FALSE;
	}
}