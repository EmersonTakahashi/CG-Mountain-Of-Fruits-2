#include <gl/glut.h>
#include <Windows.h>

//char movement
GLfloat xchar = 0.0f;
GLfloat ychar = 0.0f;

float x_position = 0;
int state = 1; //1: right, 2: left
float moviment_speed = 0.15f;

//game finished
bool game_finished = FALSE; 

void drawCharacter() {
    // Desenha o corpo
    glBegin(GL_QUADS);
    glColor3f(1.0f + x_position, 0.0f, 0.0f);
    glVertex2f(-0.1f + x_position, -0.5f);
    glVertex2f(0.1f + x_position, -0.5f);
    glVertex2f(0.1f + x_position, -0.7f);
    glVertex2f(-0.1f + x_position, -0.7f);
    glEnd();

    // Desenha a cabeça
    glBegin(GL_QUADS);
    glColor3f(1.0f + x_position, 0.8f, 0.6f);
    glVertex2f(-0.15f + x_position, -0.3f);
    glVertex2f(0.15f + x_position, -0.3f);
    glVertex2f(0.15f + x_position, -0.5f);
    glVertex2f(-0.15f + x_position, -0.5f);
    glEnd();

    // Desenha a arma
    glBegin(GL_QUADS);
    glColor3f(0.0f + x_position, 0.0f, 0.0f);
    glVertex2f(0.15f + x_position, -0.5f);
    glVertex2f(0.2f + x_position, -0.5f);
    glVertex2f(0.2f + x_position, -0.6f);
    glVertex2f(0.15f + x_position, -0.6f);
    glEnd();

}

void display() {

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
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glColor3f(0.2f, 0.8f, 0.2f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    // Desenha a personagem
    glPushMatrix();
    glTranslatef(-0.4f, 0.1f, 0.0f);
    glScalef(0.5f, 0.5f, 1.0f);
    drawCharacter();
    glPopMatrix();

    glutSwapBuffers();
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

    switch (state) {
    case RIGHT:
        if (x_position < 2.6) {
            x_position += moviment_speed;
        }
        else {
            state = LEFT;
        }
        break;
    case LEFT:
        if (x_position > -1) {
            x_position -= moviment_speed;
        }
        else {
            state = RIGHT;
        }
        break;
    }
    
}


void MOUSE_MENU(int item) // MOUSE MENU / MENU DE RATO
{
    switch (item)
    {
    case PLAY_GAME:
        glutTimerFunc(0, timer, 0);
        break;
    case RESTART_GAME:break;
    case MAIN_MENU_GAME:break;
    case LEAVE_GAME:break;

        glutPostRedisplay();

    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Cena simples com personagem de atirador");
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
