/*
rect예제. 사각형 도형 그리기
fixed - glutInitWindowSize(640, 480)
      - glViewport(0, 0, 640, 480)
      - glRectf(0, 240, 320, 0)
에서 glOrtho()를 수정하여 원하는 이미지 생성하기.

(원래 오른쪽 위에 뜨는 빨간색 도형을 왼쪽 맨 아래로 옮기기)
*/


#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

void RenderScene(void) {
	std::cout << "RenderScene" << std::endl;
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, 640, 480);
	glOrtho(0, 640, 0, 480, 0, -1);
	/*
	보통 Ortho의 기본값은 glOrtho(-1, 1, -1, 1, 1, -1); 이렇게 되어있음.
	근데 지금 Window랑 ViewPort는 640*480 임. 그래서 그냥 도형이 짤려서 보이는거라
	glOrtho(1, -1, 1, -1, 1, -1); 이렇게 해도 맞게 한 것 처럼 보이긴하나, 눈속임에 불과함.
	*/

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(0, 240, 320, 0);

	glFlush();
}

void SetupRC(void) {
	std::cout << "SetupRC" << std::endl;
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(640, 480);
	glutInitWindowPosition(1500, 250);
	glutCreateWindow("simple");

	SetupRC();
	glutDisplayFunc(RenderScene);

	glutMainLoop();
}