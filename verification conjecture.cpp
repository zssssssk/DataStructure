#include<iostream>
#include<cmath> 
using namespace std;

//show main menu

void showmenu();
void goldbach();
void collatz(); 
void nico(); 
void fours();
void Sieve();
void bg();
void tl();

int isprime(int n)
{
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)
		return 0;
	
	}
	return 1;
}


int main(){
	system("color 3f");
	
	
	int choice=1; 
	while(choice!=8)
	{
		showmenu();
		
		cout<<"\n请选择：";
		
		while(!(cin>>choice)||(choice<=0)||(choice>8))
		{
			cout<<"输入错误，请重新输入：";
			cin.clear();
			cin.sync(); 
		}
		
		switch(choice){
			case 1:
				cout<<"you select 1..."<<endl;
				goldbach();
				break;
			case 2:
				cout<<"you select 2..."<<endl;
				collatz();
				break;
			case 3:
				cout<<"you select 3..."<<endl;
				nico();
				break;
			case 4:
				cout<<"you select 4..."<<endl;
				fours();
				break;
			case 5:
				cout<<"you select 5..."<<endl;
				Sieve();
				break;
			case 6:
				cout<<"you select 6..."<<endl;
				bg();
				break;
			case 7:
				cout<<"you select 7..."<<endl;
				tl();
				break;
			case 8:
				cout<<"you select 8..."<<endl;
				cout<<"good bye"<<endl;
				break;
			default:
				cout<<"valid input."<<endl;
				break;
				
		}
		
	}
	
	return 0;
}

//implementation
void showmenu()
{
	cout<<"                   ****************************************"<<endl; 
	cout<<"                   *                                      *"<<endl; 
	cout<<"                   *         1.哥德巴赫猜想               *"<<endl; 
	cout<<"                   *         2.考拉兹猜想                 *"<<endl;
	cout<<"                   *         3.尼科斯特定理               *"<<endl;
	cout<<"                   *         4.四平方数和定理             *"<<endl;
	cout<<"                   *         5.埃拉托斯特尼筛选法找质数   *"<<endl;
	cout<<"                   *         6.新娘和新郎                 *"<<endl;
	cout<<"                   *         7.真实或谎言                 *"<<endl;
	cout<<"                   *         8.退出                       *"<<endl;
	cout<<"                   *                                      *"<<endl;
	cout<<"                   *                                      *"<<endl;
	cout<<"                   *                                      *"<<endl;
	cout<<"                   ****************************************"<<endl; 
}

void goldbach(){
	long int n=1;
	int i,flag=0;
	cout<<".....Begin to solve the goldbach......"<<endl;
	while(n!=888){
	cout<<"请输入一个大于3的偶数"<<endl;
	cout<<"输入888返回主界面"<<endl; 
	while(!(cin>>n)||(n<4)||(n%2==1))
	{
		cout<<"输入错误，请重新输入：";
		cin.clear();
		cin.sync(); 
	}
	for(i=2;i<=(n-1);i++){
		if(isprime(i)&&isprime(n-i))
			cout<<n<<"="<<i<<"+"<<n-i<<endl;
			flag=1;
	}
	if(flag==0)cout<<"此数不满足哥德巴赫猜想"<<endl; 
	}
}

void collatz(){
	long int n=1;
	cout<<".....Begin to solve the collatz conjecture......"<<endl;
	while(n!=888){
	
	cout<<"请输入一个正整数"<<endl;
	cout<<"输入888返回主界面"<<endl;  
	while(!(cin>>n)||(n<1))
	{
		cout<<"输入错误，请重新输入：";
		cin.clear();
		cin.sync(); 
	}
	cout<<n;
	while((n!=1)&&(n!=888)){
		if(n%2==1){
			n=3*n+1;
			cout<<"->"<<n;
		}
		else{
			n=n/2;
			cout<<"->"<<n;
		}
	}
	cout<<endl;
	}
}

void nico(){
	long int n=0,max,sum=0,i,j;
	cout<<".....Begin to solve the nico chester theorem......"<<endl;
	while(n!=888){
	
	cout<<"请输入一个正整数"<<endl;
	cout<<"输入888返回主界面"<<endl;  
	while(!(cin>>n)||(n<1))
	{
		cout<<"输入错误，请重新输入：";
		cin.clear();
		cin.sync(); 
	}
	max=n*n*n;
	for(i=1;i<max;i+=2)
		for(j=i;j<max;j+=2){ 
			sum+=j;
			if(sum==max) cout<<n<<"的立方="<<i<<"+...+"<<j<<endl;
			if(sum>max){
				sum=0;
				break;
			}
	}
}
}
void fours(){
	long int n=1,a,b,c,d;
	cout<<".....Begin to solve the four square Theorem......"<<endl;
	while(n!=888){
	
	cout<<"请输入一个正整数"<<endl;
	cout<<"输入888返回主界面"<<endl;  
	while(!(cin>>n)||(n<1))
	{
		cout<<"输入错误，请重新输入：";
		cin.clear();
		cin.sync(); 
	}
	for(a=0;a<n;a++)
	 for(b=a;b<n;b++)
	  for(c=b;c<n;c++)
	   for(d=c;d<n;d++){
	   	if(a*a+b*b+c*c+d*d==n)
	   		cout<<n<<"="<<a<<"×"<<a<<"+"<<b<<"×"<<b<<"+"<<c<<"×"<<c<<"+"<<d<<"×"<<d<<endl;
	   	if(a*a+b*b+c*c+d*d>n) break;
	   }

	}
}	
void Sieve(){
	long int n=1;
	cout<<".....Begin to solve Sieve of Eratosthenes......"<<endl;
	while(n!=888){
	cout<<"请输入一个正整数"<<endl;
	cout<<"输入888返回主界面"<<endl;  
	while(!(cin>>n)||(n<1))
	{
		cout<<"输入错误，请重新输入：";
		cin.clear();
		cin.sync(); 
	}
	cout<<"start from 1,end from "<<n<<endl;
	cout<<"printf all these prime number:"<<endl;
   int *isprimes=new int[n+1];
   for(int i=2;i<=n;i++) isprimes[i]=1;
   for(int j=2;j<=n;j++)
     if(isprimes[j]==1)
      for(int m=2;m*j<=n;m++) isprimes[j*m]=0;
    for(int k=2;k<=n;k++)
     if(isprimes[k]==1) cout<<k<<" ";
     cout<<endl;
     delete [] isprimes;
	}
}
void bg(){
	int n=0,m=1;
	while(m!=2){
   cout<<"There are 3 brides (A, B, C) and 3 grooms (X, Y, Z).\nA: I will marry X.\nX: My fiance is C.\nC: I will marry Z.\nIt is known that they are all kidding.\nThen, do you know who and who are a couple?"<<endl;
   cout<<"press 1 to get the answer"<<endl;
   cin>>n;
   if(n==1) cout<<"the groom X's bride is B.\nthe groom Y's bride is C\nthe groom Z's bride is A"<<endl;
   cout<<"press 2 to return the menu"<<endl;
   cin>>m;
	}
   
}
void tl(){
	int n=0,m=1;
	while(m!=2){
   cout<<"Ben says that Bob is lying.\nBob says that Bill is lying.\nBill says that they are all lying.\nThen, do you know who is lying?"<<endl;
   cout<<"press 1 to get the answer"<<endl;
   cin>>n;
   if(n==1) cout<<"Ben is lying.\nBob is true\nBill is lying."<<endl;
   cout<<"press 2 to return the menu"<<endl;
   cin>>m;
	}
}


