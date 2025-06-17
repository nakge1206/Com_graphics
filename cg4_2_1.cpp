/*
glutSolidSphere(double radius, int slices, int stacks)
반지름, 구의 세로방향 분할 수(경도), 구의 가로방향 분할 수(위도)

구2개
glutSolidSphere(1,30,30)와 동일한 좌표2개이용
glTranslatef() 2번이용

이런 행렬관련은 스택으로 관리됨 
최대로 사용가능한 스택 수는 시스템마다 다르니 참고해야함
*/

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

// 장면 렌더링
void RenderScene(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
   glLoadIdentity();
   
   //x,y,z 축 표시
   GLfloat x, y;
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

   //구 그리기
   glTranslatef(0.0f, 10.0f, 0.0f);
   glutSolidSphere(1, 30, 30);
   glTranslatef(10.0f, -10.0f, 0.0f);
   glutSolidSphere(1, 30, 30);

   //위 방법은 계산하기 쉬워서 해도 되는데, 애매할때는 초기화 시켜서 하는 것도 방법
   // glTranslatef(0.0f, 10.0f, 0.0f);
   // glutSolidSphere(1, 30, 30);
   // glLoadIdentity();
   // glTranslatef(10.0f, 0.0f, 0.0f);
   // glutSolidSphere(1, 30, 30);

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