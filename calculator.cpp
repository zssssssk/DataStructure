#include<iostream>
#include<stdlib.h>

using namespace std;


void add();
void jian();
void multiply();
void divide();
void mixed(); 
void showmenu();

int main(){
	system("color 3f") ;
	int choice=1;
	while(choice!=8)
	{
		showmenu();
		cout<<"\n��ѡ��";
		while(!(cin>>choice)||(choice<=0)||(choice>6))
		{
			cout<<"����������������룺";
			cin.clear();
			cin.sync();
		}
		switch(choice){
			case 1:
				cout<<"you select 1..."<<endl;
				add();
				break;
			case 2:
				cout<<"you select 2..."<<endl;
				jian();

				break;
            case 3:
				cout<<"you select 3..."<<endl;
				multiply();

				break;
            case 4:
				cout<<"you select 4..."<<endl;
				divide();

				break;
            case 5:
				cout<<"you select 5..."<<endl;
				mixed();

				break;

			case 6:
				cout<<"you select 6..."<<endl;
				cout<<"good bye"<<endl;
				return 0;
				break;
			default:
				cout<<"valid input."<<endl;
				break;
		}
	}
	return 0;
}
void showmenu()
{
	cout<<"**********************************************"<<endl;
	cout<<"*                                            *"<<endl;
	cout<<"*              1���ӷ���+��������0���˳���   *"<<endl;
	cout<<"*                                            *"<<endl;
	cout<<"*              2��������-��������0���˳���   *"<<endl;
	cout<<"*                                            *"<<endl;
	cout<<"*              3���˷���*��������0���˳���   *"<<endl;
	cout<<"*                                            *"<<endl;
	cout<<"*              4��������/��������0���˳���   *"<<endl;
	cout<<"*                                            *"<<endl;
	cout<<"*              5����ϣ�+-*/��������0���˳���*"<<endl;
	cout<<"*                                            *"<<endl;
	cout<<"*              6���˳�                       *"<<endl;
	cout<<"**********************************************"<<endl;
} 

void add()
{
	int a,b,x,y;
	int s;
	int flag=0;

	
	cout<<"������ȡֵ��Χ�½磺"<<endl;
	while(!(cin>>x))
		{
			cout<<"����������������룺";
			cin.clear();
			cin.sync();
		}
	cout<<"������ȡֵ��Χ�Ͻ磺"<<endl; 
	while(!(cin>>y))
		{
			cout<<"����������������룺";
			cin.clear();
			cin.sync();
		}
	while(s!=0){
	a=(rand()%(y-x+1))+x; 
	b=(rand()%(y-x+1))+x; 
	cout<<a<<"+"<<b<<"=";
	while(!(cin>>s))
		{
			cout<<"����������������룺";
			cin.clear();
			cin.sync();
		}
		if(s==a+b&&flag==0){
		cout<<"right!"<<endl;
		flag++;
	}
		else if(s==a+b&&flag==1)
		{
			cout<<"great!"<<endl;
			flag++;
		}
		else if(s==a+b&&flag==2)
		{
			cout<<"wonderful!"<<endl;
			flag++;
		}
		else if(s==a+b&&flag==3)
		{
			cout<<"Excellent!"<<endl;
			flag++;
		}
		else if(s==a+b&&flag==4)
		{
			cout<<"Perfect!"<<endl;
			flag++;
		}
		else if(s==a+b&&flag>4)
		{
			cout<<"Perfect!"<<endl;
			flag++;
		}
		else
		{
			cout<<"try again."<<endl;
			flag=0;
		}
		
}
	
	
}

void jian()
{
	int a,b,x,y;
	int s;
	int flag=0;

	
	cout<<"������ȡֵ��Χ�½磺"<<endl;
	while(!(cin>>x))
		{
			cout<<"����������������룺";
			cin.clear();
			cin.sync();
		}
	cout<<"������ȡֵ��Χ�Ͻ磺"<<endl; 
	while(!(cin>>y))
		{
			cout<<"����������������룺";
			cin.clear();
			cin.sync();
		}
	while(s!=0){
	a=(rand()%(y-x+1))+x; 
	b=(rand()%(y-x+1))+x; 
	cout<<a<<"-"<<b<<"=";
	while(!(cin>>s))
		{
			cout<<"����������������룺";
			cin.clear();
			cin.sync();
		}
		if(s==a-b&&flag==0){
		cout<<"right!"<<endl;
		flag++;
	}
		else if(s==a-b&&flag==1)
		{
			cout<<"great!"<<endl;
			flag++;
		}
		else if(s==a-b&&flag==2)
		{
			cout<<"wonderful!"<<endl;
			flag++;
		}
		else if(s==a-b&&flag==3)
		{
			cout<<"Excellent!"<<endl;
			flag++;
		}
		else if(s==a-b&&flag==4)
		{
			cout<<"Perfect!"<<endl;
			flag++;
		}
		else if(s==a-b&&flag>4)
		{
			cout<<"Perfect!"<<endl;
			flag++;
		}
		else
		{
			cout<<"try again."<<endl;
			flag=0;
		}
		
}
	
}

void multiply()
{
	int a,b,x,y;
	int s;
	int flag=0;

	
	cout<<"������ȡֵ��Χ�½磺"<<endl;
	while(!(cin>>x))
		{
			cout<<"����������������룺";
			cin.clear();
			cin.sync();
		}
	cout<<"������ȡֵ��Χ�Ͻ磺"<<endl; 
	while(!(cin>>y))
		{
			cout<<"����������������룺";
			cin.clear();
			cin.sync();
		}
	while(s!=0){
	a=(rand()%(y-x+1))+x; 
	b=(rand()%(y-x+1))+x; 
	cout<<a<<"*"<<b<<"=";
	while(!(cin>>s))
		{
			cout<<"����������������룺";
			cin.clear();
			cin.sync();
		}
		if(s==a*b&&flag==0){
		cout<<"right!"<<endl;
		flag++;
	}
		else if(s==a*b&&flag==1)
		{
			cout<<"great!"<<endl;
			flag++;
		}
		else if(s==a*b&&flag==2)
		{
			cout<<"wonderful!"<<endl;
			flag++;
		}
		else if(s==a*b&&flag==3)
		{
			cout<<"Excellent!"<<endl;
			flag++;
		}
		else if(s==a*b&&flag==4)
		{
			cout<<"Perfect!"<<endl;
			flag++;
		}
		else if(s==a*b&&flag>4)
		{
			cout<<"Perfect!"<<endl;
			flag++;
		}
		else
		{
			cout<<"try again."<<endl;
			flag=0;
		}
		
}
}

void divide()
{
	int a,b,x,y;
	int s;
	int flag=0;

	
	cout<<"�������ȡֵ��Χ�½磺"<<endl;
	while(!(cin>>x))
		{
			cout<<"����������������룺";
			cin.clear();
			cin.sync();
		}
	cout<<"�������ȡֵ��Χ�Ͻ磺"<<endl; 
	while(!(cin>>y))
		{
			cout<<"����������������룺";
			cin.clear();
			cin.sync();
		}
	while(s!=0){
	
	b=(rand()%(y-x+1))+x; 
	a=b*((rand()%(y-x+1))+x);
	cout<<a<<"/"<<b<<"=";
	while(!(cin>>s))
		{
			cout<<"����������������룺";
			cin.clear();
			cin.sync();
		}
		if(s==a/b&&flag==0){
		cout<<"right!"<<endl;
		flag++;
	}
		else if(s==a/b&&flag==1)
		{
			cout<<"great!"<<endl;
			flag++;
		}
		else if(s==a/b&&flag==2)
		{
			cout<<"wonderful!"<<endl;
			flag++;
		}
		else if(s==a/b&&flag==3)
		{
			cout<<"Excellent!"<<endl;
			flag++;
		}
		else if(s==a/b&&flag==4)
		{
			cout<<"Perfect!"<<endl;
			flag++;
		}
		else if(s==a/b&&flag>4)
		{
			cout<<"Perfect!"<<endl;
			flag++;
		}
		else
		{
			cout<<"try again."<<endl;
			flag=0;
		}
		
}
	
}

void mixed()
{
	int a,b,x,y;
	int s;
	int flag=0;
	int f;
	f=rand()%4; 
	cout<<"������ȡֵ��Χ�½磺"<<endl;
	while(!(cin>>x))
		{
			cout<<"����������������룺";
			cin.clear();
			cin.sync();
		}
	cout<<"������ȡֵ��Χ�Ͻ磺"<<endl; 
	while(!(cin>>y))
		{
			cout<<"����������������룺";
			cin.clear();
			cin.sync();
		}

while(s!=0){

	
	if(f%4==0)
	{
	
	a=(rand()%(y-x+1))+x; 
	b=(rand()%(y-x+1))+x; 
	cout<<a<<"+"<<b<<"=";
	while(!(cin>>s))
		{
			cout<<"����������������룺";
			cin.clear();
			cin.sync();
		}
		if(s==a+b&&flag==0){
		cout<<"right!"<<endl;
		flag++;
	}
		else if(s==a+b&&flag==1)
		{
			cout<<"great!"<<endl;
			flag++;
		}
		else if(s==a+b&&flag==2)
		{
			cout<<"wonderful!"<<endl;
			flag++;
		}
		else if(s==a+b&&flag==3)
		{
			cout<<"Excellent!"<<endl;
			flag++;
		}
		else if(s==a+b&&flag==4)
		{
			cout<<"Perfect!"<<endl;
			flag++;
		}
		else if(s==a+b&&flag>4)
		{
			cout<<"Perfect!"<<endl;
			flag++;
		}
		else
		{
			cout<<"try again."<<endl;
			flag=0;
		}
		f=rand()%4;  
	}
	if(f%4==1)
	{
	a=(rand()%(y-x+1))+x; 
	b=(rand()%(y-x+1))+x; 
	cout<<a<<"-"<<b<<"=";
	while(!(cin>>s))
		{
			cout<<"����������������룺";
			cin.clear();
			cin.sync();
		}
		if(s==a-b&&flag==0){
		cout<<"right!"<<endl;
		flag++;
	}
		else if(s==a-b&&flag==1)
		{
			cout<<"great!"<<endl;
			flag++;
		}
		else if(s==a-b&&flag==2)
		{
			cout<<"wonderful!"<<endl;
			flag++;
		}
		else if(s==a-b&&flag==3)
		{
			cout<<"Excellent!"<<endl;
			flag++;
		}
		else if(s==a-b&&flag==4)
		{
			cout<<"Perfect!"<<endl;
			flag++;
		}
		else if(s==a-b&&flag>4)
		{
			cout<<"Perfect!"<<endl;
			flag++;
		}
		else
		{
			cout<<"try again."<<endl;
			flag=0;
		}
		f=rand()%4; 
		
}
		
	
	if(f%4==2)
	{
	a=(rand()%(y-x+1))+x; 
	b=(rand()%(y-x+1))+x; 
	cout<<a<<"*"<<b<<"=";
	while(!(cin>>s))
		{
			cout<<"����������������룺";
			cin.clear();
			cin.sync();
		}
		if(s==a*b&&flag==0){
		cout<<"right!"<<endl;
		flag++;
	}
		else if(s==a*b&&flag==1)
		{
			cout<<"great!"<<endl;
			flag++;
		}
		else if(s==a*b&&flag==2)
		{
			cout<<"wonderful!"<<endl;
			flag++;
		}
		else if(s==a*b&&flag==3)
		{
			cout<<"Excellent!"<<endl;
			flag++;
		}
		else if(s==a*b&&flag==4)
		{
			cout<<"Perfect!"<<endl;
			flag++;
		}
		else if(s==a*b&&flag>4)
		{
			cout<<"Perfect!"<<endl;
			flag++;
		}
		else
		{
			cout<<"try again."<<endl;
			flag=0;
		}
		
		f=rand()%4;  
	}
	if(f%4==3)
	{

	
	b=(rand()%(y-x+1))+x; 
	a=b*((rand()%(y-x+1))+x);
	cout<<a<<"/"<<b<<"=";
	while(!(cin>>s))
		{
			cout<<"����������������룺";
			cin.clear();
			cin.sync();
		}
		if(s==a/b&&flag==0){
		cout<<"right!"<<endl;
		flag++;
	}
		else if(s==a/b&&flag==1)
		{
			cout<<"great!"<<endl;
			flag++;
		}
		else if(s==a/b&&flag==2)
		{
			cout<<"wonderful!"<<endl;
			flag++;
		}
		else if(s==a/b&&flag==3)
		{
			cout<<"Excellent!"<<endl;
			flag++;
		}
		else if(s==a/b&&flag==4)
		{
			cout<<"Perfect!"<<endl;
			flag++;
		}
		else if(s==a/b&&flag>4)
		{
			cout<<"Perfect!"<<endl;
			flag++;
		}
		else
		{
			cout<<"try again."<<endl;
			flag=0;
		}
		
		f=rand()%4;  
	}}
}
	
	


