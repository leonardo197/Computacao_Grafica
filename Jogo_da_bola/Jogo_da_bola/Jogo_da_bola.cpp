#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "Bola.h"
//var
int windowX = 640;
int windowY = 640;


//tela de jogo
void telaDeJogo(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
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
	Bola bola(1, 1, 1,20,2);
	Bola bola1(0, 1, 0,2,0);
	bola.gerarBola();
	bola1.gerarBola();
	

	glutSwapBuffers();
}

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(windowX, windowY);
	glutInitWindowPosition(500, 500);
	//Bola bola(1,1,1);


	glutCreateWindow("Jogo da bola");
	glutDisplayFunc(display);
	glutMouseFunc(rato);
	glutKeyboardFunc(teclas);
	telaDeJogo();
	glutMainLoop();
}

