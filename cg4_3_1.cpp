/*
1초마다 배경색이 r,g,b 바뀌고, 구형이 돌아가게
*/

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

int count=0;
GLfloat GL_PI = 3.14f;
GLfloat angle = 0;

// 장면 렌더링
void RenderScene(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
   glLoadIdentity();
   if(count>2) count = 0;

   if(count==0){
      //배경색
      glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
   }else if(count==1){
      //배경색
      glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
   }else if(count==2){
      //배경색
      glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
   }

   glColor3f(0.0f, 0.0f, 0.0f);
   glTranslatef(10.0f, 0.0f, 0.0f);
   glutSolidSphere(1, 30, 30);

   glRotatef(20.0f*count, 0.0f, 0.0f, 1.0f);
   
   count++;
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