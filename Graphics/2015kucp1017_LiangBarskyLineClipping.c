/*
 * Submitted By: Sumir Mathur 2015KUCP1017
 * 
 * Liang Barsky Line Clipping Algorithm
 * 
 * */

#include <stdio.h>
#include <graphics.h>

double xMin,xMax,yMin,yMax;   
double clippedx1=-1,clippedx2=-1,clippedy1=-1,clippedy2=-1;

double maximum(double a, double b)
{
	if(a > b) return a;
	return b;
}
double minimum(double a, double b)
{
	if(a < b)  return a;
	return b;
}

char* clip(double x1, double y1, double x2, double y2)
{

    double q1,q2,q3,q4,P1,P2,P3,P4;
    double t1,t2;
    char *s = (char *)calloc(100,sizeof(char));
    
    P1 = -(x2 - x1);
    P2 = (x2 - x1);
    P3 = -(y2 - y1);
    P4 = (y2 - y1);
    
    q1 = x1 - xMin;
    q2 = xMax - x1;
    q3 = y1 - yMin;
    q4 = yMax - y1;

    t1 = 0; 
    t2 = 1;
    
    if( (P1 == 0 && q1 < 0) || (P2 ==0 && q2 < 0) || (P3 == 0 && q3 < 0) || (P4 == 0 && q4 < 0))
    {
    	sprintf(s,"Line rejected"); 
    	return s;
    } 
    
    if(P1 < 0)
    {
	t1 = maximum(0,q1/P1);
	t2 = minimum(1,q2/P2);
	
	if( P3 < 0)
	{
		t1 = maximum(t1,q3/P3);
		t2 = minimum(t2,q4/P4);
	}
	else if(P4 < 0)
	{
		t1 = maximum(t1,q4/P4);
		t2 = minimum(t2,q3/P3);
	}
    }
    
    else if(P2 < 0)
    {
	t1 = maximum(0,q2/P2);
	t2 = minimum(1,q1/P1);
 	if( P3 < 0)
	{
		t1 = maximum(t1,q3/P3);
		t2 = minimum(t2,q4/P4);
	}
	else if(P4 < 0)
	{
		t1 = maximum(t1,q4/P4);
		t2 = minimum(t2,q3/P3);
	}
    }
    
    if(t1 > t2)
    {
    	sprintf(s,"Line rejected"); 
    	return s;
    }
   
    clippedx1 = x1 + t1*(x2 - x1);
    clippedy1 = y1 + t1*(y2 - y1);
    clippedx2 = x1 + t2*(x2 - x1);
    clippedy2 = y1 + t2*(y2 - y1);
 
    sprintf(s,"Line accepted from %.1lf, %.1lf to %.1lf, %.1lf",clippedx1,clippedy1,clippedx2,clippedy2);
    
    return s;
}

int main()
{
   int gd = DETECT,gm;
 
   double x1,y1,x2,y2;
   char *s = (char *)calloc(100,sizeof(char));
   
   printf("Enter the x min value of the window: ");
   scanf("%lf",&xMin);
   
   printf("Enter the y min value of the window: ");
   scanf("%lf",&yMin);
   
   printf("Enter the x max value of the window: ");
   scanf("%lf",&xMax);
   
   printf("Enter the y max value of the window: ");
   scanf("%lf",&yMax);
   
  //xMax = 400,xMin = 200;
  // yMax = 400,yMin = 200;
    
   printf("\nEnter the coordinates of the line\n");
   printf("x1: ");
   scanf("%lf",&x1);
   
   printf("y1: ");
   scanf("%lf",&y1);
   
   printf("x2: ");
   scanf("%lf",&x2);
   
   printf("y2: ");
   scanf("%lf",&y2);
   
  //x1 = 100,y1 = 250;
    //x2 = 300,y2 = 300;
   
   s = clip(x1,y1,x2,y2);
	
   initgraph(&gd,&gm,"");
   
   rectangle(xMin,yMin,xMax,yMax); 
   line(x1,y1,x2,y2);
   
   outtextxy(30,50,s);
   
   setcolor(3);
   line(clippedx1,clippedy1,clippedx2,clippedy2);

   getchar();   
   closegraph();

    return 0;
}
