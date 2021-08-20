#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
#define maxx getmaxx()
#define maxy getmaxy()
#define SIN(x) sin(x * 3.141592653589 / 180)
#define COS(x) cos(x * 3.141592653589 / 180)

void initscene();
void stars();
void genstars();
void spaceconflict();
void midnaration();
void shipdown();
void shiprun();
void fall();
void opencrawl();
void finale();
void prologue(int);
void breakoff(int, int);
void repship(int, int);
void sepship(int, int);
void citadel(int, int, int);
void invishand(int, int, int);
void reenter(int, int , int);
void shipfront(int, int, int);
void shipback(int, int, int);
void afterburner(int, int, int);
void breakoffsub(int, int, int, int);
void crack(int, int, int, int);
void fighter(int, int, int, int);
void fire(int, int, int, int);
void deltafire(int, int, int, int);
void bluefire(int, int, int, int);
void hide(int, int, int, int);
void explosion(int, int, float, float);
int* rotate(int*, int, int, int, int);
void drawEllipse(int, int, int, int, float, int);

int stararr[500][2];

int main()
{
    int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
    genstars();
    initscene();
    cleardevice();
    shiprun();
    cleardevice();
    midnaration();
    cleardevice();
    shipdown();
    fall();
    finale();
    getch();
	closegraph();
	return 0;
}

void genstars()
{
    int x, y;
    for(int i=0; i<=500; i++)
    {
        x=rand()%getmaxx();
        y=rand()%getmaxy();
        putpixel(x,y,15);
        stararr[i][0] = x;
        stararr[i][1] = y;
    }
}

void initscene()
{
    opencrawl();
    cleardevice();
    stars();
    spaceconflict();
}

void shiprun()
{
    stars();
    invishand(150, 50, 0);
    fighter(maxx/2, 3*maxy/4, 25, YELLOW);
    delay(2000);
    settextstyle(0, 0, 1);
    setcolor(WHITE);
    settextjustify(1, 1);
    outtextxy(maxx/2, maxy-50, "Guude: That's the Dreadnought!");
    delay(3000);
    cleardevice();
    stars();
    invishand(150, 50, 0);
    fighter(maxx/2, 3*maxy/4, 25, YELLOW);
    settextstyle(0, 0, 1);
    setcolor(WHITE);
    outtextxy(maxx/2, maxy-50, "Guude: The Leader ought to be there");
    delay(3000);
    cleardevice();
    stars();
    invishand(150, 50, 0);
    fighter(maxx/2, 2*maxy/3, 20, YELLOW);
    afterburner(maxx/2, 2*maxy/3, 20);
    delay(2000);
    cleardevice();
    stars();
    invishand(150, 50, 0);
    fighter(maxx/2, maxy/2, 15, YELLOW);
    afterburner(maxx/2, maxy/2, 15);
    delay(2000);
    cleardevice();
    stars();
    invishand(150, 50, 0);
    fighter(maxx/2, maxy/3, 10, YELLOW);
    afterburner(maxx/2, maxy/3, 10);
    delay(2000);
}

void midnaration()
{
    stars();
    settextstyle(0, 0, 2);
    setcolor(CYAN);
    settextjustify(1, 1);
    outtextxy(maxx/2, maxy/2, "The Dreadnought was a trap,");
    outtextxy(maxx/2, maxy/2+30, "no one was onboard,");
    outtextxy(maxx/2, maxy/2+60, "communications were cut!");
    delay(5000);
    cleardevice();
    stars();
    outtextxy(maxx/2, maxy/2-80, "With no communication,");
    outtextxy(maxx/2, maxy/2-40, "the Reds were clueless");
    outtextxy(maxx/2, maxy/2, "about the whereabouts of Guude and");
    outtextxy(maxx/2, maxy/2+40, "they decided to destroy");
    outtextxy(maxx/2, maxy/2+80, "the dangerous dreadnought.");
    delay(10000);
}

void shipdown()
{
    int temp = maxy;
    while(temp > 400)
    {
	    cleardevice();
	    stars();
	    invishand(150, 50, 0);
	    repship(550, temp);
	    delay(500);
	    temp -= 20;
    }
    delay(500);
    deltafire(522, 350, 480, 310);
    float a = 0.8;
    float b = 1;
    int c = -0.3;
    for(int i = 1; i<= 5; i++)
    {
        explosion(250, 80, a, b);
        explosion(230, 70, a-0.1, b-0.2);
        explosion(260, 90, a+c, b+c);
        a+=0.1;
        b+=0.1;
        c+=0.4;
        delay(500);
    }
    deltafire(522, 350, 480, 310);
    for(i = 1; i<= 5; i++)
    {
        explosion(250, 80, a, b);
        explosion(230, 70, a-0.1, b-0.2);
        explosion(260, 90, a+c, b+c);
        a+=0.2;
        b+=0.2;
        c+=0.5;
        delay(500);
    }
    for(i = 1; i<= 10; i++)
    {
        cleardevice();
        stars();
        invishand(150-20*i, 50+10*i, -i);
        crack(150-20*i, 50+10*i, BLACK, 0);
        repship(550, temp);
        explosion(250-20*i, 80+10*i, a, b);
        explosion(230-20*i, 70+10*i, a-0.1, b-0.2);
        explosion(260-20*i, 90+10*i, a+c, b+c);
        a-=0.2;
        b-=0.2;
        c-=0.5;
        delay(500);
    }
    for(i = 11; i<= 20; i++)
    {
        cleardevice();
        stars();
        invishand(150-20*i, 50+10*i, -i);
        crack(150-20*i, 50+10*i, BLACK, 0);
        repship(550, temp);
        delay(500);
    }
}

void fall()
{
    cleardevice();
    stars();
    setcolor(CYAN);
    settextstyle(0, 0, 2);
    settextjustify(1, 1);
    outtextxy(maxx/2, maxy/2-80, "the dreadnought has been");
    outtextxy(maxx/2, maxy/2-40, "knocked out of orbit");
    outtextxy(maxx/2, maxy/2, "and it is falling to the surface.");
    outtextxy(maxx/2, maxy/2+40, "Guude just manages to reach");
    outtextxy(maxx/2, maxy/2+80, "the bridge in time, he observes");
    outtextxy(maxx/2, maxy/2+120, "the ship is now engulfed in fire.");
    delay(10000);
    int x = maxx;
    int y = 0;
    int i;
    for(i = 0; i <= 40; i++)
    {
        cleardevice();
        stars();
        invishand(x-10*i, y+6*i, -20);
        reenter(x-10*i, y+6*i, -20);
        citadel(x-10*i, y+6*i, -20);
        crack(x-10*i, y+6*i, RED, -20);
        if(i<10)
        {
            setcolor(GREEN);
            settextstyle(0, 0, 1);
            settextjustify(0, 1);
            outtextxy(20, 50, "Upper atmosphere");
        }
        delay(300);
    }
    int xn = x-10*i;
    int yn = y+6*i;
    setcolor(WHITE);
    settextstyle(0, 0, 1);
    settextjustify(1, 1);
    outtextxy(maxx/2, maxy-80, "Guude: If the ship remains in one");
    outtextxy(maxx/2, maxy-50, "piece, i should be able to land it safely");
    delay(4000);
    breakoff(xn, yn);
    delay(1000);
}

void finale()
{
    cleardevice();
    stars();
    shipfront(maxx/2, maxy/2, -20);
    reenter(maxx/2, maxy/2, -20);
    setcolor(WHITE);
    settextstyle(0, 0, 1);
    settextjustify(1, 1);
    outtextxy(maxx/2, maxy-80, "Guude: I think i lost something important");
    delay(6000);
    cleardevice();
    stars();
    settextstyle(10, 0, 0);
    setcolor(YELLOW);
    settextjustify(1, 1);
    outtextxy(maxx/2, maxy/2, "To be continued...");
    delay(10000);
    cleardevice();
    stars();
    settextstyle(0, 0, 2);
    settextjustify(1, 1);
    setcolor(CYAN);
    outtextxy(maxx/2, maxy/2-40, "Created by");
    outtextxy(maxx/2, maxy/2, "Nimish Jayakar");
    outtextxy(maxx/2, maxy/2+40, "19302F0013");
    delay(5000);
}

void breakoff(int x, int y)
{
    for(int i = 0; i<=37; i++)
    {
        cleardevice();
        stars();
        shipfront(x-10*i, y+6*i, -20);
        reenter(x-10*i, y+6*i, -20);
        shipback(x, y, -20-2*i);
        citadel(x, y, -20-2*i);
        crack(x, y, RED, -20-2*i);
        breakoffsub(x-i, y-5*i, 20, i);
        setcolor(WHITE);
        settextstyle(0, 0, 1);
        settextjustify(1, 1);
        if(i>30)
        {
            outtextxy(maxx/2, maxy-80, "Guude: ...");
        }
        delay(300);
    }
}

void breakoffsub(int x, int y, int angle, int i)
{
    int xn = x+i;
    int yn = y+5*i;
    int nangle = -angle-2*i;
    int arr[] = {xn+70, yn, xn+200, yn, xn+200, yn+2, xn+70, yn+2};
    int *redd = rotate(arr, 8, xn, yn, nangle);
    setfillstyle(SOLID_FILL, RED);
    fillpoly(4, redd);
    drawEllipse(x+70, y+30, 110, 50+2*i, angle, RED);
    drawEllipse(x+69, y+30, 110, 50+2*i, angle, RED);
    drawEllipse(x+68, y+31, 110, 50+2*i, angle, RED);
    drawEllipse(x+67, y+31, 110, 50+2*i, angle, RED);
}

void reenter2(int x, int y)
{
    drawEllipse(x, y+30, 110, 50, 20, RED);
    drawEllipse(x-1, y+30, 110, 50, 20, RED);
    drawEllipse(x-2, y+31, 110, 50, 20, RED);
    drawEllipse(x-3, y+31, 110, 50, 20, RED);
}

void reenter(int x, int y, int angle)
{
    int ired[] = {x, y+60, x-100, y+40, x-100, y+30, x-30, y, x, y, x, y+4, x-30, y+4, x-96, y+30, x-96, y+40, x, y+56};
    int *red = rotate(ired, 20, x, y, angle);
    reenter2(x, y);
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    fillpoly(10, red);
}

void shipfront(int x, int y, int angle)
{
    setcolor(DARKGRAY);
    int def1[] = {x, y, x+70, y, x+50, y+20, x+70, y+40, x+50, y+60, x, y+60, x-100, y+40, x-100, y+30, x-30, y};
    int decal[6] = {x-50, y+20, x-50, y+40, x-10, y+30};
    int *outline = rotate(def1, 18, x, y, angle);
    int *decalf = rotate(decal, 6, x, y, angle);
    setfillstyle(SOLID_FILL, DARKGRAY);
    fillpoly(9, outline);
    setfillstyle(SOLID_FILL, BLUE);
    fillpoly(3, decalf);
}

void citadel(int x, int y, int angle)
{
    int cit[] = {x+200, y, x+215, y-25, x+210, y-25, x+210, y-30, x+220, y-30, x+202, y};
    int *redcit = rotate(cit, 12, x, y, angle);
    setfillstyle(SOLID_FILL, RED);
    fillpoly(6, redcit);
}

void shipback(int x, int y, int angle)
{
    int def1[] = {x+70, y, x+200, y, x+215, y-25, x+210, y-25, x+210, y-30, x+225, y-30, x+205, y, x+250, y, x+250, y+60, x+50, y+60, x+70, y+40, x+50, y+20, x+70, y};
    int def2[] = {x+250, y, x+300, y, x+250, y+60};
    int eng1[] = {x+270, y+10, x+270, y+30, x+310, y+30, x+310, y+10};
    int eng2[] = {x+250, y+35, x+250, y+55, x+290, y+55, x+290, y+35};
    int deck[] = {x+150, y+30, x+150, y+40, x+200, y+40, x+200, y+30};
    int decal4[12] = {x+110, y+50, x+90, y+30, x+110, y+10, x+130, y+10, x+110, y+30, x+130, y+50};
    int *outline1 = rotate(def1, 26, x, y, angle);
    int *outline2 = rotate(def2, 6, x, y, angle);
    int *engine1 = rotate(eng1, 8, x, y, angle);
    int *engine2 = rotate(eng2, 8, x, y, angle);
    int *deckf = rotate(deck, 8, x, y, angle);
    int *decal4f = rotate(decal4, 12, x, y, angle);
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, DARKGRAY);
    fillpoly(13, outline1);
    setcolor(LIGHTCYAN);
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    fillpoly(4, engine1);
    fillpoly(4, engine2);
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, DARKGRAY);
    fillpoly(3, outline2);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    fillpoly(4, deckf);
    setfillstyle(SOLID_FILL, BLUE);
    fillpoly(6, decal4f);
}

void crack(int x, int y, int color, int angle)
{
    setcolor(color);
    int arr[] = {x+70, y, x+50, y+20, x+70, y+40, x+50, y+60, x+52, y+60, x+72, y+40, x+52, y+20, x+72, y};
    int *farr = rotate(arr, 16, x, y, angle);
    setfillstyle(SOLID_FILL, color);
    fillpoly(8, farr);
}

void invishand(int x, int y, int angle)
{
	shipfront(x, y, angle);
	shipback(x, y, angle);
	setcolor(BLUE);
	int decal2[12] = {x+50, y+50, x+30, y+30, x+50, y+10, x+70, y+10, x+50, y+30, x+70, y+50};
	int decal3[12] = {x+80, y+50, x+60, y+30, x+80, y+10, x+100, y+10, x+80, y+30, x+100, y+50};
	int *decal2f = rotate(decal2, 12, x, y, angle);
	int *decal3f = rotate(decal3, 12, x, y, angle);
	setfillstyle(SOLID_FILL, BLUE);
	fillpoly(6, decal2f);
	fillpoly(6, decal3f);
}

void explosion(int x, int y, float i, float j)
{
    int exp1[] = {x-j*18, y, x-i*10, y-i*4, x-i*14, y-i*13, x-i*4, y-i*10, x, y-j*18, x+i*4, y-i*10, x+i*14, y-i*13, x+i*10, y-i*4, x+j*18, y, x+i*10, y+i*4, x+i*14, y+i*13, x+i*4, y+i*10, x, y+j*18, x-i*4, y+i*10, x-i*14, y+i*13, x-i*10, y+i*4};
    i/=2;
    j/=2;
    int exp2[] = {x-j*18, y, x-i*10, y-i*4, x-i*14, y-i*13, x-i*4, y-i*10, x, y-j*18, x+i*4, y-i*10, x+i*14, y-i*13, x+i*10, y-i*4, x+j*18, y, x+i*10, y+i*4, x+i*14, y+i*13, x+i*4, y+i*10, x, y+j*18, x-i*4, y+i*10, x-i*14, y+i*13, x-i*10, y+i*4};
    int *fexp = rotate(exp2, 32, x, y, 55);
    setcolor(YELLOW);
    fillpoly(16, exp1);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(x, y, YELLOW);
    setcolor(RED);
    fillpoly(16, fexp);
    setfillstyle(SOLID_FILL, RED);
    floodfill(x, y, RED);
}

void spacefight()
{
    fire(275, 390, 320, 370);
    fire(350, 300, 395, 300);
    delay(500);
    hide(350, 300, 395, 300);
    hide(275, 390, 320, 370);
    fire(340, 361, 385, 341);
    fire(415, 300, 460, 300);
    bluefire(530, 175, 375, 225);
    delay(500);
    hide(415, 300, 460, 300);
    hide(340, 361, 385, 341);
    bluefire(530, 175, 320, 242);
    fire(405, 332, 450, 312);
}

void prologue(int i)
{
    repship(200, 425+i);
    repship(100, 350+i);
    repship(300, 300+i);
    sepship(450, 300+i);
    sepship(550, 200+i);
}

void sepship(int x, int y)
{
    setcolor(LIGHTGRAY);
    ellipse(x, y, 180, 360, 25, 50);
    int poly[8] = {x-25, y, x-15, y-75, x+15, y-75, x+25, y};
    drawpoly(4, poly);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    floodfill(x, y, LIGHTGRAY);
    setcolor(BLUE);
    int decal1[6] = {x-10, y, x+10, y, x, y-25};
    int decal2[12]  = {x-20, y-65, x, y-55, x+20, y-65, x+20, y-55, x, y-45, x-20, y-55};
    fillpoly(3, decal1);
    fillpoly(6, decal2);
    setfillstyle(SOLID_FILL, BLUE);
	floodfill(x-9,y-1, BLUE);
	floodfill(x, y-46, BLUE);
}

void repship(int x, int y)
{
    setcolor(DARKGRAY);
    int body[10] = {x-50, y, x, y+20, x+50, y, x+20, y-10, x-20, y-10};
    fillpoly(5, body);
    line(x-50, y, x, y-100);
    line(x+50, y, x, y-100);
    line(x-20, y-10, x,y-100);
    line(x+20, y-10, x,y-100);
    setfillstyle(SOLID_FILL, DARKGRAY);
    floodfill(x, y, DARKGRAY);
    floodfill(x, y-90, DARKGRAY);
    floodfill(x-21, y-11, DARKGRAY);
    floodfill(x+21, y-11, DARKGRAY);
    setcolor(RED);
    line(x-50, y, x, y-100);
    line(x+50, y, x, y-100);
    line(x-20, y-10, x,y-100);
    line(x+20, y-10, x,y-100);
    line(x-50, y, x-20, y-10);
    line(x+50, y, x+20, y-10);
    line(x-20, y-10, x+20, y-10);
    setfillstyle(SOLID_FILL, RED);
    floodfill(x-21, y-50, RED);
    floodfill(x+21, y-50, RED);
    setcolor(CYAN);
    circle(x, y+10, 12);
    circle(x-24, y+5, 12);
    circle(x+24, y+5, 12);
    setfillstyle(SOLID_FILL, CYAN);
    floodfill(x, y+10, CYAN);
    floodfill(x-24, y+5, CYAN);
    floodfill(x+24, y+5, CYAN);
}

void opencrawl()
{
    stars();
    settextstyle(10, 0, 0);
    setcolor(YELLOW);
    settextjustify(1, 1);
    outtextxy(maxx/2, maxy/2, "Conflict in Space");
    delay(5000);
    cleardevice();
    stars();
    settextstyle(0, 0, 2);
    setcolor(CYAN);
    outtextxy(maxx/2, maxy/3, "Evil Strikes!");
    outtextxy(maxx/2, maxy/2, "The Blues have attacked the Reds");
    outtextxy(maxx/2, maxy/2+30, "and captured their leader.");
    outtextxy(maxx/2, maxy/2+60, "Now it is upto Guude");
    outtextxy(maxx/2, maxy/2+90, "to rescue the leader.");
    delay(8000);
}

void spaceconflict()
{
    prologue(0);
    setcolor(GREEN);
    settextstyle(0, 0, 1);
    settextjustify(0, 1);
    outtextxy(20, 50, "19 BBY");
    outtextxy(20, 60, "High above Coruscant");
    delay(3000);
    cleardevice();
    stars();
    prologue(0);
    spacefight();
    float a = 0.4;
    float b = 0.6;
    for(int i = 1; i<= 5; i++)
    {
        explosion(450, 320+i, a, b);
        explosion(460, 300+i, a, b);
        explosion(320, 242+i, a+0.2, b+0.3);
        a+=0.1;
        b+=0.1;
        delay(250);
    }
    delay(500);
    cleardevice();
    stars();
    prologue(0);
    explosion(450, 320, a, b);
    explosion(460, 300, a, b);
    explosion(320, 242, a+0.2, b+0.3);
    delay(2000);
    cleardevice();
    stars();
    int tempy = -60;
    for(i = 1; i< maxy/2; i+=20)
    {
        stars();
        prologue(i);
        explosion(450, 320+i, a, b);
        explosion(460, 300+i, a, b);
        explosion(320, 242+i, a+0.2, b+0.3);
        delay(500);
        cleardevice();
        if(i> 121)
        {
            stars();
            tempy+=20;
            invishand(150, tempy, 0);
        }
    }
    delay(2000);
    fighter(maxx/2, 6*maxy/7, 35, YELLOW);
    afterburner(maxx/2, 6*maxy/7, 35);
    delay(2000);
    cleardevice();
    stars();
    invishand(150, 50, 0);
    fighter(maxx/2, 5*maxy/6, 30, YELLOW);
    afterburner(maxx/2, 5*maxy/6, 30);
    delay(2000);
}

void fighter(int x, int y, int r, int color)
{
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    fillellipse(x, y, r, r);
    ellipse(x, y, 0, 90, r, 2*r);
    ellipse(x, y, 90, 180, r, 2*r);
    line(x-r, y, x-2*r, y);
    line(x-2*r, y, x-r+5, y-r);
    line(x+r, y, x+2*r, y);
    line(x+2*r, y, x+r-5, y-r);
    floodfill(x, y-r-1, color);
    floodfill(x-r-1, y-2, color);
    floodfill(x+r+1, y-2, color);
    setcolor(LIGHTCYAN);
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    fillellipse(x-r/2, y+r/2, r/3, r/3);
    fillellipse(x+r/2, y+r/2, r/3, r/3);
    fillellipse(x, y+r/4, r/3, r/3);
    setcolor(RED);
    line(x-r/4, y-r/4,x+r/4, y-r/4);
    line(x-1, y-r/4, x, y-2*r/3);
    line(x+1, y-r/4, x, y-2*r/3);
    setcolor(DARKGRAY);
    circle(x, y, r);
    ellipse(x, y, 0, 90, r, 2*r);
    ellipse(x, y, 90, 180, r, 2*r);
    setcolor(CYAN);
    arc(x, y, 70, 110, r);
    ellipse(x, y-r, 350, 90, r/3, r/2);
    ellipse(x, y-r, 90, 190, r/3, r/2);
    setfillstyle(SOLID_FILL, CYAN);
    floodfill(x, y-r-2, CYAN);
}

void afterburner(int x, int y, int r)
{
    setcolor(LIGHTCYAN);
    ellipse(x-r/2, y+r/2, 270, 360, r/3, r);
    ellipse(x-r/2, y+r/2, 180, 270, r/3, r);
    ellipse(x+r/2, y+r/2, 270, 360, r/3, r);
    ellipse(x+r/2, y+r/2, 180, 270, r/3, r);
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    floodfill(x-r/2, y+r, LIGHTCYAN);
    floodfill(x+r/2, y+r, LIGHTCYAN);
}

void fire(int x1, int y1, int x2, int y2)
{
    setcolor(LIGHTGREEN);
    line(x1, y1, x2, y2);
}

void deltafire(int x1, int y1, int x2, int y2)
{
    float m = 125.0/131.0;
    float c = 19400.0/131.0;
    int yn1 = (m*(x1-70))-c;
    int yn2 = (m*(x2-70))-c;
    int yn3 = (m*(x1-140))-c;
    int yn4 = (m*(x2-140))-c;
    int yn5 = (m*(x1-210))-c;
    int yn6 = (m*(x2-210))-c;
    fire(x1, y1, x2, y2);
    delay(500);
    hide(x1, y1, x2, y2);
    fire(x1, y1-15, x2, y2-15);
    fire(x1-70, yn1, x2-70, yn2);
    delay(500);
    hide(x1, y1-15, x2, y2-15);
    hide(x1-70, yn1, x2-70, yn2);
    fire(x1-70, yn1-15, x2-70, yn2-15);
    fire(x1-140, yn3, x2-140, yn4);
    fire(x1, y1+15, x2, y2+15);
    delay(500);
    hide(x1-70, yn1-15, x2-70, yn2-15);
    hide(x1-140, yn3, x2-140, yn4);
    hide(x1, y1+15, x2, y2+15);
    fire(x1-140, yn3-15, x2-140, yn4-15);
    fire(x1-210, yn5, x2-210, yn6);
    fire(x1-70, yn1+15, x2-70, yn2+15);
    delay(500);
    hide(x1-140, yn3-15, x2-140, yn4-15);
    hide(x1-210, yn5, x2-210, yn6);
    hide(x1-70, yn1+15, x2-70, yn2+15);
    fire(x1-210, yn5-15, x2-210, yn6-15);
    fire(x1-140, yn3+15, x2-140, yn4+15);
    delay(500);
    hide(x1-210, yn5-15, x2-210, yn6-15);
    hide(x1-140, yn3+15, x2-140, yn4+15);
    fire(x1-210, yn5+15, x2-210, yn6+15);
    delay(500);
    hide(x1-210, yn5+15, x2-210, yn6+15);
}

void bluefire(int x1, int y1, int x2, int y2)
{
    setcolor(LIGHTBLUE);
    line(x1, y1, x2, y2);
}

void hide(int x1, int y1, int x2, int y2)
{
    setcolor(BLACK);
    line(x1, y1, x2, y2);
}

void stars()
{
    for(int i=0; i<=500; i++)
    {
        putpixel(stararr[i][0], stararr[i][1], 15);
    }
}

void drawEllipse(int xc, int yc, int a, int b, float alpha, int color)
{
    float t = 3.14 / 180;
    alpha = 360 - alpha;
    setcolor(color);
    int theta;
    for (int i = 90; i < 270; i += 1)
    {
        theta = i;
        int x = a * cos(t * theta) * cos(t * alpha) + b * sin(t * theta) * sin(t * alpha);
        int y = b * sin(t * theta) * cos(t * alpha) - a * cos(t * theta) * sin(t * alpha);
        putpixel(xc + x, yc - y, color);
    }
}

int* rotate(int* a, int n, int x_pivot, int y_pivot, int angle)
{
    int i = 0;
    while (i < n)
    {
        int x_shifted = a[i] - x_pivot;
        int y_shifted = a[i+1] - y_pivot;
        a[i] = x_pivot + (x_shifted * COS(angle) - y_shifted * SIN(angle));
        a[i+1] = y_pivot + (x_shifted * SIN(angle) + y_shifted * COS(angle));
        i+=2;
    }
    return a;
}
