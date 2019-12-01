#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#define WSIZE 500

float xForma = 100, yForma = 200;
float tam = 50;

float vForma = 50.0;   // pixeis por segundo
float angForma = 0.0;  // angulo em radianos da direção do movimento;
float time = 30;       // tempo em milisegundos para actualização do movimento;

int estadoANIM = 0;    // no início é zero (false) não está a animar...

float r = 0.0, g = 1.0, b = 0.0;

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 1.0, 0.0);

	glLoadIdentity();
	gluOrtho2D(0, WSIZE, 0, WSIZE);

}

// display callback
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2f(xForma - tam, yForma - tam);
	glVertex2f(xForma - tam, yForma + tam);
	glVertex2f(xForma + tam, yForma + tam);
	glVertex2f(xForma + tam, yForma - tam);
	glEnd();


	glFlush();
}

void anima(int t)
{
	xForma += vForma * (t / 1000.0) * cos(angForma);
	yForma += vForma * (t / 1000.0) * sin(angForma);

	glutPostRedisplay();

	if (estadoANIM == 1)
		glutTimerFunc(t, anima, t);
}


// mouse callback
void rato(GLint button, GLint state, GLint x, GLint y)
{
	y = WSIZE - y;

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		xForma = x;
		yForma = y;

		glutPostRedisplay();
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		angForma += 3.14 + (((rand() % 1000) / 1000.0) * 3.14) - 1.57;
	}
}

void teclas(unsigned char key, int x, int y)
{
	switch (key) {
	case 'q':
	case 'Q':
		exit(0);
		break;
	case 'r':
	case 'R':
		r = 1.0;
		g = b = 0.0;
		break;
	case 'g':
	case 'G':
		g = 1.0;
		r = b = 0.0;
		break;
	case 'b':
	case 'B':
		b = 1.0;
		g = r = 0.0;
		break;
	case 'a':
	case 'A':
		if (estadoANIM == 0) {
			estadoANIM = 1;
			angForma = 2 * 3.14 * ((rand() % 1000) / 1000.0);
			printf("Algulo Velocidade: %f\n", angForma);
			glutTimerFunc(time, anima, time);
		}
		else {
			estadoANIM = 0;
		}

	}
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(WSIZE, WSIZE);
	glutInitWindowPosition(500, 50);
	glutCreateWindow("Olá Mundo em OpenGL");
	glutDisplayFunc(display);
	glutMouseFunc(rato);
	glutKeyboardFunc(teclas);
	myInit();
	glutMainLoop();
}