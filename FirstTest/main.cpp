#include <gl/glut.h>
#include <Windows.h>

//char movement
GLfloat xchar = 0.0f;
GLfloat ychar = 0.0f;

float x_position = 0;
float y_position = 0;
int state = 1; //1: right, 2: left
float moviment_speed = 0.15f;
float moviment_y = 0.2f;

bool fruit_was_peaked = FALSE;

bool game_started = FALSE;

//game finished
bool game_finished = FALSE;


void drawCharacter() {
	// Desenha o corpo
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.1f + x_position, -0.5f + y_position);
	glVertex2f(0.1f + x_position, -0.5f + y_position);
	glVertex2f(0.1f + x_position, -0.7f + y_position);
	glVertex2f(-0.1f + x_position, -0.7f + y_position);
	glEnd();

	// Desenha a cabeça
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.8f, 0.6f);
	glVertex2f(-0.15f + x_position, -0.3f + y_position);
	glVertex2f(0.15f + x_position, -0.3f + y_position);
	glVertex2f(0.15f + x_position, -0.5f + y_position);
	glVertex2f(-0.15f + x_position, -0.5f + y_position);
	glEnd();

	// Desenha a arma
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.15f + x_position, -0.5f + y_position);
	glVertex2f(0.2f + x_position, -0.5f + y_position);
	glVertex2f(0.2f + x_position, -0.6f + y_position);
	glVertex2f(0.15f + x_position, -0.6f + y_position);
	glEnd();
}

void drawPost() {
	// Define a cor cinza
	glColor3f(0.5f, 0.5f, 0.5f);

	// Desenha a parte cinza do poste
	glBegin(GL_QUADS);
	glVertex2f(-0.1f, -0.7f);
	glVertex2f(0.1f, -0.7f);
	glVertex2f(0.1f, 0.5f);
	glVertex2f(-0.1f, 0.5f);
	glEnd();

	// Define a cor preta
	glColor3f(0.0f, 0.0f, 0.0f);

	// Desenha a parte preta do poste
	glBegin(GL_QUADS);
	glVertex2f(-0.05f, -0.62f);
	glVertex2f(0.05f, -0.62f);
	glVertex2f(0.05f, 0.45f);
	glVertex2f(-0.05f, 0.45f);
	glEnd();
}

void drawLine() {
	// Define a cor vermelha
	glColor3f(0.0f, 0.0f, 0.0f);

	// Define as coordenadas da linha
	GLfloat x1 = -1.0f;
	GLfloat y1 = -0.5f;
	GLfloat x2 = 1.0f;
	GLfloat y2 = -0.5f;

	// Desenha a linha
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void drawFruits() {

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.5f, 0.5f); // rosa
	glVertex2f(-0.6f, -0.15f);
	glVertex2f(-0.5f, -0.05f);
	glVertex2f(-0.4f, -0.15f);
	glVertex2f(-0.5f, -0.25f);
	glEnd();
}

void drawStairs() {

	// Desenha os degraus
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-0.7f, -0.5f);
	glVertex2f(-0.7f, -0.4f);
	glVertex2f(-0.8f, -0.4f);

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(-0.7f, -0.5f);
	glVertex2f(-0.6f, -0.5f);
	glVertex2f(-0.6f, -0.3f);
	glVertex2f(-0.7f, -0.3f);

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex2f(-0.6f, -0.5f);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(-0.5f, -0.2f);
	glVertex2f(-0.6f, -0.2f);

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(-0.4f, -0.5f);
	glVertex2f(-0.4f, -0.1f);
	glVertex2f(-0.5f, -0.1f);

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex2f(-0.4f, -0.5f);
	glVertex2f(-0.3f, -0.5f);
	glVertex2f(-0.3f, 0.0f);
	glVertex2f(-0.4f, 0.0f);
	glEnd();
}

void level1() {

	glClear(GL_COLOR_BUFFER_BIT);

	// Desenha o céu
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(1.0f, 1.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(1.0f, 0.0f);
	glVertex2f(-1.0f, 0.0f);
	glEnd();

	// Desenha a grama
	glBegin(GL_QUADS);
	//glClearColor(0.5, 0.5, 0.5, 1.0);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(1.0f, 0.0f);
	glColor3f(0.2f, 0.8f, 0.2f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(-1.0f, -1.0f);
	glEnd();

	// Desenha a personagem
	glPushMatrix();
	glTranslatef(-0.9f, 0.3f, 0.0f);
	glScalef(0.5f, 0.5f, 1.0f);
	drawCharacter();
	glPopMatrix();

	// Desenhar Degraus 
	glPushMatrix();
	glTranslatef(1.3f, 0.5f, 0.0f);
	drawStairs();
	glPopMatrix();

	//Desenhar Fruta
	if (!fruit_was_peaked) {
		glPushMatrix();
		glTranslatef(1.0f, 0.5f, 0.0f);
		glScalef(0.3f, 0.3f, 1.0f);
		drawFruits();
		glPopMatrix();
	}

	// Desenhar Posto
	glPushMatrix();
	glTranslatef(-0.1f, 0.7f, 0.0f);
	glScalef(0.6f, 0.6f, 1.0f);
	drawPost();
	glPopMatrix();

	drawLine();


	glutSwapBuffers();
}

void display() {
	level1();
}

enum mouseMENU_TYPE //MENU ITEMS
{
	PLAY_GAME, // 0
	RESTART_GAME, // 1
	MAIN_MENU_GAME, // 2
	LEAVE_GAME, // 3
};

enum movimentDirection {
	RIGHT = 1,
	LEFT = 2
};

void timer(int) {

	glutPostRedisplay();
	glutTimerFunc(1000 / 10, timer, 0);

	if (x_position >= 3) {
		fruit_was_peaked = true;
	}

	switch (state) {
	case RIGHT:
		if (x_position < 3.5) {
			x_position += moviment_speed;
		}
		else {
			state = LEFT;
		}

		if (x_position > 2.5 && x_position < 2.8) {
			y_position += moviment_y;
		}
		else if (x_position > 2.8 && x_position < 3.1) {
			y_position += moviment_y;
		}
		else if (x_position > 3.1 && x_position < 3.4) {
			y_position += moviment_y;
		}
		break;
	case LEFT:
		if (x_position > 0) {

			x_position -= moviment_speed;
		}
		else {
			if (fruit_was_peaked) {
				game_finished = true;
				_mm_pause();
				break;
			}
			state = RIGHT;
		}

		if (x_position > 2.5 && x_position < 2.8) {
			y_position -= moviment_y;
		}
		else if (x_position > 2.8 && x_position < 3.1) {
			y_position -= moviment_y;
		}
		else if (x_position > 3.1 && x_position < 3.4) {
			y_position -= moviment_y;
		}
		break;
	}
}

void SetRestartGameVariables() {
	x_position = 0;
	moviment_speed = 0.15f;
	fruit_was_peaked = FALSE;
	game_started = FALSE;
	game_finished = FALSE;
}

void MOUSE_MENU(int item) // MOUSE MENU / MENU DE RATO
{
	switch (item)
	{
	case PLAY_GAME:
		if (!game_started) {
			game_started = true;
			glutTimerFunc(0, timer, 0);
		}
		break;
	case RESTART_GAME:
		if (game_finished) {
			SetRestartGameVariables();
			glutPostRedisplay();
		}
		break;
	case MAIN_MENU_GAME:break;
	case LEAVE_GAME:
		quick_exit;
		break;

		glutPostRedisplay();
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Mountain of the dragon fruits");
	glutDisplayFunc(display);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glutCreateMenu(MOUSE_MENU); // CREATE A MENU

	glutAddMenuEntry("PLAY", PLAY_GAME); // menu entry 0
	glutAddMenuEntry("RESTART", RESTART_GAME); // menu entry 0
	glutAddMenuEntry("MAIN MENU", MAIN_MENU_GAME); // menu entry 0
	glutAddMenuEntry("LEAVE GAME", LEAVE_GAME);  // menu entry 0

	glutAttachMenu(GLUT_LEFT_BUTTON);

	glutMainLoop();

	return 0;
}