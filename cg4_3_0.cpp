/*
glutImerFunc(unsigned int millis, void(*func)(int value), int value)
일정시간 간격으로 콜백 함수를 호출할 수 있도록 하는 타이머 함수
애니메이션이나 주기적인 작업을 구현하기 위한 타이머
*/

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

// 장면 렌더링
void RenderScene(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
   glLoadIdentity();
   



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

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void TimerFunction(int value){
   //화면 다시 그리기 요청, glutDisplayFunc에 등록된 함수 실행
   glutPostRedisplay();

   //1초마다 다시 호출
   glutTimerFunc(1000, TimerFunction, 1);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(200, 200);
   glutCreateWindow("Timer Example");

   glutDisplayFunc(RenderScene);
   glutReshapeFunc(ChangeSize);
   SetupRC();

   //처음 타이머 호출
   glutTimerFunc(1000, TimerFunction, 1);
   
   glutMainLoop();
}