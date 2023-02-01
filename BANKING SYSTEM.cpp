#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include<sstream>
#include<ctime>
#include<cstdlib>
using namespace std;
int deposit();
int otheracc ();
int withdraw();
int openaccounts();
int Register();
int newuser();
int signin();
int call();
int mybank();
class banktransaction{
	public:
		friend class openacc;
		 int account=1000+rand()%9000000000000000;
		string middlename;
		string KRA;
		int ID;
		string birth;
		string sex;
	    int pin;
		 banktransaction(){
		 	
		 }
		
};
class openacc : public banktransaction{
	public:
	  long int accbalance;
	template <typename Y>	int indigo(Y paccbalance){
			accbalance=paccbalance;
		}
};
int withdraw()
{
	system("cls");
	openacc one;
	cout<<"Enter the account number that you want to withdraw"<<endl;
	cout<<"******DO NOT SPACE THE DIGITS******"<<endl;
	string account;
	cin>>account;
	ifstream read;
	read.open(account,ios::binary);
	if(!read.is_open())
	{
		cout<<"PLEASE MAKE A DEPOSIT FIRST"<<endl;
		cout<<"ACCOUNT NOT FOUND"<<endl;
	}
	else
	{
		read.seekg(0L,ios::end);
		long int bytes=read.tellg();
		read.seekg(0L,ios::beg);
	    read.read((char*)&one,sizeof(one));
	    cout<<"Previous account balance"<<endl;
	    cout<<"\t="<<one.accbalance<<endl;
	    read.close();
	    ofstream file;
	    file.open(account,ios::binary | ios::trunc);
	    if(!file.is_open())
	    {
	    	cout<<"PLEASE MAKE A DEPOSIT FIRST"<<endl;
	    	cout<<"ACCOUNT NUMBER NOT FOUND"<<endl;
	    }
	    else
	    {
	    openacc two;
	    cout<<"Enter amount to withdraw"<<endl;
	    long int withdraw2;
	    cin>>withdraw2;
	    
	    long int newamount;
	    newamount=one.accbalance-withdraw2;
	    cout<<"Withdraw Executed successfully"<<endl;
	    cout<<"---------New balance--------"<<endl;
	 	cout<<"*************************************"<<endl;
	    two.indigo(newamount);
	    cout<<"\t="<<newamount<<endl;
	    cout<<"*************************************"<<endl;
	    file.write((char *)&two,sizeof(two));
	
	    }   
	}
	system("pause");
}
int deposit()
{
	system("cls");
	
    openacc one;
	cout<<"Enter the account number that you want to deposit"<<endl;
	cout<<"******DO NOT SPACE THE DIGITS******"<<endl;
	string account;
	cin>>account;
	ifstream read;
	read.open(account,ios::binary);
	if(!read.is_open())
	{
		openacc deposit;
		cout<<"-------First deposit------"<<endl;
		ofstream kiki;
		kiki.open(account, ios::binary);
		cout<<"Enter amount to deposit"<<endl;
		long int amount1;
		cin>>amount1;
		cout<<"Deposit Executed successfully"<<endl;
	    cout<<"---------New balance--------"<<endl;
	 	cout<<"************************************"<<endl;
	    deposit.indigo(amount1);
	    cout<<"\t="<<amount1<<endl;
	    cout<<"************************************"<<endl;
	    kiki.write((char *)&deposit,sizeof(deposit));
	    kiki.close();
	}
	else
	{
		read.seekg(0L,ios::end);
		long int bytes=read.tellg();
		read.seekg(0L,ios::beg);
	    read.read((char*)&one,sizeof(one));
	    cout<<"Previous account balance"<<endl;
	    cout<<"\t="<<one.accbalance<<endl;
	    read.close();
	    ofstream file;
	    file.open(account,ios::binary | ios::trunc);
	    if(!file.is_open())
	    {
	    	cout<<"Error while checking database"<<endl;
	    }
	    else
	    {
	    openacc two;
	    cout<<"Enter amount to deposit"<<endl;
	    long int deposit2;
	    cin>>deposit2;
	    long int newamount;
	    newamount=one.accbalance+deposit2;
	    cout<<"Deposit Executed successfully"<<endl;
	    cout<<"---------New balance--------"<<endl;
	 	cout<<"************************************"<<endl;
	    two.indigo(newamount);
	    cout<<"\t="<<newamount<<endl;
	    cout<<"*************************************"<<endl;
	    file.write((char *)&two,sizeof(two));
	
	    }
	    
	    
	}
	
	system("pause");
	
}
int main()
{
	srand(time(NULL));
	 {
	newuser();
    } 
    mybank();
    return 0;
}
int mybank()

{
	time_t t=time(NULL);
	tm *tptr=localtime(&t);
	
	system("color 2");
	srand(time(NULL));
	banktransaction customer1;
	customer1.account;
     system("cls");
	cout<<"\t\t\t\t\t\t\t\t\t\t\tLOGIN TIME : "<<(tptr->tm_hour)<<" : "<<(tptr->tm_min)<<" : "<<(tptr->tm_sec)<<endl;

	cout<<"________Welcome to DTB Banking system________"<<endl;
	cout<<"Where Customer satisfaction is our main GOAL"<<endl;
  
	cout<<"Please select the service that you want to access below"<<endl;
	cout<<"1. Open a business account"<<endl;
	cout<<"2. Open any other account type "<<endl;
	cout<<"3. Check open accounts and balances"<<endl;
	cout<<"4. Withdraw funds"<<endl;
	cout<<"5. Deposit funds"<<endl;
	cout<<"6. EXIT"<<endl;
	int a;
	cin>>a;
	if(a==1){
		system("cls");
	   call();
	   mybank();
     }
else if(a==2)
     {
    	system("cls");
        otheracc ();
        mybank();
      }
else if (a==3)
       {
		system("cls");
    	openaccounts();
    	mybank();
       }
 else if (a==4)
       {
		system("cls");
	    withdraw();
	    mybank();
       }
 else if(a==5)
       {
	   system("cls");
	   deposit ();
	   mybank();
	   }
	   else if(a==6)
	   {
	   	return 0;
	   }
}
int call()
{
	time_t t=time(NULL);
	tm *tptr=localtime(&t);
	srand(time(NULL));
	banktransaction customer1;
    	cout<<"Please answer the following questions accordingly"<<endl;
		cout<<" Enter your Middle name on your National ID"<<endl;
		string middlename;
		cin>>customer1.middlename;
		cout<<"Enter your date/month and year of birth in the form--->  dd/mm/yyyy  <----"<<endl;
		cin>>customer1.birth;
		cout<<"Enter your National ID number below "<<endl;
		cin>>customer1.ID;
		cout<<"Enter your sex below can be---> Male/Female/Intersex <----"<<endl;
		cin>>customer1.sex;
		cout<<"Enter your KRA pin below"<<endl;
		cin>>customer1.KRA;
	    cout<<"___________YOUR DETAILS ARE___________ "<<endl;
	    cout<<"NAME          : "<<customer1.middlename<<endl;
		cout<<"Date Of Birth : "<<customer1.birth<<endl;
		cout<<"National ID   : "<<customer1.ID<<endl;
	    cout<<"SEX           : "<<customer1.sex<<endl;
		cout<<"KRA PIN       : "<<customer1.KRA<<endl;
	    system("pause");
	    cout<<"If the details are correct press [1] to proceed, if you want to change press [2]"<<endl;
	    int d;
	    cin>>d;
	    if(d==1){
	     cout<<"Your account number is : "<<customer1.account<<endl;
	     stringstream kiki;
	     kiki<<customer1.ID;
	     string myID;
	     kiki>>myID;
	     myID.append("bs.txt");
	     ofstream file;
	     file.open(myID);
	     if(!file.is_open()){
	     	cout<<"98::Error while saving details in database"<<endl;
	     }else
	     {
	    file<<"NAME          : "<<customer1.middlename<<endl;
		file<<"Date Of Birth : "<<customer1.birth<<endl;
		file<<"National ID   : "<<customer1.ID<<endl;
	    file<<"SEX           : "<<customer1.sex<<endl;
		file<<"KRA PIN       : "<<customer1.KRA<<endl;
		file<<"Your account number is : "<<customer1.account<<endl;
	    file<<"Created on : "<<(tptr->tm_mday)<<"/"<<(tptr->tm_mon)+1<<"/"<<(tptr->tm_year)+1900;
	    file<<" AT : "<<(tptr->tm_hour)<<":"<<(tptr->tm_min)<<":"<<(tptr->tm_sec)<<endl;
		cout<<"**************************************"<<endl;
	    file.close();
	    cout<<"Successfully saved to the database"<<endl;
		cout<<"**************************************"<<endl;
		 system("pause");
		 system("cls");
		 }
	 }
	 else if(d==2)
	 {
	 	system("cls");
	 	call();
	 }
	 else
	 {
	 	system("cls");
	 	call();
	 }
	
}
int openaccounts()
{
	
	openacc mteja;
	cout<<"Please enter the account number that you would like to check"<<endl;
	cout<<"******DO NOT SPACE THE DIGITS******"<<endl;
	string account;
	cin>>account;
	ifstream file;
	file.open(account,ios::binary);
	if(!file.is_open())
	{
		cout<<"ACCOUNT IS NOT ACTIVE PLEASE MAKE A DEPOSIT"<<endl;
		system("pause");
		system("cls");
		mybank();
	}
	else
	{
		file.seekg(0L,ios::end);
		long int bytes=file.tellg();
		file.seekg(0L,ios::beg);
		file.read((char*)&mteja,sizeof(mteja));
		cout<<"Current balance is"<<endl;
		cout<<"**************************"<<endl;
		cout<<mteja.accbalance<<endl;
		cout<<"**************************"<<endl;
		
	}
	system("pause");
	cout<<"WOULD YOU LIKE TO PROCEED TO:"<<endl;
	cout<<"1. DEPOSIT?"<<endl;
	cout<<"2. WITHDRAW?"<<endl;
	cout<<"3. MAIN MENU"<<endl;
	cout<<"Please input your choice below"<<endl;
	int choice;
	cin>>choice;
	if(choice==1){
		deposit();
	}else if(choice==2){
		withdraw();
	}else if(choice==3){
		mybank();
	}
	
}



int otheracc ()
{
	srand(time(NULL));
	openacc mteja2;
	cout<<"In this category we have the following account types"<<endl;
	cout<<"1. Savings account"<<endl;
	cout<<"2. Sacco account"<<endl;
	cout<<"------------------------------------------------------------"<<endl;
	cout<<"Please enter the number of account that you would like to open from the above choices"<<endl;
	int inumber;
	cin>>inumber;
	if(inumber==1){
			cout<<"Please answer the following questions accordingly"<<endl;
		cout<<" Enter your Middle name on your National ID"<<endl;
		cin>>mteja2.middlename;
		cout<<"Enter your date/month and year of birth in the form--->  dd/mm/yy  <----"<<endl;
		cin>>mteja2.birth;
		cout<<"Enter your National ID number below "<<endl;
		cin>>mteja2.ID;
		cout<<"Enter your sex below can be---> Male/Female/Intersex <----"<<endl;
		cin>>mteja2.sex;
		cout<<"Enter your KRA pin below"<<endl;
		cin>>mteja2.KRA;
	    cout<<"____________YOUR DETAILS ARE____________"<<endl;
	    cout<<"NAME          : "<<mteja2.middlename<<endl;
		cout<<"Date Of Birth : "<<mteja2.birth<<endl;
		cout<<"National ID   : "<<mteja2.ID<<endl;
	    cout<<"SEX           : "<<mteja2.sex<<endl;
		cout<<"KRA PIN       : "<<mteja2.KRA<<endl;
	    ofstream file;
	    stringstream sso;
	    sso<<mteja2.ID;
	    string savings;
	    sso>>savings;
	    savings.append("sv.txt");
	    file.open(savings);
	    if(!file.is_open()){
	    	cout<<"409::Error while saving to the database"<<endl;
	    }else{
	    file<<"NAME          : "<<mteja2.middlename<<endl;
		file<<"Date Of Birth : "<<mteja2.birth<<endl;
		file<<"National ID   : "<<mteja2.ID<<endl;
	    file<<"SEX           : "<<mteja2.sex<<endl;
		file<<"KRA PIN       : "<<mteja2.KRA<<endl;
		file<<"ACCOUNT       : "<<mteja2.account<<endl;
	    cout<<"DATA SAVED TO DATABASE SUCCESSFULLY"<<endl;
	    cout<<"Your account number is : "<<mteja2.account<<endl;
	    file.close();
	    }
	}else if(inumber==2){
		cout<<"Please answer the following questions accordingly"<<endl;
		cout<<"Enter name of the sacco"<<endl;
	}
system("pause");
system("cls");
}

 int newuser()
{
	cout<<"PLease ENTER the correct option"<<endl;
	cout<<"1. Register with DTB bank"<<endl;
	cout<<"2. Sign-in to your account"<<endl;
	int option;
	cin>>option;
	if(option==1)
	{
		Register();
	}
	else if(option==2)
	{
     signin();	
	}else
	{
		cout<<"Please input an appropriate option"<<endl;
		system("pause");
		system("cls");
		newuser();
	}
		try{
		throw "an unknown error occurred";
	}
	catch(...)
	{
		
		cout<<"an unknown error occurred"<<endl;
		
	}
	
	
}
int Register()
{
	
	cout<<"Please enter your National ID below"<<endl;
	char ipin[18];
	cin>>ipin;
	cout<<"Please input your National ID to confirm"<<endl;
	char confirm[18];
	cin>>confirm;
	if(strcmpi(ipin,confirm)==0){
		
		ofstream file;
		
		file.open(confirm,ios::binary);
		if(!file.is_open()){
			cout<<"593::Error while saving pin to database"<<endl;
			Register();
		}
		else
		{
			cout<<"PLEASE INPUT  a 4-DIGIT PIN for your account"<<endl;
			banktransaction one;
			cin>>one.pin;
			file.write((char*)&one,sizeof(banktransaction));
			file.close();
			cout<<"--------REGISTRATION EXECUTED SUCCESSFULLY-------"<<endl;
		
			system("pause");
			system("cls");
		}
		
	}
	else
	{
		cout<<"PLEASE INPUT YOUR NATIONAL ID CORRECTLY"<<endl;
		Register();
	}
}
int signin()
{
	time_t t=time(NULL);
	tm *tptr=localtime(&t);
	cout<<"Please enter your NATIONAL ID below"<<endl;
	ifstream kiki;
	char myid[18];
	cin>>myid;
	kiki.open(myid);
	if(!kiki.is_open())
	{
		cout<<"ERROR 623::ID NOT FOUND"<<endl;
		signin();
		system("cls");
	}
	else
	{
	   banktransaction two;
	   cout<<"Please input your PIN below"<<endl;
	   cout<<"****PIN SHOULD BE A FOUR-DIGIT PIN****"<<endl;
	   int ipin;
	   cin>>ipin;
	   kiki.seekg(0L,ios::beg);
	   kiki.read((char*)&two,sizeof(banktransaction));
	   kiki.close();
	    two.pin;
	   if((two.pin)!=ipin)
	   {
	   	 cout<<"Please input the correct pin \a"<<endl;
	   	 signin();
	   }
	   else if((two.pin)==ipin)
	   {
	   ofstream file;
	   file.open("LOGIN.txt",ios::app);
	   if(!file.is_open())
	   {
	   	cout<<"Error while appending login check"<<endl;
	   }
	   else
	   {
	   	file<<myid<<"  LOGGED IN AT  "<<(tptr->tm_hour)<<" : "<<(tptr->tm_min)<<" : "<<(tptr->tm_sec)<<"  ON  "<<(tptr->tm_mday)<<"/"<<(tptr->tm_mon)+1<<"/"<<(tptr->tm_year)+1900<<endl;
       
	   }
       }
	   system("cls");
	   cout<<"----------------------------------------------------------"<<endl;
	   time_t t=time(NULL);
	   tm *tptr=localtime(&t);
	   cout<<"\t\t\t\t\t\t\t\t\t\t\tLOGIN TIME : "<<(tptr->tm_hour)<<" : "<<(tptr->tm_min)<<" : "<<(tptr->tm_sec)<<endl;

	}
}






