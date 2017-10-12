
#include<stdio.h>
#include<graphics.h>

 
int main()
{
   int gd = DETECT,gm;
   int colour;
   char a[100];
   initgraph(&gd,&gm,"");
   
	setbkcolor(1);
   line(10,5,200,5);
   line(10,10,10,200);

   
   rectangle(200, 50, 400, 150);
   bar(410,50,600,150);

   circle(100,100,50);
   ellipse(120,220,0,360,100,50);

   putpixel(50, 50, WHITE);
    colour = getpixel(50, 50);
   sprintf(a,"The colour of pixel at 50,50: %d",colour);
   outtextxy(100,300,a);
   getchar();   
   closegraph();
   return 0;
} 

//line horizontal/vertical bar circle ellipse setpixel getpixel bgcolor , line from xy location and fromstarting
