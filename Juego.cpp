#include <freeglut.h>
#include "Coordenada.h"
#include "Tablero.h"
#include <iostream>
#include "Pieza.h"
#include "ETSIDI.h"
#include "Interaccion.h"
#include "Selector.h"


using ETSIDI::SpriteSequence;

using namespace std;

Tablero tablero;
Interaccion interaccion;
int xpos_raton, ypos_raton;



void OnDraw(void); //esta funcion sera llamada para dibujar
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void onSpecialKeyboardDown(int key, int x, int y);
void glutMouseFunc(int boton, int estado, int x, int y);

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Jaque al descubierto");
	glClearColor(0, 0, 1, 1);
	glColor3f(1.f, 0, 0);
	glOrtho(700, 0, 700, 0, -1, 1);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutKeyboardFunc(OnKeyboardDown);
	glutSpecialFunc(onSpecialKeyboardDown); //gestion de los cursores
	glutMouseFunc(glutMouseFunc);
	
	tablero.setCoord();
	tablero.inicio();

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	tablero.dibuja();
	tablero.dibuja_selector();
	if (interaccion.getJaqueblanco() == TRUE) {
		tablero.dibuja_casilla_roja(0);
	}
	if (interaccion.getJaquenegro() == TRUE) {
		tablero.dibuja_casilla_roja(1);
	}
	tablero.piezas.dibuja();
	menu.dibuja();
	
	/*
	prueba.setSize(0.25, 0.25);
	prueba.setCenter(Tablero::coordTab[56].x,Tablero::coordTab[56].y);
	glPushMatrix();
	prueba.draw();
	glPopMatrix();*/

	//no borrar esta linea ni poner nada despues
	

	glutSwapBuffers();
}

void glutMouseFunc(int boton, int estado, int x, int y) {
	//cout << "Accion: " << interaccion.getAccion() << endl;
	if ((boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN)) {
		tablero.mouse_selector(x, y);
		Selector selector = tablero.getSelector();
		cout << tablero.getSelector().getCasilla() << endl;
		if (interaccion.getCorona() == FALSE) {
			interaccion.mover_pieza(selector, tablero.piezas);
		}
		else {
			interaccion.corona(selector, tablero.piezas, interaccion.getIndexpeon());
		}
	}
	glutPostRedisplay();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	
	if ((interaccion.getAccion() == TRUE) && (key == ' ')) {
		Selector selector= tablero.getSelector();
		cout << tablero.getSelector().getCasilla() << endl;
		interaccion.mover_pieza(selector, tablero.piezas);
		
	}
	
	tablero.tecla_selector(key);

	if (key == ' ') {
		interaccion.setAccion();
		cout << tablero.getSelector().getCasilla() << endl;
		//std::cout << tablero.getSelector().getFila() << tablero.getSelector().getColumna() << endl;
	}
	glutPostRedisplay();
}

void onSpecialKeyboardDown(int key, int x, int y)
{
	tablero.tecla_selector(key);
	glutPostRedisplay();
}



