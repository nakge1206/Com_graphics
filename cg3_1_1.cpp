/*
(0,0) ~ (50,50) 까지 점 20개 찍기
*/

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

void RenderScene(void) {
	std::cout << "RenderScene" << std::endl;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	
	glPointSize(2.0f); //begin 밖에서 써야함. 안에서 쓰면 적용 안됨
	glBegin(GL_POINTS);
		for(float i=0.0; i<=50.0; i+=2.5){
			glVertex3f(i, i, i);
		}
		//교수님이 작성한 코드는 아래와 같음.
		// for(float t=0.0f; t<=1.0f; t+=0.05f){
		// 	float x = t * 50.0f;
		// 	float y = t * 50.0f;
		// 	float z = t * 50.0f;
		// 	glVertex3f(x, y, z);
		// }
	glEnd();

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
	if(w<=h) glOrtho(-wSize, wSize, -wSize/aspectRatio, wSize/aspectRatio, 1, -50);
	else glOrtho(-wSize*aspectRatio, wSize*aspectRatio, -wSize, wSize, 1, -50);
	
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