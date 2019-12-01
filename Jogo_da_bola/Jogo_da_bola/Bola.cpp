#include"Bola.h"
Bola::Bola() {
	setTamanho(3);
    setRed(1);
	setGreen(1);
	setBlue(1);
	setVelocidade(1);
	setMovimento(false);
	setVidas(3);
}
Bola::Bola(float red, float green, float blue) {
	setTamanho(tamanho);
	setRed(red);
	setGreen(green);
	setBlue(blue);
	setVelocidade(1);
	setMovimento(false);
	setVidas(3);
}
Bola::Bola(float red, float green, float blue, float tamanho, bool movimento, float velocidade, float vidas) {
	setTamanho(tamanho);
	setRed(red);
	setGreen(green);
	setBlue(blue);
	setVelocidade(velocidade);
	setMovimento(movimento);
	setVidas(vidas);
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