/*
원뿔예제
*/

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define GL_PI 3.1415f
#define s_size  2.0f
GLfloat  xTran = 0.0f;
GLfloat  yTran = 0.0f;

GLfloat  xRot = 0.0f;
GLfloat  yRot = 0.0f;


bool bCull = true;

// 장면 렌더링
void RenderScene(void)
{
   glClear(GL_COLOR_BUFFER_BIT);

   if (bCull)
      glEnable(GL_CULL_FACE);
   else
      glDisable(GL_CULL_FACE);

   glPushMatrix();
   glRotatef(xRot, 1.0f, 0.0f, 0.0f);
   glRotatef(yRot, 0.0f, 1.0f, 0.0f);

   glTranslatef(xTran, yTran, 0.0f);

   
   GLfloat x, y, angle;
   glBegin(GL_TRIANGLE_FAN);
   glVertex3f(0.0f, 0.0f, 50.0f);
   int iPviot = 0;
   for (angle = 0.0f; angle < (2.0f * GL_PI); angle += ( GL_PI / 8.0)) {
      x = 50.0f * cos(angle);
      y = 50.0f * sin(angle);
      if((iPviot % 2) == 0)
         glColor3f(0.0f, 1.0f, 0.0f);
      else
         glColor3f(1.0f, 0.0f, 0.0f);
      iPviot++;
      glVertex3f(x, y, 0.0f);
   }
   glEnd();

   glBegin(GL_TRIANGLE_FAN);
   glVertex2f(0.0f, 0.0f);
   for (angle = 0.0f; angle < (2.0f * GL_PI); angle += (GL_PI / 8.0)) {
      x = 50.0f * sin(angle);
      y = 50.0f * cos(angle);
      if ((iPviot % 2) == 0)
         glColor3f(1.0f, 1.0f, 0.0f);
      else
         glColor3f(0.0f, 1.0f, 0.0f);
      iPviot++;
      
      glVertex2f(x, y);
   }
   glEnd();

   glPopMatrix();
   glFlush();
}

void SetupRC(void)
{
   cout << "SetupRC" << endl;
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
   glShadeModel(GL_FLAT);


}

void ChangeSize(GLsizei w, GLsizei h) {
   cout << "w = " << w << " " << "h =" << h;
   cout << "ChangeSize" << endl;

   GLint wSize = 150;
   GLfloat aspectRatio;

   if (h == 0)
      h = 1;

   glViewport(0, 0, w, h);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   aspectRatio = (GLfloat)w / (GLfloat)h;

   if (w <= h) // 비율을 h/w라고 정한 상태
      glOrtho(-wSize, wSize, -wSize / aspectRatio, wSize / aspectRatio, -100, 100);
   else
      glOrtho(-wSize * aspectRatio, wSize * aspectRatio, -wSize, wSize, -100, 100);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}


void keyboard(unsigned char key, int x, int y)
{   
   if (key == 'a')
      xTran -= 2.0f;
   else if (key == 'd')
      xTran += 2.0f; 
   else if (key == 'x')
      yTran -= 2.0f; 
   else if (key == 'w')
      yTran += 2.0f;

   glutPostRedisplay();
}

void SpecialKeys(int key, int x, int y)
{
   if (key == GLUT_KEY_UP)
      xRot -= 2.0f;
   if (key == GLUT_KEY_DOWN)
      xRot += 2.0f;
   if (key == GLUT_KEY_LEFT)
      yRot -= 2.0f;
   if (key == GLUT_KEY_RIGHT)
      yRot += 2.0f;

   if (xRot > 360.0f)
      xRot -= 360.0f;
   if (xRot < 0.0f)
      xRot += 360.0f;
   if (yRot > 360.0f)
      yRot -= 360.0f;
   if (yRot < 360.0f)
      yRot += 360.0f;

   glutPostRedisplay();

}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(800, 800);
   glutInitWindowPosition(200, 200);
   //glViewport(0, 0, 500, 500); //내가 그림을 그리는 뷰포트를 500, 500크기로 설정하겠다 (GLint x, GLint y, GLsizei width, GLsizei height)
   glutCreateWindow("simple");

   glutDisplayFunc(RenderScene);
   glutReshapeFunc(ChangeSize);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(SpecialKeys);

   SetupRC();
   glutMainLoop();
}