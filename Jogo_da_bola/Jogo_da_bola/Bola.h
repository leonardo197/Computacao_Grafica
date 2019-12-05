#pragma once
#include"Window.h"
class Bola
{
private:
	float tamanho;
	float red, green, blue;
	float velocidadeX;
	float velocidadeY;
	float x;
	float y;
	int vidas;
public:
	Bola();
	Bola(float red, float green, float blue);
	Bola(float red, float green, float blue, float tamanho, float vidas);
	void pintaBola();
	void moverBola(Window window);
};