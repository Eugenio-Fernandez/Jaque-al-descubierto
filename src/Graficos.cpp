#include "Graficos.h"
#include <GL/glut.h>
#include "ETSIDI.h"


void Graficos::dibuja()
{
	glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/inicio.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(-10, 0);
	glTexCoord2d(1, 1); glVertex2f(10, 0);
	glTexCoord2d(1, 0); glVertex2f(10, 15);
	glTexCoord2d(0, 0); glVertex2f(-10, 15);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
