#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "Bola.h"
#include"Window.h"
#include<vector>
#include <random>
#include <ctime>
#include <iostream>
//var
Window window(440, 440);
int bolasForaJogo;
std::vector<Bola> bolas;
int FPS = 30;
int pontos;

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
	case 'p':
	case 'P':
		pausa();
		break;
	}
}

// mouse callback
void rato(GLint button, GLint state, GLint x, GLint y) {


	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		for (size_t i = 0; i < bolas.size(); i++) {
			bolas[i].clickBola(x, y,window);
		}
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
	bolasForaJogo = bolas.size();
	for (size_t  i = 0; i < bolas.size(); i++) {
		bolas[i].moverBola(window);
		if (bolas[i].getVidas()<=0){
			bolasForaJogo -= 1;
		}else{
			for (size_t ii = 0; ii < bolas.size(); ii++) {
				if (i != ii) {
					bolas[i].colisaoDebolas(bolas[ii].getX(), bolas[ii].getY(), bolas[ii].getTamanho(), bolas[ii].getVelocidadeX(), bolas[ii].getVelocidadeX());
				}
			}
		}
	}
	pontos += 1;
	if (bolasForaJogo==0){
		std::cout << "Pontos " << pontos;
		exit(0);
	}

	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer, 0);
}
void testes() {
	Bola bola1(0, 1, 1, 20, 3);
	Bola bola4(0, 1, 0);

	bolas.push_back(bola1);
	bolas.push_back(bola4);
	
	for (size_t i = 0; i < 4; i++)
	{
		Bola bola = Bola();
		bolas.push_back(bola);
	
	}
}
void main(int argc, char** argv){
	srand((int)time(0));//gera uma nova srand  para os valores seren diferentes cada ves que seija otilisada
	glutInit(&argc, argv);
	testes();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(window.windowX, window.windowY);
	glutInitWindowPosition(300, 300);
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


