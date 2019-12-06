#include"Bola.h"
#include"Window.h"
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <ctime>



Bola::Bola() {
	this->tamanho = 20;
	this->red=1;
	this->green=1;
	this->blue=1;
	this->velocidadeY= rand() % 10+5;
	this->velocidadeX=rand() % 10+5;
	this->x= tamanho;
	this->y= tamanho;
	this->vidas=3;
}
Bola::Bola(float red, float green, float blue) {
	this->tamanho = 20;
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->velocidadeY = rand() % 10 + 1;
	this->velocidadeX = rand() % 10 + 1;
	this->x = 200;
	this->y = 200;
	this->vidas = 3;
}
Bola::Bola(float red, float green, float blue, float tamanho, float vidas) {
	this->tamanho = tamanho;
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->velocidadeY = rand() % 10 + 1;
	srand((int)time(0));//gera uma nova srand  para os valores seren diferentes cada ves que seija otilisada
	this->velocidadeX = rand() % 10 + 1;
	this->x = 200;
	this->y = 300;
	this->vidas = vidas;
}

void Bola::pintaBola() {
	glColor3f(red, green, blue);
	glBegin(GL_TRIANGLE_FAN);
	int numSegments = 100;
	GLfloat angle;
	for (int i = 0; i <= numSegments; i++) {
		angle = i * 2.0f * 3.14159265 / numSegments;
		glVertex2f(x+cos(angle) * tamanho, y+sin(angle) * tamanho);
	}
	glEnd();
}
void Bola::moverBola(Window window) {
	x += velocidadeX;
	y += velocidadeY;

	if (x >= window.windowX - tamanho) {
		x = window.windowX - tamanho;
		velocidadeX = -velocidadeX;
	}
	if (x <= tamanho) {
		x = tamanho;
		velocidadeX = -velocidadeX;
	}
	if (y >= window.windowY - tamanho) {
		y = window.windowY - tamanho;
		velocidadeY = -velocidadeY;
	}
	if (y <= tamanho) {
		y = tamanho;
		velocidadeY = -velocidadeY;
	}

}

