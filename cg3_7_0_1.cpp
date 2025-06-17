/*
폴리곤 이용해서 fan(부채꼴 모양으로 연결된 삼각형들) 만들기
후면제거
카메라 방향, CCW를 고려해야함
CCW(반시계)가 정면임
카메라는 항상 +z에서 -z를 보고 있다는게 기준이 됨.
*/

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

#define GL_PI 3.1415f

bool bCull = false;

void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	if(bCull) glEnable(GL_CULL_FACE); //후면 제거기능 활성화
	else glDisable(GL_CULL_FACE);

	GLfloat angle;
	GLfloat x, y, z;

	int count = 1;
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0, 0, 0);
		// z = 0;
		for(angle = 0.0f; angle < (2.0f * GL_PI); angle += (GL_PI / 8.0f)){
			//CW
			x = 50.0f * sin(angle);
			y = 50.0f * cos(angle);
			//CCW
			// x = 50.0f * cos(angle);
			// y = 50.0f * sin(angle);
			if(count%2==0) glColor3f(0.0f, 1.0f, 0.0f);
			else glColor3f(1.0f, 0.0f, 0.0f);
			count ++;
			glVertex3f(x, y, z);
		}
	glEnd();

	// glPointSize(7);
	// glBegin(GL_POINTS);
	// 	glColor3f(1.0f, 0.0f, 0.0f);
	// 	z = 0;
	// 	for(angle = 0.0f; angle <= (2.0f * GL_PI); angle += (2.0f * GL_PI)/16){ //3바퀴 돌리는거
	// 		x = 50.0f * cos(angle);
	// 		y = 50.0f * sin(angle);
	// 		glVertex3f(x, y, z);
	// 	}
	// glEnd();

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
	glShadeModel(GL_FLAT);
	// glShadeModel(GL_SMOOTH);
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