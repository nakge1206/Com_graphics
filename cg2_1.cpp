/*
간단한 RGB값을 변경하여 다양한 색상으로 초기화되는 창 만들기
*/

#include <GL/freeglut.h>
#include <stdio.h>
#include <iostream>

void RenderScence(void){
    std::cout << "RenderScene" << std::endl;
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void SetupRC(void){
    std::cout << "SetupRC" << std::endl;
    //여기 있는 RGBA를 조정하면 설정한 색상으로 창이 초기화됨.
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("simple");

    SetupRC();
    glutDisplayFunc(RenderScence);

    glutMainLoop();
}