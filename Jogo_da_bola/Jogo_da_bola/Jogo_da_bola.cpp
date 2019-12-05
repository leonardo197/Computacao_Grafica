#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "Bola.h"
#include"Window.h"
#include<vector>
//var

Window window(640, 640);

std::vector<Bola> bolas;
int FPS = 40;

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

	for (int i = 0; i < bolas.size(); i++) {
		bolas[i].pintaBola();
	}
	glutSwapBuffers();
}
void timer(int)
{
	for (int i = 0; i < bolas.size(); i++) {
		bolas[i].moverBola(window);
	}
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer, 0);
}
void testes() {
	Bola bola1(0, 1, 1, 20, 3);
	Bola bola(0, 1, 0);
	Bola bola2 = Bola();

	bolas.push_back(bola1);
	bolas.push_back(bola);
	bolas.push_back(bola2);
}
void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(window.windowX, window.windowY);
	glutInitWindowPosition(500, 500);
	glutCreateWindow("Jogo da bola");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(0, window.windowX, 0, window.windowY);
	testes();
	glutDisplayFunc(display);
	glutMouseFunc(rato);
	glutKeyboardFunc(teclas);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
}


