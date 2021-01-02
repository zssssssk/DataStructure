#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int a[100];
void showmenu();
void showmenu1();
void creat();
void show();
void clear();
void sort1();
void search1();
void search2();
void insert();
void delet();
void delet1();
void delet2();
void reserve();
void part();
void import();
void export1();
void plat();

int main(){
	system("color 3f");
	int choice=1;
	int flag=1;
	while(choice!=16){
		if(flag) showmenu();
		else showmenu1();
		while(!(cin>>choice)||(choice<0)||(choice>16)){
			cout<<"输入错误，请重新输入：";
			cin.clear();
			cin.sync();
		}
		switch(choice){
			case 0:
				flag=1-flag;
			    break;
			case 1:
		        creat();
				break;
			case 2:
				show();
				break;
			case 3:
				clear();
				break;
		    case 4:
		    	sort1();
		    	break;
		    case 5:
			   search1();
			   break;
			case 6:
              search2();
			  break;
			case 7:
			  insert();
			  break;
			 case 8:
			  delet();
			  break;
			case 9:
				delet1();
				break;
			case 10:
				delet2();
				break;
			case 11:
				reserve();
				break;
			case 12:
				part();
				break;
			case 13:
				import();
				break;
			case 14:
				export1();
				break;
			case 15:
				plat();
				break;
			
		}
	}
	return 0;
}
void showmenu(){
	cout<<"                   ********************************************************************"<<endl;
	cout<<"                   *                                                                  *"<<endl;
	cout<<"                   *         1.create list             2.show list                    *"<<endl;
	cout<<"                   *         3.clear  list             4.sort list                    *"<<endl;
	cout<<"                   *         5.search by location      6.seach by value               *"<<endl;
	cout<<"                   *         7.insert by location      8.delete by location           *"<<endl;
	cout<<"                   *         9.delete by value         10.delete duplicate            *"<<endl;
	cout<<"                   *         11.reserve list           12.partition list              *"<<endl;
	cout<<"                   *         13.import form file       14.export to file              *"<<endl;
	cout<<"                   *         15.max platform           16.exit(0 for Chinese menu)    *"<<endl;
	cout<<"                   *                                                                  *"<<endl;
	cout<<"                   ********************************************************************"<<endl;
}
void showmenu1(){
	cout<<"                   *********************************************************"<<endl;
	cout<<"                   *                                                       *"<<endl;
	cout<<"                   *         1.创建列表          2.展示列表                *"<<endl;
	cout<<"                   *         3.清除列表          4.排序列表                *"<<endl;
	cout<<"                   *         5.位置查找          6.值查找                  *"<<endl;
	cout<<"                   *         7.位置插入          8.位置删除                *"<<endl;
	cout<<"                   *         9.删除指定元素      10.删除重复元素           *"<<endl;
	cout<<"                   *         11.置逆链表         12.划分链表               *"<<endl;
	cout<<"                   *         13.从文件中导入     14.导出到文件             *"<<endl;
	cout<<"                   *         15.求最大平台       16.退出（按0显示英文菜单）*"<<endl;
	cout<<"                   *                                                       *"<<endl;
	cout<<"                   *********************************************************"<<endl;
}
void creat(){
	cout<<"the sequence list has been created and initiated by 60 random unmbers:"<<endl;
	for(int i=0;i<60;i++){
		a[i]=rand()%100+1;
		cout<<a[i]<<"\t";
	}
	cout<<endl;
	cout<<"press any key to return to the menu."<<endl;
	getchar();getchar();
}
void show(){
	int i;
	for(i=0;a[i]!=0;i++) cout<<a[i]<<"\t";
	cout<<endl;
	cout<<"the length of the sequence is:"<<i<<endl;
	cout<<"press any key to return to the menu."<<endl;
	getchar();getchar();
}
void clear(){
	cout<<"the current sequence list has been clear."<<endl;
	memset(a,0,sizeof(a));
	cout<<"press any key to return to the menu."<<endl;
	getchar();getchar();
}
void sort1(){
	int i;
	for(i=0;a[i]!=0;i++){
	}
	sort(a,a+i);
	cout<<"the sorted list in ascending order is:"<<endl;
	for(i=0;a[i]!=0;i++){
		cout<<a[i]<<"\t";
	}
	cout<<endl;
	cout<<"press any key to return to the menu."<<endl;
	getchar();getchar();
}
void search1(){
	int l;
	cout<<"please input a location to search:";
	cin>>l;
	cout<<"the value of "<<l<<" the sequence list is:"<<a[l-1]<<endl;
	cout<<"press any key to return to the menu."<<endl;
	getchar();getchar();
}
void search2(){
	int x;
	cout<<"please input a number to search:";
	cin>>x;
	for(int i=0;a[i]!=0;i++){
		if(a[i]==x) cout<<"the location of "<<x<<" in the sequence list is:"<<i+1<<endl;
	}
	cout<<"press any key to return to the menu."<<endl;
	getchar();getchar();
}
void insert(){
	int t,m;
	cout<<"please input the location to be inserted:";
	cin>>t;
	cout<<"please input a number to be inserted:";
	cin>>m;
	for(int i=t;a[i]!=0;i++) a[t]=a[t-1];
	a[t-1]=m;
	cout<<endl;
	cout<<"insertion success."<<endl;
	for(int i=0;a[i]!=0;i++) cout<<a[i]<<"\t";
	cout<<endl;
	cout<<"press any key to return to the menu."<<endl;
	getchar();getchar();
}
void delet(){
	int t;
	cout<<"please input the location to delete:";
	cin>>t;
	cout<<endl;
	cout<<"the location of "<<t<<" in the sequence list has been deleted:"<<a[t-1]<<endl;
	for(int i=t;a[i]!=0;i++) a[t-1]=a[t];
	cout<<"press any key to return to the menu."<<endl;
	getchar();getchar();
}
void delet1(){
	int t,i,sum=0;
	cout<<"please input a number to be deleted:";
	cin>>t;
	cout<<endl;
	for(i=0;a[i]!=0;i++){
		if(a[i]==t){
			sum++;
			for(int j=i;a[j]!=0;j++){
				a[j]=a[j+1];
			}
			i--;
		}
	}
	cout<<"There are "<<sum<<" of "<<t<<" deleted in the link list."<<endl;
	cout<<"press any key to return to the menu."<<endl;
	getchar();getchar();
}
void delet2(){
	int i;
	cout<<" All the duplicate elements have been deleted."<<endl;
	for(i=1;a[i]!=0;i++){
		if(a[i-1]==a[i]){
			for(int j=i-1;a[j]!=0;j++) a[j]=a[j+1];
			i--;
		}
	}
	cout<<"press any key to return to the menu."<<endl;
	getchar();getchar();
}
void reserve(){
	int i,sum=0;
	cout<<"The link before inversion is:"<<endl;
	for(i=0;a[i]!=0;i++){
		sum++;
		cout<<a[i]<<"\t";
	}
	cout<<endl;cout<<endl;
	cout<<"The link after inversion is :"<<endl;
	for(i=sum-1;i>=0;i--) cout<<a[i]<<"\t";
	cout<<"press any key to return to the menu."<<endl;
	getchar();getchar();
}
void part(){
	int t,i,m[100],n[100],k[100],m1=0,n1=0,k1=0;
	cout<<"Please input the partition value:";
	cin>>t;
	cout<<"The link before partition :"<<endl;
	for(i=0;a[i]!=0;i++) cout<<a[i]<<"\t";
	cout<<endl<<endl;
	cout<<"The link after partition by "<<t<<" :"<<endl;;
	memset(m,0,sizeof(m));memset(n,0,sizeof(n));memset(k,0,sizeof(k));
	for(i=0;a[i]!=0;i++){
		if(a[i]<t){
			m[m1]=a[i];
			m1++;
		}
		else if(a[i]==t){
			n[n1]=t;
			n1++;
		}
		else{
			k[k1]=a[i];
			k1++;
		}
	}
	for(i=0;m[i]!=0;i++) cout<<m[i]<<"\t";
	for(i=0;n[i]!=0;i++) cout<<n[i]<<"\t";
	for(i=0;k[i]!=0;i++) cout<<k[i]<<"\t";
	cout<<endl<<"press any key to return to the menu."<<endl;
	getchar();getchar();
}
void import(){
	ifstream in;
	in.open("data.txt");
	if(!in) cout<<"error"<<endl; 
    string str;
    int t1;
    cout<<"存入vector"<<endl;
    vector<int> ve;
    while(in>>t1) ve.push_back(t1);
    for(int i=0;i<ve.size();i++) cout<<ve[i]<<"\t";
    cout<<endl;
    in.close() ;
    cout<<endl<<"press any key to return to the menu."<<endl;
	getchar();getchar();
}
void export1(){
	cout<<"data output to the file success"<<endl;
	ofstream out;
	out.open("data.txt");
	if(!out) cout<<"error"<<endl;
	for(int i=0;a[i]!=0;i++){
		out<<a[i]<<"\t";
	}
	out.close() ;
	cout<<endl<<"press any key to return to the menu."<<endl;
	getchar();getchar();
}
void plat(){
	int x[1000],max=0;
	memset(x,0,sizeof(x));
	for(int i=0;a[i]!=0;i++){
		x[a[i]]++;
		if(max<x[a[i]]) max=x[a[i]];
	}
	cout<<"The max platform is: "<<max<<endl;
	cout<<endl<<"press any key to return to the menu."<<endl;
	getchar();getchar();
}
