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

//////////////////////////////////////////////////////
////   		     bus class 	   		 /////
//////////////////////////////////////////////////////

class bus
{
	  char reg_no[20],bus_type[7],bus_name[15],source[15],dest[15],dt[11];
	  int seat_capacity,km;
	  float seat_fare;     //this should be multiplied with km charges

	    public:
			int remaining;
			     bus()       //constructor
			     {
				  seat_capacity=0;
				  km=0;
				  seat_fare=0;
				  strcpy(reg_no,'\0');
				  strcpy(bus_type,'\0');
				  strcpy(bus_name,'\0');
				  strcpy(source,'\0');
				  strcpy(dest,'\0');
				  strcpy(dt,'\0');
			     }
			     void routechange()
			     {  int k;
			     char s[15],d[15];

				gotoxy(23,10);cout<<"New source             :";
				gets(s);
				strcpy(source,s);
				gotoxy(23,12);cout<<"New destination        :";
				gets(d);
				strcpy(dest,d);
				gotoxy(23,14);cout<<"Total kilometers       :";
				cin>>k;
				km=k;
			     }
			      void datechange()
			      {char dd[10];
			      gotoxy(23,10);cout<<"Enter date (dd/mm/yy)  :";
				gets(dd);
				strcpy(dt,dd);
			      }
			       void farechange()
			       { int fare;
				gotoxy(23,10);cout<<"Bus fare per seat :";
				cin>>fare;
				seat_fare=fare;
			       }
	     void getdata(char *r)
	    {
			strcpy(reg_no,r);
	       gotoxy(10,14);cout<<"Bus name             : ";
	       gets(bus_name);
	       gotoxy(10,15);cout<<"Bus type (ac/non ac) : ";
	       gets(bus_type);
	       gotoxy(10,16);cout<<"Seat capacity        : ";
	       cin>>seat_capacity;
	       gotoxy(10,17);cout<<"Fare per seat        : ";
	       cin>>seat_fare;
	       gotoxy(10,18);cout<<"Source               : ";
	       gets(source);
	       gotoxy(10,19);cout<<"Destination          : ";
	       gets(dest);
	       gotoxy(10,20);cout<<"Total kilometers     : ";
	       cin>>km;
	       gotoxy(10,21);cout<<"Date                 : ";
	       gets(dt);
	       remaining=seat_capacity;
	    }

		void display()           //display details of particular bus
	    {
			       gotoxy(17,9);	cout<<"Registration number     : "<<reg_no;
			       gotoxy(17,10);	cout<<"Bus name                : "<<bus_name;
			       gotoxy(17,11);	cout<<"Bus type                : "<<bus_type;
			       gotoxy(17,12);	cout<<"Seat capacity           : "<<seat_capacity;
			       gotoxy(17,13);	cout<<"Bus fare per seat       : "<<seat_fare;
			       gotoxy(17,14);   cout<<"Source                  : "<<source;
			       gotoxy(17,15);   cout<<"Destination             : "<<dest;
			       gotoxy(17,16);   cout<<"Date                    : "<<dt;
	    }
	   float calcfare()
	   {

		return 1.2*km+seat_fare;
	   }

	void displayallbus(int c,int a)
	{
	char seat[3],charge[6],fare[4],rem[3];
	setcolor(3);
	settextstyle(0,HORIZ_DIR,1);
	outtextxy(8,c,reg_no);
	outtextxy(115,c,bus_name);
	outtextxy(200,c,bus_type);
	if(a==1)
	{	itoa(seat_capacity,seat,10);
		outtextxy(300,c,seat);
	}
	if(a==2)
	{	itoa(remaining,rem,10);
		outtextxy(270,c,rem);
		outtextxy(290,c,"seats");
	}

	itoa(seat_fare,fare,10);
	outtextxy(350,c,fare);
	outtextxy(400,c,source);
	outtextxy(470,c,dest);
	outtextxy(560,c,dt);

	}

		////////////accessor functions//////////

		char *retreg_no()
		{		return reg_no;  }
		char *retsource()
		{		return source;  }

		char *retdest()
		{		return dest;  }

		char *retname()
		{		return bus_name;}

}Bus;//class ends here

//////////////////////////////////////////////////////
////   		   passenger class 	        /////
//////////////////////////////////////////////////////
class Passenger
{
	char pass_name[25],password[10],phone_num[11],email[25];
	int pass_id;

	public:
		void getpassenger(int id)
		{         pass_id=id;
			  gotoxy(17,9);	cout<<"User name      : ";
			  gets(pass_name);
			  gotoxy(17,11);cout<<"Password       : ";
			  gets(password);
			  gotoxy(17,13);cout<<"Phone number   : ";
			  gets(phone_num);
			  gotoxy(17,15);cout<<"Email ID       : ";
			  gets(email);
		}

		void display_pass()
		{
			  gotoxy(17,9);	cout<<"Passenger ID        : "<<pass_id;
			  gotoxy(17,12);cout<<"Passenger name      : ";puts(pass_name);
			  gotoxy(17,15);cout<<"Phone number        : "<<phone_num;
			  gotoxy(17,18);cout<<"Email ID            : ";puts(email);
		}
	      ///////////change functions///////
		void change_phonenum()
		{       cleardevice();
			gotoxy(17,13);	cout<<"Enter new phone number  : ";
			gets(phone_num);
		}
		void change_password()
		{
			cleardevice();
			gotoxy(17,13);	cout<<"Enter new password : ";
			gets(password);
		}

	    /////accessor function////////
		int retpass_id()
		{		return pass_id;  }
		char *retemail()
		{		return email;  }
		char *retpass_name()
		{		return pass_name; }
}P;
//////////////////////////////////////////////////////
////   		   reserve class 	        /////
//////////////////////////////////////////////////////
class Reserve
{
	 char src[15],dst[15],dd[11],bname[20],reg[20],pname[20];
	 int bkno,noofpass;
	 float tfare;

	 public:
		void getrevdetails()
		{
		       gotoxy(17,9);	cout<<"Enter source                : "; gets(src);
		       gotoxy(17,11);	cout<<"Enter destination           : "; gets(dst);
		       gotoxy(17,13);	cout<<"Enter date(dd/mm//yy)       : "; gets(dd);

		}
		void initpassnum(int passnum)
		{
			noofpass=passnum;
		}
		void initno_nm(int b,char n[],char p[])
		{
			bkno=b;
			strcpy(bname,n);
			strcpy(pname,p);
		}
		void initreg(char r[])
		{
			strcpy(reg,r);
		}
		void dispdetails()
		{
		     gotoxy(17,12); cout<<"Passenger name      : "<<pname;
		     gotoxy(17,13); cout<<"Booking number      : "<<bkno;
		     gotoxy(17,14); cout<<"Bus name            : "<<bname;
		     gotoxy(17,15); cout<<"Source              : "<<src;
		     gotoxy(17,16); cout<<"Destination         : "<<dst;
		     gotoxy(17,17); cout<<"Date                : "<<dd;
		     gotoxy(17,18); cout<<"Number of passengers: "<<noofpass;
		     gotoxy(17,19); cout<<"Total Fare          : Rs "<<tfare;

		}
		void fare(float fr)
		{
		       tfare=noofpass*fr;
		       gotoxy(17,22);	cout<<"Total fare = Rs "<<tfare;

		}

		///////////accessor function////////////
		int retbkno()
		{		return bkno;  }
		char *retsource()
		{		return src;}
		char *retreg_no()
		{		return reg;}
		char *retdest()
		{		return dst;}
		int retpassnum()
		{		return noofpass;}
}res;

void box9();
void box8();
int P_id; //global variable for passenger id

		///////bus settings/////////////

//function to display all bus details
void displaybus(int b)
{       cleardevice();
	heading();
	setcolor(15);
	line(1,100,630,100);
	line(1,140,630,140);
	setcolor(12);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(10,120,"Reg.number");
	outtextxy(120,120,"Name");
	outtextxy(200,120,"Type");
	if(b==1)
		outtextxy(290,120,"Seats");
	if(b==2)
		outtextxy(265,120,"Remaining");
	outtextxy(347,120,"Fare ");
	outtextxy(390,120,"Source");
	outtextxy(470,120,"Destination");
	outtextxy(570,120,"Date");
	int a=150;
	ifstream fin("Bus.dat",ios::in|ios::binary);
	while(fin.read((char*)&Bus,sizeof(Bus)))
	{
		delay(500);
		Bus.displayallbus(a,b);
		line(1,a+20,630,a+20);
		a+=40;
	}
	fin.close();
}

//function to check duplication of bus
//return value :- 0 -no duplication
//		  1 -duplication
int duplicate(char *Reg)
{
	ifstream fp("Bus.dat",ios::in|ios::binary);
	if(!fp)
	     return 0;

	while(fp.read((char*)&Bus,sizeof(Bus)))
	{
		if(strcmpi(Bus.retreg_no(),Reg)==0)
		{
		     fp.close();
		     return 1;
		}
	}
	fp.close();
	return 0;
}
//function to add new bus details
void addbus()
{
	fstream fp;
	fp.open("Bus.dat",ios::in|ios::binary|ios::app);

	if(!fp)
	{
		cleardevice();
		cout<<"No bus records found";
		getch();
		return;
	}
	char ch='y',reg[20];
	do
	{
	    here:
		cleardevice();
		heading();
		setcolor(13);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
		outtextxy(280,120,"ADD BUS SECTION"); delay(600);

		gotoxy(10,13);cout<<"Registration number  : ";
		gets(reg);

		while(duplicate(reg))             //checking for duplication
		{
			gotoxy(7,15);	cout<<"Duplication found!!!"; delay(400);
			gotoxy(5,17);	cout<<"Press any key to continue.......";
			getch();
			goto here;
		}
		Bus.getdata(reg);
		fp.write((char*)&Bus,sizeof(Bus));
		gotoxy(17,25);	cout<<"Do you want add more(y/n) ";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	fp.seekg(0);
	fp.close();
 }
 //function to delete bus details
void deletebus()
{
     char c;
     do
     {
	 ifstream fp("Bus.dat",ios::in|ios::binary);
	 ofstream ftemp("temp.dat",ios::out|ios::binary);
	if(!fp)
	{
		gotoxy(13,17);cout<<"File not found!!!!!!!!!";
		getch();
		return;
	}
	  cleardevice();
	  heading();
	  displaybus(1);
	  setcolor(13);
	  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	  outtextxy(260,70,"DELETION"); delay(600);

	  char reg[20],found='n',confirm='n';
	  gotoxy(5,24);cout<<"Enter registration number of bus for deletion : ";
	  gets(reg);

	  while(fp.read((char*)&Bus,sizeof(Bus)))
	  {
		if(strcmpi(reg,Bus.retreg_no())==0)
		{
		   cleardevice();
		   heading();
		   Bus.display();
		   found='y';
		   gotoxy(7,18);cout<<"Are you sure to delete the record(y/n)?";
		   cin>>confirm;
		   if(confirm=='n'||confirm=='N')
			ftemp.write((char*)&Bus,sizeof(Bus));
		   else
		   {
			gotoxy(11,20); cout<<"DELETED!!!!!!!!!!!!";
			getch();
		   }
		}
		else
		   ftemp.write((char*)&Bus,sizeof(Bus));
	  }
	  if(found=='n')
	  {
		cleardevice();
		gotoxy(12,13);cout<<"Incorrect registration number!!!!!! ";
	  }
	  gotoxy(12,22);cout<<"Do you want to continue(y/n) : ";
	  cin>>c;

	fp.close();
	ftemp.close();
	remove("Bus.dat");
	rename("temp.dat","Bus.dat");
     }while(c=='y'||c=='Y');
}
///////////////////////route related settings//////////

void modify()
{
    char Regis[20],ch='y';
    int f;
    do
    {
	fstream fp("Bus.dat",ios::in|ios::binary);
	ofstream ftemp("temp.dat",ios::out|ios::binary);
	if(!fp)
	{
		gotoxy(13,17);cout<<"File not found!!!!!!!!!";
		getch();
		return;
	}

	cleardevice();
	heading();
	displaybus(1);
	setcolor(13);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(255,70,"MODIFICATION");
	char seen='n',sure='n';
	gotoxy(5,23);cout<<"Enter registration number of bus for modification : ";
	gets(Regis);
	fp.seekg(0);
	while(fp.read((char*)&Bus,sizeof(Bus)))
	{
	    if(strcmpi(Regis,Bus.retreg_no())==0)
	    {
		cleardevice();
		heading();
		Bus.display();
		seen='y';
		gotoxy(12,20);	cout<<"Any modification needed?(y/n)";
		cin>>sure;
		if(sure=='y'||sure=='Y')
		{
		    box8();   //calling function in menu.h

		    ftemp.write((char*)&Bus,sizeof(Bus));
		}
		else      //not sure to modify
		    ftemp.write((char*)&Bus,sizeof(Bus));
	    }    //comparing reg.number
	    else
		ftemp.write((char*)&Bus,sizeof(Bus));
	}      //end of while
	if(seen=='n')
	{
	    gotoxy(17,19);
	    cout<<"Incorrect regisration number!!!!!! ";
	}
	gotoxy(17,12);	cout<<"Do you want to modify more records (y/n)? ";
	cin>>ch;

	fp.close();
	ftemp.close();
	remove("Bus.dat");
	rename("temp.dat","Bus.dat");
    }while(ch=='y'||ch=='Y');    //end of do while
}
void disp_allreserve()
{
     ifstream fr("Reserve.dat",ios::in|ios::binary);
     if(!fr)
     {
	 gotoxy(13,17);cout<<"NO RECORDS FOUND!!!!!!!!!!!";
	 getch();
	 return;
     }
     int i=0;
     while(fr.read((char*)&res,sizeof(res)))
     {          i++;
		cleardevice();
		heading();
		gotoxy(13,8);cout<<"RESERVATION DETAILS No:"<<i;
		res.dispdetails();
		getch();
     }
     fr.close();
}
void disp_allpass()
{
     ifstream fin("Passenger.dat",ios::in|ios::binary);
     if(!fin)
     {
	 gotoxy(13,17);cout<<"NO RECORDS FOUND!!!!!!!!!!!";
	 getch();
	 return;
     }
     int i=0;
     while(fin.read((char*)&P,sizeof(P)))
     {          i++;
		cleardevice();
		heading();
		gotoxy(18,6);cout<<"DETAILS OF PASSENGER "<<i;
		P.display_pass();
		getch();
     }
     fin.close();
}

//////////////////////user mode/////////////////

//function to modify account details
void Modify_Passenger()
{
     ifstream fp("Passenger.dat",ios::in|ios::binary);
     ofstream ftemp("temp.dat",ios::out|ios::app|ios::binary);
     if(!fp)
     {
	cout<<"SORRY,FILE DON'T EXIST!!!!";
	getch();
	return;
     }
     int c;
     cleardevice();
     heading();
     while(fp.read((char*)&P,sizeof(P)))
     {
	if(P_id==P.retpass_id())
	{
		box9();
	     ftemp.write((char*)&P,sizeof(P));
	}      //comparing
	else
	    ftemp.write((char*)&P,sizeof(P));
     }  //end of while
     fp.close();
     ftemp.close();
     remove("Passenger.dat");
     rename("temp.dat","Passenger.dat");
}
//function to delete account
void Del_Passenger()
{

   ifstream fp("Passenger.dat",ios::in|ios::binary);
   ofstream ftemp("temp.dat",ios::out|ios::binary);
   cleardevice();
   if(!fp)
   {
	gotoxy(17,13);cout<<"SORRY,FILE DON'T EXIST!!!!";
	getch();
	return;
   }
   int c;
   char sure='y';
   heading();
   fp.seekg(0);
   while(fp.read((char*)&P,sizeof(P)))
   {
	if(P_id==P.retpass_id())
	{
	     P.display_pass();
	     gotoxy(17,21); cout<<"Are u sure to delete your account (y/n)";
	     cin>>sure;
	     if(sure=='n'||sure=='N')
	     {
		ftemp.write((char*)&P,sizeof(P));
	     }
	}
	else
	     ftemp.write((char*)&P,sizeof(P));
   }
   fp.close();
   ftemp.close();
   remove("Passenger.dat");
   rename("temp.dat","Passenger.dat");
   if(sure=='y'||sure=='Y')
   {
	  gotoxy(20,22);cout<<"YOUR ACCOUNT HAS BEEN DELETED!!!!!!!!!";
	  getch();
	  cleardevice();
	  gotoxy(19,14);cout<<"Thank you for using the program";
	  getch();
	  exit(0);
   }
}
//function to add new account
void signup()
{
	cleardevice();
	fstream fp("Passenger.DAT",ios::out|ios::in|ios::binary|ios::ate);

	if(!fp)
	{
		gotoxy(17,13);cout<<"SORRY,FILE DON'T EXIST!!!!";
		getch();
		return;
	}

	int pno;
	if(fp.tellg()==0)// no passenger yet added
	{
	    pno=1000;
	}
	else
	{
	    fp.seekg(fp.tellg()-sizeof(P));  //pointer goes to the previous element
	    fp.read((char*)&P,sizeof(P));
	    pno=P.retpass_id();
	}
	    pno+=1;
	    P.getpassenger(pno);
	    fp.write((char *)&P, sizeof(P));

	    gotoxy(17,19);cout<<"WELCOME TO SANCHAR BUS TICKET RESERVATION SYSTEM";delay(400);
	    gotoxy(21,21);cout<<"Your passenger ID is :"<<pno;
	    getch();
	    P_id=pno;        //assigning to global passenger id
	    fp.close();
}
//function to signin
int signin()
{
    ifstream fin;
    fin.open("Passenger.dat",ios::in|ios::binary);
    cleardevice();
    if(!fin)
    {
	gotoxy(17,14);cout<<"Please sign up";
	getch();
	return 0;
    }
    int i=0,ps=0;
    label:
	cleardevice();
	heading();
	setcolor(3);
	outtextxy(250,130,"SIGNING IN");
	char E_id[25],pass[10]="";
	setcolor(14);
	rectangle(110,170,480,205);
	rectangle(110,215,480,250);
	setcolor(15);
	settextstyle(SMALL_FONT,HORIZ_DIR,6);
	outtextxy(125,172,"Email ID   : ");gotoxy(32,12);gets(E_id);
	settextstyle(SMALL_FONT,HORIZ_DIR,6);
	outtextxy(125,219,"Password  : ");strcpy(pass,password());
	while(fin.read((char*)&P,sizeof(P)))
	{
	     if(strcmpi(E_id,P.retemail())==0)
	     {
		   ps=1;
		   gotoxy(16,19);cout<<"WELCOME TO SANCHAR BUS TICKET RESERVATINON SYSTEM";delay(400);
		   gotoxy(16,21); cout<<"Your Passenger ID is : "<<P.retpass_id();
		   getch();
		   P_id=P.retpass_id();
		   fin.close();
		   return 1;
	     }
	}
	if(!ps)
	{
	     i++;
	     gotoxy(19,18);cout<<"INCORRECT INPUT!!!!!!!";
	     getch();
	     if(i==3)
	     {
		cleardevice();
		gotoxy(19,14);cout<<"Thank you for using the program";
		fin.close();
		exit(0);
	     }
	     goto label;
	}
}  //end of function

//login window
void login()
{
   int ch;
   cleardevice();
   logo();
   setcolor(14);
   setfillstyle(SOLID_FILL,14);
   rectangle(240,250,420,280);
   rectangle(240,300,420,330);

   setcolor(15);
   settextstyle(SMALL_FONT,HORIZ_DIR,5);
   outtextxy(292,258,"1. SIGN UP");
   settextstyle(SMALL_FONT,HORIZ_DIR,5);
   outtextxy(292,308,"2. SIGN IN");
   outtextxy(240,367,"Enter your choice (1-2) ");
   gotoxy(55,24);
   cin>>ch;
   switch(ch)
   {
	case 1:	signup();  break;
	case 2:	signin();  break;
   }
   clrscr();
}

///////////////////////reservation section//////////////////

//function to check the available buses
void enquiry()
{
	displaybus(2);
	 setcolor(13);
	  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	  outtextxy(255,70,"ENQUIRY SECTION");

	getch();
}

void booking()
{
     int n,bn;
     float f;
     char confirm='n';
     cleardevice();
     heading();
     setcolor(13);
     settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
     outtextxy(235,70,"RESERVATION SECTION");

     res.getrevdetails();
     gotoxy(17,15);   cout<<"Enter number of passengers  : ";
     cin>>n;
     res.initpassnum(n);
     fstream fin("Passenger.dat",ios::in|ios::binary);
     fstream fp("Bus.dat",ios::in|ios::out|ios::binary);
     fstream fr("Reserve.dat",ios::in|ios::app|ios::binary);
     time_t t;
     while(fp.read((char*)&Bus,sizeof(Bus)))
     {
	  if(strcmpi(res.retsource(),Bus.retsource())==0&&(strcmpi(res.retdest(),Bus.retdest())==0))
	  {
		cleardevice();
		heading();
		Bus.display();
		if((Bus.remaining-n)<=0)
		{
		     gotoxy(10,23);cout<<"SEATS NOT AVAILABLE!! "<<bn;
		     goto x;
		}
		else
		{
		     gotoxy(7,20);cout<<"CONFIRMATION ok or not(y/n)?";
		     cin>>confirm;
		     if(confirm=='y'||confirm=='Y')
		     {
			  Bus.remaining-=n;                  //decrementing remaining seats
			  fp.seekp(fp.tellg()-sizeof(Bus));  //pointer goes to the previous element
			  fp.write((char*)&Bus,sizeof(Bus));

			  f= Bus.calcfare();                 //fare of one ticket
			  res.fare(f);                       //total fare
			  srand((unsigned) time(&t));
			  bn=rand();
			   while(fin.read((char*)&P,sizeof(P)))
			   {
				if(P_id==P.retpass_id())
				    res.initno_nm(bn,Bus.retname(),P.retpass_name());
			   }
			  res.initreg(Bus.retreg_no());
			  gotoxy(10,24);cout<<"TICKET RESERVED WITH BOOKING NUMBER : "<<bn;
			  setcolor(13);
			  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			  outtextxy(3,410,"This booking number is needed for checking record and cancelation");

			  fr.write((char*)&res,sizeof(res));
			  goto x;
		     }
		     else           //not confirmed
			  goto x;
		}
	  }
     }      //end of while
     gotoxy(17,20);cout<<" incorrect route !!!";delay(400);
     gotoxy(17,22);cout<<" please check enquiry section";
 x:
     getch();
     fp.close();
     fr.close();
     fin.close();
}

//function to display booking record
void booking_record()
{
     cleardevice();
     heading();
     fstream fr("Reserve.dat",ios::in|ios::binary);
     if(!fr)
     {
	 gotoxy(13,17);cout<<"NO RECORDS FOUND!!!!!!!!!!!";
	 getch();
	 return;
     }
     int bn;
     gotoxy(14,7); cout<<"Enter your booking number : ";
     cin>>bn;
     while(fr.read((char*)&res,sizeof(res)))
     {
	 if(bn==res.retbkno())
	 {
		     res.dispdetails();
		     getch();
		     fr.close();
		     return;
	 }
     }
     gotoxy(13,18);cout<<"No booking record with booking number "<<bn;
     getch();
     fr.close();
}
//function to cancel booked ticket
void cancel()
{
    cleardevice();
    heading();
    setcolor(13);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    outtextxy(235,70,"CANCELATION SECTION");

    fstream fr("Reserve.dat",ios::in|ios::binary);
    ofstream ftemp("temp.dat",ios::out|ios::binary);
    fstream fp("Bus.dat",ios::in|ios::out|ios::binary);
    if(!fr)
    {
	cleardevice();
	gotoxy(16,17);cout<<"NO RECORDS FOUND FOR CANCELATION !!!!!!!!!";
	getch();
	return;
    }
    int bno;
    char c='y';
    gotoxy(13,11);cout<<"Enter booking number for cancelation : ";
    cin>>bno;
    while(fr.read((char*)&res,sizeof(res)))
    {
	 if(res.retbkno()==bno)
	 {
	     cleardevice();
	     heading();
	     res.dispdetails();
	     gotoxy(13,23);cout<<"Are you sure to cancel your ticket(y/n)?";
	     cin>>c;
	     if(c=='n'||c=='N')
		  ftemp.write((char*)&res,sizeof(res));
	     else
	     {      while(fp.read((char*)&Bus,sizeof(Bus)))
		    {
			 if(strcmpi(Bus.retreg_no(),res.retreg_no())==0)
			 {
			      Bus.remaining+=res.retpassnum();       //incrementing remaining seats
			      fp.seekp(fp.tellg()-sizeof(Bus));  //pointer goes to the previous element
			      fp.write((char*)&Bus,sizeof(Bus));
			 }
		    }
		    gotoxy(13,25);cout<<"TICKET NUMBER "<<bno<<" CANCELLED !!!!!!!!!";
		    goto y;
	     }
	 }
	 else
	     ftemp.write((char*)&res,sizeof(res));
    }
    gotoxy(13,13);cout<<"No record with booking number "<<bno<<"found for cancelation!!!";
y:
    getch();
    fr.close();
    ftemp.close();
    remove("Reserve.dat");
    rename("temp.dat","Reserve.dat");
}



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


