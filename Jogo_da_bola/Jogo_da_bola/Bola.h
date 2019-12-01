#pragma once
class Bola
{
 private:
	float tamanho;
	float red, green, blue;
	float velocidade;
	bool movimento;
	int vidas;

public:
	Bola();
	Bola(float red, float green, float blue);
	Bola(float red, float green, float blue, float tamanho, bool movimento, float velocidade, float vidas);
	float getTamanho();
	void  setTamanho(float tamanho);
	float getRed();
	void  setRed(float red);
	float getGreen();
	void  setGreen();
	void  setGreen(float green);
	float getBlue();
	void  setBlue(float blue);
	float getVelocidade();
	void  setVelocidade(float velocidade);
	bool  getMovimento();
	void  setMovimento(bool movimento);
	float getVidas();
	void  setVidas(float vidas);
};
