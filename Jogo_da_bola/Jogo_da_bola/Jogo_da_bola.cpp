#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "Bola.h"
#include"Window.h"
#include<vector>
#include <random>

#include <ctime>
//var
Window window(640, 640);

std::vector<Bola> bolas;
int FPS = 40;

void pausa() {
	for (size_t i = 0; i < bolas.size(); i++) {
		bolas[i].pausaBola();
	}
}

void teclas(unsigned char key, int x, int y) {
	switch (key) {
	case 'q':
	case 'Q':
		exit(0);
		break;
	case 'r':
	case 'R':

		break;
	case 'p':
	case 'P':
		pausa();
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
	for (size_t  i = 0; i < bolas.size(); i++) {
		bolas[i].pintaBola();
	}
	glutSwapBuffers();
}
void timer(int)
{
	for (size_t  i = 0; i < bolas.size(); i++) {
		bolas[i].moverBola(window);
	}
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer, 0);
}
void testes() {

	Bola bola1(0, 1, 1, 20, 3);
	Bola bola(0, 1, 0);
	Bola bola2 = Bola();
	Bola bola3 = Bola();


	bolas.push_back(bola1);
	bolas.push_back(bola);
	bolas.push_back(bola2);
	bolas.push_back(bola3);
}
void main(int argc, char** argv){
	srand((int)time(0));//gera uma nova srand  para os valores seren diferentes cada ves que seija otilisada
	glutInit(&argc, argv);
	testes();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(window.windowX, window.windowY);
	glutInitWindowPosition(500, 500);
	glutCreateWindow("Jogo da bola");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(0, window.windowX, 0, window.windowY);
	glutDisplayFunc(display);
	glutMouseFunc(rato);
	glutKeyboardFunc(teclas);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
}


