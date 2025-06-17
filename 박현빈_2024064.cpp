#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define GL_PI 3.14f
GLfloat xTran = 0.0f;
GLfloat yTran = 0.0f;
GLfloat xRot = 0.0f;
GLfloat yRot = 0.0f;
bool A[8] = {0};

void RenderScene(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glEnable(GL_CULL_FACE);
   glLoadIdentity();

   GLfloat x, y, angle;
   int iPivot = 1;
   glBegin(GL_TRIANGLE_FAN);
      glVertex2f(0.0f, 0.0f);
      //(2.0f*3.14)+0.5 = 6.78
      //6.78/8 = 0.8475
      //3.14/4.0 = 0.785
      //0, 0.785, 1.57, 2.355, 3.14. 3.925, 4.71, 5.495, 6.28

      if(A[0]==1&&A[1]==0&&A[2]==0&&A[3]==0&&A[4]==0&&A[5]==0&&A[6]==0&&A[7]==0){
         for(angle = 0.0f; angle < 0.8475; angle += (GL_PI / 4.0f)){
            x = 50.0f * cos(angle);
            y = 50.0f * sin(angle);
            if ((iPivot % 2) == 0)
               glColor3f(0.0f, 1.0f, 0.0f);
            else
               glColor3f(1.0f, 0.0f, 0.0f);
            iPivot++;
            glVertex2f(x, y);
         }
      }
      else if(A[0]==1&&A[1]==1&&A[2]==0&&A[3]==0&&A[4]==0&&A[5]==0&&A[6]==0&&A[7]==0){
         for(angle = 0.0f; angle < 0.8475*2; angle += (GL_PI / 4.0f)){
            x = 50.0f * cos(angle);
            y = 50.0f * sin(angle);
            if ((iPivot % 2) == 0)
               glColor3f(0.0f, 1.0f, 0.0f);
            else
               glColor3f(1.0f, 0.0f, 0.0f);
            iPivot++;
            glVertex2f(x, y);
         }
      }
      else if(A[0]==1&&A[1]==1&&A[2]==1&&A[3]==0&&A[4]==0&&A[5]==0&&A[6]==0&&A[7]==0){
         for(angle = 0.0f; angle < 0.8475*3; angle += (GL_PI / 4.0f)){
            x = 50.0f * cos(angle);
            y = 50.0f * sin(angle);
            if ((iPivot % 2) == 0)
               glColor3f(0.0f, 1.0f, 0.0f);
            else
               glColor3f(1.0f, 0.0f, 0.0f);
            iPivot++;
            glVertex2f(x, y);
         }
      }
      else if(A[0]==1&&A[1]==1&&A[2]==1&&A[3]==1&&A[4]==0&&A[5]==0&&A[6]==0&&A[7]==0){
         for(angle = 0.0f; angle < 0.8475*4; angle += (GL_PI / 4.0f)){
            x = 50.0f * cos(angle);
            y = 50.0f * sin(angle);
            if ((iPivot % 2) == 0)
               glColor3f(0.0f, 1.0f, 0.0f);
            else
               glColor3f(1.0f, 0.0f, 0.0f);
            iPivot++;
            glVertex2f(x, y);
         }
      }
      else if(A[0]==1&&A[1]==1&&A[2]==1&&A[3]==1&&A[4]==1&&A[5]==0&&A[6]==0&&A[7]==0){
         for(angle = 0.0f; angle < 0.8475*5; angle += (GL_PI / 4.0f)){
            x = 50.0f * cos(angle);
            y = 50.0f * sin(angle);
            if ((iPivot % 2) == 0)
               glColor3f(0.0f, 1.0f, 0.0f);
            else
               glColor3f(1.0f, 0.0f, 0.0f);
            iPivot++;
            glVertex2f(x, y);
         }
      }
      else if(A[0]==1&&A[1]==1&&A[2]==1&&A[3]==1&&A[4]==1&&A[5]==1&&A[6]==0&&A[7]==0){
         for(angle = 0.0f; angle < 0.8475*6; angle += (GL_PI / 4.0f)){
            x = 50.0f * cos(angle);
            y = 50.0f * sin(angle);
            if ((iPivot % 2) == 0)
               glColor3f(0.0f, 1.0f, 0.0f);
            else
               glColor3f(1.0f, 0.0f, 0.0f);
            iPivot++;
            glVertex2f(x, y);
         }
      }
      else if(A[0]==1&&A[1]==1&&A[2]==1&&A[3]==1&&A[4]==1&&A[5]==1&&A[6]==1&&A[7]==0){
         for(angle = 0.0f; angle < 0.8475*7; angle += (GL_PI / 4.0f)){
            x = 50.0f * cos(angle);
            y = 50.0f * sin(angle);
            if ((iPivot % 2) == 0)
               glColor3f(0.0f, 1.0f, 0.0f);
            else
               glColor3f(1.0f, 0.0f, 0.0f);
            iPivot++;
            glVertex2f(x, y);
         }
      }
      else if(A[0]==1&&A[1]==1&&A[2]==1&&A[3]==1&&A[4]==1&&A[5]==1&&A[6]==1&&A[7]==1){
         for(angle = 0.0f; angle < 0.8475*8; angle += (GL_PI / 4.0f)){
            x = 50.0f * cos(angle);
            y = 50.0f * sin(angle);
            if ((iPivot % 2) == 0)
               glColor3f(0.0f, 1.0f, 0.0f);
            else
               glColor3f(1.0f, 0.0f, 0.0f);
            iPivot++;
            glVertex2f(x, y);
         }
      }
      
      
   glEnd();

   glFlush();
}

void SetupRC(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glShadeModel(GL_FLAT);
}

void ChangeSize(GLsizei w, GLsizei h)
{
    std::cout << "ChangeSize" << std::endl;

    GLdouble nRange = 100.0f;
    GLdouble aspectRatio;

    if (h == 0)
        h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    aspectRatio = (GLfloat)w / (GLfloat)h;
    if (w <= h)
        glOrtho(-nRange, nRange, -nRange / aspectRatio, nRange / aspectRatio, nRange, -nRange);
    else
        glOrtho(-nRange * aspectRatio, nRange * aspectRatio, -nRange, nRange, nRange, -nRange);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
	printf("key: %c (%d)\n", key, key);
    if( key == '1'){
      if(A[0]==0 && A[1]==0 && A[2]==0 && A[3]==0 && A[4]==0 && A[5]==0 && A[6]==0 && A[7]==0)
         A[0] = 1;
    }
    else if( key == '2'){
      if(A[0]==1 && A[1]==0 && A[2]==0 && A[3]==0 && A[4]==0 && A[5]==0 && A[6]==0 && A[7]==0)
         A[1] = 1;
    }
    else if( key == '3'){
      if(A[0]==1 && A[1]==1 && A[2]==0 && A[3]==0 && A[4]==0 && A[5]==0 && A[6]==0 && A[7]==0)
         A[2] = 1;
    }
    else if( key == '4'){
      if(A[0]==1 && A[1]==1 && A[2]==1 && A[3]==0 && A[4]==0 && A[5]==0 && A[6]==0 && A[7]==0)
         A[3] = 1;
    }
    else if( key == '5'){
      if(A[0]==1 && A[1]==1 && A[2]==1 && A[3]==1 && A[4]==0 && A[5]==0 && A[6]==0 && A[7]==0)
         A[4] = 1;
    }
    else if( key == '6'){
      if(A[0]==1 && A[1]==1 && A[2]==1 && A[3]==1 && A[4]==1 && A[5]==0 && A[6]==0 && A[7]==0)
         A[5] = 1;
    }
    else if( key == '7'){
      if(A[0]==1 && A[1]==1 && A[2]==1 && A[3]==1 && A[4]==1 && A[5]==1 && A[6]==0 && A[7]==0)
         A[6] = 1;
    }
    else if( key == '8'){
      if(A[0]==1 && A[1]==1 && A[2]==1 && A[3]==1 && A[4]==1 && A[5]==1 && A[6]==1 && A[7]==0)
         A[7] = 1;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(400, 200);
    glViewport(0, 0, 500, 500);
    glutCreateWindow("simple");

    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutKeyboardFunc(keyboard);

    SetupRC();
    glutMainLoop();
}