#include<iostream>
#include<fstream>
using namespace std;
struct letter{
	char a[16];
	int b;
}; 
int main(){
	char x[16];
	letter n;
	int end=1;
	for(int i=0;i<16;i++) x[i]='1';
	int z=0;
	ifstream ip;
	while(end){
		cout<<"请输入你的成语"<<endl;
		cin>>x;
		z=0;
		for(int i=0;i<16;i++)
		   if(x[i]=='1') break;
		   else z++;
		ip.open("idiom");
		if(!ip) cout<<"error";
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
		if(n.b ==1){
			cout<<"你赢了，是（1）否（0）继续？"<<endl;
			cin>>end;
		}
	}
	ip.close();
	return 0;
}
