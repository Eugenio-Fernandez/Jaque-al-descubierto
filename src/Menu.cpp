#include "Menu.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include "Menu.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <iostream>
#include "Tablero.h"
using ETSIDI::Sprite;
Tablero  tablero2;
Menu::Menu()
{
	menu1->setSize(8.0, 8.0);
	menu1->setPos(4.0, 4.0);
	menu2->setSize(8.0, 8.0);
	menu2->setPos(4.0, 4.0);
}

Menu::~Menu() {
	menu1->~Sprite();
	menu2->~Sprite();
}

void Menu::dibuja() {
	if (pantalla == 0) {
		menu1->draw();
	}

	if (pantalla == 1) {
		menu2->draw();
	}
}

void Menu::flecha(int key) {

	if (start == false) {
		switch (key) {
		case GLUT_KEY_UP:
			if (pantalla == 0) {
				pantalla = 1;
			}
			break;

		case GLUT_KEY_DOWN:
			if (pantalla == 1) {
				pantalla = 0;
			}
			break;
		}
	}
}

void op(int value) {

	switch (value) {
	case 1:
		std::cout << "Has seleccionado: Nueva partida" << std::endl;
		// Aquí va el código para iniciar una nueva partida
		//void dibuja();
		tablero2.dibuja_selector();
		tablero2.piezas.dibuja();
		tablero2.dibuja();

		//tablero2.dibuja();
		//tablero2.dibuja_selector();
		break;
	case 2:
		std::cout << "Has seleccionado: Cargar partida" << std::endl;
		// Aquí va el código para cargar una partida guardada
		break;
	case 3:
		std::cout << "Has seleccionado: Guardar partida" << std::endl;
		// Aquí va el código para guardar la partida actual
		break;
	case 4:
		std::cout << "Has seleccionado: Salir del juego" << std::endl;
		// Aquí va el código para salir del juego
		exit(0);
		break;
	case 5:
		std::cout << "Has seleccionado: Menu" << std::endl;
		// Aquí va el código para volver a sacar el menu
		//Menu();
		//~Menu();
		void dibuja();
		void inicializa();
		void tecla(unsigned char key);
		void tecla2(unsigned char key);
		break;
	}


}
