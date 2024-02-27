

///Menu no: 9 -> Modify passenger details
void pass_modify(int y)
{
	cleardevice();
	heading();
	setcolor(3);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(240,70,"MODIFICATION MENU  ");
		    rect2(y);
	setcolor(14);
	rectangle(180,120,460,300);
	setcolor(13);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(210,150,"Change Password  ");
	outtextxy(210,210,"Change Phone number");
	outtextxy(210,270,"Back ");


}
 void box9()
{

		int key,x=120 , menu=1;
while(menu)
{
     pass_modify(x);
     switch(key=getch())
     {   case 80:
	if(x!=240)
	{
		x+=60;
		pass_modify(x);
		menu++;
		continue;
	}
	if(x==240||menu==3)
	{
		x=120;
		pass_modify(x);
		menu=1;  continue;
	}
     break;
     case 72:
	if(x!=120)
	{
		x-=60;
		pass_modify(x);
		menu--;  continue;
	}
	else if(x==120||menu==1)
	{
		x=240;
		pass_modify(x);
		menu=3;  continue;
	}

     break;
     default:
      if((char)key=='\r')
     {
	switch(menu)
	{
	  case 1:	P.change_password(); break;
	  case 2:	P.change_phonenum(); break;
	  case 3:        return;
	}
	if(menu<3)
	{
		gotoxy(26,20);cout<<"MODIFIED!!!";
		getch();
	}

     }
     }
}
}

///Menu no: 8 -> SETTINGS
void settings(int y)
{
	cleardevice();
	heading();
	setcolor(2);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(220,70,"SETTINGS");
		    rect2(y);
	setcolor(14);
	rectangle(180,120,460,360);
	setcolor(13);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(210,150,"Source and destination");
	outtextxy(210,210,"Date ");
	outtextxy(210,270,"Charge per seat ");
	outtextxy(210,330,"Back ");
}

 void box8()
{

		int key,ch=1 , x=120 , menu=1;
while(menu)
{
     settings(x);
      switch(key=getch())
     {   case 80:
	if(x!=300)
	{
		x+=60;
		settings(x);
		menu++;
		continue;
	}
	if(x==300||menu==4)
	{
		x=120;
		settings(x);
		menu=1;  continue;
	}
     break;
     case 72:
	if(x!=120)
	{
		x-=60;
		settings(x);
		menu--;  continue;
	}
	else if(x==120||menu==1)
	{
		x=300;
		settings(x);
		menu=4;  continue;
	}
	break;
     default:
     if((char)key=='\r')
     {
	cleardevice();
	heading();

	switch(menu)
	{
		case 1: Bus.routechange(); break;
		case 2: Bus.datechange();  break;
		case 3: Bus.farechange();  break;
		case 4: return;
	}
	if(menu<4)
		gotoxy(23,23);cout<<"MODIFIED!!!";
		getch();

     }
     }
}
}
//////Menu no:7 -> MODIFICATION MENU
void modifymenu(int y)
{
	cleardevice();
	heading();
	setcolor(3);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(240,70,"MODIFICATION MENU  ");
		    rect2(y);
	setcolor(14);
	rectangle(180,120,460,300);
	setcolor(13);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(210,150,"Modify  ");
	outtextxy(210,210,"Display modified data");
	outtextxy(210,270,"Back ");

}
 void box7()
{

		int key, x=120 , menu=1;
while(menu)
{
     modifymenu(x);
      switch(key=getch())
     {   case 80:
	if(x!=240)
	{
		x+=60;
		modifymenu(x);
		menu++;
		continue;
	}
	if(x==240||menu==3)
	{
		x=120;
		modifymenu(x);
		menu=1;  continue;
	}
    break;
    case 72:
	if(x!=120)
	{
		x-=60;
		modifymenu(x);
		menu--;  continue;
	}
	else if(x==120||menu==1)
	{
		x=240;
		modifymenu(x);
		menu=3;  continue;
	}
     break;
     default:
     if((char)key=='\r')
     {
	switch(menu)
	{
	  case 1: modify();		break;
	  case 2: displaybus(1);getch(); break;
	  case 3:        return;
	}

     }
     }
}
}
//////Menu no:6 -> BUS SETTINGS
void bussetting(int y)
{
cleardevice();
heading();
	setcolor(2);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(240,70,"BUS SETTINGS");
		    rect3(y);
	setcolor(14);
	rectangle(180,130,460,330);
	setcolor(13);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(210,140,"Add bus details");
	outtextxy(210,180,"Delete bus details");
	outtextxy(210,220,"Modify bus details ");
	outtextxy(210,260,"Display bus details ");
	outtextxy(210,300,"Back ");

}
void box6()
{

		int key,x=130 , menu=1;
while(menu)
{
     bussetting(x);
      switch(key=getch())
     {   case 80:
	if(x!=290)
	{
		x+=40;
		bussetting(x);
		menu++;
		continue;
	}
	if(x==290||menu==5)
	{
		x=130;
		bussetting(x);
		menu=1;  continue;
	}
    break;
    case 72:
	if(x!=130)
	{
		x-=40;
		bussetting(x);
		menu--;  continue;
	}
	else if(x==130||menu==1)
	{
		x=290;
		bussetting(x);
		menu=5;  continue;
	}
     break;
     default:
     if((char)key=='\r')
     {
	switch(menu)
	{
		case 1: addbus();   		break;
		case 2: deletebus();		break;
		case 3: box7();		   	break;
		case 4: displaybus(1);getch();  break;
		case 5: return;
	}

     }
     }
}
}
//////Menu no:5 -> ADMINSTRATOR SETTING
void adminsettings(int y)
{
	cleardevice();
	heading();
	setcolor(2);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(220,70,"ADMINISTRATOR SETTINGS");
		    rect2(y);
	setcolor(14);
	rectangle(180,120,460,360);
	setcolor(13);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(210,140,"BUS SETTINGS ");
	outtextxy(210,200,"RESERVATION DETAILS ");
	outtextxy(210,260,"PASSENGER DETAILS ");
	outtextxy(210,320,"BACK ");

}
 void box5()
{

		int key, ch=1 , x=120 , menu=1;
while(menu)
{
     adminsettings(x);
     switch(key=getch())
     {   case 80:
	if(x!=300)
	{
		x+=60;
		adminsettings(x);
		menu++;
		continue;
	}
	if(x==300||menu==4)
	{
		x=120;
		adminsettings(x);
		menu=1;  continue;
	}
    break;
    case 72:
	if(x!=120)
	{
		x-=60;
		adminsettings(x);
		menu--;  continue;
	}
	else if(x==120||menu==1)
	{
		x=300;
		adminsettings(x);
		menu=4;  continue;
	}
    break;
    default:
     if((char)key=='\r')
     {
	switch(menu)
	{
		case 1: box6();		    break;
		case 2:	disp_allreserve();  break;
		case 3: disp_allpass();     break;
		case 4: return;
	}
     }
     }
}
}


void admin()
{
      int b=1;
      char pass[8]="admin";
pass:
	setcolor(3);
	cleardevice();
	settextstyle(1,HORIZ_DIR,3);
	outtextxy(20,210,"Admin password :");
	rectangle(240,210,350,245);

if(strcmpi(pass,password())==0)
{
	box5();
}//end of if

else            ////wrong password
{
	b++;
	gotoxy(34,20);cout<<"Wrong password!!!!!!";
	if(b<4)
	{
	gotoxy(34,25);cout<<"try again";
	getch();
	goto pass;
	}
	else
	{
		cleardevice();
		gotoxy(19,14);cout<<"Thank you for using the program";
		getch();
		exit(0);
	}
}
} //end of function

/////Menu no:4 -> RESERVATION MENU
void reser_menu(int y)
{
cleardevice();
heading();
	setcolor(2);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(240,70,"RESERVATION MENU");
		    rect3(y);
	setcolor(14);
	rectangle(180,130,460,330);
	setcolor(13);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(210,140,"ENQUIRY ");
	outtextxy(210,180,"TICKET BOOKING");
	outtextxy(210,220,"BOOKING RECORD ");
	outtextxy(210,260,"CANCELLATION  ");
	outtextxy(210,300,"BACK ");

}
 void box4()
{

		int key,ch=1 , x=130 , menu=1;
while(menu)
{
     reser_menu(x);
      switch(key=getch())
     {   case 80:
	if(x!=290)
	{
		x+=40;
	       reser_menu(x);
		menu++;
		continue;
	}
	if(x==290||menu==5)
	{
		x=130;
		reser_menu(x);
		menu=1;  continue;
	}
     break;
    case 72:
	if(x!=130)
	{
		x-=40;
		reser_menu(x);
		menu--;  continue;
	}
	else if(x==130||menu==1)
	{
		x=290;
		reser_menu(x);
		menu=5;  continue;
	}
    break;
     default:
     if((char)key=='\r')
     {
	switch(menu)
	{
		case 1: enquiry();       break;
		case 2:	booking();       break;
		case 3: booking_record();break;
		case 4: cancel();        break;
		case 5: return;
	}

     }
     }//switch
}
}

//////Menu no:3 -> USER MANAGEMENT
void user_manage(int y)
{

cleardevice();
heading();
	setcolor(3);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(240,70,"USER MANAGEMENT");
		    rect2(y);
	setcolor(14);
	rectangle(180,130,460,310);
	setcolor(13);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(210,150,"MODIFY ACCOUNT ");
	outtextxy(210,210,"DELETE ACCOUNT");
	outtextxy(210,270,"BACK ");


}
 void box3()
{

		int key, x=130 , menu=1;
while(menu)
{     user_manage(x);
       switch(key=getch())
     {   case 80:
	if(x!=250)
	{
		x+=60;
		user_manage(x);
		menu++;
		continue;
	}
	if(x==250||menu==3)
	{
		x=130;
		user_manage(x);
		menu=1;  continue;
	}
       break;
     case 72:

	if(x!=130)
	{
		x-=60;
		user_manage(x);
		menu--;  continue;
	}
	else if(x==130||menu==1)
	{
		x=250;
		user_manage(x);
		menu=3;  continue;
	}

     break;

     default:
     if((char)key=='\r')
     {
	switch(menu)
	{
	 case 1:	Modify_Passenger(); break;
	 case 2:        Del_Passenger();    break;
	 case 3:        return;
	}

     }
     } //switch
}
}

////////MENU no:2 -> USER MENU
void usermenu(int y)
{
int ch;

cleardevice();
heading();              rect2(y);
	setcolor(3);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	outtextxy(240,70,"USER MENU");
	setcolor(14);
	rectangle(180,130,460,310);
	setcolor(14);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(210,150,"RESERVATION MENU ");
	outtextxy(210,210,"USER MANAGEMENT");
	outtextxy(210,270,"BACK ");


}
 void box2()
{

		int ch=1 , x=130 , menu=1,key;
while(menu)
{
     usermenu(x);
       switch(key=getch())
     {   case 80:
	if(x!=250)
	{
		x+=60;
		usermenu(x);
		menu++;
		continue;
	}
	if(x==250||menu==3)
	{
		x=130;
		usermenu(x);
		menu=1;  continue;
	}
       break;
     case 72:

	if(x!=130)
	{
		x-=60;
		usermenu(x);
		menu--;  continue;
	}
	else if(x==130||menu==1)
	{
		x=250;
		usermenu(x);
		menu=3;  continue;
	}

     break;
     default:
     if((char)key=='\r')
     {
	switch(menu)
	{
		case 1:	box4(); 	break;
		case 2:	box3(); 	break;
		case 3: return;
	}
     }
     }//switch
}
}
void exitmenu(int z)
{
     cleardevice();
   gotoxy(22,14);cout<<"Are you sure to exit?";
   outtextxy(180,260,"YES");
     outtextxy(295,260,"NO");

	rect4(z);
}
int box10()
{

   int x=270 , menu=2, key;
    exitmenu(x);
while(menu)
{
     switch(key=getch())
     {

     case 77:
	if(x==270)
	{
		x-=110;
		exitmenu(x);
		menu=1;
		continue;
	}
	if(menu)
	{
		x+=110;
		exitmenu(x);
		menu=2;  continue;
	}
     break;
    case 75:
	if(x!=160)
	{
		x-=110;
		exitmenu(x);
		menu=1;  continue;
	}
	if(x==270)
	{
		x-=110;
		exitmenu(x);
		menu=1;
		continue;
	}
	else if(menu)
	{
		x+=110;
		exitmenu(x);
		menu=2;  continue;
	}
     break;
     default:
    if((char)key=='\r')
	return menu;
	}
	}
}

void mainmenu(int a)
{
	cleardevice();
	menuscreen();
	if(a)
	    rect(a);

     setcolor(14);
     settextstyle(1,HORIZ_DIR,1);
     outtextxy(20,140,"  USER MODE");
     outtextxy(20,200,"  ADMIN MODE");
     outtextxy(20,260,"  CREDITS");
     outtextxy(20,320,"  EXIT");


     setcolor(9);

     settextstyle(3,HORIZ_DIR,5);
      outtextxy(360,120,"MAIN MENU");

     setcolor(15);
     settextstyle(3,HORIZ_DIR,1);

     if(a==120)
     {
	    outtextxy(240,200,"User mode :");
	    outtextxy(240,260,"You can reserve tickets , check records");
	    outtextxy(240,300,"cancel ticket...........................");
	    outtextxy(240,340,"You can modify or delete your account...");

     }
     else if(a==180)
     {
	    outtextxy(240,200,"Administrator settings :");
	    outtextxy(240,260,"Manipulate bus route and details........");
	    outtextxy(240,300,"See reservation and passenger details...");

     }
     else if(a==240)
     {
	    outtextxy(240,200,"Credits:");
	    outtextxy(240,260,"Gives a brief visualisation about the");
	    outtextxy(240,300,"background of the project............");

     }
}

void box1()
{
		char ch='y';
		int x=120 , menu=1, key;
		mainmenu(0);
	     //	getch();

while(menu)
{
ahead:
     mainmenu(x);
     switch(key=getch())
     {

     case 80:
	if(x!=300)
	{
		x+=60;
		mainmenu(x);
		menu++;
		continue;
	}
	if(x==300||menu==4)
	{
		x=120;
		mainmenu(x);
		menu=1;  continue;
	}
     break;
    case 72:
	if(x!=120)
	{
		x-=60;
		mainmenu(x);
		menu--;  continue;
	}
	else if(x==120||menu==1)
	{
		x=300;
		mainmenu(x);
		menu=4;  continue;
	}
     break;
     default:
    if((char)key=='\r') {
	switch(menu)
	{       int ch;
		case 1: login();box2();   break;
		case 2: admin();          break;
		case 3: credits();        break;
		case 4:	ch= box10();

			if(ch==1)
			{       cleardevice();
				gotoxy(19,14);cout<<"Thank you for using the program";
				delay(500);
				exit(0);
			}
			else
				goto ahead;
			break;
	}
       }
	break;
     }//switch
}
}



////////////MENU no:1 -> MAIN MENU

