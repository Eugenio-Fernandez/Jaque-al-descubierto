#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;

class Menu
{
private:
	Sprite* menu1 = new Sprite("imagenes/AlfilBlanco.png", 4.0, 4.0, 8.0, 8.0);
	Sprite* menu2 = new Sprite("imagenes/CaballoBlanco.png", 4.0, 4.0, 8.0, 8.0);
	bool start = false;
	int pantalla = 0;
public:
	Menu();
	~Menu();
	void dibuja();
	void flecha(int key);
};

