#ifndef __INFO_H__
#define __INFO_H__

#include "calc.h"

//This offers functions showing the infomation of a quadratic equation.

//Check the input.
int ifgood(int b, int d, int f)
{
	if(b==0||d==0||f==0) {return(0);} else {return(1);}
}

//Check if it is a quadratic equation.
int ifquad(int a)
{
	if(a==0) {return(0);} else {return(1);}
}

//Get the shape. U or n.
int getshape(int a, int b)
{
	if(a*b>0) {return(1);} else {return(-1);}
}

//Get the axis of symmetry. Use as a void.
void getaxis(int *a, int *b, int *c, int *d, int *axis1, int *axis2)
{
	int up,down,get1,get2;
	up=-(*c)*(*b);
	down=(*d)*2*(*a);
	rof(&up,&down,&get1,&get2);
	*axis1=get1;
	*axis2=get2;
}

//Get min or max. Or give the x and get y.
void gety(int *a, int *b, int *c, int *d, int *e, int *f, int *y1, int *y2)
{
	int aa,bb,cc,dd,ee,ff,axis1,axis2,up1,down1,up2,down2,up3,down3,fu,fd;
	aa=*a;
	bb=*b;
	cc=*c;
	dd=*d;
	ee=*e;
	ff=*f;
	getaxis(&aa,&bb,&cc,&dd,&axis1,&axis2);
	up1=aa*axis1*axis1;
	down1=bb*axis2*axis2;
	up2=cc*axis1;
	down2=dd*axis2;
	fracadd(&up1,&down1,&up2,&down2,&up3,&down3);
	fracadd(&up3,&down3,&ee,&ff,&fu,&fd);
	*y1=fu;
	*y2=fd;
}

//Get delta.
void getdelta(int *a, int *b, int *c, int *d, int *e, int *f, int *delta1, int *delta2)
{
	int up1,down1,up2,down2,fu,fd;
	up1=(*c)*(*c);
	down1=(*d)*(*d);
	up2=-4*(*a)*(*e);
	down2=(*b)*(*f);
	fracadd(&up1,&down1,&up2,&down2,&fu,&fd);
	*delta1=fu;
	*delta2=fd;
}

//The number of solutions.
int nos(int delta1, int delta2)
{
	if(delta1==0) return(1);
	if(delta1*delta2>0) return(2);
	if(delta1*delta2<0) return(0);
}


#endif
