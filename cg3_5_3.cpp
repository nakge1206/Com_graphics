/*
정육면체 만들기
*/

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

// void RenderScene(void) {
// //정육면체 1개
// 	std::cout << "RenderScene" << std::endl;

// 	glClear(GL_COLOR_BUFFER_BIT);

// 	glPushMatrix();
// 	glRotatef(45, 1.0f, 0.0f, 0.0f);
// 	glRotatef(45, 0.0f, 1.0f, 0.0f);



// 	glBegin(GL_LINES); //r
// 		glColor3f(1.0f, 0.0f, 0.0f); //r

// 		glVertex3f(0.0f, 0.0f, 0.0f);
// 		glVertex3f(50.0f, 0.0f, 0.0f);
// 		glVertex3f(0.0f, 0.0f, 0.0f);
// 		glVertex3f(0.0f, 0.0f, -50.0f);
// 		glVertex3f(0.0f, 0.0f, 0.0f);
// 		glVertex3f(0.0f, -50.0f, 0.0f);

// 		glVertex3f(0.0f, -50.0f, 0.0f);
// 		glVertex3f(50.0f, -50.0f, 0.0f);
// 		glVertex3f(0.0f, -50.0f, 0.0f);
// 		glVertex3f(0.0f, -50.0f, -50.0f);

// 		glVertex3f(50.0f, -50.0f, 0.0f);
// 		glVertex3f(50.0f, 0.0f, 0.0f);

// 		glVertex3f(0.0f, 0.0f, -50.0f);
// 		glVertex3f(0.0f, -50.0f, -50.0f);

// 		glVertex3f(50.0f, 0.0f, -50.0f);
// 		glVertex3f(50.0f, 0.0f, 0.0f);
// 		glVertex3f(50.0f, 0.0f, -50.0f);
// 		glVertex3f(0.0f, 0.0f, -50.0f);
// 	glEnd();
	
// 	glEnable(GL_LINE_STIPPLE);
// 	GLint factor = 5;
// 	GLushort pattern = 0x5555;
// 	glLineStipple(factor, pattern);
// 	glBegin(GL_LINES);
// 		glVertex3f(50.0f, -50.0f, -50.0f);
// 		glVertex3f(0.0f, -50.0f, -50.0f);
		
// 		glVertex3f(50.0f, -50.0f, -50.0f);
// 		glVertex3f(50.0f, -50.0f, 0.0f);

// 		glVertex3f(50.0f, -50.0f, -50.0f);
// 		glVertex3f(50.0f, 0.0f, -50.0f);
// 	glEnd();


// 	glPopMatrix();
// 	glFlush();
// }

void RenderScene(void) {
	// 정육면체 3개
	std::cout << "RenderScene" << std::endl;

	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glRotatef(45, 1.0f, 0.0f, 0.0f);
	glRotatef(45, 0.0f, 1.0f, 0.0f);



	glBegin(GL_LINES); //r
		glColor3f(1.0f, 0.0f, 0.0f); //r

		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(50.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, -50.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, -50.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-50.0f, 0.0f, 0.0f);

		glVertex3f(0.0f, -50.0f, 0.0f);
		glVertex3f(50.0f, -50.0f, 0.0f);
		glVertex3f(0.0f, -50.0f, 0.0f);
		glVertex3f(-50.0f, -50.0f, 0.0f);

		glVertex3f(-50.0f, -50.0f, -50.0f);
		glVertex3f(-50.0f, 0.0f, -50.0f);
		glVertex3f(-50.0f, -50.0f, -50.0f);
		glVertex3f(-50.0f, -50.0f, 0.0f);

		glVertex3f(-50.0f, 0.0f, 0.0f);
		glVertex3f(-50.0f, -50.0f, 0.0f);

		glVertex3f(-50.0f, 0.0f, -50.0f);
		glVertex3f(-50.0f, 0.0f, 0.0f);
		glVertex3f(-50.0f, 0.0f, -50.0f);
		glVertex3f(0.0f, 0.0f, -50.0f);
		

		glVertex3f(50.0f, -50.0f, 0.0f);
		glVertex3f(50.0f, 0.0f, 0.0f);
		glVertex3f(50.0f, -50.0f, 0.0f);
		glVertex3f(100.0f, -50.0f, 0.0f);

		

		glVertex3f(50.0f, 0.0f, -50.0f);
		glVertex3f(50.0f, 0.0f, 0.0f);
		glVertex3f(50.0f, 0.0f, -50.0f);
		glVertex3f(0.0f, 0.0f, -50.0f);
		glVertex3f(50.0f, 0.0f, -50.0f);
		glVertex3f(100.0f, 0.0f, -50.0f);

		glVertex3f(100.0f, 0.0f, 0.0f);
		glVertex3f(50.0f, 0.0f, 0.0f);
		glVertex3f(100.0f, 0.0f, 0.0f);
		glVertex3f(100.0f, -50.0f, 0.0f);
		glVertex3f(100.0f, 0.0f, 0.0f);
		glVertex3f(100.0f, 0.0f, -50.0f);
		
	glEnd();
	
	glEnable(GL_LINE_STIPPLE);
	GLint factor = 5;
	GLushort pattern = 0x5555;
	glLineStipple(factor, pattern);
	glBegin(GL_LINES);
		

		glVertex3f(0.0f, 0.0f, -50.0f);
		glVertex3f(0.0f, -50.0f, -50.0f);

		
		
		glVertex3f(50.0f, -50.0f, -50.0f);
		glVertex3f(50.0f, -50.0f, 0.0f);

		glVertex3f(50.0f, -50.0f, -50.0f);
		glVertex3f(50.0f, 0.0f, -50.0f);

		glVertex3f(-50.0f, -50.0f, -50.0f);
		//glVertex3f(0.0f, -50.0f, -50.0f);
		// glVertex3f(50.0f, -50.0f, -50.0f);
		// glVertex3f(0.0f, -50.0f, -50.0f);
		// glVertex3f(0.0f, -50.0f, 0.0f);
		glVertex3f(100.0f, -50.0f, -50.0f);

		glVertex3f(100.0f, 0.0f, -50.0f);
		glVertex3f(100.0f, -50.0f, -50.0f);
		

		// glVertex3f(100.0f, -50.0f, -50.0f);
		// glVertex3f(50.0f, -50.0f, -50.0f);

		glVertex3f(100.0f, -50.0f, -50.0f);
		glVertex3f(100.0f, -50.0f, 0.0f);

		glVertex3f(0.0f, -50.0f, -50.0f);
		glVertex3f(0.0f, -50.0f, 0.0f);
		

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

	GLint wSize = 150;
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