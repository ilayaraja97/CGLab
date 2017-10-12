/*
 * Submitted By: Sumir Mathur 2015KUCP1017
 * 
 * Cohen Sutherland Line Clipping Algorithm
 * 
 * 
 * */

#include <stdio.h>
#include <graphics.h>

// Defining region codes
#define INSIDE 0
#define LEFT 1   
#define RIGHT 2  
#define BOTTOM 4 
#define TOP 8  

double xMin,xMax,yMin,yMax;   
double clippedx1,clippedx2,clippedy1,clippedy2;
 
int Sw(double* a,double* b)
{
	double temp = *a;
	if(*a > *b)
	{
		*a = *b;
		*b = temp;
		return 1;
	}
	return 0;
}
	
// Function to compute region code for a point(x, y)
int findRegion(double x, double y)
{
    // initialized as being inside 
    int code = INSIDE;
 
    if(x < xMin)       
    { 
		   code = code | LEFT;
    }
    else if (x > xMax)
		code =  code | RIGHT;
	
        
    if(y < yMin)       // below the rectangle
    {
		code = code | TOP;
	}
    else if (y > yMax)  // above the rectangle
        code = code | BOTTOM;
 
    return code;
}

char* clip(double x1, double y1,double x2, double y2)
{
    int code1 = findRegion(x1, y1);
    int code2 = findRegion(x2, y2);
	char *s = (char *)calloc(100,sizeof(char));
   
    int accept = 0;
 
    while(1)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            accept = 1;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            int code_out;
            double x, y;
 
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;
 
            if (code_out & TOP)
            {
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
                y = yMax;
            }
            else if (code_out & BOTTOM)
            {
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
                y = yMin;
            }
            else if (code_out & RIGHT)
            {
                y = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
                x = xMax;
            }
            else if (code_out & LEFT)
            {
                y = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
                x = xMin;
            }
 
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = findRegion(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = findRegion(x2, y2);
            }
        }
    }
    if (accept)
    {
        sprintf(s,"Line accepted from %.1lf, %.1lf to %.1lf, %.1lf",x1,y1,x2,y2);
    }
    else
        sprintf(s,"Line rejected");
    
    
    clippedx1 = x1;
    clippedy1 = y1;
    clippedx2 = x2;
    clippedy2 = y2;
    
    return s;
}

int main()
{
   int gd = DETECT,gm;
 
   
   double x1,y1,x2,y2;
   int region1, region2;
   char *s = (char *)calloc(100,sizeof(char));
   
   printf("Enter the x min value of the window: ");
   scanf("%lf",&xMin);
   
   printf("Enter the y min value of the window: ");
   scanf("%lf",&yMin);
   
   printf("Enter the x max value of the window: ");
   scanf("%lf",&xMax);
   
   printf("Enter the y max value of the window: ");
   scanf("%lf",&yMax);
   
  // int xMax = 400,xMin = 200;
  // int yMax = 400,yMin = 200;
    
    
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
   
   if(Sw(&x1,&x2)) Sw(&y1,&y2);
   
   s = clip(x1,y1,x2,y2);
	
   initgraph(&gd,&gm,"");
   
   rectangle(xMin,yMax,xMax,yMin); 
   line(x1,y1,x2,y2);
   
   	outtextxy(30,50,s);
   
   setcolor(3);
   line(clippedx1,clippedy1,clippedx2,clippedy2);
   getchar();   
   closegraph();

    return 0;
}
