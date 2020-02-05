#include"Bola.h"
#include"Window.h"
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <ctime>
//tipos de bola
Bola::Bola() {
	this->tamanho = 20;
	this->red= 0;
	this->green=0.25;
	this->blue = 0;
	this->velocidadeY= rand() % 5+5;
	this->velocidadeX=rand() % 5+5;
	this->x= rand() % 400;
	this->y= rand() % 400;
	this->vidas=10;
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
	this->x = rand() % 400;
	this->y = rand() % 400;
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
	this->x = rand() % 400;
	this->y = rand() % 400;
	this->vidas = vidas;
	this->velocidadeXP = 0;
	this->velocidadeYP = 0;
}
//get
float Bola::getX(){
	return x;
}
float Bola::getY(){
	return y;
}
float Bola::getTamanho(){
	return tamanho;
}
float Bola::getVelocidadeX() {
	return velocidadeX;
}
float Bola::getVelocidadeY() {
	return velocidadeX;
}
float Bola::getVidas() {
	return vidas;
}
//metodos internos 
void Bola::apagaBola() {
	mudaCor();
	vidas -=1;
	if (vidas<=0)
	{
		tamanho = 0;
		x = -10;
		y = -10;
	}
}
//metodos
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

void Bola::mudaCor() {
	if (green<1){
		this->green += 0.25;
	}else if (red < 1){
		this->red += 0.25;
	}else if (blue < 1){
		this->blue += 0.25;
	}else{
		green = 0;
		red = 0;
		blue = 0;
	}
}

void Bola::moverBola(Window window) {
	x += velocidadeX;
	y += velocidadeY;

	if (x >= window.windowX - tamanho) {
		x = window.windowX - tamanho;
		velocidadeX = -velocidadeX;

		apagaBola();
	}
	if (x < tamanho) {
		x = tamanho;
		velocidadeX = -velocidadeX;
		apagaBola();
	}
	if (y >= window.windowY - tamanho) {
		y = window.windowY - tamanho;
		velocidadeY = -velocidadeY;
		apagaBola();
	}
	if (y <= tamanho) {
		y = tamanho;
		velocidadeY = -velocidadeY;
		apagaBola();
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
	yRato = window.windowY - yRato;
	if (x < xRato) {
		distaciaX = xRato - x;
	}
	else {
		distaciaX = x - xRato;
	}
	if (y < yRato) {
		distaciaY = yRato - y;
	}
	else {
		distaciaY = y - yRato;
	}
	if (distaciaX <= tamanho) {
		velocidadeX = -velocidadeX;
	}
	if (distaciaY <= tamanho) {
		velocidadeY = -velocidadeY;
	}
}
void Bola::colisaoDebolas(float xBola, float yBola, float tamanhoBola, float xVelocidade, float yVelocidade) {
	float difX;
	float difY;
	float difXY = tamanho + tamanhoBola ;
	BOOLEAN topX;
	BOOLEAN topY;

	if (x >= xBola) {
		topX = false;
		difX = x - xBola;
	}
	else{
		topX = true;
		difX = xBola - x;
	}
	if (y >= yBola) {
		topY = false;
		difY = y - yBola;
	}
	else {
		topY = true;
		difY = yBola - y;
	}
	if (difY<= difXY && difX <= difXY) {
			velocidadeX = -velocidadeX;
			velocidadeY = -velocidadeY;
	}
}
