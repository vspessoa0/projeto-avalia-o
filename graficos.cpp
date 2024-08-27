#include <math.h>
#include <stdio.h>
#include <GL/freeglut.h>
#include <GL/gl.h>


int funcaoAtual = 0;

void menu(int num) {
    funcaoAtual = num;
    glutPostRedisplay();
}

void redimensiona(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    glMatrixMode(GL_MODELVIEW);
}

void astroide() {
    float t;
    glBegin(GL_LINE_LOOP);
    for (t = 0; t < 2 * M_PI; t += 0.01) {
        float x = cos(t) * cos(t) * cos(t);
        float y = sin(t) * sin(t) * sin(t);
        glVertex2f(x, y);
    }
    glEnd();
}

void cardioide() {
    float t;
    glBegin(GL_LINE_LOOP);
    for (t = 0; t < 2 * M_PI; t += 0.01) {
        float x = 1 * (2 * cos(t) - cos(2 * t));
        float y = 1 * (2 * sin(t) - sin(2 * t));
        glVertex2f(x, y);
    }
    glEnd();
}

void cicloide() {
    float t;
    glBegin(GL_LINE_STRIP);
    for (t = 0; t < 4 * M_PI; t += 0.01) {
        float x = t - sin(t);
        float y = 1 - cos(t);
        glVertex2f((x - 2 * M_PI) / (2 * M_PI), y);
    }
    glEnd();
}

void circun() {
    float t;
    glBegin(GL_LINE_LOOP);
    for (t = 0; t < 2 * M_PI; t += 0.01) {
        float x = cos(t);
        float y = sin(t);
        glVertex2f(x, y);
    }
    glEnd();
}

void cossen() {
    float t;
    glBegin(GL_LINE_STRIP);
    for (t = -M_PI; t < M_PI; t += 0.01) {
        float x = t;
        float y = cos(t);
        glVertex2f(x / M_PI, y);
    }
    glEnd();
}

void elipse() {
    float t;
    glBegin(GL_LINE_LOOP);
    for (t = 0; t < 2 * M_PI; t += 0.01) {
        float x = cos(t);
        float y = 0.5 * sin(t);
        glVertex2f(x, y);
    }
    glEnd();
}

void espiral() {
    float t;
    glBegin(GL_LINE_STRIP);
    for (t = 0; t < 4 * M_PI; t += 0.01) {
        float x = t * cos(t) / (4 * M_PI);
        float y = t * sin(t) / (4 * M_PI);
        glVertex2f(x, y);
    }
    glEnd();
}

void hiperbole() {
    float t;
    glBegin(GL_LINE_STRIP);
    for (t = -1.5; t <= 1.5; t += 0.01) {
        float x = sinh(t);
        float y = cosh(t);
        glVertex2f(x / 1.5, y / 1.5);
    }
    glEnd();
}

void parabola() {
    float t;
    glBegin(GL_LINE_STRIP);
    for (t = -2; t <= 2; t += 0.01) {
        float x = t;
        float y = t * t;
        glVertex2f(x / 2.0, y / 4.0);
    }
    glEnd();
}

void rosacea() {
    float t;
    glBegin(GL_LINE_LOOP);
    for (t = 0; t < 2 * M_PI; t += 0.01) {
        float r = cos(2 * t);
        float x = r * cos(t);
        float y = r * sin(t);
        glVertex2f(x, y);
    }
    glEnd();
}

void seno() {
    float t;
    glBegin(GL_LINE_STRIP);
    for (t = -M_PI; t < M_PI; t += 0.01) {
        float x = t;
        float y = sin(t);
        glVertex2f(x / M_PI, y);
    }
    glEnd();
}

void tangente() {
    float t;
    glBegin(GL_LINE_STRIP);
    for (t = -M_PI / 2 + 0.1; t < M_PI / 2 - 0.1; t += 0.01) {
        float x = t;
        float y = tan(t);
        glVertex2f(x / (M_PI / 2), y / 2.0);
    }
    glEnd();
}

void planoCartesiano(){
	glBegin(GL_LINES);
		glVertex2f(0.0,4.0);
		glVertex2f(0.0,-4.0);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(4.0,0.0);
		glVertex2f(-4.0,0.0);
	glEnd();
}

void DesenhaTexto(float x, float y, const char* string) {
    glRasterPos2f(x, y);
    while (*string) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string);
        string++;
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    
    DesenhaTexto(-3.9,3.8, "CLIQUE LADO DIREITO PARA ABRIR MENU");
    planoCartesiano();

    switch (funcaoAtual) {
        case 1: astroide(); break;
        case 2: cardioide(); break;
        case 3: cicloide(); break;
        case 4: circun(); break;
        case 5: cossen(); break;
        case 6: elipse(); break;
        case 7: espiral(); break;
        case 8: hiperbole(); break;
        case 9: parabola(); break;
        case 10: rosacea(); break;
        case 11: seno(); break;
        case 12: tangente(); break;
    }

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(500, 100);
    glutCreateWindow("Graficos de Funções");

    glutCreateMenu(menu);
    glutAddMenuEntry("Astroide", 1);
    glutAddMenuEntry("Cardioide", 2);
    glutAddMenuEntry("Cicloide", 3);
    glutAddMenuEntry("Circunferencia", 4);
    glutAddMenuEntry("Cosseno", 5);
    glutAddMenuEntry("Elipse", 6);
    glutAddMenuEntry("Espiral", 7);
    glutAddMenuEntry("Hiperbole", 8);
    glutAddMenuEntry("Parabola", 9);
    glutAddMenuEntry("Rosacea", 10);
    glutAddMenuEntry("Seno", 11);
    glutAddMenuEntry("Tangente", 12);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutDisplayFunc(display);
    glutReshapeFunc(redimensiona);
    glutMainLoop();

    return 0;
}
