#include"Bola.h"
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

Bola::Bola(void) {
	setTamanho(3);
    setRed(1);
	setGreen(1);
	setBlue(1);
	setVelocidade(1);
	setMovimento(false);
	setVidas(3);
	//gerarBola();
}
Bola::Bola(float red, float green, float blue, GLfloat x, GLfloat y) {
	setTamanho(tamanho);
	setRed(red);
	setGreen(green);
	setBlue(blue);
	setVelocidade(1);
	setMovimento(false);
	setVidas(3);
	setX(x);
	setY(y);
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
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();



	glTranslatef(x,y,0.0f);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(red, green, blue);
	glVertex2f(0, 0);		 // Centro do circulo

	int numSegments = 100;
	GLfloat angle;

	for (int i = 0; i <= numSegments; i++) {
		angle = i * 2.0f * 3.14159265 / numSegments;
		glVertex2f(cos(angle) * 0.1f, sin(angle) * 0.1f);
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
GLfloat Bola::getX() {
	return x;
};
void  Bola::setX(GLfloat x) {
	this->x = x;
};
GLfloat Bola::getY() {
	return y;
};
void  Bola::setY(GLfloat y) {
	this->y = y;
};
