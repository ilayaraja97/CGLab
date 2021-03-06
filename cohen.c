#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

int main(int argv,char *args[])
{
    if(argv<8)
    {
    	printf("\nUsage : ./cohen.o x1 y1 x2 y2 xmin ymin xmax ymax\n\n");
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
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    rectangle(xmin,ymin,xmax,ymax);
    setcolor(3);
    line(x1,y1,x2,y2);
    setcolor(5);
    //set bit regions
    int p,q;
    while(1){
    	p=q=0;
    	if(x1<xmin)
    	p=p|1;
		if(x1>xmax)
			p=p|2;
		if(y1<ymin)
			p=p|4;
		if(y1>ymax)
			p=p|8;
		if(x2<xmin)
			q=q|1;
		if(x2>xmax)
			q=q|2;
		if(y2<ymin)
			q=q|4;
		if(y2>ymax)
    	q=q|8;
		if(p==0&&q==0)
		{
			//completely in
			line(x1,y1,x2,y2);
			break;
		}
		else
		{
			if((p&q)==0)
			{	
				//partially in
				if(p!=0)
				{
					if(p&8)
					{
						x1 = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
		            	y1 = ymax;
		            }
		            else if(p&4)
		            {
		            	x1 = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
		            	y1 = ymin;
		            }
		            else if(p&2)
		            {
		            	y1 = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
		            	x1 = xmax;
		            }
		            else if(p&1)
		            {
		            	y1 = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
		            	x1 = xmin;
		            }
		        }
		        else if(q!=0)
				{
					if(q&8)
					{
						x2 = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
		            	y2 = ymax;
		            }
		            else if(q&4)
		            {
		            	x2 = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
		            	y2 = ymin;
		            }
		            else if(q&2)
		            {
		            	y2 = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
		            	x2 = xmax;
		            }
		            else if(q&1)
		            {
		            	y2 = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
		            	x2 = xmin;
		            }
		        }
		    }
		    else break;
		}
    }		
    delay(5000);
    closegraph();
    printf("\n\nCyan is actual line \nMagenta is clipped line\
    \nwhite rectangle is window\n");
    
    return 0;
}
