#include <iostream>
#include<winbgim.h>
#include<graphics.h>
using namespace std;

int functie(int x,int a,int b,int c)
{
    if(x==0)
        return c;
    return a*x*x+b*x+c;
}
void reprezentare_grafic(int a,int b, int x1, int x2, int y1, int y2,int m,int n, int p)
{
    int x0,y0,xe,ye,i,xev,yev,ymin,ymax, aux,x,y;
     rectangle(x1,y1,x2,y2);
     ymin=functie(a,m,n,p);
        ymax=ymin;
        for(i=0;i<=x1-x2;i++)
        {
            x=a+i*(b-a)/(x2-x1);
            y=functie(x,m,n,p);

            if (y>ymax)
                ymax=y;

            if (y<ymin)
                ymin=y;
        }

    x0 = ((b*x1-a*x2)/(b-a));

    if ((a<=0) && (0<=b))
        line(x0,y2,x0,y1);

     y0 = ((ymax*y1-ymin*y2)/(ymax-ymin));

     if ((ymin<=0) && (0<=ymax))
        line(x1,y0,x2,y0);

     x= a;
     y= functie(a,m,n,p);
     xev = ((x2-x1)*x/(b-a)+(b*x1-a*x2)/(b-a));
     yev = ((y2-y1)*y/(ymax-ymin)+(ymax*y1-ymin*y2)/(ymax-ymin));

     for (i= 0;i<=(x2-x1);i++)
        {
        x=a+i*(b-a)/(x2-x1);
        xe=((x2-x1)*x/(b-a)+(b*x1-a*x2)/(b-a));
        y=functie(x,m,n,p);
        ye=((y2-y1)*y/(ymax-ymin)+(ymax*y1-ymin*y2)/(ymax-ymin));
        line(xev,yev,xe,ye);
        xev = xe; yev = ye;}
}


int main()
{
   int m,n,p,a,b;
 cin>>a>>b>>m>>n>>p;
    int height=GetSystemMetrics(SM_CYSCREEN);
    int width=GetSystemMetrics(SM_CXSCREEN);
    initwindow(width,height,"Name");


    reprezentare_grafic(a,b,50,600,400,100,m,n,p);
    getch();
    closegraph();

    return 0;
}
