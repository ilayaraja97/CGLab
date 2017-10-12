#include <GL/glut.h>//Drawing funciton
void draw(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer

	   // Draw a white line
	   glBegin(GL_LINES);              // Each set of 2 vertices form a line
	      glColor3f(1.0f, 0.0f, 0.0f); // red
	      glVertex2f(-0.5f,0.0f);    // x, y
	      glVertex2f(0.5f,0.0f);
	   glEnd();

	glBegin(GL_LINES);              // Each set of 2 vertices form a line
	      glColor3f(0.0f, 1.0f, .0f); // green
	      glVertex2f(0.0f,0.5f);    // x, y
	      glVertex2f(0.0f,-0.5f);
	glEnd();

	glBegin(GL_LINES);              // Each set of 2 vertices form a line
	      glColor3f(0.0f, 0.0f, 1.0f); // blue
	      glVertex2f(-0.5f,-0.5f);    // x, y
	      glVertex2f(0.5f,0.5f);
	glEnd();
	
	glLineStipple(1, 0xAAAA);
	glPushAttrib(GL_ENABLE_BIT); 
	glEnable(GL_LINE_STIPPLE);
	glColor3f(1.0f, 1.0f, 1.0f); // white
		glBegin(GL_LINES);
		glVertex2f(-0.7f,-0.7f);
		glVertex2f(0.70f,-0.7f);
		glEnd();
	glPopAttrib();
	glFlush();
}

//Main program
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	
	//Simple buffer
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
	glutInitWindowPosition(50,25);
	glutInitWindowSize(500,250);
	glutCreateWindow("Lines");


	//Call to the drawing function
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}
