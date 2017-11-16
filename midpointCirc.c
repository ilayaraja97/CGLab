#include <stdio.h>
#include <graphics.h>

#define X 200
#define Y 200

void drawCircle(int r)
{
    int x = 0, y = r;
    int P = 1 - r;
    while(x<=y)
    {
        putpixel(X+x,Y+y,7);  
        putpixel(-x+X,y+Y,7); 
        putpixel(x+X,-y+Y,7); 
        putpixel(-x+X,-y+Y,7);
        
        putpixel(Y+y,X+x,7);  
        putpixel(y+Y,-x+X,7);  
        putpixel(-y+Y,x+X,7); 
        putpixel(-y+Y,-x+X,7);  
        
        if(P<0) 
            P = P + 2*(x+1) + 1;
        else
        {
            P = P + 2*(x+1) + (3 - 2*y); 
            y--;    
        }
        
        x++;        
    }
}

int main(int argv,char *args[])
{
    int gd = DETECT, gm;
    
    initgraph(&gd,&gm,NULL);
    
    drawCircle(atoi(args[1]));
    
    getch();    
    closegraph();
    return 0;
}
