t#include<stdio.h>
#include<GL/glut.h>
#include <math.h>

void drawRect(float x[4][4]);
void loop();
int main (int argc, char**argv)
{
   int windowWidth = 640;
   int windowHeight = 480;
   glutInit(&argc, argv);
   glutInitWindowSize(windowWidth, windowHeight);
   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
   glutCreateWindow("Basic OpenGL Example");
   glutIdleFunc(loop);

   glViewport( 0, 0, windowWidth, windowHeight );
   glMatrixMode( GL_PROJECTION );
   glEnable( GL_DEPTH_TEST );
   gluPerspective( 45, (float)windowWidth/windowHeight, .1, 100 );
   glMatrixMode( GL_MODELVIEW );

   glutMainLoop();
   return 0;

}
void loop()
{
    float a[4][4]=
        {
        {0,0,4,4},
        {0,5,5,0},
        {0,0,0,0},
        {0,0,0,0},
        };
        
    float w=3.14/180*45;
    float t[4][4]=
    {
        /*//scaling
        {2,0,0,0},
        {0,2,0,0},
        {0,0,1,0},
        {0,0,0,1},
        */
        /*//shearing
        {1,2,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1},
        */
        /*//reflection
        {-1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1},
        */
        //rotation
        {cos(w),-1*sin(w),0,0},
        {sin(w),cos(w),0,0},
        {0,0,1,0},
        {0,0,0,1},
        
    };
    float c[4][4]={0};
    int i,j,k;
    for(i=0;i<4;i++)
    for(j=0;j<4;j++)
    for(k=0;k<4;k++)
        c[i][j]+=t[i][k]*a[k][j];
    glColor3ub(255, 0, 0); 
    drawRect(a);
    for(i=0;i<4;i++)
    {for(j=0;j<4;j++)
    printf("%0f  ",c[i][j]);
    printf("\n");
    }
    printf("\n");
    glColor3ub(0, 255, 0);
    drawRect(c);
}

void drawRect(float x[4][4])
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();
   glTranslatef(-5,-5, -30);

   glBegin(GL_QUADS);
   
   glVertex2f(x[0][0],x[1][0]);
   glVertex2f(x[0][1],x[1][1]);
   glVertex2f(x[0][2], x[1][2]);
   glVertex2f(x[0][3], x[1][3]);
   //glColor3ub(255, 0, 0);
   glEnd();
   glutSwapBuffers();

}
