#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

int main(int argv,char *args[])
{
    if(argv<8)
    {
    	printf("\nUsage : ./barsky.o x1 y1 x2 y2 xmin ymin xmax ymax\n\n");
    	return 1;
    }
    double x1=atof(args[1]),
    	y1=atof(args[2]),
    	x2=atof(args[3]),
    	y2=atof(args[4]),
    	xmin=atof(args[5]),
    	ymin=atof(args[6]),
    	xmax=atof(args[7]),
    	ymax=atof(args[8]);
    int gd=DETECT,gm,i;
    initgraph(&gd,&gm,NULL);
    rectangle(xmin,ymin,xmax,ymax);
    setcolor(3);
    line(x1,y1,x2,y2);
    setcolor(5);
    
    double dx=x2-x1,
    	dy=y2-y1,
    	p[4]={-dx,dx,dy,dy},
    	q[4]={x1-xmin,xmax-x1,y1-ymin,ymax-y1},
    	t1=0,
    	t2=1;
    
    for(i=0;i<4;i++)
    {
    	if(p[i]==0)
    	{//parallel
    		if(q[i]<0)
    		{
    			//outside window
    			break;
    		}
    	}
    	else
    	{
    		if(p[i]<0)
    		{
    			if(t1<q[i]/p[i])
    				t1=q[i]/p[i];
    		}
    		if(p[i]>0)
    		{
    			if(t2>q[i]/p[i])
    				t2=q[i]/p[i];
    		}
    	}
    }
    if(t1<=t2)
    {	
    	double a1=x1+t1*dx,
    		b1=y1+t1*dy,
    		a2=x1+t2*dx,
    		b2=y1+t2*dy;
    	line(a1,b1,a2,b2);
    }
    
    delay(5000);
    closegraph();
    printf("\n\nCyan is actual line \nMagenta is clipped line\
    \nwhite rectangle is window\n");
    
    return 0;
}
