/*
이제 깊이(Depth)도 고려함
glClear에 GL_DEPTH_BUFFER_BIT 추가
glFlush() 대신 glutSwapBuffers로 변경
initDisplayMode에서 SINGLE 대신 DOUBLE로 변경하고, DEPTH 추가
*/

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

#define GL_PI 3.1415f
#define s_size  2.0f
GLfloat  xTran = 0.0f;
GLfloat  yTran = 0.0f;

GLfloat  xRot = 0.0f;
GLfloat  yRot = 0.0f;

// 장면 렌더링
void RenderScene(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glEnable(GL_CULL_FACE);
   glEnable(GL_DEPTH_TEST);
   glLoadIdentity();
   gluLookAt(0.0f, 0.0f, 0.0f, //카메라 위치(eye position)
            0.0f, 0.0f, -1.0f, //바라볼 목표 지점(look-at point)
            0.0f, 1.0f, 0.0f); //카메라 상향 벡터(up direction) - 보통(0, 1, 0) 사용
   
   glPushMatrix();
   glRotatef(xRot, 1.0f, 0.0f, 0.0f);
   glRotatef(yRot, 0.0f, 1.0f, 0.0f);
   glTranslatef(xTran, yTran, 0.0f);

   GLfloat x, y, angle;
   glBegin(GL_TRIANGLE_FAN);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(0, 0, 10.0f);
      for (angle = 0.0f; angle < (2.0f * GL_PI)+0.5; angle += ( GL_PI / 8.0)) {
         x = 50.0f * sin(angle);
         y = 50.0f * cos(angle);
         glVertex3f(x, y, 10.0f);
      }
   glEnd();

   glBegin(GL_TRIANGLE_FAN);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(0, 0, 20.0f);
      for (angle = 0.0f; angle < (2.0f * GL_PI)+0.5; angle += ( GL_PI / 8.0)) {
         x = 20.0f * sin(angle);
         y = 20.0f * cos(angle);
         glVertex3f(x, y, 20.0f);
      }
   glEnd();

   glPopMatrix();
   glutSwapBuffers();
}

void SetupRC(void)
{
   std::cout << "SetupRC" << std::endl;
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
   glShadeModel(GL_FLAT);
}

void ChangeSize(GLsizei w, GLsizei h) {
   std::cout << "w = " << w << " " << "h =" << h;
   std::cout << "ChangeSize" << std::endl;

   GLint wSize = 100;
   GLfloat aspectRatio;

   if (h == 0)
      h = 1;

   glViewport(0, 0, w, h);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   aspectRatio = (GLfloat)w / (GLfloat)h;
   
   if (w <= h) // 비율을 h/w라고 정한 상태
      glOrtho(-wSize, wSize, -wSize / aspectRatio, wSize / aspectRatio, 100, -100);
   else
      glOrtho(-wSize * aspectRatio, wSize * aspectRatio, -wSize, wSize, 100, -100);
   //Ortho에서 near, far는 near값은 far보다 작아야 상식선의 해석이 가능함. 근데 near가 더 크다면
   //z축이 뒤집혀서 가까이 있는 도형이 멀리 출력됨

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}
/*
opneGL에서는 카메라 위치를 옮겨도 찐 카메라를 옮기는 거말고 도형을 반대로 옮겨서 같은 효과를 내도록 계산한다고 함
*/

void keyboard(unsigned char key, int x, int y) {   
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

void SpecialKeys(int key, int x, int y) {
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
   if (yRot < 0.0f)
      yRot += 360.0f;

   glutPostRedisplay();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(500, 500);
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