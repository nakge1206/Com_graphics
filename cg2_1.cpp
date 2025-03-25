/*
간단한 RGB값을 변경하여 다양한 색상으로 초기화되는 창 만들기
*/

#include <GL/freeglut.h>
#include <stdio.h>
#include <iostream>

//장면 렌더링
void RenderScence(void){
    std::cout << "RenderScene" << std::endl;

    //현재 색상을 사용하여 화면을 지운다.
    glClear(GL_COLOR_BUFFER_BIT);

    //드로잉 명령을 전달한다.
    glFlush();
}

void SetupRC(void){
    std::cout << "SetupRC" << std::endl;
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