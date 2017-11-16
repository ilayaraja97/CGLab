#include <grapics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define min(x,y) x<y?x:y
#define max(x,y) x<y?y:x

void dda(double x1, double y1, double x2, double y2);
void bresenham(double x1, double, y1, double x2, double y2);
int main(int argv, char *argc[])
{
    if (argv < 4)
    {
        printf("\nUsage: ./line x1 y1 x2 y2\n\n");
        return 1;
    }
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    double x1 = atof(args[1]),
           x2 = atof(args[3]),
           y1 = atof(args[2]),
           y2 = atof(args[4]);
    // dda(x1,y1,x2,y2);
    // bresenham(x1,y2,x2,y2);
    return 0;
}

void dda(double x1, double y1, double x2, double y2)
{
    double m = (y2 - y1) / (x2 - x1);
    double x, y;
    if (abs(m) > 1) //det x
    {
        for (y = min(y1,y2); y < max(y1,y2); y++)
        {
            x+=1/m;
            putpixel(x, y, 7);
        }
    }
    else if (abs(m) < 1) //det y
    {
        for (x = min(x1,x2); x < max(x1,x2); x++)
        {
            y+=m;
            putpixel(x, y, 7);
        }
    }
    else //xy same.. 45 degs
    {
        for (x = min(x1,x2); x < max(x1,x2); x++)
        {
            y++;
            putpixel(x, y, 7);
        }
    }
}

void bresenham(double x1, double, y1, double x2, double y2)
{
    int x, y, pk, m = (y2 - y1) / (x2 - x1),t;
    if (abs(m) < 1)
    {
        pk=2*(y2-y1)-(x2-x1);
        for(x=min(x1,x2);x<max(x1,x2);x++)
        {
            putpixel(x,y,7);
            if(pk>=0)
            {
                t=y+1;
            }
            x++;
            pk=pk+2*(y2-y1)-2*(x2-x1)*(t-y);
        }
    }
    else if (abs(m) > 1)
    {
        pk=2*(x2-x1)-(y2-y1);
        for(y=min(y1,y2);y<max(y1,y2);y++)
        {
            putpixel(x,y,7);
            if(pk>=0)
            {
                t=x+1;
            }
            y++;
            pk=pk+2*(x2-x1)-2*(y2-y1)*(t-x);
        }
    }
    else
    {
        for (x = min(x1,x2); x < max(x1,x2); x++)
        {
            y++;
            putpixel(x, y, 7);
        }
    }
}