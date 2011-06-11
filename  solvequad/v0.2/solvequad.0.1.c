#include <stdio.h>
#include <math.h>
int main()
{	
	float a,b,c,x1,x2,delta,midx,y;
	scanf("%g",&a);
	scanf("%g",&b);
	scanf("%g",&c);
	if (a!=0)
	{
		if (a>0)
		{
			printf("Is U-shaped\n");
			midx=-b/(2*a);
			y=a*midx*midx+b*midx+c;
			printf("Axis of symmetry is x=%g\n",midx);
			printf("Min y=%g\n",y);
		}
		else
		{
			printf("Is n-shaped\n");
			midx=-b/(2*a);
			y=a*midx*midx+b*midx+c;
			printf("Axis of symmetry is x=%g\n",midx);
			printf("Max y=%g\n",y);
		}
		delta=b*b-4*a*c;
		printf("delta=%g\n",delta);
		if (delta>0)
		{
			printf("Two solutions\n");
			x1=(-b+sqrt(delta))/(2*a);
			x2=(-b-sqrt(delta))/(2*a);
			printf("x1=%g\n",x1);
			printf("x2=%g\n",x2);
		}
		if (delta==0)
		{
			printf("One solution\n");
			x1=-b/(2*a);
			printf("x=%g\n",x1);
		}
		if (delta<0)
		{
			printf("No solution\n");
		}
	}
	else
	{
		printf("Is not a quadratic equation\n");
	}
}
