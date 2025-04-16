/*
z축에 따라 원을 3번 그리는 예제
원 대신 rect으로 만드는거.
*/

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

#define GL_PI 3.1415f

void RenderScene(void) {
	std::cout << "RenderScene" << std::endl;

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 0.0f, 0.0f);
	
	glPushMatrix();
	glRotatef(45, 1.0f, 0.0f, 0.0f);
	glRotatef(45, 0.0f, 1.0f, 0.0f);
	

	GLfloat x, y, z, angle;
	GLfloat rectSize = 1.5f;
	
	GLfloat r, g, b;

	glBegin(GL_POINTS);
		z = -50.0f;
		for(angle = 0.0f; angle <= (2.0f * GL_PI) * 3.0f; angle += 0.1f){ //3바퀴 돌리는거
			x = 50.0f * cos(angle);
			y = 50.0f * sin(angle);

			r = (rand()%100) / 99.0f; //%100은 해도되고, 안해도 되고
			g = (rand()%100) / 99.0f;
			b = (rand()%100) / 99.0f;
			glColor3f(r, g, b);

			for(GLfloat i = 0.00f; i <= rectSize; i+=0.01){
				glVertex3f(x+rectSize, y+i, z);
				glVertex3f(x+rectSize, y-i, z);
				glVertex3f(x-rectSize, y+i, z);
				glVertex3f(x-rectSize, y-i, z);
				glVertex3f(x+i, y+rectSize, z);
				glVertex3f(x-i, y+rectSize, z);
				glVertex3f(x+i, y-rectSize, z);
				glVertex3f(x-i, y-rectSize, z);
			}
			// for(float i= - rectSize; i <= rectSize; i+=0.2){
			// 	glVertex3f(x+rectSize, y+i,z);
			// 	glVertex3f(x-rectSize, y+i,z);
			// 	glVertex3f(x+i, y+rectSize,z);
			// 	glVertex3f(x+i, y-rectSize,z);
			// }
			z += 0.5f;
		}
	glEnd();

	glPopMatrix();

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