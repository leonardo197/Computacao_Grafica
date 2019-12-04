#pragma once
#include <GL/glut.h>
class Bola
{
 private:
	float tamanho;
	float red, green, blue;
	float velocidade;
	bool movimento;
	int vidas;
	float x;
	float y;
public:
	Bola();
	Bola(float red, float green, float blue);
	Bola(float red, float green, float blue, float tamanho, bool movimento, float velocidade, float vidas);
	void gerarBola();
	void moverBola();
	float getTamanho();
	void  setTamanho(float tamanho);
	float getRed();
	void  setRed(float red);
	float getGreen();
	void  setGreen(float green);
	float getBlue();
	void  setBlue(float blue);
	float getVelocidade();
	void  setVelocidade(float velocidade);
	bool  getMovimento();
	void  setMovimento(bool movimento);
	float getVidas();
	void  setVidas(float vidas);
	float getX();
	void  setX(float x);
	float getY();
	void  setY(float y);
};
