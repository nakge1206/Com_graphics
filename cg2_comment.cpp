/*
2주차까지의 실습내용 중 주석을 포함하여 설명해둔 코드임
*/

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

//장면 렌더링
void RenderScene(void) {
	std::cout << "RenderScene" << std::endl;

	//현재 색상을 사용해 화면을 지운다
	glClear(GL_COLOR_BUFFER_BIT);

	//default좌표계 = ModelView = object 좌표계
	//projection 좌표계로 이동(카메라 좌표계)
	glMatrixMode(GL_PROJECTION);
	//좌표계 초기화
	glLoadIdentity();

	//기준 (x,y)에서 얼마만큼의 사이즈(width, height)만큼 도화지로 설정한건지
	glViewport(0, 0, 500, 500);

	//실제 화면에 보이는 이미지의 공간 (Ortho의 사이즈만 이동하여 보이는 화면 조절)
	//glOrtho(1, -1, 1, -1, 1, -1); //역전세계
    //glOrtho(0, 640, 0, 480, 0, -1); //역전세계
	//glOrtho(-10, 10, -10, 10, 1, -1); //신기하노

    //glOrtho(-320, 320, -240, 240, 10000, -10000); //직교투영이기때문에 z값은 아무리 바꿔도 똑같음
    glOrtho(0, 500, 0, 500, 1, -1);
    
	

	//object 좌표계로 다시 이동
	glMatrixMode(GL_MODELVIEW);
	//좌표계 초기화
	glLoadIdentity();

	glColor3f(1.0f, 0.0f, 0.0f);

    //500 -> 250 -> 125
	//왼아래, 오른아래 점. 좌표계 설정이 없다면, 일반적으로 직교 투영으로 [-1,1] 범위 내에서 작동
	glRectf(250, 375, 375, 250);
	//왼 위(x, y), 오른 아래(x, y)


	glFlush(); //gpu, os종류 및 버전에 따라 더블 버퍼를 기본값으로 사용되는 경우가 있을 수 있음 -> GLUTDOUBLE로 바꾸고, glFlush() => glutSwapBuffers() 로 바꾸기
	//glutSwapBuffers();
}

void SetupRC(void) {
	std::cout << "SetupRC" << std::endl;
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	//glutInitWindowPosition(0, 0); //왼쪽 상단
	glutInitWindowPosition(1500, 250);
	glutCreateWindow("simple");
	SetupRC();
	glutDisplayFunc(RenderScene);
	glutMainLoop();
}                                 


/*
viewport: 실제로 그리고자 하는 도화지
(GLint x, GLint y, GLsizei width, GLsizei height)
GLint (0,0)은 왼쪽 맨 아래임.
일반적으로 glutWindowSize와 동일하게 많이들 설정함
projection할 공간의 영역은 viewport 크기에 맞춰서 출력
*/