#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
struct letter{
	char a[16];
	int b;
};
int main(){
	char x[16];
	char baba[16]="�ְ��Ҵ���";
	letter n;
	int end=1;int sum=1;
	for(int i=0;i<16;i++) x[i]='1';
	int z=0;
	ifstream ip;
	while(end){
		cout<<"��������ĳ���"<<endl;
		cin>>x;
		z=0;
		for(int i=0;i<16;i++)
		   if(x[i]=='1') break;
		   else z++; 
		ip.clear();  
		ip.open("idiom.txt");
		if(!ip) cout<<"error";
		sum++;
		ip>>n.a;
		ip>>n.b;
		while(n.b ==0){
			if(n.a[0]==x[z-3]&&n.a[1]==x[z-2]){
				cout<<n.a<<endl;
				n.b =0;
				break;
			}
			ip>>n.a>>n.b;
		}
		if(x[0]==baba[0]&&x[1]==baba[1]&&x[2]==baba[2]&&x[3]==baba[3]&&x[4]==baba[4]&&x[5]==baba[5]&&x[6]==baba[6]&&x[7]==baba[7]&&x[8]==baba[8]&&x[9]==baba[9])
		{
			cout<<"                  �� ";
			Sleep(100);
			cout<<"�� ";
			Sleep(100);
			cout<<"һ ";
			Sleep(100);
			cout<<"�� \n";
			Sleep(500);
			cout<<"��";
			Sleep(100);
			cout<<"ǿ";
			Sleep(100);
			cout<<"��"<<endl;
			Sleep(500);
			cout<<"��";
			Sleep(100);
			cout<<"��";
			Sleep(100);
			cout<<"��"<<endl;
			cout<<"�����ˣ��ǣ�1����0��������"<<endl;
			cin>>end;
			

		}
		if(n.b ==1){
			cout<<"��Ӯ�ˣ��ǣ�1����0��������"<<endl;
			cin>>end;
		}
		ip.close();
	}
	
	return 0;
}
