/*
지오메트리(Geometry)
기하학
공간에 존재하는 point, line, plan, surface, angle, 이동, 등등 모든 것들을 말함

카메라 좌표 = eye coordinate(시각 좌표)
공간영역(ortho, perspective)설정 내에 있는 모든 도형은 렌더링한다는게 opengl의 기본임

관측 변환 = viewing transformation

modeling transformation
시점을 움직이는거나, 모델을 움직이는거나 같은 현상임 (카메라 방향의 반대로 물체를 움직이면 같은 효과가 있으므로)
translation, rotation, scaling 이렇게 3가지가 크게 3가지
rotation이랑 translation은 순서에 따라 살짝쿵 다름
회전 후 이동하면, 회전된 축에 따라 이동하게됨
이동 후 회전하면, 이동된 자리에서 축이 회전하게 됨
-> 결과가 달라짐

지오메트리 변환
1. 모델뷰 변환(modelview transformaion)
모델뷰(modelview) = 관측(viewing) + 모델링(modeling)
두 변환의 효과가 같음로 합해서 모댈뷰라고 함

2. 투영변환(projection transformation)
직교투영, 원근투영

3. 뷰포트 변환
색상버퍼와 창의 픽셀간의 1:1대응이 일반적이지만, 특정한 경우 변경이 이루어지기더 함
특별한 경우(고해상도디스플레이, 안티애일리어싱 등등)

변환 파이프라인
버텍스 데이터->ㅂ모델뷰행렬->변환된 시각좌표->투영행렬->클립좌표->원근분할->정규화된 장치 좌표-< 뷰포트 변환 -> 창좌표

이러한 것들은 행렬 연산을 통해서 이루어짐(두 행렬의 곱)

동차좌표(Homogeneous coordinates)
기하학적인 변화느 특히 이동)(translation)까지 행렬 곱으로 표현할 수 있게 해주는 좌표 표현 방식

일반적으로는 데카르트좌표계 사용( 2d:(x,y) , 3d(x,y,z))
여기서는 homo...로 사용함
2d(x,y->x,y,1)
3d(x,y,z -> x,y,z,1)
마지막 원소 w는 스케일 계수임 동차좌표(x,y,w)는 실제좌표(x/w, y/w)를 의미
데카르트에서는 이동에서는 벡터를 합연산을 이용함 (확대, 회전은 곱연산임)
호모지니어스에서는 이동을 곱연산으로 할 수 있음 (모두 곱연산만 사용하므로 계산이 단순화됨)
opengl에서도 호모지니어스좌표계를 사용함
모델뷰 행렬에서도 4x4행렬로 구성됨(마지막w는 보통1로 되고 보통의 경우에는 고려및사용 안하긴함)

point와 vertex의 차이는 정보의 차이
point는 위치의 값만 나타내지만, vertex는 색상이나, 좌표, 법선, 텍스처등 다양한 속성이 존재하므로 다른거임(위치+그래픽정보)

4_1_a code의 변환을 배워보기로~
코드상으로는 3_5_2 코드랑 매우 비슷

*/

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

// 장면 렌더링
void RenderScene(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glColor3f(0.0f, 0.0f, 0.0f);

   glPushMatrix();
   glTranslatef(0.0f, 0.0f, -30.0f); //뒤로 조금 이동
   glRotatef(30.0f, 1.0f, 0.0f, 0.0f); //x축으로 30도 회전
   glRotatef(-30.0f, 0.0f, 1.0f, 0.0f); //y축으로 -30도 회정
   

   GLfloat x, y, angle;
   glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f); //r
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(80.0f, 0.0f, 0.0f);

		glVertex3f(80.0f, 0.0f, 0.0f);
		glVertex3f(75.0f, 5.0f, 0.0f);

		glVertex3f(80.0f, 0.0f, 0.0f);
		glVertex3f(75.0f, -5.0f, 0.0f);

		glColor3f(0.0f, 1.0f, 0.0f); //g
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 80.0f, 0.0f);

		glVertex3f(0.0f, 80.0f, 0.0f);
		glVertex3f(5.0f, 75.0f, 0.0f);

		glVertex3f(0.0f, 80.0f, 0.0f);
		glVertex3f(-5.0f, 75.0f, 0.0f);

		glColor3f(0.0f, 0.0f, 1.0f); //b
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 80.0f);

		glVertex3f(0.0f, 0.0f, 80.0f);
		glVertex3f(5.0f, 0.0f, 75.0f);

		glVertex3f(0.0f, 0.0f, 80.0f);
		glVertex3f(-5.0f, 0.0f, 75.0f);
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
      glOrtho(-wSize, wSize, -wSize / aspectRatio, wSize / aspectRatio, -100, 100);
   else
      glOrtho(-wSize * aspectRatio, wSize * aspectRatio, -wSize, wSize, -100, 100);
   //Ortho에서 near, far는 near값은 far보다 작아야 상식선의 해석이 가능함. 근데 near가 더 크다면
   //z축이 뒤집혀서 가까이 있는 도형이 멀리 출력됨

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}
/*
opneGL에서는 카메라 위치를 옮겨도 찐 카메라를 옮기는 거말고 도형을 반대로 옮겨서 같은 효과를 내도록 계산한다고 함
*/

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