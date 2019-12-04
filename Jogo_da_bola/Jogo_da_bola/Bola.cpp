#include"Bola.h"
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

Bola::Bola(void) {
	setTamanho(0.3);
    setRed(1);
	setGreen(1);
	setBlue(1);
	setVelocidade(1);
	setMovimento(false);
	setVidas(3);
	//gerarBola();
}
Bola::Bola(float red, float green, float blue) {
	setTamanho(20);
	setRed(red);
	setGreen(green);
	setBlue(blue);
	setVelocidade(1);
	setMovimento(false);
	setVidas(3);
	setX(100);
	setY(200);
}
Bola::Bola(float red, float green, float blue, float tamanho, bool movimento, float velocidade, float vidas) {
	setTamanho(tamanho);
	setRed(red);
	setGreen(green);
	setBlue(blue);
	setVelocidade(velocidade);
	setMovimento(movimento);
	setVidas(vidas);
	//gerarBola();

}

void Bola::gerarBola() {
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


float Bola::getTamanho(){
	return tamanho;
}
void  Bola::setTamanho(float tamanho) {
	this->tamanho= tamanho;
}
float Bola::getRed() {
	return red;
}
void  Bola::setRed(float red) {
	this->red = red;
}
float Bola::getGreen(){
	return green;
}
void  Bola::setGreen(float green) {
	this->green = green;
}
float Bola::getBlue() {
	return blue;
}
void  Bola::setBlue(float blue) {
	this->blue = blue;
}
float Bola::getVelocidade() {
	return velocidade;
}
void  Bola::setVelocidade(float velocidade) {
	this->velocidade = velocidade;
}

bool  Bola::getMovimento() {
	return movimento;
}
void  Bola::setMovimento(bool movimento) {
	this->movimento = movimento;
}
float Bola::getVidas() {
	return vidas;
}
void  Bola::setVidas(float Vidas) {
	this->vidas = Vidas;
}
float Bola::getX() {
	return x;
};
void  Bola::setX(float x) {
	this->x = x;
};
float Bola::getY() {
	return y;
};
void  Bola::setY(float y) {
	this->y = y;
};
