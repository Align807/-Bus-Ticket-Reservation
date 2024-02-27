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