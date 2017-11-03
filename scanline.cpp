#include<stdio.h>
#include<GL/glut.h>
#include <math.h>

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
	
}
