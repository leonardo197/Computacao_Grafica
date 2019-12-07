#include"Bola.h"
#include"Window.h"
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <ctime>

Bola::Bola() {
	this->tamanho = 20;
	this->red= (rand() % 365+1)/ 365.0;
	this->green= (rand() % 365 +1) / 365.0;
	this->blue= (rand() % 365 +1) / 365.0;
	this->velocidadeY= rand() % 5+5;
	this->velocidadeX=rand() % 5+5;
	this->x= tamanho;
	this->y= tamanho;
	this->vidas=3;
	this->velocidadeXP=0;
	this->velocidadeYP=0;
}
Bola::Bola(float red, float green, float blue) {
	this->tamanho = 20;
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->velocidadeY = rand() % 5 + 5;
	this->velocidadeX = rand() % 5 + 5;
	this->x = 200;
	this->y = 200;
	this->vidas = 3;
	this->velocidadeXP = 0;
	this->velocidadeYP = 0;
}
Bola::Bola(float red, float green, float blue, float tamanho, float vidas) {
	this->tamanho = tamanho;
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->velocidadeY = rand() % 5 + 5;
	srand((int)time(0));//gera uma nova srand  para os valores seren diferentes cada ves que seija otilisada
	this->velocidadeX = rand() % 5 + 5;
	this->x = 200;
	this->y = 300;
	this->vidas = vidas;
	this->velocidadeXP = 0;
	this->velocidadeYP = 0;
}

void Bola::pintaBola() {
	glColor3f(red, green, blue);
	glBegin(GL_TRIANGLE_FAN);
	int numSegments = 100;
	GLfloat angle;
	for (int i = 0; i <= numSegments; i++) {
		angle = i * 2 * 3.14159265 / numSegments;
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
void Bola::pausaBola() {
	if (velocidadeXP==0 &&velocidadeYP==0) {
		 velocidadeXP= velocidadeX;
		 velocidadeYP= velocidadeY;
		 velocidadeX=0;
		 velocidadeY=0;
	}
	else {
		velocidadeX = velocidadeXP;
		velocidadeY = velocidadeXP;
		velocidadeXP = 0;
		velocidadeYP = 0;
	}
}
void Bola::clickBola(int xRato, int yRato, Window window) {
	float distaciaX;
	float distaciaY;
	BOOLEAN topX;
	BOOLEAN topY;
	yRato = window.windowY- yRato;
	if (x<xRato) {
		distaciaX = xRato - x;
		topX = true;
	}
	else{
		distaciaX = x - xRato;
		topX = false;
	}
	if (distaciaX<=tamanho){
		if (y < yRato) {
			distaciaY = yRato - y;
			topY = true;
		}
		else{
			distaciaY = y - yRato;
			topY = false;
		}
		if (distaciaY <= tamanho) {
			if (topX){
				velocidadeX = -velocidadeX;
			}
			else {
				velocidadeX = velocidadeX;
			}
			if (topY) {
				velocidadeY = -velocidadeY;
			}
			else {
				velocidadeY = velocidadeY;
			}
		}
	}
}
