#include <stdio.h>
#include "info.h"
#include "calc.h"

//This is the main file. Rational numbers only.

int main()
{
	int a,b,c,d,e,f;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);
	scanf("%d",&e);
	scanf("%d",&f);
	if(ifgood(b,d,f)==0||ifquad(a)==0)
	{
		printf("Error\n");
	}
	else
	{
		printf("Shape=%d\n",getshape(a,b));
		int axis1,axis2;
		getaxis(&a,&b,&c,&d,&axis1,&axis2);
		printf("Axis of symmetry is x=%d/%d\n",axis1,axis2);
		int y1,y2;
		gety(&a,&b,&c,&d,&e,&f,&y1,&y2);
		printf("Max or min is y=%d/%d\n",y1,y2);
		int delta1,delta2;
		getdelta(&a,&b,&c,&d,&e,&f,&delta1,&delta2);
		printf("Delta=%d/%d\n",delta1,delta2);
		int num;
		num=nos(delta1,delta2);
		printf("The number of the real roots=%d\n",num);
		if(num==1) printf("Solution x=%d/%d\n",axis1,axis2);
		if(num==2)
		{
			//The rational part is the same as the axis.
			int up,down,root;
			fracsqrt(&delta1,&delta2,&up,&down,&root);
			int fu,fd,ffu,ffd;
			fu=up*b;
			fd=2*a*down;
			rof(&fu,&fd,&ffu,&ffd);
			//Try to display in a good format.
			if(ffu*ffd<0&&ffu>0)
			{
				ffu=-ffu;
				ffd=-ffd;
			}
			//Solutions.
			printf("Solution 1 x1=(%d/%d)+(%d/%d)*sqrt(%d)\n",axis1,axis2,ffu,ffd,root);
			printf("Solution 2 x2=(%d/%d)-(%d/%d)*sqrt(%d)\n",axis1,axis2,ffu,ffd,root);
		}
	}
}
