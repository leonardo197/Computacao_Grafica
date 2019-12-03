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
	GLfloat x;
	GLfloat y;
public:
	Bola();
	Bola(float red, float green, float blue, GLfloat x, GLfloat y);
	Bola(float red, float green, float blue, float tamanho, bool movimento, float velocidade, float vidas);
	void gerarBola();
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
	GLfloat getX();
	void  setX(GLfloat x);
	GLfloat getY();
	void  setY(GLfloat y);
};
