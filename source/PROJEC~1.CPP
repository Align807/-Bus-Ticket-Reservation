
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<process.h>
#include<graphics.h>
#include<string.h>
#include<time.h>
#include<Load.h>
#include<busclass.h>
#include<func.h>
#include<menu.h>

void modifymenu();
void mainmenu(int);

void main()
{

int gdriver = DETECT, gmode;
	 initgraph(&gdriver, &gmode, "c:/turboc3/bgi");
	loading();
	box1();
	cleardevice();
closegraph();
getch();

}
