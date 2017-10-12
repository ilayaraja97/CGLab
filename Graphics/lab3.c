#include<stdio.h>
#include<graphics.h>

void Multiply(int original[3][1], int translate[3][3], int newP[3][1])
{
	int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<1;j++)
		{
			newP[i][j] = 0;
			for(k=0;k<3;k++)
			{
				newP[i][j] +=  translate[i][k] * original[k][j];
			}
		}
	}
}

int main()
{
   int gd = DETECT,gm;
   int colour;
 
   initgraph(&gd,&gm,"");
   
   int x0 = 10;
   int y0 = 5;
   int x1 = 200;
   int y1 = 5;	

   line(x0,y0,x1,y1);
   
   int originalP0[3][1] = {x0,y0,1};
   int originalP1[3][1] = {x1,y1,1};
   int translate[3][3] = {1,0,100,0,1,100,0,0,1};
   
   int newP0[3][1],newP1[3][1];
   
   Multiply(originalP0,translate,newP0);
   Multiply(originalP1,translate,newP1);
   
   line(newP0[0][0],newP0[1][0],newP1[0][0],newP1[1][0]);
   getchar();   
   closegraph();
   return 0;
} 

