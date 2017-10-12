#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
//#include <math.h>


void translate(int tx,int ty)
{
	outtextxy(240,10,"TRANSLATION");
	outtextxy(238,20,"------------");
	rectangle(0,0,150,200);
	rectangle(0+tx,0+ty,150+tx,200+ty);
}

void scale(int sx,int sy)
{
	 outtextxy(240,10,"SCALING");
	 outtextxy(238,20,"------------");
	 rectangle(0,0,150,200);
	 rectangle(0*sx,0*sy,150*sx,200*sy);
}

/*
void rotate(float theta)
{
	int x1,y1,x2,y2;
	x1 = 50,y1 = 50,x2 = 100,y2 = 100;
	theta = theta*3.14/180;
	line(x1,y1,x2,y2);
	int nx1,nx2,ny1,ny2;
	
	nx1 = x1*cos(theta) - y1*sin(theta);
	ny1 = x1*sin(theta) + y1*cos(theta);
	
	nx2 = x2*cos(theta) - y2*sin(theta);
	ny2 = x2*sin(theta) + y2*cos(theta);
	
	line(nx1,ny1,nx2,ny2);

}
*/

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);

	int tx = 10,ty = 10,sx = 2,sy = 2;
	float theta = 30;

	outtextxy (100,88,"Object.");
	//rectangle(100,250,150,200);
	
	translate(tx,ty);	
	//scale(sx,sy);
	//rotate(30);


	getch();
	closegraph();
	
	
	return 0;
}

