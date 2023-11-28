/*****************************************************************************************
A3:Write C++ program to draw 2-D object and perform following basic transformations,
a) Scaling
b) Translation
c) Rotation
Use operator overloading.
***********************************************************************************/

#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;
int pi[10];
double b[3][3] = {1, 0, 0,
                  0, 1, 0,
                  0, 0, 1};
int c[1][1];
float a[1][1];
void matmul(float[]);
int main()
{
        int i, x, y, tx, ty, sx, sy, angle = 10, xmax, ymax, xmid, ymid, op;
        int gd, gm;
        gd = DETECT;
        float p1[10] = {50, 50,
                        100, 50,
                        100, 100,
                        50, 100,
                        50, 50};
        cout << "\n select the transformation";
        cout << "\n 1:translation";
        cout << "\n 2:rotation";
        cout << "\n 3:scaling";
        cout << "\n 4:rotation about arbitary point";
        cout << "\n enter the option:";
        cin >> op;
        switch (op)
        {
        case 1:
                cout << "\n enter x translation:";
                cin >> tx;
                cout << "\n enter y translation:";
                cin >> ty;
                b[0][0] = 1;
                b[0][1] = 0;
                b[0][2] = 0;

                b[1][0] = 0;
                b[1][1] = 1;
                b[1][2] = 0;

                b[2][0] = tx;
                b[2][1] = ty;
                b[2][2] = 1;
                break;
        case 2:
                cout << "\n enter rotation angle:";
                cin >> angle;
                b[0][0] = cos(angle * 3.142 / 180);
                b[0][1] = sin(angle * 3.142 / 180);
                b[0][2] = 0;

                b[1][0] = -sin(angle * 3.142 / 180);
                b[1][1] = cos(angle * 3.142 / 180);
                b[1][2] = 0;

                b[2][0] = 0;
                b[2][1] = 0;
                b[2][2] = 1;
                break;
        case 3:
                cout << "\n enter x scalling:";
                cin >> sx;
                cout << "\n enter y scalling:";
                cin >> sy;
                b[0][0] = sx;
                b[0][1] = 0;
                b[0][2] = 0;

                b[1][0] = 0;
                b[1][1] = sy;
                b[1][2] = 0;

                b[2][0] = 0;
                b[2][1] = 0;
                b[2][2] = 1;
                break;
        case 4:
                cout << "\n enter x co-ordinate of arbitary point:";
                cin >> x;
                cout << "\n enter y co-ordinate of arbitary point:";
                cin >> y;
                cout << "\n enter rotation angle:";
                cin >> angle;
                tx = x;
                ty = y;

                b[0][0] = cos(angle * 3.142 / 180);
                b[0][1] = sin(angle * 3.142 / 180);
                b[0][2] = 0;

                b[1][0] = -sin(angle * 3.142 / 180);
                b[1][1] = cos(angle * 3.142 / 180);
                b[1][2] = 0;

                b[2][0] = -tx * cos(angle * 3.142 / 180) + ty * sin(angle * 3.142 / 180) + tx;
                b[2][1] = -tx * sin(angle * 3.142 / 180) - ty * cos(angle * 3.142 / 180) + ty;
                b[2][2] = 1;
                break;
        }

        initgraph(&gd, &gm, NULL);
        xmax = getmaxx();
        ymax = getmaxy();
        xmid = xmax / 2;
        ymid = ymax / 2;

        setcolor(1);
        line(xmid, 0, xmid, ymax);
        line(0, ymid, xmax, ymid);

        setcolor(4);
        for (i = 0; i < 8; i = i + 2)
        {
                line(p1[i] + xmid, ymid - p1[i + 1], p1[i + 2] + xmid, ymid - p1[i + 3]);
        }

        matmul(p1);
        setcolor(15);
        for (i = 0; i < 8; i = i + 2)
        {
                line(xmid + pi[i], ymid - pi[i + 1], pi[i + 2] + xmid, ymid - pi[i + 3]);
        }
        getch();
        closegraph();
        return 0;
}
void matmul(float p[10])
{
        int i;
        for (i = 0; i < 9; i = i + 2)
        {
                a[0][0] = p[i];
                a[0][1] = p[i + 1];
                c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0] + b[2][0];
                c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1] + b[2][1];
                pi[i] = c[0][0];
                pi[i + 1] = c[0][1];
        }
}

/*********************************************************************************************

 select the transformation
 1:translation
 2:rotation
 3:scaling
 4:rotation about arbitary point
 enter the option:1

 enter x translation:10

 enter y translation:20


*************************************************************************************************/
