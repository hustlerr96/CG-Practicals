//Write a C++ program to implement bouncing ball using sine wave form. Apply the concept of polymorphism.


#include<iostream>
#include<graphics.h>
#include<math.h>

int main()
{
 int gd= DETECT, gm;
 int x,y,i;

 initgraph(&gd, &gm, NULL);

 x= getmaxx() /2;
 y= getmaxy() /2;

 for (i=0; i<1000; i++)
 {
    cleardevice();

    x= x+1;
    y= 200 + 50* sin(i*3.14 /180);

    setcolor(RED);
    circle(x,y, RED);
    floodfill(x,y, RED);

    delay(10);
 }

getch();
closegraph();
return 0;

}
