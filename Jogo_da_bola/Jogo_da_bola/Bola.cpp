#include"Bola.h"
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

Bola::Bola(void) {
	this->tamanho = 20;
	this->red=1;
	this->green=1;
	this->blue=1;
	this->velocidadeY;
	this->velocidadeX;
	this->x=400;
	this->y=400;
	this->vidas=3;
}
Bola::Bola(float red, float green, float blue) {
	this->tamanho = 20;
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->velocidadeY;
	this->velocidadeX;
	this->x = 200;
	this->y = 200;
	this->vidas = 3;
}
Bola::Bola(float red, float green, float blue, float tamanho, float vidas) {
	this->tamanho = tamanho;
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->velocidadeY;
	this->velocidadeX;
	this->x = 200;
	this->y = 300;
	this->vidas = vidas;
}

void Bola::pintaBola() {
	glClear(GL_COLOR_BUFFER_BIT);
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

