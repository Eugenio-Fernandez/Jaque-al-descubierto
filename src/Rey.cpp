#include "Rey.h"

Rey::Rey(Coordenada posicion_, int color_, int casilla_)
{
	conf_modo();

	if (modo == 1)
		sprite5.setSize(0.25, 0.25);
	if (modo == 2)
		sprite5_1.setSize(0.25, 0.25);

	if (modo == 1)
		sprite11.setSize(0.25, 0.25);
	if (modo == 2)
		sprite11_1.setSize(0.39, 0.58);

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

		if (modo == 1)
			sprite5.setCenter((float)posicion.x, (float)posicion.y);
		if (modo == 2)
			sprite5_1.setCenter((float)posicion.x, (float)posicion.y);

		glPushMatrix();

		if (modo == 1)
			sprite5.draw();
		if (modo == 2)
			sprite5_1.draw();

		glPopMatrix();
	}
	if (color == 1) {

		if (modo == 1)
			sprite11.setCenter((float)posicion.x, (float)posicion.y);
		if (modo == 2)
			sprite11_1.setCenter((float)posicion.x + 0.064, (float)posicion.y + 0.17);

		glPushMatrix();

		if (modo == 1)
			sprite11.draw();
		if (modo == 2)
			sprite11_1.draw();

		glPopMatrix();
	}
}

void Rey::movimientovalido(int origen, int destino, bool& b) {
	int dif = destino - origen;
	if ((((dif % 7 == 0) || (dif % 8 == 0) || (dif % 9 == 0)||(dif==1)||(dif==-1))&&(dif<10)&&(dif>-10))
		||
		(pieza_movida==0)&&(((color==0)&&(((destino==2))||(destino==6)))||(((color == 1) && (((destino == 62)) || (destino == 58)))))
		) {
		b=TRUE;
		ETSIDI::play("sonidos/mov.wav");
	}
	else {
		b=FALSE;
	}
}
