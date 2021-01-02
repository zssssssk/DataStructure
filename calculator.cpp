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
		cout<<"\n请选择：";
		while(!(cin>>choice)||(choice<=0)||(choice>6))
		{
			cout<<"输入错误，请重新输入：";
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
	cout<<"*              1、加法（+）（输入0以退出）   *"<<endl;
	cout<<"*                                            *"<<endl;
	cout<<"*              2、减法（-）（输入0以退出）   *"<<endl;
	cout<<"*                                            *"<<endl;
	cout<<"*              3、乘法（*）（输入0以退出）   *"<<endl;
	cout<<"*                                            *"<<endl;
	cout<<"*              4、除法（/）（输入0以退出）   *"<<endl;
	cout<<"*                                            *"<<endl;
	cout<<"*              5、混合（+-*/）（输入0以退出）*"<<endl;
	cout<<"*                                            *"<<endl;
	cout<<"*              6、退出                       *"<<endl;
	cout<<"**********************************************"<<endl;
} 

void add()
{
	int a,b,x,y;
	int s;
	int flag=0;

	
	cout<<"请输入取值范围下界："<<endl;
	while(!(cin>>x))
		{
			cout<<"输入错误，请重新输入：";
			cin.clear();
			cin.sync();
		}
	cout<<"请输入取值范围上界："<<endl; 
	while(!(cin>>y))
		{
			cout<<"输入错误，请重新输入：";
			cin.clear();
			cin.sync();
		}
	while(s!=0){
	a=(rand()%(y-x+1))+x; 
	b=(rand()%(y-x+1))+x; 
	cout<<a<<"+"<<b<<"=";
	while(!(cin>>s))
		{
			cout<<"输入错误，请重新输入：";
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

	
	cout<<"请输入取值范围下界："<<endl;
	while(!(cin>>x))
		{
			cout<<"输入错误，请重新输入：";
			cin.clear();
			cin.sync();
		}
	cout<<"请输入取值范围上界："<<endl; 
	while(!(cin>>y))
		{
			cout<<"输入错误，请重新输入：";
			cin.clear();
			cin.sync();
		}
	while(s!=0){
	a=(rand()%(y-x+1))+x; 
	b=(rand()%(y-x+1))+x; 
	cout<<a<<"-"<<b<<"=";
	while(!(cin>>s))
		{
			cout<<"输入错误，请重新输入：";
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

	
	cout<<"请输入取值范围下界："<<endl;
	while(!(cin>>x))
		{
			cout<<"输入错误，请重新输入：";
			cin.clear();
			cin.sync();
		}
	cout<<"请输入取值范围上界："<<endl; 
	while(!(cin>>y))
		{
			cout<<"输入错误，请重新输入：";
			cin.clear();
			cin.sync();
		}
	while(s!=0){
	a=(rand()%(y-x+1))+x; 
	b=(rand()%(y-x+1))+x; 
	cout<<a<<"*"<<b<<"=";
	while(!(cin>>s))
		{
			cout<<"输入错误，请重新输入：";
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

	
	cout<<"请输入答案取值范围下界："<<endl;
	while(!(cin>>x))
		{
			cout<<"输入错误，请重新输入：";
			cin.clear();
			cin.sync();
		}
	cout<<"请输入答案取值范围上界："<<endl; 
	while(!(cin>>y))
		{
			cout<<"输入错误，请重新输入：";
			cin.clear();
			cin.sync();
		}
	while(s!=0){
	
	b=(rand()%(y-x+1))+x; 
	a=b*((rand()%(y-x+1))+x);
	cout<<a<<"/"<<b<<"=";
	while(!(cin>>s))
		{
			cout<<"输入错误，请重新输入：";
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
	cout<<"请输入取值范围下界："<<endl;
	while(!(cin>>x))
		{
			cout<<"输入错误，请重新输入：";
			cin.clear();
			cin.sync();
		}
	cout<<"请输入取值范围上界："<<endl; 
	while(!(cin>>y))
		{
			cout<<"输入错误，请重新输入：";
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
			cout<<"输入错误，请重新输入：";
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
			cout<<"输入错误，请重新输入：";
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
			cout<<"输入错误，请重新输入：";
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
			cout<<"输入错误，请重新输入：";
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
	
	


