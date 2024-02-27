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