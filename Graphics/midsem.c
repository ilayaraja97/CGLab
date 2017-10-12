#include <stdio.h>
#include <graphics.h>

#define X 200
#define Y 200

void draw(int r, int a)
{
	
	//circle part
	double P = 1-r;
	int x=0, y=r;
	
	while(x<=y)
	{
		putpixel(Y-y,X+x,7);
		putpixel(Y-y,X-x,7);
		
		putpixel(X-x,Y-y,7);
		putpixel(X-x,Y+y,7);

		if(P<0) 
			P = P + 2*(x+1) + 1;
		else
		{
		 	P = P + 2*(x+1) + (3 - 2*y); 
			y--;	
		}
		
		x++;		
	}
	
	//ellipse part
	int b = r;
	x = 0, y = r;
	P = b*b + 0.25*a*a - a*a*b;

	while(b*b*x <= a*a*y)
	{
		putpixel(X+x,Y+y,7);
		putpixel(X+x,Y-y,7);
		
		if(P<0) 
			P = P + b*b + 2*b*b*(x+1);
		else
		{
		 	P = P + b*b + 2*b*b*(x+1) + a*a*(1-2*y) +a*a; 
			y--;	
		}
		
		x++;		
	}
	
	while(y >= 0)
	{
		putpixel(X+x,Y+y,7);
		putpixel(X+x,Y-y,7);
		
		if(P>=0) 
			P = P - 2*a*a*(y-1) + a*a;
		else
		{
			P = P + b*b*(1 + 2*x) + b*b + -2*a*a*(y-1) + a*a;
		 	x++;	
		}
		
		y--;	
	}
}

int main()
{
	
	int gd,gm;
	int r = 3, a=5;	
	initgraph(&gm,&gd,"");

	outtextxy(100,100,"The desired figure is: ");
	
	draw(r*20,a*20);
	
	getch();
	closegraph();
 return 0;	
}