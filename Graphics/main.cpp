#include <bits/stdc++.h>
#include<graphics.h>

double a[1000],b[1000],pk,pk1,x,y,x_1,y_1;

int main(void)
{
    int i, flag=0, r=5;
    int gd = DETECT, gm;
    initgraph(&gd,&gm,NULL);
    x = 0;
    y = r;
    pk = 1-r;
    a[flag] = x;
    b[flag] = y;
    if(pk>=0)
    {
        x_1 = x + 1;
        y_1 = y - 1;
    }
    else if(pk<0)
    {
        x_1 = x + 1;
        y_1 = y;
    }
    flag++;
    a[flag] = x_1;
    b[flag] = y_1;
    flag++;
    while(x_1<y_1)
    {
        pk1 =pk + 2*(x_1+1) + (y_1*y_1 - x_1*x_1) - (y_1 - x_1) + 1;
        if(pk1>=0)
        {
            x_1 = x + 1;
            y_1 = y - 1;
        }
        else if(pk1<0)
        {
            x_1 = x + 1;
            y_1 = y;
        }
        x = a[flag-1];
        y = b[flag -1];
        a[flag] = x_1;
        b[flag] = y_1;
        flag++;
        pk = pk1;
    }
    for(i=0;i<flag;i++)
    {
        putpixel(a[i],b[i],WHITE);
    }


}
