#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;

class Menu
{
private:
	

	bool start = false;
	Sprite* menu1 = new Sprite("imagenes/menunuevapartida.png", 4.0, 4.0, 10.0, 10.0);
	Sprite* menu2 = new Sprite("imagenes/menusalir.png", 4.0, 4.0, 10.0, 10.0);
	Sprite* menu3 = new Sprite("imagenes/modoclasico.png", 4.0, 4.0, 10.0, 10.0);
	Sprite* menu4 = new Sprite("imagenes/modoetsidi.png", 4.0, 4.0, 10.0, 10.0);


	int modo1 = 1, modo2, modo3 = 0, inicio = 0, a = 1;
	int pantalla = 0;

public:

	int marcha;

	Menu();
	~Menu();
	int dibuja();
	void flecha(int key);
	void inicializa();
	void tecla(unsigned char key);
	void tecla2(unsigned char key);

	int getMarcha() { return dibuja(); }

};

