/*
WRITE C++ PROGRAM TO DRAW THE PATTERN, USE
DDA LINE AND BRESENHAMS CIRCLE DRAWING ALGORITHM.
APPLY CONCEPT OF ENCAPSULATION
*/

#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
class pt
{
	protected:
		int xco,yco,color;
	public:
		pt()
		{
			xco=0;
			yco=0;
			color=15;
		}
		void setco(int x,int y)
		{
			xco=x;
			yco=y;
		}
		void setcolor(int c)
		{
			color=c;
		}
		void draw()
		{
			putpixel(xco,yco,color);
		}
};
class dline: public pt
{
	private:
		int x2,y2,x0,y0;
	public:
		dline():pt()
		{
			x2=0;
			y2=0;
		}
		void setline(int x,int y,int xx, int yy)
		{
			pt::setco(x,y);
			x2=xx;
			y2=yy;
		}
		void draw1(int color)
		{
			float x,y,dx,dy,length;
			int i;
			pt::setcolor(color);
			dx=abs(x2-xco);
			dy=abs(y2-yco);
			if(dx>=dy)
			{
				length=dx;
			}
			else
			{
				length=dy;
			}
			dx=(x2-xco)/length;
			dy=(y2-yco)/length;
			x=xco+0.5;
			y=yco+0.5;
			i=1;
			while(i<=length)
			{
				pt::setco(x,y);
				//delay(500);
				pt::draw();
				x=x+dx;
				y=y+dy;
				i=i+1;
			}
			pt::setco(x,y);
			pt::draw();
		}
		void draw1(int colour,int xo,int yo)
		{
			float x,y,dx,dy,e,temp;
			int i,gd,gm,s1,s2,ex;
			pt::setcolor(colour);
			dx=abs(x2-xco);
			dy=abs(y2-yco);
			x=xco;
			y=yco;
			putpixel(x+xo,yo-y,15);
			if(x2>xco)
			{
				s1=1;
			}
			if(x2==xco)
			{
				s1=0;
			}
			if(x2<xco)
			{
				s1=-1;
			}
			if(y2>yco)
			{
				s2=1;
			}
			if(y2==yco)
			{
				s2=0;
			}
			if(y2<yco)
			{
				s2=-1;
			}
			if(dy>dx)
			{
				temp=dx;
				dx=dy;
				dy=temp;
				ex=1;
			}
			else
			{
				ex=0;
			}
			e=2*dy-dx;
			i=1;
			do
			{
				while(e>=0)
				{
					if(ex==1)
					{
						x=x+s1;
					}
					else
					{
						y=y+s2;
					}
					e=e-2*dx;
				}
				if(ex==1)
				{
					y=y+s2;
				}
				else
				{
					x=x+s1;
				}
				e=e+2*dy;
				//delay(500);
				putpixel(x+xo,yo-y,15);
				i=i+1;
			}while(i<=dx);
		}


		void setline1(int x,int y,int xx,int yy,int xm,int ym)
		{
			pt::setco(x,y);
			x2=xx;
			y2=yy;
			x0=xm;y0=ym;
		}

		void drawl(int x1, int y1, int r)//bresanhams
		{
			int i, x, y;
			float d;   
			x=0, y=r;
			d = 3 - 2*r;            //decision variable

			do
			{
				      
			    putpixel(x1+x0+x, y0-y1+y,15);
			    putpixel(x1+x0+y, y0-y1+x,15);
			    putpixel(x1+x0+y, y0-y1-x,15);
			    putpixel(x1+x0+x, y0-y1-y,15);
			    putpixel(x1+x0-x, y0-y1-y,15);
			    putpixel(x1+x0-y, y0-y1-x,15);
			    putpixel(x1+x0-y, y0-y1+x,15);
			    putpixel(x1+x0-x, y0-y1+y,15);
			 

			    if(d<=0)
			    {
				x = x + 1;
				d = d + (4*x) + 6;
			    }
			    else
			    {
				x = x + 1;
				y = y - 1;
				d = d + (4*x-4*y) + 10;
			    }

			}while(x<=y);
		}



};
int main()
{
	int gd=DETECT,gm=VGAMAX;
	int x1,x2,y1,y2,x3,y3,xmax,ymax,xmid,ymid;
	float xc,yc,r,r1,yd;
	pt p1;
	p1.setco(5000,5000);
	p1.setcolor(14);
	dline l;
	cout<<"\nEnter three points for triangle:";
	cout<<"\nEnter the value of x1:";
	cin>>x1;
	cout<<"\nEnter the value of y1:";
	cin>>y1;
	cout<<"\nEnter the value of x2:";
	cin>>x2;
	cout<<"\nEnter the value of y2:";
	cin>>y2;
	/*cout<<"\nEnter the value of x3:";
	cin>>x3;
	cout<<"\nEnter the value of y3:";
	cin>>y3;*/

	x3=(x2+x1)/2;
	
	yd=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)))/2;

	//yd=(x2-x1)/2;

	y3=(yd*sqrt(3))+y1;
	
	xc=(x1+x2+x3)/3; yc=(y1+y2+y3)/3;
	r=sqrt(((x2-xc)*(x2-xc))+((y2-yc)*(y2-yc)));
	
	r1=r/2;

	initgraph(&gd,&gm,NULL);
	xmax=getmaxx();
	ymax=getmaxy();
	xmid=xmax/2;
	ymid=ymax/2;
	line(xmid,0,xmid,ymax);
	line(0,ymid,xmax,ymid);
	
	l.setline(x1,y1,x2,y2);//first line
	l.draw1(15,xmid,ymid);

	l.setline(x2,y2,x3,y3);//second line
	l.draw1(15,xmid,ymid);

	l.setline(x3,y3,x1,y1);//third line
	l.draw1(15,xmid,ymid);

	
	l.setline1(x1,y1,x2,y2,xmid,ymid);//Big circle
	l.drawl(xc,yc,r);

	
	l.setline1(x1,y1,x2,y2,xmid,ymid);//small circle
	l.drawl(xc,yc,r1);
		
	delay(500000);
	closegraph();
	return 0;
}



/******
output:


Enter three points for triangle:
Enter the value of x1:40

Enter the value of y1:70

Enter the value of x2:180

Enter the value of y2:70
**/
