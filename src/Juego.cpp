#include <freeglut.h>
#include "Coordenada.h"
#include "Tablero.h"
#include <iostream>
#include "Pieza.h"

using namespace std;

Tablero tablero;
Pieza peon;

void OnDraw(void); //esta funcion sera llamada para dibujar
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void onSpecialKeyboardDown(int key, int x, int y);

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

	tablero.inicio();
	tablero.setCoord();

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

	for (int i = 0; i < TAM_TABLERO; i++) {
		peon.dibuja(1.0001 - i * 0.25, 0.74);
	}
	

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	glutPostRedisplay();
}

void onSpecialKeyboardDown(int key, int x, int y)
{
	tablero.tecla_selector(key);
	glutPostRedisplay();
}



