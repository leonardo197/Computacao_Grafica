#pragma once
#include"Window.h"
class Bola
{
private:
	float tamanho;
	float red, green, blue;
	float velocidadeX;
	float velocidadeY;
	float velocidadeXP;
	float velocidadeYP;
	float x;
	float y;
	int vidas;
public:
	Bola();
	Bola(float red, float green, float blue);
	Bola(float red, float green, float blue, float tamanho, float vidas);

	float getX();
	float getY();
	float getTamanho();
	float getVelocidadeX();
	float getVelocidadeY();

	void pintaBola();
	void moverBola(Window window);
	void pausaBola();
	void clickBola(int xRato,int yRato, Window window);
	void colisaoDebolas(float xBola, float yBola, float tamanhoBola, float xVelocidade, float yVelocidade);
};