#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "Bola.h"
//var
int windowX = 640;
int windowY = 640;


void teclas(unsigned char key, int x, int y) {
	switch (key) {
	case 'q':
	case 'Q':
		exit(0);
		break;
	case 'r':
	case 'R':

		break;
	case 'g':
	case 'G':

		break;
	case 'b':
	case 'B':

		break;
	case 'a':
	case 'A':
		break;

	}
}
// mouse callback
void rato(GLint button, GLint state, GLint x, GLint y) {


	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {

	}
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	Bola bola(0, 0, 1);
	//Bola bola1(0, 1, 0, 1, 0.1);
	//bola1.gerarBola();
	bola.gerarBola();

	glutSwapBuffers();
}

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(windowX, windowY);
	glutInitWindowPosition(500, 500);
	glutCreateWindow("Jogo da bola");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(0, windowX, 0, windowY);
	glutDisplayFunc(display);
	glutMouseFunc(rato);
	glutKeyboardFunc(teclas);
	glutMainLoop();
}


