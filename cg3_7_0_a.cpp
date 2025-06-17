/*
wdax, 방향키 누르면 바뀜
*/

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define GL_PI 3.1415f
bool bCull = true;
GLfloat xTran = 0.0f;
GLfloat yTran = 0.0f;
GLfloat xRot = 0.0f;
GLfloat yRot = 0.0f;
void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    if (bCull)
        glEnable(GL_CULL_FACE);
    else
        glDisable(GL_CULL_FACE);

    glPushMatrix();
    glRotatef(xRot, 1.0f ,0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);

    glTranslatef(xTran, yTran, 0.0f);

    GLfloat x, y, angle; // 좌표와 각도 저장
    int iPivot = 1;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);
    for (angle = 0.0f; angle < (2.0f * GL_PI); angle += (GL_PI / 8.0f))
    {
        x = 50.0f * sin(angle);
        y = 50.0f * cos(angle);
        if ((iPivot % 2) == 0)
            glColor3f(0.0f, 0.0f, 1.0f);
        else
            glColor3f(0.0f, 1.0f, 0.0f);
        iPivot++;
        glVertex2f(x, y);

    }
    glVertex2f(0.0f, 0.0f);
    for (angle = 0.0f; angle < (2.0f * GL_PI); angle += (GL_PI / 8.0f))
    {
        x = 50.0f * cos(angle);
        y = 50.0f * sin(angle);
        if ((iPivot % 2) == 0)
            glColor3f(0.0f, 1.0f, 0.0f);
        else
            glColor3f(1.0f, 0.0f, 0.0f);
        iPivot++;
        glVertex2f(x, y);

    }
    glEnd();
    glPopMatrix();
    glFlush();
}

void SetupRC(void)
{
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glShadeModel(GL_FLAT);
}

void ChangeSize(GLsizei w, GLsizei h)
{
    std::cout << "ChangeSize" << std::endl;

    GLdouble nRange = 100.0f;
    GLdouble aspectRatio;

    if (h == 0)
        h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    aspectRatio = (GLfloat)w / (GLfloat)h;
    if (w <= h)
        glOrtho(-nRange, nRange, -nRange / aspectRatio, nRange / aspectRatio, nRange, -nRange);
    else
        glOrtho(-nRange * aspectRatio, nRange * aspectRatio, -nRange, nRange, nRange, -nRange);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
	printf("key: %c (%d)\n", key, key);
    if (key == 'a') {
        xTran -= 2.0f;
    }
    else if (key == 'd') {
        xTran += 2.0f;
    }
    else if (key == 'w')
        {
        yTran += 2.0f;
        }
    else if( key == 'x'){
        yTran -= 2.0f;
    }

    glutPostRedisplay();
}
void SpecialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_UP) {
        xRot -= 2.0f;
    }
    else if (key == GLUT_KEY_DOWN) {
        xRot += 2.0f;
    }
    else if (key == GLUT_KEY_LEFT) {
        yRot += 2.0f;
    }
    else if (key == GLUT_KEY_RIGHT) {
        yRot += 2.0f;
    }

    if (xRot > 360.0f) {
        xRot -= 360.0f;
    }
    if (xRot < 0.0f) {
        xRot += 360.0f;
    }
    if (yRot > 360.0f) {
        yRot -= 360.0f;
    }
    if (yRot < 0.0f) {
        yRot += 360.0f;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(500, 500);
    glViewport(0, 0, 500, 500); //내가 그림을 그리는 뷰포트를 500, 500크기로 설정하겠다 (GLint x, GLint y, GLsizei width, GLsizei height)
    glutCreateWindow("simple");

    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(SpecialKeys);

    SetupRC();
    glutMainLoop();
}