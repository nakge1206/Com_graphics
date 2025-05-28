/*
폴리곤 그리기 1
*/

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>



void RenderScene(void) {
	std::cout << "RenderScene" << std::endl;

	glClear(GL_COLOR_BUFFER_BIT);

	// glPushMatrix();
	// glRotatef(45, 1.0f, 0.0f, 0.0f);
	// glRotatef(45, 0.0f, 1.0f, 0.0f);

	glBegin(GL_TRIANGLE_STRIP); //r
		glColor3f(1.0f, 0.0f, 0.0f);

		glVertex2f(0.0f, 0.0f);
		glVertex2f(25.0f, 25.0f);
		glVertex2f(50.0f, 0.0f);
		glVertex2f(0.0f, 50.0f);
		glVertex2f(50.0f, 100.0f);
		

		
	glEnd();

	// glPopMatrix();
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
	if(w<=h) glOrtho(-wSize, wSize, -wSize/aspectRatio, wSize/aspectRatio, -500, 500);
	else glOrtho(-wSize*aspectRatio, wSize*aspectRatio, -wSize, wSize, -500, 500);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void SetupRC(void) {
	std::cout << "SetupRC" << std::endl;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	// glShadeModel(GL_FLAT);
	glShadeModel(GL_SMOOTH);
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