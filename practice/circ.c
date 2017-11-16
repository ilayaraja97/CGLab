#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void circ(double X,double Y,double r,double t);
int main(int argv,char *argc[])
{
	if(argv<4)
	{
		printf("\nUsage : ./circ x y r theta\n\n");
		return 1;
	}
	int gm=DETECT,gd;
	initgraph(&gm,&gd,NULL);
	double x=atof(argc[1]),
		y=atof(argc[2]),
		r=atof(argc[3]),
		t=atof(argc[4])*M_PI/180;
	circ(x,y,r,t);
	getch();
	closegraph();
	return 0;
}

void circ(double X,double Y,double r,double t)
{
	int x=0,y=r,P=1-r;
	while(x<=y)
	{
		putpixel(X+x*cos(t)-y*sin(t),Y+x*sin(t)+y*cos(t),1);t+=M_PI/4;
		putpixel(X+x*cos(t)-y*sin(t),Y+x*sin(t)+y*cos(t),2);t+=M_PI/4;
		putpixel(X+x*cos(t)-y*sin(t),Y+x*sin(t)+y*cos(t),3);t+=M_PI/4;
		putpixel(X+x*cos(t)-y*sin(t),Y+x*sin(t)+y*cos(t),4);t+=M_PI/4;
		
		putpixel(X+x*cos(t)-y*sin(t),Y+x*sin(t)+y*cos(t),5);t+=M_PI/4;
		putpixel(X+x*cos(t)-y*sin(t),Y+x*sin(t)+y*cos(t),6);t+=M_PI/4;
		putpixel(X+x*cos(t)-y*sin(t),Y+x*sin(t)+y*cos(t),7);t+=M_PI/4;
		putpixel(X+x*cos(t)-y*sin(t),Y+x*sin(t)+y*cos(t),8);t+=M_PI/4;
		
		if(P<0) 
			P = P + 2*(x+1) + 1;
		else
		{
		 	P = P + 2*(x+1) + (3 - 2*y); 
			y--;	
		}
		
		x++;
	}
}
