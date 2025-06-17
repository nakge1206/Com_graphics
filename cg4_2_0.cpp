/*
glWireCube(10.0f)
원점을 중심으로 하여 10크기만듬 변 길이를 가지는 육면체 생성

y축 10이동, 45도 꺽은
*/

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

// 장면 렌더링
void RenderScene(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
   glLoadIdentity();
   // glPushMatrix();
   glTranslatef(0.0f, 0.0f, -30.0f); //뒤로 조금 이동
   glRotatef(30.0f, 1.0f, 0.0f, 0.0f); //x축으로 30도 회전
   glRotatef(-30.0f, 0.0f, 1.0f, 0.0f); //y축으로 -30도 회정
   
   //x, y, z 축 표시
   GLfloat x, y, angle;
   glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f); //r
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(30.0f, 0.0f, 0.0f);

		glColor3f(0.0f, 1.0f, 0.0f); //g
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 30.0f, 0.0f);

		glColor3f(0.0f, 0.0f, 1.0f); //b
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 30.0f);
	glEnd();

   //정육면체 그리기
   glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x00ff);
   glColor3f(0.0f, 0.0f, 1.0f);
   glutWireCube(10.0f);
   glDisable(GL_LINE_STIPPLE);

   glTranslatef(0.0f, 20.0f, 0.0f);
   glColor3f(1.0f, 0.0f, 0.0f);
   glutWireCube(10.0f);

   // glPopMatrix();
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

   GLint wSize = 50;
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
   //Ortho에서 near, far는 near값은 far보다 작아야 상식선의 해석이 가능함. 근데 near가 더 크다면
   //z축이 뒤집혀서 가까이 있는 도형이 멀리 출력됨

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(200, 200);
   glutCreateWindow("simple");

   glutDisplayFunc(RenderScene);
   glutReshapeFunc(ChangeSize);

   SetupRC();
   glutMainLoop();
}