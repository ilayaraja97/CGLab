#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

void drawCube(const float x[6][4][4]);
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
    const float a[6][4][4]=
    {
        {
            {1,-1,-1,1},
            {1,1,1,1},
            {-1,-1,1,1},
            {0,0,0,0}
        },
        {
            {1,-1,-1,1},
            {-1,-1,-1,-1},
            {1,1,-1,-1},
            {0,0,0,0}
        },
        {
            {1,-1,-1,1},
            {1,1,-1,-1},
            {1,1,1,1},
            {0,0,0,0}
        },
        {
            {1,-1,-1,1},
            {-1,-1,1,1},
            {-1,-1,-1,-1},
            {0,0,0,0}
        },
        {
            {-1,-1,-1,-1},
            {1,1,-1,-1},
            {1,-1,-1,1},
            {0,0,0,0}
        },
        {
            {1,1,1,1},
            {1,1,-1,-1},
            {-1,1,1,-1},
            {0,0,0,0}
        }
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
        {0,0,-1,0},
        {0,0,0,1},
        */
        //rotation
        {cos(w),-1*sin(w),0,0},
        {sin(w),cos(w),0,0},
        {0,0,1,0},
        {0,0,0,1},
        
    };
    float c[6][4][4]={0};
    int i,j,k,l;
    for(l=0;l<6;l++)
    for(i=0;i<4;i++)
    for(j=0;j<4;j++)
    for(k=0;k<4;k++)
        c[l][i][j]+=t[i][k]*a[l][k][j];
    glColor3ub(255, 0, 0); 
    drawCube(a);
    
    //for(i=0;i<4;i++)
    //{for(j=0;j<4;j++)
    //printf("%0f  ",c[i][j]);
    //printf("\n");
    //}
    printf("\n");
    glColor3ub(0, 255, 0);
    drawCube(c);
}

void drawCube(const float x[6][4][4])
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();
   glTranslatef(1.5f, 0.0f, -7.0f);

   glBegin(GL_QUADS);
   
   glVertex3f(x[0][0][0],x[0][1][0],x[0][2][0]);
   glVertex3f(x[0][0][1],x[0][1][1],x[0][2][1]);
   glVertex3f(x[0][0][2],x[0][1][2],x[0][2][2]);
   glVertex3f(x[0][0][3],x[0][1][3],x[0][2][3]);
   
   glVertex3f(x[1][0][0],x[1][1][0],x[1][2][0]);
   glVertex3f(x[1][0][1],x[1][1][1],x[1][2][1]);
   glVertex3f(x[1][0][2],x[1][1][2],x[1][2][2]);
   glVertex3f(x[1][0][3],x[1][1][3],x[1][2][3]);
   
   glVertex3f(x[2][0][0],x[2][1][0],x[2][2][0]);
   glVertex3f(x[2][0][1],x[2][1][1],x[2][2][1]);
   glVertex3f(x[2][0][2],x[2][1][2],x[2][2][2]);
   glVertex3f(x[2][0][3],x[2][1][3],x[2][2][3]);
   
   glVertex3f(x[3][0][0],x[3][1][0],x[3][2][0]);
   glVertex3f(x[3][0][1],x[3][1][1],x[3][2][1]);
   glVertex3f(x[3][0][2],x[3][1][2],x[3][2][2]);
   glVertex3f(x[3][0][3],x[3][1][3],x[3][2][3]);
   
   glVertex3f(x[4][0][0],x[4][1][0],x[4][2][0]);
   glVertex3f(x[4][0][1],x[4][1][1],x[4][2][1]);
   glVertex3f(x[4][0][2],x[4][1][2],x[4][2][2]);
   glVertex3f(x[4][0][3],x[4][1][3],x[4][2][3]);
   
   glVertex3f(x[5][0][0],x[5][1][0],x[5][2][0]);
   glVertex3f(x[5][0][1],x[5][1][1],x[5][2][1]);
   glVertex3f(x[5][0][2],x[5][1][2],x[5][2][2]);
   glVertex3f(x[5][0][3],x[5][1][3],x[5][2][3]);
   //glColor3ub(255, 0, 0);
   glEnd();
   glutSwapBuffers();

}
