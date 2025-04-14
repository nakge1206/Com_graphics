#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

#include <cstdlib> //랜덤

#define GL_PI 3.1415f

void RenderScene(void) {
	std::cout << "RenderScene" << std::endl;

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 0.0f, 0.0f);
	
	glPushMatrix();
	glRotatef(45, 1.0f, 0.0f, 0.0f);
	glRotatef(45, 0.0f, 1.0f, 0.0f);
	

	GLfloat x, y, z, angle;
	bool isFirst = true;
	
	GLfloat sizes[2];
	GLfloat step = 0.1;
	glGetFloatv(GL_POINT_SIZE_RANGE, sizes);
	GLfloat curSize = sizes[0];
	GLfloat maxSize = sizes[1];

	GLfloat r, g, b;
	r = 0.0f; g = 0.0f; b = 0.0f;

	z = -50.0f;
	for(angle = 0.0f; angle <= (2.0f * GL_PI) * 3.0f; angle += 0.1f){ //3바퀴 돌리는거
		if(isFirst){ //맨 처음 점이라면 흰색점으로 표시
			glColor3f(1.0f, 1.0f, 1.0f); 
			isFirst = false;
		} else glColor3f(1.0f, 0.0f, 0.0f);
		x = 50.0f * cos(angle);
		y = 50.0f * sin(angle);

		// r = (sin(angle * 0.3f) + 1.0f) / 2.0f;
		// g = (sin(angle * 0.5f + 1.0f) + 1.0f) / 2.0f;
		// b = (sin(angle * 0.7f + 2.0f) + 1.0f) / 2.0f;
		r = static_cast<float>(rand()) / RAND_MAX;
		g = static_cast<float>(rand()) / RAND_MAX;
		b = static_cast<float>(rand()) / RAND_MAX;
		
		glColor3f(r, g, b);
		glBegin(GL_POINTS);
			glVertex3f(x, y, z);
		glEnd();
		z += 0.5f;
		if(curSize < maxSize) curSize += step;
		std::cout<< curSize << std::endl;
		glPointSize(curSize);
	}

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