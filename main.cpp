
/* THIS IS A SIMPLE NEPAL FLAG CODE WHICH I CREATED IN OPENGL.
YOU CAN USE IT FOR REFERENCE PURPOSE. COPYING CODE WON'T GET YOU NOWEHERE. TRY TO UNDERSTAND THIS
                       -SWODESH SHARMA
                        github : swodesh-2001
*/


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#define PI 3.14

using namespace std;

float x(0);
void create_sqaure(float point[4][3],float ,float ,float ,float );
void create_nepal_flag();
void display();
void reshape(int,int);


void init(){
glClearColor(0,0,0,1.0);
glEnable(GL_DEPTH_TEST);

}

void timer(int);


int main(int argc , char**argv){
glutInit(&argc , argv);

glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
glutInitWindowPosition(500,250);
glutInitWindowSize(500,500);

glutCreateWindow("First window");


glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutTimerFunc(0,timer,0);
init();
glutMainLoop();


}


void reshape(int w,int h){
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(60,1,1,50); // perspective mode ma chalako euta pyramid ko top katesi frustam banxa ni , top chai hamro screen ani pyramid ko bhtra ko sabai dekhinxa

glMatrixMode(GL_MODELVIEW);

}


void display()
{


glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
//draw

x += 1;
if (x>=1000){
    x=0;
}


glTranslatef(-0.2,-0.2,-2);
glRotatef(x,0,1,0);
create_nepal_flag();
glutSwapBuffers();

}



void timer(int ){
glutPostRedisplay();

glutTimerFunc(1000/60.,timer,0);
}


void create_sqaure(float point[4][3],float depth=1 , float r=1.0,float g=0 ,float b=0){

float x1(point[0][0]),y1(point[0][1]),z1(point[0][2]);
float x2(point[1][0]),y2(point[1][1]),z2(point[1][2]);
float x3(point[2][0]),y3(point[2][1]),z3(point[2][2]);
float x4(point[3][0]),y4(point[3][1]),z4(point[3][2]);

glBegin(GL_QUADS);
//front face coordinates
    glColor3f(r,g,b);

    glVertex3f(x1,y1,z1);
    glVertex3f(x2,y2,z2);
    glVertex3f(x3,y3,z3);
    glVertex3f(x4,y4,z4);

    glColor3f(r,g,b);
    glVertex3f(x4,y4,z4 - depth);
    glVertex3f(x3,y3,z3 - depth);
    glVertex3f(x2,y2,z2 - depth);
    glVertex3f(x1,y1,z1 - depth);
    //right
    glColor3f(0.0,0.0,1.0);
    glVertex3f(x4,y4,z4);
    glVertex3f(x3,y3,z3);
    glVertex3f(x3,y3,z3 - depth);
    glVertex3f(x4,y4,z4 - depth);
    //left
    glColor3f(0.0,0.0,1.0);
    glVertex3f(x1,y1,z1 - depth);
    glVertex3f(x2,y2,z2 - depth);
    glVertex3f(x2,y2,z2);
    glVertex3f(x1,y1,z1);
    //top
    glColor3f(0.0,0.0,1.0);
    glVertex3f(x1,y1,z1 - depth);
    glVertex3f(x1,y1,z1);
    glVertex3f(x4,y4,z4);
    glVertex3f(x4,y4,z4 - depth);
    //bottom
    glColor3f(0.0,0.0,1.0);
    glVertex3f(x2,y2,z2 - depth);
    glVertex3f(x2,y2,z2);
    glVertex3f(x3,y3,z3);
    glVertex3f(x3,y3,z3 - depth);

glEnd();
}




void create_nepal_flag(){

float cube1[4][3] = {
   { -0.07,-0.4,0},
   { 0.01,-0.4,0},
   { 0.01,1,0 },
   { -0.07,1,0 }
};

float cube2[4][3] = {
   { 0.01,0.2,0},
   { 0.7,0.2,0},
   { 0.2,0.7,0 },
   { 0.01,0.7,0 }
};

float cube3[4][3] = {
   { 0.01,0.7,0},
   { 0.2,0.7,0},
   { 0.5,0.7,0 },
   { 0.01,1,0 }
};


float j(0.15),k(0.4);
float s(0.05); //size
float f(1.4);  //factor

float cube4[4][3] = {
   { j-s,k-s,0.01},
   { j+s,k-s,0.01},
   { j+s,k+s,0.01 },
   { j-s,k+s,0.01 }
};

float cube5[4][3] = {
   { j-f*s,k,0.01},
   { j,k-f*s,0.01},
   { j+f*s,k,0.01 },
   { j,k+f*s,0.01 }
};


k = 0.8;
s= 0.035;
f = 1.4;

float cube6[4][3] = {
   { j-s,k-s,0.01},
   { j+s,k-s,0.01},
   { j+s,k+s,0.01 },
   { j-s,k+s,0.01 }
};

float cube7[4][3] = {
   { j-f*s,k,0.01},
   { j,k-f*s,0.01},
   { j+f*s,k,0.01 },
   { j,k+f*s,0.01 }
};


float cube8[4][3] = {
   { j-1.5*f*s,k,0.01},
   { j-f*s,k-f*s,0.01},
   { j+f*s,k-f*s,0.01 },
   { j+1.5*f*s,k,0.01 }
};


create_sqaure(cube1,0.1,0,0.5,1);
create_sqaure(cube2,0.1);
create_sqaure(cube3,0.1);

create_sqaure(cube4,0.12,1,1,1);
create_sqaure(cube5,0.12,1,1,1);


create_sqaure(cube6,0.12,1,1,1);
create_sqaure(cube7,0.12,1,1,1);
create_sqaure(cube8,0.12,1,1,1);

}
