
#include <windows.h>
#include <GL/glut.h>
#include <Math.h>
constexpr auto PI = 3.14159265f;

// Variaveis Globais
int refreshMillis = 30;
int windowWidth = 640;
int windowHeight = 480;
int windowPosX = 50;
int windowPosY = 50;

GLfloat ballRadius = 0.1f;
GLfloat ballX = 0.0f;
GLfloat ballY = 0.0f;
GLfloat ballXMax, ballXMin, ballYMax, ballYMin;
GLfloat xSpeed = 0.025f;
GLfloat	ySpeed = 0.025f;

// Area de proje�ao
GLdouble clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;

bool fullScreenMode = false;
bool paused = false;
GLfloat xSpeedSaved, ySpeedSaved;

// Inicializar OpenGL
void initGL() {
	glClearColor(0.0, 0.0, 0.0, 1.0); // Cor de fundo
}

// Mostrar Janela
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Traduzir valores para coordenada x e y
	glTranslatef(ballX, ballY, 0.0f);

	// Formar um circulo com segmentos triangulares
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 1.0f); // Azul
	glVertex2f(0.0f, 0.0f);		 // Centro do circulo

	int numSegments = 100;
	GLfloat angle;

	for (int i = 0; i <= numSegments; i++) {
		angle = i * 2.0f * PI / numSegments;
		glVertex2f(cos(angle) * ballRadius, sin(angle) * ballRadius);
	}

	glEnd();

	glutSwapBuffers();

	// Controlo da anima��o - Posi��o de x e y para o proximo refresh
	ballX += xSpeed;
	ballY += ySpeed;

	// Verificar se a posi��o da bola est� fora dos limites da janela
	if (ballX > ballXMax) {
		ballX = ballXMax;
		xSpeed = -xSpeed;
	}
	else if (ballX < ballXMin) {
		ballX = ballXMin;
		xSpeed = -xSpeed;
	}
	if (ballY > ballYMax) {
		ballY = ballYMax;
		ySpeed = -ySpeed;
	}
	else if (ballY < ballYMin) {
		ballY = ballYMin;
		ySpeed = -ySpeed;
	}

}

// Redefinir tamanho da janela
void reshape(GLsizei width, GLsizei height) {
	if (height == 0) height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	glViewport(0, 0, width, height);

	// Definir a propor��o da da janela
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (width >= height) {
		clipAreaXLeft = -1.0 * aspect;
		clipAreaXRight = 1.0 * aspect;
		clipAreaYBottom = -1.0;
		clipAreaYTop = 1.0;
	}
	else {
		clipAreaXLeft = -1.0;
		clipAreaXRight = 1.0;
		clipAreaYBottom = -1.0 / aspect;
		clipAreaYTop = 1.0 / aspect;
	}
	gluOrtho2D(clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop);
	ballXMin = clipAreaXLeft + ballRadius;
	ballXMax = clipAreaXRight - ballRadius;
	ballYMin = clipAreaYBottom + ballRadius;
	ballYMax = clipAreaYTop - ballRadius;
}

// Activar ou desativar Fullscreen Mode
void toggleFullScreen() {
	fullScreenMode = !fullScreenMode;
	if (fullScreenMode) {
		windowPosX = glutGet(GLUT_WINDOW_X);
		windowPosY = glutGet(GLUT_WINDOW_Y);
		windowWidth = glutGet(GLUT_WINDOW_WIDTH);
		windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
		glutFullScreen();
	}
	else {
		glutReshapeWindow(windowWidth, windowHeight);
		glutPositionWindow(windowPosX, windowPosX);
	}
}

void pauseGame() {
	paused = !paused;
	if (paused) {
		xSpeedSaved = xSpeed;
		ySpeedSaved = ySpeed;
		xSpeed = 0;
		ySpeed = 0;
	}
	else {
		xSpeed = xSpeedSaved;
		ySpeed = ySpeedSaved;
	}
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'F': // F: activar ou desativar Fullscreen Mode
	case 'f':
		toggleFullScreen();
		break;
	case 'P':
	case 'p':
		pauseGame();
		break;
	}
}

void timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(refreshMillis, timer, 0);
}

// Fun��o Main
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(windowPosX, windowPosY);
	glutCreateWindow("Bouncing Balls Game");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0);
	glutKeyboardFunc(keyboard);
	initGL();
	glutMainLoop();
	return 0;
}