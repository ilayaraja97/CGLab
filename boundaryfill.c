#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void boundaryFill(int x,int y,int f,int b)
{
	if(getpixel(x,y)!=b && getpixel(x,y)!=f)
	{
		putpixel(x,y,f);
		boundaryFill(x+1,y,f,b);
		boundaryFill(x-1,y,f,b);
		boundaryFill(x,y+1,f,b);
		boundaryFill(x,y-1,f,b);
	}
}

int main(int argv,char *args[])
{
    if(argv<4)
    {
    	printf("\nUsage : ./boundaryfill.o x y r\n\n");
    	return 1;
    }
    int x=atoi(args[1]),y=atoi(args[2]),r=atoi(args[3]);
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    setcolor(7);
    circle(x, y, r);
    boundaryFill(x,y,8,7);
    getch();
    closegraph();
    return 0;
}
