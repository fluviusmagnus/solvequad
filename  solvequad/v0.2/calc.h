#ifndef __CALC_H__
#define __CALC_H__

//For all of the functions here: check before call.

//Get GCD. Avoid a==0||b==0.
int gcd(int a, int b)
{
	int max,i;
	if(a<0) a=-a;
	if(b<0) b=-b;
	max=0;
	for(i=1;i<=a;i++)
	{
		if((a%i==0)&&(b%i==0)) max=i;
	}
	return(max);
}

//Reduction of a fraction. Output c,d.
void rof(int *a, int *b, int *c, int *d)
{
	//Do nothing when *a==0.
	if (*a==0) {}
	else
	{
		int x,y;
		x=*a;
		y=*b;
		*c=x/gcd(x,y);
		*d=y/gcd(x,y);
		if(*c<0&&*d<0)
		{
			*c=-*c;
			*d=-*d;
		}
	}
}

//Sqrt in the form of a*root(b). Avoid b<0. Output c,d.
void finesqrt(int *a, int *b, int *c, int *d)
{
	if(*b==0)
	{
		*c=0;
		*d=0;
	}
	else
	{
		int root,i,x,y;
		//a must be 1 when use this void.
		y=*b;
		for(i=1;i<=y;i++)
		{
			if(y%(i*i)==0) root=i;
		}
		x=y/root/root;
		*c=root;
		*d=x;
	}
}

//Fraction add. Output e,f.
void fracadd(int *a, int *b, int *c, int *d, int *e, int *f)
{
	int x,y,m,n;
	x=(*a)*(*d)+(*b)*(*c);
	y=(*b)*(*d);
	rof(&x,&y,&m,&n);
	*e=m;
	*f=n;
}

//Fraction multiplication. Output e,f.
void fracmul(int *a, int *b, int *c, int *d, int *e, int *f)
{
	int x,y,m,n;
	x=(*a)*(*c);
	y=(*b)*(*d);
	rof(&x,&y,&m,&n);
	*e=m;
	*f=n;
}

#endif
