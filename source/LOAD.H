
void heading()
{
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
	setcolor(14);
	line(1,1,630,1);
	line(1,60,630,60);
	line(1,440,630,440);
	line(1,1,1,440);
	line(630,1,630,440);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	setcolor(12);
	outtextxy(100,20,"SANCHAR BUS");

	setcolor(15);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(270,20,"TICKET");

	setcolor(2);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	outtextxy(368,20,"RESERVATION SYSTEM");

}
//function to display menu box of main menu
void menuscreen()
{
	cleardevice();
     setcolor(4);
     int poly[8]={0,0,650,0,650,20,0,20};
     setfillstyle(SOLID_FILL,7);
     fillpoly(4, poly);

     int poly2[8]={650,55,0,55,0,75,650,75};   //second horizontal line
     setfillstyle(SOLID_FILL,7);
     fillpoly(4,poly2);

     int poly3[8]={650,465,0,465,0,500,650,500};
     setfillstyle(SOLID_FILL,7);			//horizontal bottom
     fillpoly(4,poly3);

     setcolor(4);
     int poly4[8]={0,0,5,0,5,500,0,500};       //vertical first line
     setfillstyle(SOLID_FILL,7);
     fillpoly(4,poly4);

     int poly5[8]={230,75,235,75,235,500,230,500}; //vertical  second line
     setfillstyle(SOLID_FILL,7);
     fillpoly(4,poly5);

     int poly6[8]={635,0,640,0,640,1000,635,1000};  //vertical last line
     setfillstyle(SOLID_FILL,7);
     fillpoly(4,poly6);

	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	setcolor(12);
	outtextxy(90,20,"SANCHAR BUS");

	setcolor(15);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(260,20,"TICKET");

	setcolor(2);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(360,20,"RESERVATION SYSTEM");
}

void logo()
{
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	setcolor(12);
	outtextxy(275,168,"SANCHAR BUS");

	setcolor(15);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(300,185,"TICKET");

	setcolor(2);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	outtextxy(242,202,"RESERVATION SYSTEM");
}
void loading()
{
cleardevice();
setbkcolor(0);
logo();
setcolor(15);
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy(400,450,"LOADING.....PLEASE WAIT.....");

int x=170;
	for(int i=0;i<=320;++i)
	{       delay(30);
		setcolor(14);
		rectangle(170,250,490,260);
		line(x,250,x,260);
		if(i==310)
		{       settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			outtextxy(170,265,"CONNECTED.....");

		}
	x++;
	}
	//getch();
	delay(1000);

}
void credits()
{
	for(int y=500;y+440>=-10;y-=10)
	{
		cleardevice();
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	setcolor(12);
	outtextxy(275,y,"SANCHAR BUS");

	setcolor(15);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(300,y+17,"TICKET");

	setcolor(2);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	outtextxy(242,y+34,"RESERVATION SYSTEM");

	setcolor(15);
	outtextxy(125,y+72,"This is a convenient program that emphasise ");
	outtextxy(120,y+92,"to manifest the promptness in right direction");
	outtextxy(107,y+112,"of a sample with limited size.This can be ellaborated ");
	outtextxy(125,y+132,"without any distraction for a large frame.");
	outtextxy(122,y+172,"We must offer special thanks to our teachers ");
	outtextxy(121,y+192,"Mrs.Jini Elizabeth and Mrs Jestina P. Cherian ");
	outtextxy(70,y+212,"whose enthusiasm always inspire us to dream big dreams ");
	outtextxy(45,y+232,"by shaping and articulating our ideas to make this flamboyant");

	setcolor(3);
	settextstyle(1,HORIZ_DIR,2);
	outtextxy(225,y+270,"PROGRAM COORDINATORS:");
	setcolor(15);
	settextstyle(3,HORIZ_DIR,1);
	outtextxy(235,y+320,"1.KEVIN GEORGE SABU");
	outtextxy(235,y+350,"2.JEROME CHERIAN PHILIP");
	outtextxy(235,y+380,"3.CHRISTINA SUSAN BIJI");
	outtextxy(235,y+410,"4.TITTU SARA TITUS");
	outtextxy(235,y+440,"5.ALIGN ELSA AGITH");
	delay(400);
	// if(getch())
		  //	return;
	}
	return;
}

char* password()
{
	setcolor(15);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
    char h[12]={""};
    char a[12]={""},ch;
    int i=0;
    while(!kbhit())
    {
     ch=getch();
     a[i]='*';
     if(ch=='\b')
     {   a[i]='*';
	 setcolor(0);
	 outtextxy(250,217,a);
	 a[i-1]=' ';
	 a[i--]=' ';
	 h[i--]='\0';
	 setcolor(15);
	 outtextxy(250,217,a);
    }
    else if(ch=='\r')
    {
	 h[i]='\0';
	return h;
    }
    else
    {   a[i]='*';
	h[i]=ch;
	setcolor(15);
	outtextxy(250,217,a);
    }
    i++;
     if(i<0)
	i++;
}
}
void rect(int y)
{     setcolor(14);
     int box[8]={5,y,230,y,230,y+60,5,y+60};
     setfillstyle(SOLID_FILL,8);
     fillpoly(4, box);

}
void rect2(int z)
{     setcolor(14);
     int box[8]={180,z,460,z,460,z+60,180,z+60};
     setfillstyle(SOLID_FILL,8);
     fillpoly(4, box);

}
void rect3(int z)
{     setcolor(14);
     int box[8]={180,z,460,z,460,z+40,180,z+40};
     setfillstyle(SOLID_FILL,8);
     fillpoly(4, box);

}
void rect4(int z)
{
	setcolor(14);
     rectangle(160,250,230,290);
     rectangle(270,250,340,290);
     int box[8]={z,250,z+70,250,z+70,290,z,290};
     setfillstyle(SOLID_FILL,8);
     fillpoly(4, box);
     outtextxy(180,260,"YES");
     outtextxy(295,260,"NO");
}