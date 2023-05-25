#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;

class Menu
{
private:

	bool start = false;
	Sprite* menu1 = new Sprite("imagenes/menunuevapartida.png", 4.0, 4.0, 10.0, 10.0);
	Sprite* menu2 = new Sprite("imagenes/menusalir.png", 4.0, 4.0, 10.0, 10.0);
	//bool inicio;
	int modo1 = 1, modo2, inicio = 0;
	int pantalla = 0;
public:
	Menu();
	~Menu();
	void dibuja();
	void flecha(int key);
	void inicializa();
	void tecla(unsigned char key);
	void tecla2(unsigned char key);
};
