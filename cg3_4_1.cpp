/*
가로, 세로로 굵기가 다른 선을 여러개 긋는 예제
*/

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

void RenderScene(void) {
	std::cout << "RenderScene" << std::endl;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);

	GLfloat sizes[2];
	GLfloat step;
	GLfloat curSize = 1.0f;

	glGetFloatv(GL_LINE_WIDTH_RANGE, sizes);
	//glGetFloatv(GL_LINE_WIDTH_GRANULARITY, &step);
	step = 2.0f;

	for(int i=-90; i<=90; i+=20){
		glLineWidth(curSize);
		glBegin(GL_LINES);
			glVertex3f(80, i, 0);
			glVertex3f(-80, i, 0);
		glEnd();
		curSize += step;
	}

	// for(int i=-3; i<=3; i++){
	// 	glLineWidth(curSize);
	// 	glBegin(GL_LINES);
	// 		glVertex3f(i*20, 80, 0);
	// 		glVertex3f(i*20, -80, 0);
	// 	glEnd();
	// 	curSize += step;
	// }
	
	glFlush();
}

void ChangeSize(GLsizei w, GLsizei h){
	std::cout << "w = " << w << " " << "h = " << h << std::endl;
	std::cout << "ChangeSize" << std::endl;

	if(h==0) h = 1;
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLint wSize = 100;
	GLfloat aspectRatio;
	aspectRatio = (GLfloat)w / (GLfloat)h;
	if(w<=h) glOrtho(-wSize, wSize, -wSize/aspectRatio, wSize/aspectRatio, -100, 100);
	else glOrtho(-wSize*aspectRatio, wSize*aspectRatio, -wSize, wSize, -100, 100);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void SetupRC(void) {
	std::cout << "SetupRC" << std::endl;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(400, 200);
	glutCreateWindow("simple");

	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);

	SetupRC();
	glutMainLoop();
}