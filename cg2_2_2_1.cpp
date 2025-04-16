/*
fixed - glutInitWindowSize(500, 500)
      - glViewport(0, 0, 500, 500)
      - glOrtho(0, 500, 0, 500, 1, -1)
에서 glRectf()를 수정하여 원하는 이미지 생성하기.

창의 1/4 만큼의 사이즈의 도형이 창을 보고있는 기준으로 (0,0)에서부터 오른쪽 위에 위치하게 함.
*/

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

void RenderScene(void) {
	std::cout << "RenderScene" << std::endl;
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, 500, 500);
    glOrtho(0, 500, 0, 500, 1, -1);
    
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(250, 375, 375, 250);
	/*
	Ortho가 (0,500,0,500) 이니까 정 가운데는 (250,250)임
	500의 1/4는 125 => (250, 375), (375,250)
	*/


	glFlush();
}

void SetupRC(void) {
	std::cout << "SetupRC" << std::endl;
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(1500, 250);
	glutCreateWindow("simple");

	SetupRC();
	glutDisplayFunc(RenderScene);

	glutMainLoop();
}                                 