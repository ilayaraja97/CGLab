/*
	Bresenham's Line algo
*/

#include<stdio.h>
#include<graphics.h>

float X1,Y1,X2,Y2;
float PK1;
float dx,dy;
float m;


int main()
{
	printf("Enter lines's co-ordinate : \n x1 => ");
	scanf("%f",&X1);
	printf(" y1 => ");	
	scanf("%f",&Y1);
	printf(" x2 => ");	
	scanf("%f",&X2);
	printf(" y2 => ");	
	scanf("%f",&Y2);


	dx=X2-X1; //diff
	dy=Y2-Y1;
	
	m=dy/dx;	//slope
	
	int grd, grm,i=30;
	initgraph(&grd, &grm, NULL);
	
	char a[100];
	
	float x,y,xk,yk;
	x=X1; //to iniitialise x with starting point
	y=Y1; //to intialise y with starting point
		
	if(m<1) 
	{				
		PK1=2*dy-dx;
		while(x<=X2 && y<=Y2) //till reach at the ending point
		{			
			if(PK1>=0)
			{
				xk=x+1; 
				yk=y+1;
			}
			else
			{
				xk=x+1;
				yk=y;
			}

			PK1=PK1 + 2*dy - 2*dx*(yk-y);	 //change p
			x=xk;
			y=yk;
			putpixel(xk,yk,10); //draw a pixel on every point
			i=i+10; // to print points on terminal
		}
	}
	else if(m>1) 
	{		
		PK1=2*dx-dy;	
		outtextxy(getmaxx()-150,10,"Intermediate points");	
		while(x<=X2 && y<=Y2) 
		{
			sprintf(a,"%.1f %.1f",x,y);
			outtextxy(getmaxx()-100,i,a);									
			if(PK1>=0)
			{
				xk=x+1; 
				yk=y+1;
			}
			else
			{
				xk=x;
				yk=y+1;
			}
			PK1=PK1 + 2*dy - 2*dx*(yk-y);	 //change p
			x=xk;
			y=yk;
			putpixel(xk,yk,100);
			i=i+10; // to print intermediate points on terminal
		}
	}
	else //for m==1
	{	
		outtextxy(getmaxx()-150,10,"Intermediate points");				
		while(x<=X2 && y<=Y2) 
		{
			sprintf(a,"%.1f %.1f",x,y); //store  x & y's val in a
			outtextxy(getmaxx()-100,i,a);	//to print						
			x=x+1;
			y=y+1;
			putpixel(x,y,20);
			i=i+10; // to print intermediate point on terminal
		}			
		
	}
 	getch();
 	closegraph();
}
