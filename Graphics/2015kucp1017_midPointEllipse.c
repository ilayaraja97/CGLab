#include<stdio.h>
#include<graphics.h>

#define X 200
#define Y 200

void drawEllipse(int a, int b)
{
	int x = 0, y = b;
	int P = b*b + 0.25*a*a - a*a*b;
	
	outtextxy(20,20,"The desired ellipse");
	while(b*b*x <= a*a*y)
	{
		putpixel(X+x,Y+y,7);
		putpixel(X-x,Y+y,7);
		putpixel(X+x,Y-y,7);
		putpixel(X-x,Y-y,7);
				
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
		putpixel(X-x,Y+y,7);
		putpixel(X+x,Y-y,7);
		putpixel(X-x,Y-y,7);
	
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
	int gd = DETECT, gm;
	int a,b;
	printf("Enter the a for the ellipse: ");
	scanf("%d",&a);
	printf("Enter the b for the ellipse: ");
	scanf("%d",&b);
	
	initgraph(&gd,&gm,NULL);
	
	drawEllipse(a,b);
	
	getch();	
	closegraph();
}
