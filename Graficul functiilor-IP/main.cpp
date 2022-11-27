/*
Plan:
-transformare in plan complet/full screen
-poza de la zona cu functia si evaluatorul
-limba
-sunet
-poate integrala, zoom, stanga dreapta
Grafic:
-punct minim
-punct maxim
-asimptota verticala
-asimptota orizontala
-grafic efectiv cu linii
-transformare sir caractere->functie
-puncte de discontinuitate
Evaluator:
-restrictii fiecare semn
-stive?
*/
#include<iostream>
#include <graphics.h>
#include <winbgim.h>
using namespace std;
//Ana-Maria
void click(int &coordxclick, int &coordyclick )
{
    int x, y;
    while(!ismouseclick(WM_LBUTTONDOWN))
        delay(20);
    getmouseclick(WM_LBUTTONDOWN, x, y);
    coordxclick=x;
    coordyclick=y;
}


int main()
{
    //Ana-Maria Ursache
    int coordx, coordy;

    //window initialization
    int height=GetSystemMetrics(SM_CYSCREEN);
    int width=GetSystemMetrics(SM_CXSCREEN);
    initwindow(width,height,"Name");

    // background image
    readimagefile("image1_1.jpg",0,0,width,height);

    //text
    setcolor(WHITE);
    settextstyle(6, HORIZ_DIR, 8 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/2,height/4,"Graficul functiei");
    rectangle(width/2-379,height/4-63,width/2+376,height/4+15);

    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(width/2,height/2,"Grafic");
    rectangle(width/2,height/2,width/2,height/2);

    outtextxy(width/2,height/2+150,"Contact");
    rectangle(width/2,(height/2+150),width/2,(height/2+150));


    //buton
    click(coordx,coordy);
    if(coordx>=339&&coordx<=440&&coordy>=330&&coordy<=370)
        {
            initwindow(800,800);
            getch();
            closegraph();
        }
        else if(coordx>=330&&coordx<=460&&coordy>=430&&coordy<=470)
            {
                initwindow(800,800);
                settextstyle(7, HORIZ_DIR, 5);
                outtextxy(100,200,"Proiectul a fost realizat de:");
                settextstyle(7, HORIZ_DIR, 4);
                outtextxy(200,350,"Ursache Ana-Maria");
                settextstyle(7, HORIZ_DIR, 3);
                outtextxy(380,400,"si");
                settextstyle(7, HORIZ_DIR, 4);
                outtextxy(250,450,"Galatanu Emilia");
                getch();
                closegraph();
            }
    getch();
    closegraph();
    return 0;
}
