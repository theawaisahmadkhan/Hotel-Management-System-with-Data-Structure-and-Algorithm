#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;
struct node{
		string Room_type;
		int Room_No;
		int Time;
		int Remaning_time;
		string F_name;
	string L_name;
	int Age;
	string Gender;
	long long int Id;//take iid card number
		int Charge;
	int Balance;
	int Reserve_days_no;
	int floor;
	int Hr,Min;
	int Date;
	int month;
	int Count_days;
	node *next;
};
struct node1{
		string Room_type;
		int Room_No;
		int Time;
		int Remaning_time;
		string F_name;
	string L_name;
	int Age;
	string Gender;
	long long int Id;//take iid card number
		int Charge;
	int Balance;
	int Reserve_days_no;
	int floor;
	int Hr,Min;
	int Date;
	int month;
	int Count_days;
	node1 *next;
};
struct node2{
		string Room_type;
		int Room_No;
		int Time;
		int Remaning_time;
		string F_name;
	string L_name;
	int Age;
	string Gender;
	long long int Id;//take iid card number
		int Charge;
	int Balance;
	int Reserve_days_no;
	int floor;
	int Hr,Min;
	int Date;
	int month;
	int Count_days;
	node2 *next;
};
struct node3{
		string Room_type;
		int Room_No;
		int Time;
		int Remaning_time;
		string F_name;
	string L_name;
	int Age;
	string Gender;
	long long int Id;//take iid card number
		int Charge;
	int Balance;
	int Reserve_days_no;
	int floor;
	int Hr,Min;
	int Date;
	int month;
	int Count_days;
	node3 *next;
	node3 *prev;
};
struct node4{
		string Room_type;
		int Room_No;
		int Time;
		int Remaning_time;
		string F_name;
	string L_name;
	int Age;
	string Gender;
	long long int Id;//take iid card number
		int Charge;
	int Balance;
	int Reserve_days_no;
	int floor;
	int Hr,Min;
	int Date;
	int month;
	int Count_days;
	node4 *left,*right;
};
class Room{    //base class 
	protected:
		char room_type[20];
		int Room_no;
		int time;
		int remaning_time;
	
	public://use pure virtual function for polymorphismz
	virtual int avail(int f,int r,fstream &file)=0;
			virtual 	int input(int floor,int room_no,int t_date,int month,fstream &f6,fstream &file)=0;/*this take input from accountant and fstream f6 file is a global file
			     that save the customer record how many customer are reserve the room*/
			virtual 	int output(fstream &file)=0;                                                     //this function use for output for reserced room
			virtual int check(int floor,int room_no,fstream &file)=0;                             // this function check room availibility
			virtual 	int update(int t_hr,int t_min,int t_date,int d,fstream &f7,int f,int r,fstream &file)=0;            //this function update the room data if days are commplete
		virtual int reset(int f,int r,fstream &file)=0;
			
		
};
class standard:public Room{//first derived class 
char f_name[50];
	char l_name[50];
	int age;
	char gender[10];
	long long int id;//take iid card number
		int charge;
	int balance;
	int reserve_days_no;
	int Floor;
	int hr,min;
	int date;
	int Month;
	int count_days;
	node *top;
	public:
			standard()//constructor
		{
			top=NULL;
            char f_name[]="";
            char l_name[]="";
            char gender[]="";;
			age=0;
			id=0;
			balance=0;
			charge=300;             //rooom charges by default assign
			reserve_days_no=0;
			Floor=0;
		}
		int avail(int f,int r,fstream &file){
			string w1 = "seq";
string filename;
stringstream str;
str << w1 << f << r << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::out|ios::binary );
if(file.good())
{
	return 1;
}
else
{
	return 0;
}
file.close();
	}
		int reset(int f,int r,fstream &file)
		{
							string w1 = "seq";
string filename;
stringstream str;
str << w1 << f << r << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::out|ios::binary );

			if(file.good())
			{
					file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
		if(age!=0)
		{
		node *temp=new node;
		temp->next=NULL;
        temp->F_name=f_name;
    	temp->L_name=l_name;
		temp->Age=age;
		temp->Gender=gender;
		temp->Id=id;
		temp->Reserve_days_no=reserve_days_no;
		balance=charge*reserve_days_no;
		temp->Balance=balance;
		temp->floor=Floor;
		temp->Room_No=Room_no;
		temp->Hr=hr;
		temp->Min=min;
		temp->Date=date;
		temp->month=Month;
		temp->Room_type=room_type;
			if(top==NULL)
		{
			top=temp;
		}
		else{
			temp->next=top;
			top=temp;
		}	
		}
				}	
	

		file.close();
		
		}
		
			int input(int floor,int room_no,int t_date,int month,fstream &f6,fstream &file)
		{
			
			
			
		node *temp=new node;
	temp->next=NULL;
		cout<<"ENTERR CUSTOMER FIRST NAME:"<<endl;
		cin>>f_name;
temp->F_name=f_name;
    	cout<<"ENTER CUSTOME LAST NAME:"<<endl;
    	cin>>l_name;
    	temp->L_name=l_name;
		cout<<"ENTER CUSTOMER AGE:"<<endl;
		cin>>age;
		temp->Age=age;
		cout<<"ENTER CUSTOMER GENDER:"<<endl;
		cin>>gender;
		temp->Gender=gender;
		cout<<"ENTER CUSTOMER ID:"<<endl;
		cin>>id;
		temp->Id=id;
	
		cout<<"ENTER RESERVE DAYS NO:"<<endl;
		cin>>reserve_days_no;
		temp->Reserve_days_no=reserve_days_no;
		balance=charge*reserve_days_no;
		temp->Balance=balance;
		Floor=floor;
		temp->floor=Floor;
		Room_no=room_no;
		temp->Room_No=room_no;
		cout<<"ENTER TIME IN HOUUR AND MINUTE:"<<endl;
		cin>>hr>>min;
		temp->Hr=hr;
		temp->Min=min;
		date=t_date;
		temp->Date=date;
		Month=month;
		temp->month=Month;
		cout<<"ENTER ROOM TYPE STANDARD:"<<endl;
		cin>>room_type;
		temp->Room_type=room_type;
			if(top==NULL)
		{
			top=temp;
		}
		else{
			temp->next=top;
			top=temp;
		}
		//binary writing in f6 file global and file within the class file
		//f6 store customer record
		f6.write((char*)&f_name,sizeof(f_name));
		f6.write((char*)&l_name,sizeof(l_name));
		f6.write((char*)&gender,sizeof(gender));
		f6.write((char*)&age,sizeof(age));
        f6.write((char*)&room_type,sizeof(room_type));
    	f6.write((char*)&id,sizeof(id));
		f6.write((char*)&balance,sizeof(balance));
		f6.write((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.write((char*)&Floor,sizeof(Floor));
		f6.write((char*)&Room_no,sizeof(Room_no));
		f6.write((char*)&hr,sizeof(hr));
		f6.write((char*)&min,sizeof(min));
		f6.write((char*)&Month,sizeof(Month));
		f6.write((char*)&date,sizeof(date));
		
		//file store the room record
		file.write((char*)&f_name,sizeof(f_name));
		file.write((char*)&l_name,sizeof(l_name));
		file.write((char*)&gender,sizeof(gender));
		file.write((char*)&age,sizeof(age));
        file.write((char*)&room_type,sizeof(room_type));
    	file.write((char*)&id,sizeof(id));
		file.write((char*)&balance,sizeof(balance));
		file.write((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.write((char*)&Floor,sizeof(Floor));
		file.write((char*)&Room_no,sizeof(Room_no));
		file.write((char*)&hr,sizeof(hr));
		file.write((char*)&min,sizeof(min));
		file.write((char*)&Month,sizeof(Month));
		file.write((char*)&date,sizeof(date));
		
		bill();

	    	file.close();
		
		}
		int output(fstream &file)//show the room data 
		{

		node *temp=top;
		while(temp!=NULL)
		{
				cout<<"NAME:="<<temp->F_name<<" "<<temp->L_name<<endl;
				cout<<"GENDER:"<<temp->Gender<<endl;
				cout<<"AGE:"<<temp->Age<<endl;
				cout<<"ROOM_TYPE:"<<temp->Room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<temp->Id<<endl;
				cout<<"ROOM_BALANCE:"<<temp->Balance<<endl;
				cout<<"RESERVE_DAYS:"<<temp->Reserve_days_no<<endl;
				cout<<"FLOOR:"<<temp->floor<<endl;
				cout<<"ROOM_NO:"<<temp->Room_No<<endl;
				cout<<"DATE:"<<temp->Date<<endl;
				cout<<"HOURE:MIN"<<temp->Hr<<":"<<temp->Min<<endl;
				cout<<endl<<endl;
			temp=temp->next;
		}
	
		}
		int check(int floor,int room_no,fstream &file)//check room availibility
		{
		
				int a=1;
node *temp=top;
while(temp!=NULL)
{
	if(floor==temp->floor&&room_no==temp->Room_No)
	{
		a=0;
	}

	temp=temp->next;
}
if(a==1)
{
	
		cout<<"Floor:"<<floor<<"\t"<<"Room:"<<room_no<<endl;
	
}
		}
		int bill()//this function create the customer bill
		{
			cout<<endl;
			cout<<"THANKYOU FOR CHOOSE OUR HOTEL SIR/MADAM"<<endl;
			cout<<"NAME:"<<f_name<<" "<<l_name<<endl;
			cout<<"ROOM TYPE:"<<room_type<<endl;
			cout<<"RESERVED DAYS:"<<reserve_days_no<<endl;
			cout<<"ROOM CHARGES FOR 24 HOURS:"<<charge<<endl;
			cout<<"YOUR BILL IS:"<<balance<<endl<<endl;
			cout<<"HAVE A NICE DAY SIR/MADAM:"<<endl;
			
		}
		int update(int t_hr,int t_min,int t_date,int d,fstream &f7,int f,int r,fstream &file)
		{
				string w1 = "seq";
string filename;
stringstream str;
str << w1 << f << r << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::out|ios::binary );
				fstream file_del;
				file_del.open("temp.dat",ios::out|ios::binary);
				if(file.good())
				{
									
		file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
	if(age!=0)
	{
					
			
	int days;int calculate,calculate1;
	int left_d;
	int time_h;
	int time_m;
	int h,m;
	days=t_date-date;
	//these line of code calculate the remaining time and calculate the day hour and minute
	//if reserved days no and count days number equal to then update the and remove the customer data from room file
 if(t_hr>hr)
 {
 	if(t_min>min)
 	{
 		t_hr=t_hr-hr;
 		t_min=t_min-min;
 		calculate=60*t_hr;
 		calculate+=t_min;
	 }
	 else{
	 		t_hr=t_hr-hr;
 		t_min=min-t_min;
 			calculate=60*t_hr;
 		calculate+=t_min;
	 	
	 }
 }
 else if(t_hr<hr)
 {
  if(t_min>min)
  {
  		t_hr=hr-t_hr;
  		t_min=min-t_min;
  			calculate=60*t_hr;
 		calculate+=t_min;
  		
  }
  else{
  		t_hr=hr-t_hr;
  		t_min=t_min-min;
  		calculate=60*t_hr;
 		calculate+=t_min;
  }
 }
 calculate1=days*24*60;
 calculate+=calculate1;
 
 left_d=calculate/(24*3600);
 time_h=calculate%(24*3600);
 
 h=time_h/3600;
 m=time_h%3600;
 time_m=m/60;
	left_d=reserve_days_no-days;
	if(d==1)
	{
	//if time is remaining
	if(days<reserve_days_no)
	{
			cout<<"NAME:"<<f_name<<endl;
			cout<<"FLOOR:"<<Floor<<endl;
			cout<<"ROOM:"<<Room_no<<endl;
			cout<<"RREMAINING TIME:"<<left_d<<"DAYS:"<<":"<<h<<"HOUR:"<<":"<<time_m<<"MIN:"<<endl;
			cout<<endl<<endl;	
	}
}
//if time complete then remove the data fromm file
		if(days>=reserve_days_no)
		{
			//when time coomplete 
	f7<<f_name<<"\t"<<l_name<<"\t"<<gender<<"\t"<<age<<"\t"<<room_type<<"\t"<<id<<"\t"<<balance<<"\t"<<reserve_days_no<<"\t"<<Floor<<"\t"<<Room_no<<"\t"<<hr<<"\t"<<min<<"\t"<<Month<<"\t"<<date<<endl ;

			remove(filename.c_str());//room file data remove
			rename("temp.dat",filename.c_str());//and again create new file
		}
			
		}
					
				}

		file.close();
	
}
};
class moderate:public Room{//second derived class 
	char f_name[50];
	char l_name[50];
	int age;
	char gender[10];
	long long int id;
		int charge;
	int balance;
	int reserve_days_no;
	int Floor;
	int hr,min;
	int date;
	int Month;
	int count_days;
	node1 *front,*rear;
	public:
			moderate()//constructor
		{
			front=NULL;
			rear=NULL;
			char f_name[]="";
			char l_name[]="";
			char gender[]="";
			age=0;
			
			id=0;
			balance=0;
			reserve_days_no=0;
			charge=500;//by default assignt the charges of 1 day
			Floor=0;
		}
		int avail(int f,int r,fstream &file){
			string w1 = "seq";
string filename;
stringstream str;
str << w1 << f << r << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::out|ios::binary );
if(file.good())
{
	return 1;
}
else
{
	return 0;
}
file.close();
	}
				int reset(int f,int r,fstream &file)
		{
							string w1 = "seq";
string filename;
stringstream str;
str << w1 << f << r << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::out|ios::binary );

				if(file.good())
				{
							file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
		if(id!=0)
		{
			node1 *temp=new node1;
		temp->next=NULL;
	   temp->F_name=f_name;
    	temp->L_name=l_name;
		temp->Age=age;
		temp->Gender=gender;
		temp->Id=id;
		temp->Reserve_days_no=reserve_days_no;
		balance=charge*reserve_days_no;
		temp->Balance=balance;
		temp->floor=Floor;
		temp->Room_No=Room_no;
		temp->Hr=hr;
		temp->Min=min;
		temp->Date=date;
		temp->month=Month;
		temp->Room_type=room_type;
			if(front==NULL)
		{
			front=temp;
			rear=temp;
		}
		else{
		rear->next=temp;
		rear=rear->next;
		}	
		}
				}

	
		file.close();
		
		}
			int input(int floor,int room_no,int t_date,int month,fstream &f6,fstream &file)//take input in room file and global file f6.
		{
	node1 *temp=new node1;
	temp->next=NULL;
		cout<<"ENTERR CUSTOMER FIRST NAME:"<<endl;
		cin>>f_name;
temp->F_name=f_name;
    	cout<<"ENTER CUSTOME LAST NAME:"<<endl;
    	cin>>l_name;
    	temp->L_name=l_name;
		cout<<"ENTER CUSTOMER AGE:"<<endl;
		cin>>age;
		temp->Age=age;
		cout<<"ENTER CUSTOMER GENDER:"<<endl;
		cin>>gender;
		temp->Gender=gender;
		cout<<"ENTER CUSTOMER ID:"<<endl;
		cin>>id;
		temp->Id=id;
	
		cout<<"ENTER RESERVE DAYS NO:"<<endl;
		cin>>reserve_days_no;
		temp->Reserve_days_no=reserve_days_no;
		balance=charge*reserve_days_no;
		temp->Balance=balance;
		Floor=floor;
		temp->floor=Floor;
		Room_no=room_no;
		temp->Room_No=room_no;
		cout<<"ENTER TIME IN HOUUR AND MINUTE:"<<endl;
		cin>>hr>>min;
		temp->Hr=hr;
		temp->Min=min;
		date=t_date;
		temp->Date=date;
		Month=month;
		temp->month=Month;
		cout<<"ENTER ROOM TYPE MODERATE:"<<endl;
		cin>>room_type;
		temp->Room_type=room_type;
			if(front==NULL)
		{
			front=temp;
			rear=temp;
		}
		else{
			rear->next=temp;
			rear=rear->next;
		}
		//binary writing in f6 file global and file within the class file
		//f6 store customer record
		f6.write((char*)&f_name,sizeof(f_name));
		f6.write((char*)&l_name,sizeof(l_name));
		f6.write((char*)&gender,sizeof(gender));
		f6.write((char*)&age,sizeof(age));
        f6.write((char*)&room_type,sizeof(room_type));
    	f6.write((char*)&id,sizeof(id));
		f6.write((char*)&balance,sizeof(balance));
		f6.write((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.write((char*)&Floor,sizeof(Floor));
		f6.write((char*)&Room_no,sizeof(Room_no));
		f6.write((char*)&hr,sizeof(hr));
		f6.write((char*)&min,sizeof(min));
		f6.write((char*)&Month,sizeof(Month));
		f6.write((char*)&date,sizeof(date));
		
		//file store the room record
		file.write((char*)&f_name,sizeof(f_name));
		file.write((char*)&l_name,sizeof(l_name));
		file.write((char*)&gender,sizeof(gender));
		file.write((char*)&age,sizeof(age));
        file.write((char*)&room_type,sizeof(room_type));
    	file.write((char*)&id,sizeof(id));
		file.write((char*)&balance,sizeof(balance));
		file.write((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.write((char*)&Floor,sizeof(Floor));
		file.write((char*)&Room_no,sizeof(Room_no));
		file.write((char*)&hr,sizeof(hr));
		file.write((char*)&min,sizeof(min));
		file.write((char*)&Month,sizeof(Month));
		file.write((char*)&date,sizeof(date));
		
		bill();

	    	file.close();
		}
		int output(fstream &file)//show data in a single room
		{
			
			node1 *temp=front;
		while(temp!=NULL)
		{
				cout<<"NAME:="<<temp->F_name<<" "<<temp->L_name<<endl;
				cout<<"GENDER:"<<temp->Gender<<endl;
				cout<<"AGE:"<<temp->Age<<endl;
				cout<<"ROOM_TYPE:"<<temp->Room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<temp->Id<<endl;
				cout<<"ROOM_BALANCE:"<<temp->Balance<<endl;
				cout<<"RESERVE_DAYS:"<<temp->Reserve_days_no<<endl;
				cout<<"FLOOR:"<<temp->floor<<endl;
				cout<<"ROOM_NO:"<<temp->Room_No<<endl;
				cout<<"DATE:"<<temp->Date<<endl;
				cout<<"HOURE:MIN"<<temp->Hr<<":"<<temp->Min<<endl;
				cout<<endl<<endl;
			temp=temp->next;
		}
	
		}
		int check(int floor,int room_no,fstream &file)//check room availibility
		{
		
			int a=1;
node1 *temp=front;
while(temp!=NULL)
{
	if(floor==temp->floor&&room_no==temp->Room_No)
	{
		a=0;
	}

	temp=temp->next;
}
if(a==1)
{
	
		cout<<"Floor:"<<floor<<"\t"<<"Room:"<<room_no<<endl;
	
}
		}
			int bill()//this function create the customer bill
		{
			cout<<endl;
			cout<<"THANKYOU FOR CHOOSE OUR HOTEL SIR/MADAM"<<endl;
			cout<<"NAME:"<<f_name<<" "<<l_name<<endl;
			cout<<"ROOM TYPE:"<<room_type<<endl;
			cout<<"RESERVED DAYS:"<<reserve_days_no<<endl;
			cout<<"ROOM CHARGES FOR 24 HOURS:"<<charge<<endl;
			cout<<"YOUR BILL IS:"<<balance<<endl<<endl;
			cout<<"HAVE A NICE DAY SIR/MADAM:"<<endl;
			
		}
		int update(int t_hr,int t_min,int t_date,int d,fstream &f7,int f,int r,fstream &file)
		{
				string w1 = "seq";
string filename;
stringstream str;
str << w1 << f << r << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::out|ios::binary );
				fstream file_del;
				file_del.open("temp.dat",ios::out|ios::binary);
				if(file.good())
				{
									
		file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
if(age!=0)
{
					
			
	int days;int calculate,calculate1;
	int left_d;
	int time_h;
	int time_m;
	int h,m;
	days=t_date-date;
	//these line of code calculate the remaining time and calculate the day hour and minute
	//if reserved days no and count days number equal to then update the and remove the customer data from room file
 if(t_hr>hr)
 {
 	if(t_min>min)
 	{
 		t_hr=t_hr-hr;
 		t_min=t_min-min;
 		calculate=60*t_hr;
 		calculate+=t_min;
	 }
	 else{
	 		t_hr=t_hr-hr;
 		t_min=min-t_min;
 			calculate=60*t_hr;
 		calculate+=t_min;
	 	
	 }
 }
 else if(t_hr<hr)
 {
  if(t_min>min)
  {
  		t_hr=hr-t_hr;
  		t_min=min-t_min;
  			calculate=60*t_hr;
 		calculate+=t_min;
  		
  }
  else{
  		t_hr=hr-t_hr;
  		t_min=t_min-min;
  		calculate=60*t_hr;
 		calculate+=t_min;
  }
 }
 calculate1=days*24*60;
 calculate+=calculate1;
 
 left_d=calculate/(24*3600);
 time_h=calculate%(24*3600);
 
 h=time_h/3600;
 m=time_h%3600;
 time_m=m/60;
	left_d=reserve_days_no-days;
	if(d==1)
	{
	//if time is remaining
	if(days<reserve_days_no)
	{
			cout<<"NAME:"<<f_name<<endl;
			cout<<"FLOOR:"<<Floor<<endl;
			cout<<"ROOM:"<<Room_no<<endl;
			cout<<"RREMAINING TIME:"<<left_d<<"DAYS:"<<":"<<h<<"HOUR:"<<":"<<time_m<<"MIN:"<<endl;
			cout<<endl<<endl;	
	}
}
//if time complete then remove the data fromm file
		if(days>=reserve_days_no)
		{
			//when time coomplete 
	f7<<f_name<<"\t"<<l_name<<"\t"<<gender<<"\t"<<age<<"\t"<<room_type<<"\t"<<id<<"\t"<<balance<<"\t"<<reserve_days_no<<"\t"<<Floor<<"\t"<<Room_no<<"\t"<<hr<<"\t"<<min<<"\t"<<Month<<"\t"<<date<<endl ;

	
			remove(filename.c_str());//room file data remove
			rename("temp.dat",filename.c_str());//and again create new file
		}
		
		}
				}

			file.close();

}
};

class superior:public Room{//third derived class
		char f_name[50];
	char l_name[50];
	int age;
	char gender[10];
	long long int id;
		int charge;
	int balance;
	int reserve_days_no;
	int Floor;
	int hr,min;
	int date;
	int Month;
	int count_days;
	node2 *head,*tail;
	
	public:
			superior()//constructor
		{
			head=NULL;
			tail=NULL;
			char f_name[]="";
			char l_name[]="";
			char gender[]="";
			age=0;
			id=0;
			balance=0;
			reserve_days_no=0;
			charge=1000;
			Floor=0;
		}
		int avail(int f,int r,fstream &file){
			string w1 = "seq";
string filename;
stringstream str;
str << w1 << f << r << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::out|ios::binary );
if(file.good())
{
	return 1;
}
else
{
	return 0;
}
file.close();
	}
				int reset(int f,int r,fstream &file)
		{
							string w1 = "seq";
string filename;
stringstream str;
str << w1 << f << r << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::out|ios::binary );
				fstream file_del;
				file_del.open("temp.dat",ios::out|ios::binary);
				if(file.good())
				{
							file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
		if(id!=0)
		{
				node2 *temp=new node2;
		temp->next=NULL;
			
        temp->F_name=f_name;
    	temp->L_name=l_name;
		temp->Age=age;
		temp->Gender=gender;
		temp->Id=id;
		temp->Reserve_days_no=reserve_days_no;
		balance=charge*reserve_days_no;
		temp->Balance=balance;
		temp->floor=Floor;
		temp->Room_No=Room_no;
		temp->Hr=hr;
		temp->Min=min;
		temp->Date=date;
		temp->month=Month;
		temp->Room_type=room_type;
			if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		else{
			tail->next=temp;
			tail=tail->next;
		}
			
		}
				}

	file.close();
		
		}
			int input(int floor,int room_no,int t_date,int month,fstream &f6,fstream &file)
		{
			

				
		node2 *temp=new node2;
	temp->next=NULL;
		cout<<"ENTERR CUSTOMER FIRST NAME:"<<endl;
		cin>>f_name;
temp->F_name=f_name;
    	cout<<"ENTER CUSTOME LAST NAME:"<<endl;
    	cin>>l_name;
    	temp->L_name=l_name;
		cout<<"ENTER CUSTOMER AGE:"<<endl;
		cin>>age;
		temp->Age=age;
		cout<<"ENTER CUSTOMER GENDER:"<<endl;
		cin>>gender;
		temp->Gender=gender;
		cout<<"ENTER CUSTOMER ID:"<<endl;
		cin>>id;
		temp->Id=id;
	
		cout<<"ENTER RESERVE DAYS NO:"<<endl;
		cin>>reserve_days_no;
		temp->Reserve_days_no=reserve_days_no;
		balance=charge*reserve_days_no;
		temp->Balance=balance;
		Floor=floor;
		temp->floor=Floor;
		Room_no=room_no;
		temp->Room_No=room_no;
		cout<<"ENTER TIME IN HOUUR AND MINUTE:"<<endl;
		cin>>hr>>min;
		temp->Hr=hr;
		temp->Min=min;
		date=t_date;
		temp->Date=date;
		Month=month;
		temp->month=Month;
		cout<<"ENTER ROOM TYPE SUPERIOR:"<<endl;
		cin>>room_type;
		temp->Room_type=room_type;
			if(head==NULL)
		{
		head=temp;
		tail=temp;
		}
		else{
			tail->next=temp;
			tail=tail->next;
		}
		f6.write((char*)&f_name,sizeof(f_name));
		f6.write((char*)&l_name,sizeof(l_name));
		f6.write((char*)&gender,sizeof(gender));
		f6.write((char*)&age,sizeof(age));
        f6.write((char*)&room_type,sizeof(room_type));
    	f6.write((char*)&id,sizeof(id));
		f6.write((char*)&balance,sizeof(balance));
		f6.write((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.write((char*)&Floor,sizeof(Floor));
		f6.write((char*)&Room_no,sizeof(Room_no));
		f6.write((char*)&hr,sizeof(hr));
		f6.write((char*)&min,sizeof(min));
		f6.write((char*)&Month,sizeof(Month));
		f6.write((char*)&date,sizeof(date));
		
		
		file.write((char*)&f_name,sizeof(f_name));
		file.write((char*)&l_name,sizeof(l_name));
		file.write((char*)&gender,sizeof(gender));
		file.write((char*)&age,sizeof(age));
        file.write((char*)&room_type,sizeof(room_type));
    	file.write((char*)&id,sizeof(id));
		file.write((char*)&balance,sizeof(balance));
		file.write((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.write((char*)&Floor,sizeof(Floor));
		file.write((char*)&Room_no,sizeof(Room_no));
		file.write((char*)&hr,sizeof(hr));
		file.write((char*)&min,sizeof(min));
		file.write((char*)&Month,sizeof(Month));
		file.write((char*)&date,sizeof(date));
		bill();
	
			file.close();
		}
		int output(fstream &file)
		{
			
			node2 *temp=head;
		while(temp!=NULL)
		{
				cout<<"NAME:="<<temp->F_name<<" "<<temp->L_name<<endl;
				cout<<"GENDER:"<<temp->Gender<<endl;
				cout<<"AGE:"<<temp->Age<<endl;
				cout<<"ROOM_TYPE:"<<temp->Room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<temp->Id<<endl;
				cout<<"ROOM_BALANCE:"<<temp->Balance<<endl;
				cout<<"RESERVE_DAYS:"<<temp->Reserve_days_no<<endl;
				cout<<"FLOOR:"<<temp->floor<<endl;
				cout<<"ROOM_NO:"<<temp->Room_No<<endl;
				cout<<"DATE:"<<temp->Date<<endl;
				cout<<"HOURE:MIN"<<temp->Hr<<":"<<temp->Min<<endl;
				cout<<endl<<endl;
			temp=temp->next;
		}
	
		}
		int check(int floor,int room_no,fstream &file)//check room availibility
		{
		
							int a=1;
node2 *temp=head;
while(temp!=NULL)
{
	if(floor==temp->floor&&room_no==temp->Room_No)
	{
		a=0;
	}

	temp=temp->next;
}
if(a==1)
{
	
		cout<<"Floor:"<<floor<<"\t"<<"Room:"<<room_no<<endl;
	
}
		}
			int bill()
		{
			cout<<endl;
			cout<<"THANKYOU FOR CHOOSE OUR HOTEL SIR/MADAM"<<endl;
			cout<<"NAME:"<<f_name<<" "<<l_name<<endl;
			cout<<"ROOM TYPE:"<<room_type<<endl;
			cout<<"RESERVED DAYS:"<<reserve_days_no<<endl;
			cout<<"ROOM CHARGES FOR 24 HOURS:"<<charge<<endl;
			cout<<"YOUR BILL IS:"<<balance<<endl<<endl;
			cout<<"HAVE A NICE DAY SIR/MADAM:"<<endl;
			
		}
		int update(int t_hr,int t_min,int t_date,int d,fstream &f7,int f,int r,fstream &file)
		{
				string w1 = "seq";
string filename;
stringstream str;
str << w1 << f << r << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::out|ios::binary );
				fstream file_del;
				file_del.open("temp.dat",ios::out|ios::binary);
				if(file.good())
				{
									
		file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
			
if(age!=0)
{
						
	int days;int calculate,calculate1;
	int left_d;
	int time_h;
	int time_m;
	int h,m;
	days=t_date-date;
	//these line of code calculate the remaining time and calculate the day hour and minute
	//if reserved days no and count days number equal to then update the and remove the customer data from room file
 if(t_hr>hr)
 {
 	if(t_min>min)
 	{
 		t_hr=t_hr-hr;
 		t_min=t_min-min;
 		calculate=60*t_hr;
 		calculate+=t_min;
	 }
	 else{
	 		t_hr=t_hr-hr;
 		t_min=min-t_min;
 			calculate=60*t_hr;
 		calculate+=t_min;
	 	
	 }
 }
 else if(t_hr<hr)
 {
  if(t_min>min)
  {
  		t_hr=hr-t_hr;
  		t_min=min-t_min;
  			calculate=60*t_hr;
 		calculate+=t_min;
  		
  }
  else{
  		t_hr=hr-t_hr;
  		t_min=t_min-min;
  		calculate=60*t_hr;
 		calculate+=t_min;
  }
 }
 calculate1=days*24*60;
 calculate+=calculate1;
 
 left_d=calculate/(24*3600);
 time_h=calculate%(24*3600);
 
 h=time_h/3600;
 m=time_h%3600;
 time_m=m/60;
	left_d=reserve_days_no-days;
	if(d==1)
	{
	//if time is remaining
	if(days<reserve_days_no)
	{
			cout<<"NAME:"<<f_name<<endl;
			cout<<"FLOOR:"<<Floor<<endl;
			cout<<"ROOM:"<<Room_no<<endl;
			cout<<"RREMAINING TIME:"<<left_d<<"DAYS:"<<":"<<h<<"HOUR:"<<":"<<time_m<<"MIN:"<<endl;
			cout<<endl<<endl;	
	}
}
//if time complete then remove the data fromm file
		if(days>=reserve_days_no)
		{
			//when time coomplete 
	f7<<f_name<<"\t"<<l_name<<"\t"<<gender<<"\t"<<age<<"\t"<<room_type<<"\t"<<id<<"\t"<<balance<<"\t"<<reserve_days_no<<"\t"<<Floor<<"\t"<<Room_no<<"\t"<<hr<<"\t"<<min<<"\t"<<Month<<"\t"<<date<<endl ;

		node2 *t=head;
		int count=1;
		while(t!=NULL)
		{
			if(t->F_name==f_name&&t->L_name==l_name&&t->Id==id&&t->Reserve_days_no==reserve_days_no)
			{
				delete_position(count);
			}
			count++;
			t=t->next;
		}
			remove(filename.c_str());//room file data remove
			rename("temp.dat",filename.c_str());//and again create new file
		}
				}

		
		}
			file.close();

}
   void delete_position(int pos)   
    {
        node2 *current = new node2;
        node2 *previous = new node2;
        node2 *next = new node2;
        current = head;
        for (int i = 1;i<pos;i++)   
        {
            if (current == NULL)
                return;
            previous = current;
            current = current->next;
        }
        next = current->next;
        previous->next = current->next;
        delete current;
    }

};
class junior_suite:public Room{//fourth derived class
	char f_name[50];
	char l_name[50];
	int age;
	char gender[10];
	long long int id;
	int charge;
	int balance;
	int reserve_days_no;
	int Floor;
	int hr,min;
	int date;
	int Month;
	int count_days;
	node3 *start;
	public:
			junior_suite()//connstructor
		{
			start=NULL;
			char f_name[]="";
			char l_name[]="";
			char gender[]="";
			age=0;
			id=0;
			balance=0;
			reserve_days_no=0;
			charge=2000;
			Floor=0;
		}
		int avail(int f,int r,fstream &file){
			string w1 = "seq";
string filename;
stringstream str;
str << w1 << f << r << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::out|ios::binary );
if(file.good())
{
	return 1;
}
else
{
	return 0;
}
file.close();
	}
				int reset(int f,int r,fstream &file)
		{
							string w1 = "seq";
string filename;
stringstream str;
str << w1 << f << r << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::out|ios::binary );
				fstream file_del;
				file_del.open("temp.dat",ios::out|ios::binary);
				if(file.good())
				{
						file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
		
	if(id!=0)
	{
			node3 *temp=new node3;
		temp->next=NULL;
	 temp->F_name=f_name;
    	temp->L_name=l_name;
		temp->Age=age;
		temp->Gender=gender;
		temp->Id=id;
		temp->Reserve_days_no=reserve_days_no;
		balance=charge*reserve_days_no;
		temp->Balance=balance;
		temp->floor=Floor;
		temp->Room_No=Room_no;
		temp->Hr=hr;
		temp->Min=min;
		temp->Date=date;
		temp->month=Month;
		temp->Room_type=room_type;
		node3 *s;
		   if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
	}
				}
	
		
		}
			int input(int floor,int room_no,int t_date,int month,fstream &f6,fstream &file)
		{
			

			node3 *temp=new node3;
	temp->next=NULL;
		cout<<"ENTERR CUSTOMER FIRST NAME:"<<endl;
		cin>>f_name;
temp->F_name=f_name;
    	cout<<"ENTER CUSTOME LAST NAME:"<<endl;
    	cin>>l_name;
    	temp->L_name=l_name;
		cout<<"ENTER CUSTOMER AGE:"<<endl;
		cin>>age;
		temp->Age=age;
		cout<<"ENTER CUSTOMER GENDER:"<<endl;
		cin>>gender;
		temp->Gender=gender;
		cout<<"ENTER CUSTOMER ID:"<<endl;
		cin>>id;
		temp->Id=id;
	
		cout<<"ENTER RESERVE DAYS NO:"<<endl;
		cin>>reserve_days_no;
		temp->Reserve_days_no=reserve_days_no;
		balance=charge*reserve_days_no;
		temp->Balance=balance;
		Floor=floor;
		temp->floor=Floor;
		Room_no=room_no;
		temp->Room_No=room_no;
		cout<<"ENTER TIME IN HOUUR AND MINUTE:"<<endl;
		cin>>hr>>min;
		temp->Hr=hr;
		temp->Min=min;
		date=t_date;
		temp->Date=date;
		Month=month;
		temp->month=Month;
		cout<<"ENTER ROOM TYPE JUNIOR SUITE:"<<endl;
		cin>>room_type;
		temp->Room_type=room_type;
		node3 *s;
   // temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
		f6.write((char*)&f_name,sizeof(f_name));
		f6.write((char*)&l_name,sizeof(l_name));
		f6.write((char*)&gender,sizeof(gender));
		f6.write((char*)&age,sizeof(age));
        f6.write((char*)&room_type,sizeof(room_type));
    	f6.write((char*)&id,sizeof(id));
		f6.write((char*)&balance,sizeof(balance));
		f6.write((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.write((char*)&Floor,sizeof(Floor));
		f6.write((char*)&Room_no,sizeof(Room_no));
		f6.write((char*)&hr,sizeof(hr));
		f6.write((char*)&min,sizeof(min));
		f6.write((char*)&Month,sizeof(Month));
		f6.write((char*)&date,sizeof(date));
		
		
		file.write((char*)&f_name,sizeof(f_name));
		file.write((char*)&l_name,sizeof(l_name));
		file.write((char*)&gender,sizeof(gender));
		file.write((char*)&age,sizeof(age));
        file.write((char*)&room_type,sizeof(room_type));
    	file.write((char*)&id,sizeof(id));
		file.write((char*)&balance,sizeof(balance));
		file.write((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.write((char*)&Floor,sizeof(Floor));
		file.write((char*)&Room_no,sizeof(Room_no));
		file.write((char*)&hr,sizeof(hr));
		file.write((char*)&min,sizeof(min));
		file.write((char*)&Month,sizeof(Month));
		file.write((char*)&date,sizeof(date));
		bill();
	

		file.close();
		}
		int output(fstream &file)
		{
			
		
			node3 *temp=start;
		while(temp!=NULL)
		{
				cout<<"NAME:="<<temp->F_name<<" "<<temp->L_name<<endl;
				cout<<"GENDER:"<<temp->Gender<<endl;
				cout<<"AGE:"<<temp->Age<<endl;
				cout<<"ROOM_TYPE:"<<temp->Room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<temp->Id<<endl;
				cout<<"ROOM_BALANCE:"<<temp->Balance<<endl;
				cout<<"RESERVE_DAYS:"<<temp->Reserve_days_no<<endl;
				cout<<"FLOOR:"<<temp->floor<<endl;
				cout<<"ROOM_NO:"<<temp->Room_No<<endl;
				cout<<"DATE:"<<temp->Date<<endl;
				cout<<"HOURE:MIN"<<temp->Hr<<":"<<temp->Min<<endl;
				cout<<endl<<endl;
			temp=temp->next;
		}
	
		}
			int check(int floor,int room_no,fstream &file)//check room availibility
		{
		
						int a=1;
node3 *temp=start;
while(temp!=NULL)
{
	if(floor==temp->floor&&room_no==temp->Room_No)
	{
		a=0;
	}

	temp=temp->next;
}
if(a==1)
{
	
		cout<<"Floor:"<<floor<<"\t"<<"Room:"<<room_no<<endl;
	
}
		}
			int bill()
		{
			cout<<endl;
			cout<<"THANKYOU FOR CHOOSE OUR HOTEL SIR/MADAM"<<endl;
			cout<<"NAME:"<<f_name<<" "<<l_name<<endl;
			cout<<"ROOM TYPE:"<<room_type<<endl;
			cout<<"RESERVED DAYS:"<<reserve_days_no<<endl;
			cout<<"ROOM CHARGES FOR 24 HOURS:"<<charge<<endl;
			cout<<"YOUR BILL IS:"<<balance<<endl<<endl;
			cout<<"HAVE A NICE DAY SIR/MADAM:"<<endl;
			
		}
		int update(int t_hr,int t_min,int t_date,int d,fstream &f7,int f,int r,fstream &file)
		{
				string w1 = "seq";
string filename;
stringstream str;
str << w1 << f << r << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::out|ios::binary );
				fstream file_del;
				file_del.open("temp.dat",ios::out|ios::binary);
				if(file.good())
				{
							file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
			
if(age!=0)
{
					
	int days;int calculate,calculate1;
	int left_d;
	int time_h;
	int time_m;
	int h,m;
	days=t_date-date;
	//these line of code calculate the remaining time and calculate the day hour and minute
	//if reserved days no and count days number equal to then update the and remove the customer data from room file
 if(t_hr>hr)
 {
 	if(t_min>min)
 	{
 		t_hr=t_hr-hr;
 		t_min=t_min-min;
 		calculate=60*t_hr;
 		calculate+=t_min;
	 }
	 else{
	 		t_hr=t_hr-hr;
 		t_min=min-t_min;
 			calculate=60*t_hr;
 		calculate+=t_min;
	 	
	 }
 }
 else if(t_hr<hr)
 {
  if(t_min>min)
  {
  		t_hr=hr-t_hr;
  		t_min=min-t_min;
  			calculate=60*t_hr;
 		calculate+=t_min;
  		
  }
  else{
  		t_hr=hr-t_hr;
  		t_min=t_min-min;
  		calculate=60*t_hr;
 		calculate+=t_min;
  }
 }
 calculate1=days*24*60;
 calculate+=calculate1;
 
 left_d=calculate/(24*3600);
 time_h=calculate%(24*3600);
 
 h=time_h/3600;
 m=time_h%3600;
 time_m=m/60;
	left_d=reserve_days_no-days;
	if(d==1)
	{
	//if time is remaining
	if(days<reserve_days_no)
	{
			cout<<"NAME:"<<f_name<<endl;
			cout<<"FLOOR:"<<Floor<<endl;
			cout<<"ROOM:"<<Room_no<<endl;
			cout<<"RREMAINING TIME:"<<left_d<<"DAYS:"<<":"<<h<<"HOUR:"<<":"<<time_m<<"MIN:"<<endl;
			cout<<endl<<endl;	
	}
}
//if time complete then remove the data fromm file
		if(days>=reserve_days_no)
		{
			//when time coomplete 
	f7<<f_name<<"\t"<<l_name<<"\t"<<gender<<"\t"<<age<<"\t"<<room_type<<"\t"<<id<<"\t"<<balance<<"\t"<<reserve_days_no<<"\t"<<Floor<<"\t"<<Room_no<<"\t"<<hr<<"\t"<<min<<"\t"<<Month<<"\t"<<date<<endl ;

			
		node3 *t;
		t=start;
		while(t!=NULL)
		{
			if(t->next->F_name==f_name&&t->next->Age==age&&t->Reserve_days_no==reserve_days_no&&days>=t->Reserve_days_no)
			{
				deleteNode(&start,t);
			}
			t=t->next;
		}
			remove(filename.c_str());//room file data remove
			rename("temp.dat",filename.c_str());//and again create new file
		}
	
				}

		}
			file.close();

}
void deleteNode(node3** head_ref, node3* del) {
   if (*head_ref == NULL || del == NULL) {
      return;
   }
   if (*head_ref == del) {
      *head_ref = del->next;
   }
   if (del->next != NULL) {
      del->next->prev = del->prev;
   }
   if (del->prev != NULL) {
      del->prev->next = del->next;
   }
   delete del;
   return;
}
};
class suite:public Room{//fifth derived class
	char f_name[50];
	char l_name[50];
	int age;
	char gender[10];
	long long int id;
		int charge;
	int balance;
	int reserve_days_no;
	int Floor;
	int hr,min;
	int date;
	int Month;
	int count_days;
	node4 *root;



	public:
		suite()
		{
			root=NULL;
			char f_name[]="";
			char l_name[]="";
			char gender[]="";
			age=0;
			
			id=0;
			balance=0;
			reserve_days_no=0;
			charge=5000;
			Floor=0;
		}
		int avail(int f,int r,fstream &file){
			string w1 = "seq";
string filename;
stringstream str;
str << w1 << f << r << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::out|ios::binary );
if(file.good())
{
	return 1;
}
else
{
	return 0;
}
file.close();
	}
			int reset(int f,int r,fstream &file)
		{
							string w1 = "seq";
string filename;
stringstream str;
str << w1 << f << r << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::out|ios::binary );

				if(file.good())
				{
					file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
		if(id!=0)
		{
			node4 *temp=new node4;
				node4 *parent=NULL;
	temp->left=NULL;
	temp->right=NULL;
		 temp->F_name=f_name;
    	temp->L_name=l_name;
		temp->Age=age;
		temp->Gender=gender;
		temp->Id=id;
		temp->Reserve_days_no=reserve_days_no;
		balance=charge*reserve_days_no;
		temp->Balance=balance;
		temp->floor=Floor;
		temp->Room_No=Room_no;
		temp->Hr=hr;
		temp->Min=min;
		temp->Date=date;
		temp->month=Month;
		temp->Room_type=room_type;
	
				if(root==NULL)
				{
					root=temp;
				}
				else{
					node4 *cur;
					cur=root;
					
					while(cur)
					{
						parent=cur;
						if(temp->F_name>cur->F_name)
						{
							cur=cur->right;
						}
						else{
							cur=cur->left;
						}
					}
					
					if(temp->F_name>parent->F_name)
					{
						parent->right=temp;
					}
					else{
						parent->left=temp;
					}
				}	
		}
				}

		
		file.close();
		
		}

		int input(int floor,int room_no,int t_date,int month,fstream &f6,fstream &file)
		{

			node4 *temp=new node4;
				node4 *parent=NULL;
	temp->left=NULL;
	temp->right=NULL;
		cout<<"ENTERR CUSTOMER FIRST NAME:"<<endl;
		cin>>f_name;
temp->F_name=f_name;
    	cout<<"ENTER CUSTOME LAST NAME:"<<endl;
    	cin>>l_name;
    	temp->L_name=l_name;
		cout<<"ENTER CUSTOMER AGE:"<<endl;
		cin>>age;
		temp->Age=age;
		cout<<"ENTER CUSTOMER GENDER:"<<endl;
		cin>>gender;
		temp->Gender=gender;
		cout<<"ENTER CUSTOMER ID:"<<endl;
		cin>>id;
		temp->Id=id;
	
		cout<<"ENTER RESERVE DAYS NO:"<<endl;
		cin>>reserve_days_no;
		temp->Reserve_days_no=reserve_days_no;
		balance=charge*reserve_days_no;
		temp->Balance=balance;
		Floor=floor;
		temp->floor=Floor;
		Room_no=room_no;
		temp->Room_No=room_no;
		cout<<"ENTER TIME IN HOUUR AND MINUTE:"<<endl;
		cin>>hr>>min;
		temp->Hr=hr;
		temp->Min=min;
		date=t_date;
		temp->Date=date;
		Month=month;
		temp->month=Month;
		cout<<"ENTER ROOM TYPE SUITE:"<<endl;
		cin>>room_type;
		temp->Room_type=room_type;
			
		
		
			
				if(root==NULL)
				{
					root=temp;
				}
				else{
					node4 *cur;
					cur=root;
					
					while(cur)
					{
						parent=cur;
						if(temp->F_name>cur->F_name)
						{
							cur=cur->right;
						}
						else{
							cur=cur->left;
						}
					}
					
					if(temp->F_name>parent->F_name)
					{
						parent->right=temp;
					}
					else{
						parent->left=temp;
					}
				}
		f6.write((char*)&f_name,sizeof(f_name));
		f6.write((char*)&l_name,sizeof(l_name));
		f6.write((char*)&gender,sizeof(gender));
		f6.write((char*)&age,sizeof(age));
        f6.write((char*)&room_type,sizeof(room_type));
    	f6.write((char*)&id,sizeof(id));
		f6.write((char*)&balance,sizeof(balance));
		f6.write((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.write((char*)&Floor,sizeof(Floor));
		f6.write((char*)&Room_no,sizeof(Room_no));
		f6.write((char*)&hr,sizeof(hr));
		f6.write((char*)&min,sizeof(min));
		f6.write((char*)&Month,sizeof(Month));
		f6.write((char*)&date,sizeof(date));
		
		
		file.write((char*)&f_name,sizeof(f_name));
		file.write((char*)&l_name,sizeof(l_name));
		file.write((char*)&gender,sizeof(gender));
		file.write((char*)&age,sizeof(age));
        file.write((char*)&room_type,sizeof(room_type));
    	file.write((char*)&id,sizeof(id));
		file.write((char*)&balance,sizeof(balance));
		file.write((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.write((char*)&Floor,sizeof(Floor));
		file.write((char*)&Room_no,sizeof(Room_no));
		file.write((char*)&hr,sizeof(hr));
		file.write((char*)&min,sizeof(min));
		file.write((char*)&Month,sizeof(Month));
		file.write((char*)&date,sizeof(date));
		bill();

		file.close();
		}
		int output(fstream &file)
		{
		print_inorder();
	
		}
				void print_inorder()
{
  inorder(root);
}
void inorder(node4* p)
{
	
    if(p != NULL)
    {
        if(p->left) inorder(p->left);
               out(p);
        if(p->right) inorder(p->right);
    }
   
    else return;
}
 int out(node4 *p)
    {
    	 cout<<"NAME:="<<p->F_name<<" "<<p->L_name<<endl;
				cout<<"GENDER:"<<p->Gender<<endl;
				cout<<"AGE:"<<p->Age<<endl;
				cout<<"ROOM_TYPE:"<<p->Room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<p->Id<<endl;
				cout<<"ROOM_BALANCE:"<<p->Balance<<endl;
				cout<<"RESERVE_DAYS:"<<p->Reserve_days_no<<endl;
				cout<<"FLOOR:"<<p->floor<<endl;
				cout<<"ROOM_NO:"<<p->Room_No<<endl;
				cout<<"DATE:"<<p->Date<<endl;
				cout<<"HOURE:MIN"<<p->Hr<<":"<<p->Min<<endl;
				cout<<endl<<endl;
	}
		int check(int floor,int room_no,fstream &file)//check room availibility
		{
		
			string w1 = "seq";
string filename;
stringstream str;
str << w1 << floor << room_no << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::out|ios::binary );
				
		file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
			if(id==0)
			{
				cout<<"Floor="<<floor<<"\t"<<"Room="<<room_no<<"\t";
			}
			cout<<endl;
			
			file.close();
		}
			int bill()
		{
			cout<<endl;
			cout<<"THANKYOU FOR CHOOSE OUR HOTEL SIR/MADAM"<<endl;
			cout<<"NAME:"<<f_name<<" "<<l_name<<endl;
			cout<<"ROOM TYPE:"<<room_type<<endl;
			cout<<"RESERVED DAYS:"<<reserve_days_no<<endl;
			cout<<"ROOM CHARGES FOR 24 HOURS:"<<charge<<endl;
			cout<<"YOUR BILL IS:"<<balance<<endl<<endl;
			cout<<"HAVE A NICE DAY SIR/MADAM:"<<endl;
			
		}
		int update(int t_hr,int t_min,int t_date,int d,fstream &f7,int f,int r,fstream &file)
		{
				string w1 = "seq";
string filename;
stringstream str;
str << w1 << f << r << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::in|ios::out|ios::binary );
				fstream file_del;
				file_del.open("temp.dat",ios::out|ios::binary);
				if(file.good())
				{
									
		file.read((char*)&f_name,sizeof(f_name));
		file.read((char*)&l_name,sizeof(l_name));
		file.read((char*)&gender,sizeof(gender));
		file.read((char*)&age,sizeof(age));
        file.read((char*)&room_type,sizeof(room_type));
    	file.read((char*)&id,sizeof(id));
		file.read((char*)&balance,sizeof(balance));
		file.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		file.read((char*)&Floor,sizeof(Floor));
		file.read((char*)&Room_no,sizeof(Room_no));
		file.read((char*)&hr,sizeof(hr));
		file.read((char*)&min,sizeof(min));
		file.read((char*)&Month,sizeof(Month));
		file.read((char*)&date,sizeof(date));
			
if(age!=0)
{
			
	int days;int calculate,calculate1;
	int left_d;
	int time_h;
	int time_m;
	int h,m;
	days=t_date-date;
	//these line of code calculate the remaining time and calculate the day hour and minute
	//if reserved days no and count days number equal to then update the and remove the customer data from room file
 if(t_hr>hr)
 {
 	if(t_min>min)
 	{
 		t_hr=t_hr-hr;
 		t_min=t_min-min;
 		calculate=60*t_hr;
 		calculate+=t_min;
	 }
	 else{
	 		t_hr=t_hr-hr;
 		t_min=min-t_min;
 			calculate=60*t_hr;
 		calculate+=t_min;
	 	
	 }
 }
 else if(t_hr<hr)
 {
  if(t_min>min)
  {
  		t_hr=hr-t_hr;
  		t_min=min-t_min;
  			calculate=60*t_hr;
 		calculate+=t_min;
  		
  }
  else{
  		t_hr=hr-t_hr;
  		t_min=t_min-min;
  		calculate=60*t_hr;
 		calculate+=t_min;
  }
 }
 calculate1=days*24*60;
 calculate+=calculate1;
 
 left_d=calculate/(24*3600);
 time_h=calculate%(24*3600);
 
 h=time_h/3600;
 m=time_h%3600;
 time_m=m/60;
	left_d=reserve_days_no-days;
	if(d==1)
	{
	//if time is remaining
	if(days<reserve_days_no)
	{
			cout<<"NAME:"<<f_name<<endl;
			cout<<"FLOOR:"<<Floor<<endl;
			cout<<"ROOM:"<<Room_no<<endl;
			cout<<"RREMAINING TIME:"<<left_d<<"DAYS:"<<":"<<h<<"HOUR:"<<":"<<time_m<<"MIN:"<<endl;
			cout<<endl<<endl;	
	}
}
//if time complete then remove the data fromm file
		if(days>=reserve_days_no)
		{
			//when time coomplete
	f7<<f_name<<"\t"<<l_name<<"\t"<<gender<<"\t"<<age<<"\t"<<room_type<<"\t"<<id<<"\t"<<balance<<"\t"<<reserve_days_no<<"\t"<<Floor<<"\t"<<Room_no<<"\t"<<hr<<"\t"<<min<<"\t"<<Month<<"\t"<<date<<endl ;

			
		root=Delete(root,id);
			remove(filename.c_str());//room file data remove
			rename("temp.dat",filename.c_str());//and again create new file
		}
	}
				}

	file.close();
		}
		node4* FindMin(node4* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

struct node4* Delete(struct node4 *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->Id) root->left = Delete(root->left,data);
	else if (data > root->Id) root->right = Delete(root->right,data);	
	else {
		
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		else if(root->left == NULL) {
			struct node4 *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct node4 *temp = root;
			root = root->left;
			delete temp;
		}
		else { 
			struct node4 *temp = FindMin(root->right);
			root->Id = temp->Id;
			root->right = Delete(root->right,temp->Id);
		}
	}
	return root;
}

	
};

int Report()//its a global function that tell about the report date,weekly and monthly wise record show if manager want to  check
{
	char f_name[50];
	char l_name[50];
	char room_type[20];
	int age;
	char gender[10];
	long long int id;
	int balance;
	int reserve_days_no;
	int Floor;
	int hr,min;
	int date;
	int Month;
	int count_days;
    int  found=0;
	int Room_no;
	int time;
	int remaning_time;
	int daily,weekly,month,yearly;
	int choice,e;
		fstream f6;
		f6.open("customers.dat",ios::in|ios::binary);
	
        f6.read((char*)&f_name,sizeof(f_name));
        f6.read((char*)&l_name,sizeof(l_name));
        f6.read((char*)&gender,sizeof(gender));
        f6.read((char*)&age,sizeof(age));
        f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));
	
	cout<<"PRESS 1 FOR DAILY BASE OR DATE WISE RECORD SHOW:"<<endl;
	cout<<"PRESS 2 FOR WEEKLY BASE RECORD SHOW:"<<endl;
	cout<<"PRESS 3  FOR MONTHLY BASE RECORD SHOW:"<<endl;
	cout<<"ENTER YOUR CHOICE:"<<endl;
	cin>>e;
	
	if(e==1)//date wise record show check specific date record
	{
		cout<<"ENTER TODAY DATE FOR CHECK HOW MANY CUSTOMER VISIT TODAY"<<endl;
		cin>>daily;
		
		while(!f6.eof())
		{
			if(daily==date)
			{
				cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"MONTH:"<<Month<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
             	cout<<endl<<endl;
             	found=1;
			}
			
        f6.read((char*)&f_name,sizeof(f_name));
        f6.read((char*)&l_name,sizeof(l_name));
        f6.read((char*)&gender,sizeof(gender));
        f6.read((char*)&age,sizeof(age));
        f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));
	}
	if(found==0)
	{
		cout<<"RECORD NOT FOUND:"<<endl;
	}
	}
	else if(e==2)//weekly record check
	{
		cout<<"ENTER DATE WHEN YOU WANT TO CHECK RECORD FOR A WEEK HOW MANY CUSTOMERS VISIT HOTEL:"<<endl;
		cin>>daily;
		cout<<"ENTER MONTH WHICH WEEK ARE YOU WANT TO CHECK"<<endl;
		cin>>month;
		weekly=1;
		while(!f6.eof())
		{
			if(daily==date&&month==Month&&weekly<=7)
			{
				cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"MONTH:"<<Month<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
				daily++;
				weekly++;
			   	cout<<endl<<endl;
			    found=1;
			}
			
        f6.read((char*)&f_name,sizeof(f_name));
        f6.read((char*)&l_name,sizeof(l_name));
        f6.read((char*)&gender,sizeof(gender));
        f6.read((char*)&age,sizeof(age));
        f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));
			
			
			
		}
			if(found==0)
	{
		cout<<"RECORD NOT FOUND:"<<endl;
	}
	}
	
	else if(e==3)//monthly report generate for a specific month
	{
		cout<<"ENTER MONTH NUMBER FOR CHECKING THE WHOLE RECORD OF THIS MONTH:"<<endl;
		cin>>month;
		
			while(!f6.eof())
		{
			if(month==Month)
			{
				cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"MONTH:"<<Month<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
				cout<<endl<<endl;
				found=1;
			}
			
        f6.read((char*)&f_name,sizeof(f_name));
        f6.read((char*)&l_name,sizeof(l_name));
        f6.read((char*)&gender,sizeof(gender));
        f6.read((char*)&age,sizeof(age));
        f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));
			
		
		}
			if(found==0)
	{
		cout<<"RECORD NOT FOUND:"<<endl;
	}
	}
	f6.close();
			
}
int read_complete_file()//read complete file record if manager check whole record from start to now.
{
	char f_name[50];
	char l_name[50];
	char room_type[20];
	int age;
	char gender[10];
	long long int id;
	int balance;
	int reserve_days_no;
	int Floor;
	int hr,min;
	int Room_no;
	int date;
	int Month;
	fstream f6;
		f6.open("customers.dat",ios::in|ios::binary);
	

         f6.read((char*)&f_name,sizeof(f_name));
         f6.read((char*)&l_name,sizeof(l_name));
         f6.read((char*)&gender,sizeof(gender));
         f6.read((char*)&age,sizeof(age));
         f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));

	while(!f6.eof())
	{
		        cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"MONTH:"<<Month<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
	            cout<<endl<<endl;
         
        f6.read((char*)&f_name,sizeof(f_name));
        f6.read((char*)&l_name,sizeof(l_name));
        f6.read((char*)&gender,sizeof(gender));
        f6.read((char*)&age,sizeof(age));
        f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));
	
	}
	f6.close();

}
int search()//this function search a specific person record ,room record,
{
	char f_name[50];
	char l_name[50];
	char room_type[20];
	int age;
	char gender[10];
	long long int id;
	int balance;
	int reserve_days_no;
	int Floor;
	int hr,min;
	int Room_no;
	int date;
	int Month;
    string name;
    int id_card;
    int floor;
   string room;
   int found=0;
    int e;
    do{
    		fstream f6;
		f6.open("customers.dat",ios::in|ios::binary);
    cout<<"ENTER 1 FOR NAME SEARCH:"<<endl;
    cout<<"ENTER 2 FOR ID_CARD SEARCH:"<<endl;
    cout<<"ENTER 3 FOR FLOOR SEARCH:"<<endl;
    cout<<"ENTER 4 FOR ROOM_TYPE SEARCH:"<<endl;
    cout<<"PRESS 0 FOR EXIT:"<<endl;
	cout<<"ENTER CHOICE:"<<endl;
	cin>>e;
        f6.read((char*)&f_name,sizeof(f_name));
        f6.read((char*)&l_name,sizeof(l_name));
        f6.read((char*)&gender,sizeof(gender));
        f6.read((char*)&age,sizeof(age));
        f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));

		

if(e==1)//specific record find with name
{
cout<<"ENTER CUSTOMER NAME:"<<endl;
cin>>name;	
	while(!f6.eof())
	{
	if(name==f_name)
	{
		cout<<endl;
		cout<<"YOUR SEARCH NAME DATA IS:"<<endl<<endl;
		
	
	            cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"MONTH:"<<Month<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
	          	cout<<endl<<endl;
	          	found=1;
}
		       
         
        f6.read((char*)&f_name,sizeof(f_name));
        f6.read((char*)&l_name,sizeof(l_name));
        f6.read((char*)&gender,sizeof(gender));
        f6.read((char*)&age,sizeof(age));
        f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));

		
	}
		if(found==0)
	{
		cout<<"RECORD NOT FOUND:"<<endl;
	}
}
else if(e==2)//specific record find with customer id card
{
	cout<<"ENTERR CUSTOMER ID_CARD NUMBER YOU WANTT TO FIND IN RECORD:"<<endl;
	cin>>id_card;
		while(!f6.eof())
	{
	if(id_card==id)
	{
			cout<<endl;
		cout<<"YOUR SEARCH ID DATA IS:"<<endl<<endl;
		
	            cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"MONTH:"<<Month<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
	           	cout<<endl<<endl;
	           	found=1;
	}
		       
         
        f6.read((char*)&f_name,sizeof(f_name));
        f6.read((char*)&l_name,sizeof(l_name));
        f6.read((char*)&gender,sizeof(gender));
        f6.read((char*)&age,sizeof(age));
        f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));

		
	}
		if(found==0)
	{
		cout<<"RECORD NOT FOUND:"<<endl;
	}
	
}
else if(e==3)//specific floor record
{
	cout<<"ENTER FLOOR NUMBER YOU WANT TO FIND RECORD :"<<endl;
	cin>>floor;
		while(!f6.eof())
	{
	if(floor==Floor)
	{
			cout<<endl;
		cout<<"YOUR SEARCH FLOOR DATA IS:"<<endl<<endl;
		
	            cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"MONTH:"<<Month<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
		        cout<<endl<<endl;
		        found=1;
	}
		       
         
        f6.read((char*)&f_name,sizeof(f_name));
        f6.read((char*)&l_name,sizeof(l_name));
        f6.read((char*)&gender,sizeof(gender));
        f6.read((char*)&age,sizeof(age));
        f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));

		
	}
		if(found==0)
	{
		cout<<"RECORD NOT FOUND:"<<endl;
	}
}
else if(e==4)//specific room record
{
	cout<<"ENTER ROOM NAME:SUITE:STANDARD:MODERATE:SUPERIOR:JUNIOR:"<<endl;
	cin>>room;
		while(!f6.eof())
	{
	if(room==room_type)
	{
			cout<<endl;
		cout<<"YOUR SEARCH ROOM TYPE DATA IS:"<<endl<<endl;
		
	            cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE:"<<date<<endl;
				cout<<"MONTH:"<<Month<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
	            cout<<endl<<endl;
	            found=1;
	}
		       
         
        f6.read((char*)&f_name,sizeof(f_name));
        f6.read((char*)&l_name,sizeof(l_name));
        f6.read((char*)&gender,sizeof(gender));
        f6.read((char*)&age,sizeof(age));
        f6.read((char*)&room_type,sizeof(room_type));
         
		f6.read((char*)&id,sizeof(id));
		f6.read((char*)&balance,sizeof(balance));
		f6.read((char*)&reserve_days_no,sizeof(reserve_days_no));
		f6.read((char*)&Floor,sizeof(Floor));
		f6.read((char*)&Room_no,sizeof(Room_no));
		f6.read((char*)&hr,sizeof(hr));
		f6.read((char*)&min,sizeof(min));
		f6.read((char*)&Month,sizeof(Month));
		f6.read((char*)&date,sizeof(date));

		
	}
		if(found==0)
	{
		cout<<"RECORD NOT FOUND:"<<endl;
	}
}



f6.close();	
}while(e!=0);
	
}
int skip_room_data()//global function when customer leave the hotel the user leaving date and other data store in this file
{
	char f_name[50];
	char l_name[50];
	char room_type[20];
	int age;
	char gender[10];
	long long int id;
	int balance;
	int reserve_days_no;
	int Floor;
	int hr,min;
	int Room_no;
	int date;
	int Month;
    int t_date;
    	fstream f7;
		f7.open("skipping.txt",ios::in);
    
    	f7>>f_name>>l_name>>gender>>age>>room_type>>id>>balance>>reserve_days_no>>Floor>>Room_no>>hr>>min>>Month>>date; 

		while(!f7.eof())
		{
			if(age!=0)
			{
			
			    cout<<"NAME:="<<f_name<<" "<<l_name<<endl;
				cout<<"GENDER:"<<gender<<endl;
				cout<<"AGE:"<<age<<endl;
				cout<<"ROOM_TYPE:"<<room_type<<endl;
				cout<<"CUSTOMER_ID_CARD:"<<id<<endl;
				cout<<"ROOM_BALANCE:"<<balance<<endl;
				cout<<"RESERVE_DAYS:"<<reserve_days_no<<endl;
				cout<<"FLOOR:"<<Floor<<endl;
				cout<<"ROOM_NO:"<<Room_no<<endl;
				cout<<"DATE WHEN ROOM RESERVED:"<<date<<endl;
				cout<<"DATE WHEN CUSTOMER SKIP HOTEL:"<<t_date<<endl;
				cout<<"MONTH:"<<Month<<endl;
				cout<<"HOURE:MIN"<<hr<<":"<<min<<endl;
	            cout<<endl<<endl;
	        }
	        f7>>f_name>>l_name>>gender>>age>>room_type>>id>>balance>>reserve_days_no>>Floor>>Room_no>>hr>>min>>Month>>date; 

		}
	
}

int main()//main body
{
			cout<<"\n\n\n\t\t\t   __      __   ___  | |   ___    ___    _ __ ___     ___  "<<endl;
			cout<<"\t\t\t   \\ \\ /\\ / /  / _ \\ | |  / __|  / _ \\  | '_ ` _ \\   / _ \\ "<<endl;
			cout<<"\t\t\t    \\ V  V /  |  __/ | | | (__  | (_) | | | | | | | |  __/ "<<endl;
			cout<<"\t\t\t     \\_/\\_/    \\___| |_|  \\___|  \\___/  |_| |_| |_|  \\___| "<<endl;
int t_hr,t_min;//by default passing t_hr and t_min to check room availibility
int c,d,e;
int t_date;//by default passing today date 
int month;//by dfefault passing month
int choice;
fstream file,file1,file2;//files
/*each derived a same floor and same room number of array i use room pointer that point a speific number */

Room *p[6];
standard s;
p[0]=&s;
moderate m;
p[1]=&m;
superior su;
p[2]=&su;
junior_suite j;
p[3]=&j;
Room *r;
suite s1;
p[4]=&s1;
r=&s1;
//p=&s;
//suite s1;
int b5;//that is use for room  number because every floor
 	file1.open("customers.dat",ios::in|ios::out|ios::app|ios::binary);//customer file
 file2.open("skipping.txt",ios::in|ios::out|ios::app);
 

//use do while for repeating because the hotel use multiple time in one day and switch first day and start second day 
do{ 

cout<<endl;
cout<<"\t"<<"\t"<<"\t"<<"\t"<<"ENTER 0 IN DATE IF YOU WANT TO CLOSE MANAGEMENT:"<<endl;
cout<<"\t"<<"\t"<<"\t"<<"\t"<<"ENTER TODAY DATE:"<<endl;
cin>>t_date;
cout<<"\t"<<"\t"<<"\t"<<"\t"<<"ENTER MONTH:"<<endl;
cin>>month;

	
if((month>0&&month<=12)&&(t_date>0&&t_date<=31))//checking date and month
{
//again use do while for repeating for furture data because the hotel enter data mmany time in one day
do{
	
	cout<<"\t"<<"\t"<<"\t"<<"WELCOME TO THE HOTEL MANAGEMENT:"<<endl;
	cout<<"\t"<<"\t"<<"\t"<<"ENTER 1 FOR STANDARD ROOM RESERVE:"<<endl;
	cout<<"\t"<<"\t"<<"\t"<<"ENTER 2 FOR MODERATE ROOM RESERVE:"<<endl;
	cout<<"\t"<<"\t"<<"\t"<<"ENTER 3 FOR SUPERIOR ROOM RESERVE:"<<endl;
	cout<<"\t"<<"\t"<<"\t"<<"ENTER 4 FOR JUNIOR_SUITE ROOM RESERVE:"<<endl;
	cout<<"\t"<<"\t"<<"\t"<<"ENTER 5 FOR SUITE ROOM RESERVE:"<<endl;
	cout<<"\t"<<"\t"<<"\t"<<"ENTER 7 FOR REPORT CUSTOMER:"<<endl;
	cout<<"\t"<<"\t"<<"\t"<<"ENTER 8 FOR COMPLETE FILE VIEW:"<<endl;
	cout<<"\t"<<"\t"<<"\t"<<"ENTER 9 FOR SEAARCH DATA FROM FILE:"<<endl;
	cout<<"\t"<<"\t"<<"\t"<<"ENTER 10 FOR CHECK RECORD WHEN CUSTTOMER LEAVE HOTEL:"<<endl;
	
	cout<<"\t"<<"\t"<<"\t"<<"ENTTER CHHOICE:"<<endl;
	cin>>choice;
	
	
switch(choice)//use switch for room reserved and room data checking
{
case 1://operate standard room
		for(int i=1;i<=5;i++)
		{
			for(int j=1;j<=10;j++)
			{
				p[0]->reset(i,j,file);
			}
		}
		do{
		//again use do while for each room 
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 1 FOR ROOM AVAILBILITY:"<<endl;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 2 FOR RESERVE ROOM:"<<endl;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 3 RESERVE ROOM DATA:"<<endl;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 4 FOR REMANING TIME OF RESERVED ROOM:"<<endl;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 0 FOR EXIT SUITE TYPE ROOM:"<<endl;
		cin>>e;
		if(e==1)//checking room availibility
		{
			cout<<"\t"<<"\t"<<"\t"<<"ENTER TIME IN HOUR AND IN MIN:"<<endl;
			cin>>t_hr>>t_min;
			for(int i=1;i<=5;i++)
			{
				for(int j=1;j<=10;j++)
				{
				p[0]->check(i,j,file);
				}
			}
		}
		else if(e==2)//for reserving room
		{ int c;
					int a,b;//we use for room and floor nuumber select
					cout<<"\t"<<"\t"<<"\t"<<"ENTER FLOOR NO:"<<endl;
					cin>>a;
					cout<<"\t"<<"\t"<<"\t"<<"ENTER ROOM NO:"<<endl;
					cin>>b;
					c=p[0]->avail(a,b,file);
string w1 = "seq";
string filename;
stringstream str;
str << w1 << a << b << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::out|ios::binary );

cout<<c<<endl;
if(c==1)
{
	cout<<"ROOM ALREADY RESERVED CHOOSE ANOTHER ROOM:"<<endl;
}
else{
p[0]->input(a,b,t_date,month,file1,file);	
}

					
		}
		else if(e==3)///show output
		{
			p[0]->output(file1);//change file name
		
		}
		else if(e==4)//use for to check time remainign oof customer that are stay in hotel
		{
				cout<<"\t"<<"\t"<<"\t"<<"ENTER TIME IN HOUR AND IN MIN:"<<endl;
			cin>>t_hr>>t_min;
			for(int i=1;i<=5;i++)
			{
				for(int j=1;j<=10;j++)
				{
						p[0]->update(t_hr,t_min,t_date,1,file2,i,j,file);				
				}
			}
		}
	}while(e!=0);

		break;
	case 2://use for a moderate type room
		
			for(int i=1;i<=5;i++)
		{    b5=1;
			for(int j=11;j<=20;j++)
			{
			p[1]->reset(i,j,file);
			}
		}
		do{
		
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 1 FOR ROOM AVAILBILITY:"<<endl;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 2 FOR RESERVE ROOM:"<<endl;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 3 RESERVE ROOM DATA:"<<endl;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 4 FOR REMANING TIME OF RESERVED ROOM:"<<endl;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 0 FOR EXIT SUITE TYPE ROOM:"<<endl;
		cin>>e;
		if(e==1)
		{
			cout<<"\t"<<"\t"<<"\t"<<"ENTER TIME IN HOUR AND IN MIN:"<<endl;
			cin>>t_hr>>t_min;
			for(int i=1;i<=5;i++)
			{
				for(int j=11;j<=20;j++)
				{
					p[1]->check(i,j,file);
				}
			}
		}
		else if(e==2)
		{int c;
					int a,b;//we use for room and floor nuumber select
					cout<<"\t"<<"\t"<<"\t"<<"ENTER FLOOR NO:"<<endl;
					cin>>a;
					cout<<"\t"<<"\t"<<"\t"<<"ENTER ROOM NO:"<<endl;
					cin>>b;
					c=p[1]->avail(a,b,file);
string w1 = "seq";
string filename;
stringstream str;
str << w1 << a << b << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::out|ios::binary );

if(c==1)
{
	cout<<"ROOM ALREADY RESERVED CHOOSE ANOTHER ROOM:"<<endl;
}
else{
p[1]->input(a,b,t_date,month,file1,file);	
}
					
		}
		else if(e==3)
		{
			
p[1]->output(file);					
			
		}
			else if(e==4)
		{
				cout<<"\t"<<"\t"<<"\t"<<"ENTER TIME IN HOUR AND IN MIN:"<<endl;
			cin>>t_hr>>t_min;
			for(int i=1;i<=5;i++)
			{
				for(int j=11;j<=20;j++)
				{
					p[1]->update(t_hr,t_min,t_date,1,file2,i,j,file);						
				}
			}
		}
	}while(e!=0);
		
		break;
	case 3:
			for(int i=1;i<=5;i++)
		{ b5=1;
			for(int j=21;j<=30;j++)
			{
			p[2]->reset(i,j,file);
			}
		}
		do{
		
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 1 FOR ROOM AVAILBILITY:"<<endl;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 2 FOR RESERVE ROOM:"<<endl;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 3 RESERVE ROOM DATA:"<<endl;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 4 FOR REMANING TIME OF RESERVED ROOM:"<<endl;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 0 FOR EXIT SUITE TYPE ROOM:"<<endl;
		cin>>e;
		if(e==1)
		{
			cout<<"\t"<<"\t"<<"\t"<<"ENTER TIME IN HOUR AND IN MIN:"<<endl;
			cin>>t_hr>>t_min;
			for(int i=1;i<=5;i++)
			{
				for(int j=21;j<=30;j++)
				{
				p[2]->check(i,j,file);
				}
			}
		}
		else if(e==2)
		{int c;
					int a,b;//we use for room and floor nuumber select
					cout<<"\t"<<"\t"<<"\t"<<"ENTER FLOOR NO:"<<endl;
					cin>>a;
					cout<<"\t"<<"\t"<<"\t"<<"ENTER ROOM NO:"<<endl;
					cin>>b;
					c=p[2]->avail(a,b,file);
string w1 = "seq";
string filename;
stringstream str;
str << w1 << a << b << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::out|ios::binary );

if(c==1)
{
	cout<<"ROOM ALREADY RESERVED CHOOSE ANOTHER ROOM:"<<endl;
}
else{
p[2]->input(a,b,t_date,month,file1,file);	
}
					
		}
		else if(e==3)
		{
			
p[2]->output(file);						
			
		}
			else if(e==4)
		{
				cout<<"\t"<<"\t"<<"\t"<<"ENTER TIME IN HOUR AND IN MIN:"<<endl;
			cin>>t_hr>>t_min;
			for(int i=1;i<=5;i++)
			{
				for(int j=21;j<=30;j++)
				{
					p[2]->update(t_hr,t_min,t_date,1,file2,i,j,file);					
				}
			}
		}
	}while(e!=0);
		
		break;
	case 4:
				for(int i=1;i<=5;i++)
		{b5=1;
			for(int j=31;j<=40;j++)
			{
			p[3]->reset(i,j,file);
			}
		}
		do{
		
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 1 FOR ROOM AVAILBILITY:"<<endl;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 2 FOR RESERVE ROOM:"<<endl;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 3 RESERVE ROOM DATA:"<<endl;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 4 FOR REMANING TIME OF RESERVED ROOM:"<<endl;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 0 FOR EXIT SUITE TYPE ROOM:"<<endl;
		cin>>e;
		if(e==1)
		{
			cout<<"\t"<<"\t"<<"\t"<<"ENTER TIME IN HOUR AND IN MIN:"<<endl;
			cin>>t_hr>>t_min;
			for(int i=1;i<=5;i++)
			{
				for(int j=31;j<=40;j++)
				{
					p[3]->check(i,j,file);
				}
			}
		}
		else if(e==2)
		{
				int c;
					int a,b;//we use for room and floor nuumber select
					cout<<"\t"<<"\t"<<"\t"<<"ENTER FLOOR NO:"<<endl;
					cin>>a;
					cout<<"\t"<<"\t"<<"\t"<<"ENTER ROOM NO:"<<endl;
					cin>>b;
					c=p[3]->avail(a,b,file);
string w1 = "seq";
string filename;
stringstream str;
str << w1 << a << b << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::out|ios::binary );

if(c==1)
{
	cout<<"ROOM ALREADY RESERVED CHOOSE ANOTHER ROOM:"<<endl;
}
else{
p[3]->input(a,b,t_date,month,file1,file);	
}
		}
		else if(e==3)
		{
			
p[3]->output(file);					
				
		}
			else if(e==4)
		{
				cout<<"\t"<<"\t"<<"\t"<<"ENTER TIME IN HOUR AND IN MIN:"<<endl;
			cin>>t_hr>>t_min;
			for(int i=1;i<=5;i++)
			{
				for(int j=31;j<=40;j++)
				{
				p[3]->update(t_hr,t_min,t_date,1,file2,i,j,file);						
				}
			}
		}
	}while(e!=0);
		break;
	case 5:
		for(int i=1;i<=5;i++)
		{b5=1;
			for(int j=41;j<=50;j++)
			{
			r->reset(i,j,file);
			}
		}
		do{
		//p=&s1;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 1 FOR ROOM AVAILBILITY:"<<endl;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 2 FOR RESERVE ROOM:"<<endl;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 3 RESERVE ROOM DATA:"<<endl;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 4 FOR REMANING TIME OF RESERVED ROOM:"<<endl;
		cout<<"\t"<<"\t"<<"\t"<<"PRESS 0 FOR EXIT SUITE TYPE ROOM:"<<endl;
		cin>>e;
		if(e==1)
		{
			cout<<"\t"<<"\t"<<"\t"<<"ENTER TIME IN HOUR AND IN MIN:"<<endl;
			cin>>t_hr>>t_min;
			for(int i=1;i<=5;i++)
			{
				for(int j=41;j<=50;j++)
				{
					r->check(i,j,file);
				}
			}
		}
		else if(e==2)
		{
				int c;
					int a,b;//we use for room and floor nuumber select
					cout<<"\t"<<"\t"<<"\t"<<"ENTER FLOOR NO:"<<endl;
					cin>>a;
					cout<<"\t"<<"\t"<<"\t"<<"ENTER ROOM NO:"<<endl;
					cin>>b;
					c=r->avail(a,b,file);
string w1 = "seq";
string filename;
stringstream str;
str << w1 << a << b << ".dat";
filename = str.str();
file.open( filename.c_str(),ios::out|ios::binary );

if(c==1)
{
	cout<<"ROOM ALREADY RESERVED CHOOSE ANOTHER ROOM:"<<endl;
}
else{
r->input(a,b,t_date,month,file1,file);	
}
					
		}
		else if(e==3)
		{
		r->output(file);
		
		}
			else if(e==4)
		{
				cout<<"\t"<<"\t"<<"\t"<<"ENTER TIME IN HOUR AND IN MIN:"<<endl;
			cin>>t_hr>>t_min;
			for(int i=1;i<=5;i++)
			{
				for(int j=41;j<=50;j++)
				{
						r->update(t_hr,t_min,t_date,1,file2,i,j,file);					
				}
			}
		}
	}while(e!=0);
		break;
	case 6:
		break;
	case 7:
	Report();//calling of report function
		break;
	case 8:
		read_complete_file();//calling function of read complete file
		break;
	case 9:
		search();//calling the function for to search record of a specific 
		break;
	case 10:
		skip_room_data();//calling after time complete customer record is save in this file
		break;
}



}while(choice!=0);

}
}while(t_date!=0);
}

