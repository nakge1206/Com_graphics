/*
fixed - glutInitWindowSize(500, 500)
	  - glRectf(-0.25f, 0.25f, 0.25f, -0.25f)
      - glOrtho(-1, 1, -1, 1, 1, -1)
에서 glViewport()를 수정하여 원하는 이미지 생성하기.

총 창의 크기가 가로가 2w, 세로가 h일때 / 도형이 (w/2,중앙)에 생성되게
*/

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

void RenderScene(void) {
	std::cout << "RenderScene" << std::endl;

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//도화지의 크기를 압축시키면 됨. width를 반토막시키면 됨.
	//기존(0, 0, 500, 500)이 (0,0)에서 (500, 500)만큼의 도화지를 쓰는데, 그걸 반토막내서 압축한거임.
	glViewport(0, 0, 250, 500);
	
	//다양하게 실습 해본 내용들.
	//glViewport(0, 0, 250, 250); //3사분면에 위치
	//glViewport(0, 250, 250, 250); //2사분면에 위치
	

    glOrtho(-1, 1, -1, 1, 1, -1);
    
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(-0.25f, 0.25f, 0.25f, -0.25f);

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