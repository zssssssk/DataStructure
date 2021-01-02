#include<iostream>
#include<cmath> 
#include<cstring> 
#include<windows.h>
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
void SetColor(int ForeColor,int BackColcr);



int qiuchang[30][30];
int n,m;
char aa=1;char bb=3;char cc=5;
int main(){


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
				collatz();
				break;
			case 2:
				cout<<"you select 2..."<<endl;
				goldbach();
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
	cout<<"                   *         1.create theater             *"<<endl; 
	cout<<"                   *         2.show status                *"<<endl;
	cout<<"                   *         3.sell ticket                *"<<endl;
	cout<<"                   *         4.refund                     *"<<endl;
	cout<<"                   *         5.book ticket                *"<<endl;
	cout<<"                   *         6.cancellation               *"<<endl;
	cout<<"                   *         7.search                     *"<<endl;
	cout<<"                   *         8.exit                       *"<<endl;
	cout<<"                   *                                      *"<<endl;
	cout<<"                   ****************************************"<<endl; 
}

void goldbach(){

	int a,b,c;
	a=0;b=0;c=0;
	for(int i=0;i<n;i++)
	 for(int j=0;j<m;j++){
	 	if(qiuchang[i][j]==0) a++;
	 	else if(qiuchang[i][j]==1) b++;
	 	else c++;
	 }
   cout<<"   "<<aa<<":"<<a<<"  available   ";
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	//设置红色
	 		cout<<bb;
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
   cout<<":"<<b<<"  sold   ";
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	 		cout<<cc;
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		cout<<":"<<c<<"  reserved";
   cout<<endl;
   cout<<"   ";
	for(int i=0;i<9;i++) cout<<i+1<<"  ";
	for(int i=9;i<=m;i++) cout<<i+1<<" ";
	cout<<endl;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    	if(j==0&&i<9) cout<<i+1<<"  ";
	 	if(j==0&&i>=9) cout<<i+1<<" ";
	 	if(qiuchang[i][j]==0) cout<<aa<<"  ";
	 	else if(qiuchang[i][j]==1){
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	//设置红色
	 		cout<<bb<<"  ";
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		 }
	 	else{
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN)
		;//设置绿色
		    cout<<cc<<"  ";
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		 }
	 }
	 cout<<endl;
}
	 cout<<endl;
	 cout<<"press any key to return to the menu"<<endl;
	 getchar();
	 getchar();
   }


void collatz(){
	cout<<".....Begin to solve the collatz conjecture......"<<endl;
	cout<<"please input the rows of the theater:"<<endl;
	while(!(cin>>n)||(n<1)||(n>20))
	{
		cout<<"输入错误，请重新输入一个小于21的正整数：";
		cin.clear();
		cin.sync(); 
	}
    cout<<"please input the golumns of the theater:"<<endl;
    while(!(cin>>m)||(m<1)||(m>20))
	{
		cout<<"输入错误，请重新输入一个小于21的正整数：";
		cin.clear();
		cin.sync(); 
	}
	memset(qiuchang,0,sizeof(qiuchang));
	cout<<"   "<<aa<<":"<<n*m<<"  available   ";
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	//设置红色
	 		cout<<bb;
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
   cout<<":0"<<"  sold   ";
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	 		cout<<cc;
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		cout<<":0"<<"  reserved";
   cout<<endl;
	cout<<"   ";
	for(int i=0;i<9;i++) cout<<i+1<<"  ";
	for(int i=9;i<=m;i++) cout<<i+1<<" ";
	cout<<endl;
	for(int i=0;i<n;i++){ 
	 for(int j=0;j<m;j++){
	 	if(j==0&&i<9) cout<<i+1<<"  ";
	 	if(j==0&&i>=9) cout<<i+1<<" ";
		 cout<<aa<<"  ";
	 }
	 	cout<<endl; 
	 }
	 cout<<"press any key to return to the menu"<<endl;
	 getchar();
	 getchar();
}

void nico(){
	int row,col;
	cout<<"please input the row:"<<endl;
	cin>>row;
	cout<<"please input the rcolumn:"<<endl;
	cin>>col;
	cout<<"    ticket:<"<<row<<","<<col<<"> sold success."<<endl;
	qiuchang[row-1][col-1]=1;
	int a,b,c;
	a=0;b=0;c=0;
	cout<<"   ";
	for(int i=0;i<9;i++) cout<<i+1<<"  ";
	for(int i=9;i<=m;i++) cout<<i+1<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)
	 for(int j=0;j<m;j++){
	 	if(qiuchang[i][j]==0) a++;
	 	else if(qiuchang[i][j]==1) b++;
	 	else c++;
	 }
   cout<<"   "<<aa<<":"<<a<<"  available   ";
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	//设置红色
	 		cout<<bb;
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
   cout<<":"<<b<<"  sold   ";
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	 		cout<<cc;
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		cout<<":"<<c<<"  reserved";
   cout<<endl;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    	if(j==0&&i<9) cout<<i+1<<"  ";
	 	if(j==0&&i>=9) cout<<i+1<<" ";
	 	if(qiuchang[i][j]==0) cout<<aa<<"  ";
	 	else if(qiuchang[i][j]==1){
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	//设置红色
	 		cout<<bb<<"  ";
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		 }
	 	else{
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN)
		;//设置绿色
		    cout<<cc<<"  ";
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		 }
	 }
	 cout<<endl;
}
	 cout<<endl;
	 cout<<"press any key to return to the menu"<<endl;
	 getchar();
	 getchar();
}
void fours(){
	int row,col,flag=1;
	while(flag){
		cout<<"please input the row:"<<endl;
	cin>>row;
	cout<<"please input the rcolumn:"<<endl;
	cin>>col;
	if(qiuchang[row-1][col-1]==1){
		cout<<"    ticket:<"<<row<<","<<col<<"> refund success."<<endl;
		qiuchang[row-1][col-1]=0;
		flag=0;
	}
	else{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	//设置红色
	 		cout<<"refund false!!!!!!!!!!"<<endl;
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
	}
	}
	
	
	int a,b,c;
	a=0;b=0;c=0;
	for(int i=0;i<n;i++)
	 for(int j=0;j<m;j++){
	 	if(qiuchang[i][j]==0) a++;
	 	else if(qiuchang[i][j]==1) b++;
	 	else c++;
	 }
	 cout<<"   "<<aa<<":"<<a<<"  available   ";
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	//设置红色
	 		cout<<bb;
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
   cout<<":"<<b<<"  sold   ";
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	 		cout<<cc;
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		cout<<":"<<c<<"  reserved";
	cout<<endl;
	cout<<"   ";
	for(int i=0;i<9;i++) cout<<i+1<<"  ";
	for(int i=9;i<=m;i++) cout<<i+1<<" ";	
   cout<<endl;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    	if(j==0&&i<9) cout<<i+1<<"  ";
	 	if(j==0&&i>=9) cout<<i+1<<" ";
	 	if(qiuchang[i][j]==0) cout<<aa<<"  ";
	 	else if(qiuchang[i][j]==1){
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	//设置红色
	 		cout<<bb<<"  ";
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		 }
	 	else{
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN)
		;//设置绿色
		    cout<<cc<<"  ";
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		 }
	 }
	 cout<<endl;
}
	 cout<<endl;
	 cout<<"press any key to return to the menu"<<endl;
	 getchar();
	 getchar();
}	
void Sieve(){
	int row,col;
	cout<<"please input the row:"<<endl;
	cin>>row;
	cout<<"please input the rcolumn:"<<endl;
	cin>>col;
	cout<<"    ticket:<"<<row<<","<<col<<"> book success."<<endl;
	qiuchang[row-1][col-1]=2;
	int a,b,c;
	a=0;b=0;c=0;
	cout<<"   ";
	for(int i=0;i<9;i++) cout<<i+1<<"  ";
	for(int i=9;i<=m;i++) cout<<i+1<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)
	 for(int j=0;j<m;j++){
	 	if(qiuchang[i][j]==0) a++;
	 	else if(qiuchang[i][j]==1) b++;
	 	else c++;
	 }
   cout<<"   "<<aa<<":"<<a<<"  available   ";
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	//设置红色
	 		cout<<bb;
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
   cout<<":"<<b<<"  sold   ";
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	 		cout<<cc;
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		cout<<":"<<c<<"  reserved";
   cout<<endl;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    	if(j==0&&i<9) cout<<i+1<<"  ";
	 	if(j==0&&i>=9) cout<<i+1<<" ";
	 	if(qiuchang[i][j]==0) cout<<aa<<"  ";
	 	else if(qiuchang[i][j]==1){
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	//设置红色
	 		cout<<bb<<"  ";
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		 }
	 	else{
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN)
		;//设置绿色
		    cout<<cc<<"  ";
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		 }
	 }
	 cout<<endl;
}
	 cout<<endl;
	 cout<<"press any key to return to the menu"<<endl;
	 getchar();
	 getchar();
}
void bg(){
    int row,col,flag=1;
	while(flag){
		cout<<"please input the row:"<<endl;
	cin>>row;
	cout<<"please input the rcolumn:"<<endl;
	cin>>col;
	if(qiuchang[row-1][col-1]==2){
		cout<<"    ticket:<"<<row<<","<<col<<"> cancel booking success."<<endl;
		qiuchang[row-1][col-1]=0;
		flag=0;
	}
	else{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	//设置green
	 		cout<<"cancel booking false!!!!!!!!!!"<<endl;
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
	}
	}
	
	
	int a,b,c;
	a=0;b=0;c=0;
	for(int i=0;i<n;i++)
	 for(int j=0;j<m;j++){
	 	if(qiuchang[i][j]==0) a++;
	 	else if(qiuchang[i][j]==1) b++;
	 	else c++;
	 }
	 cout<<"   "<<aa<<":"<<a<<"  available   ";
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	//设置红色
	 		cout<<bb;
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
   cout<<":"<<b<<"  sold   ";
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	 		cout<<cc;
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		cout<<":"<<c<<"  reserved";
	cout<<endl;
	cout<<"   ";
	for(int i=0;i<9;i++) cout<<i+1<<"  ";
	for(int i=9;i<=m;i++) cout<<i+1<<" ";	
   cout<<endl;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    	if(j==0&&i<9) cout<<i+1<<"  ";
	 	if(j==0&&i>=9) cout<<i+1<<" ";
	 	if(qiuchang[i][j]==0) cout<<aa<<"  ";
	 	else if(qiuchang[i][j]==1){
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	//设置红色
	 		cout<<bb<<"  ";
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		 }
	 	else{
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN)
		;//设置绿色
		    cout<<cc<<"  ";
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		 }
	 }
	 cout<<endl;
}
	 cout<<endl;
	 cout<<"press any key to return to the menu"<<endl;
	 getchar();
	 getchar();
   
}
void tl(){
   int row,col;
	cout<<"please input the row:"<<endl;
	cin>>row;
	cout<<"please input the rcolumn:"<<endl;
	cin>>col;
	switch(qiuchang[row-1][col-1]){
		case 0:
			cout<<"ticket:"<<"<"<<row<<","<<col<<"> is available."<<endl;
			break;
		case 1:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	//设置红色
	 		cout<<"ticket:"<<"<"<<row<<","<<col<<"> is sold."<<endl;
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		break;
	    case 2:
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN)
		;//设置绿色
		    cout<<"ticket:"<<"<"<<row<<","<<col<<"> is reserved."<<endl;
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		break;
	}
	int a,b,c;
	a=0;b=0;c=0;
	for(int i=0;i<n;i++)
	 for(int j=0;j<m;j++){
	 	if(qiuchang[i][j]==0) a++;
	 	else if(qiuchang[i][j]==1) b++;
	 	else c++;
	 }
	 cout<<"   "<<aa<<":"<<a<<"  available   ";
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	//设置红色
	 		cout<<bb;
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
   cout<<":"<<b<<"  sold   ";
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	 		cout<<cc;
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		cout<<":"<<c<<"  reserved";
	cout<<endl;
	cout<<"   ";
	for(int i=0;i<9;i++) cout<<i+1<<"  ";
	for(int i=9;i<=m;i++) cout<<i+1<<" ";	
   cout<<endl;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    	if(j==0&&i<9) cout<<i+1<<"  ";
	 	if(j==0&&i>=9) cout<<i+1<<" ";
	 	if(qiuchang[i][j]==0) cout<<aa<<"  ";
	 	else if(qiuchang[i][j]==1){
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	//设置红色
	 		cout<<bb<<"  ";
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		 }
	 	else{
	 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN)
		;//设置绿色
		    cout<<cc<<"  ";
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		 }
	 }
	 cout<<endl;
}
	 cout<<endl;
	 cout<<"press any key to return to the menu"<<endl;
	 getchar();
	 getchar();
}

