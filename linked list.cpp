#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
using namespace std;
template <class elemtype>
struct linknode
{
    elemtype data;
    linknode<elemtype> *next;
};

template <class elemtype>
class linklist{
    public:
        linklist()
        {
        	len=0;
        	head=tail=new linknode<elemtype>;
        	head->next =NULL;
		}
        linklist(const linklist<elemtype>&);
        ~linklist();
        bool isempty() const{return len<=0;}
        int length() const { return len;}
        void clear1();//1111111
        bool getelem(elemtype&,int i) const;
        bool setelem(const elemtype&,int i);
        int locateelem(const elemtype&) const;//
        int locateprior(const elemtype&) const;//
        int locatenext(const elemtype&) const;//
        bool insert1(const elemtype&,int i);//111111111111
        bool append(const elemtype &e);
        bool delete1(elemtype&,int i);//111
        int delete2(elemtype&);///删除固定的值 
        void dup();
        void traverse();
        linklist<elemtype> operator=(const linklist<elemtype>&);
    private:
        int len;
        linknode<elemtype> *head;
        linknode<elemtype> *tail;
        void copyfrom(const linklist<elemtype>&);

};

template<class elemtype>
void linklist<elemtype>::traverse(){
	linknode<elemtype> *p=head->next ;
	linknode<elemtype> *q=p->next;
	linknode<elemtype> *t;
	p->next =tail;
	while(q->next !=tail){
		t=q->next; 
		q->next=p;
		p=q;
		q=t;
	}
	q->next =p;
	head->next =q;
}
template<class elemtype>
linklist<elemtype>::linklist(const linklist<elemtype> &r)
{
    copyfrom(r);// 从r所引用的链表中复制所有的结点
}
template<class elemtype>
void linklist<elemtype>::dup(){
	linknode<elemtype> *p=head->next ,*q=p->next ;
	while(q){
		if(p->data ==q->data ){
			p->next =q->next ;
			if(tail==q) tail=p;
			--len;
			q=q->next ;
		}
		else{
			p=p->next ;q=q->next ;
		}
		
	}
}
template<class elemtype>
linklist<elemtype>::~linklist(){
 clear1();
 delete head;
}
template<class elemtype>
void linklist<elemtype>::clear1(){
   linknode<elemtype> *p=head->next,*q;
   while(p!=NULL){
    q=p->next;
    delete p;
    --len;
    p=q;
   }
   //*下面两句话没加导致各种异常
   tail=head;
   head->next=NULL;
}
template<class elemtype>
bool linklist<elemtype>::getelem(elemtype &e,int i) const
{
    if(i<1||i>len) return false;
    linknode<elemtype> *p=head->next;
    int k=1;
    while(k<i){
        p=p->next;
        k++;
    }
    e=p->data;
    return true;
}
template<class elemtype>
bool linklist<elemtype>::setelem(const elemtype &e,int i)
{
    if(i<1||i>len) return false;
    linknode<elemtype> *p=head->next;
    int k=1;
    while(k<i){
        p=p->next;
        k++;
    }
    p->data=e;
    return true;
}
template<class elemtype>
int linklist<elemtype>::locateelem(const elemtype &e) const
{
    int i=1;
    linknode<elemtype> *p=head->next;
    while(p && p->data!=e){
        i++;
        p=p->next;
    }
    if(p) return i;
    return 0;
}
template<class elemtype>
bool linklist<elemtype>::insert1(const elemtype &e,int i)
{
    linknode<elemtype> *p,*q;
    int k=1;
    if(i<1||i>len+1) return false;
    p=head;
    while(k<i){
        p=p->next;
        k++;
    }
    q=new linknode<elemtype>;
    q->data=e;
    q->next=p->next;
    p->next=q;
    ++len;
    return true;
}
template<class elemtype>
bool linklist<elemtype>::append(const elemtype &e)
{
    linknode<elemtype> *q;
    q=new linknode<elemtype>;
    q->data=e;
    tail->next=q;
    tail=q;
    tail->next=NULL;
    ++len;
    return false;
}
template<class elemtype>
bool linklist<elemtype>::delete1(elemtype &e,int i)
{
    if(i<1||i>len) return false;
    linknode<elemtype> *p,*q;
    int k=1;
    p=head;
    while(k<i){
        p=p->next;
        k++;
    }
    q=p->next;
    p->next=q->next;
    if(q==tail) tail=p;
    e=q->data;
    delete q;
    --len;
    return true;
}
template<class elemtype>
int linklist<elemtype>::delete2(elemtype &e){
	linknode<elemtype> *p ,*q;
	int n=0;
	p=head->next ;q=head;
	while(p){
		if(p->data==e ){
			q->next =p->next ;
			if(p==tail){
				tail=q;
			}
			--len;
			n++;
		}
		p=p->next ;q=q->next ;
	}
	return n;
} 
void showmenu();
void showmenu1();
void creat();
void show();
void clear();
void sort();
void search1();
void search2();
void insertl();
void deletel();
void delete22();
void duplicate();
void reserve();
void import1();
void export1();
void maxplat();
void PartitionList();
linklist<int> a;
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
		        creat() ;
		        break;
		    case 2:
		    	show();
				break;
			case 3:
				clear();
				break;
			case 4:
				sort();
				break;
			case 5:
				search1();
				break;
			case 6:
				search2();
				break;
			case 7:
				insertl();
				break;
			case 8:
				deletel();
				break;
			case 9:
				delete22();
				break;
			case 10:
				duplicate();
				break;
			case 11:
				reserve();
				break;
			case 13:
				import1();
				break;
			case 12:
			    PartitionList();
				break;
			case 14:
				export1();
				break;
			case 15:
				maxplat();
				break;
				
		}
	}
	return 0;
}
void showmenu(){
	cout<<"                   ********************************************************************"<<endl;
	cout<<"                   *                                                                  *"<<endl;
	cout<<"                   *         1.create link list        2.show link list               *"<<endl;
	cout<<"                   *         3.clear  link list        4.sort link list               *"<<endl;
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
	cout<<"                   *         1.创建链表          2.展示链表                *"<<endl;
	cout<<"                   *         3.清空链表          4.排序链表                *"<<endl;
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
	cout<<"the link list has been created and initialized by 60 random numbers:"<<endl;
	for(int i=0;i<60;i++){
		int b;b=rand()%100;
		a.append(b);
		cout<<b<<"\t";
	}
	cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar();
}
void show(){
	int b,i=1;
	while(i<a.length() ){
		if(a.getelem(b,i)) cout<<b<<"\t" ;
		i++;
	}
	cout<<endl;
	cout<<"the length of the link is:"<<a.length() <<endl;
	cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar();
}
void clear(){
	cout<<"the current link list has been clear."<<endl;
	a.clear1();
	cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar();
}
void sort(){
	int a1,a2,i;
	cout<<"the sorted list in ascending order is:"<<endl;
	for(int j=1;j<=a.length() ;j++)
	for(i=1;i<=a.length()-j ;i++){
		a.getelem(a1,i);a.getelem(a2,i+1);
		if(a1>a2){
			a.setelem(a2,i);
			a.setelem(a1,i+1); 
		}   
	}
	show();
	
}
void search1(){
	int b,x;
	cout<<"please input a location to search:";
	cin>>b;
	while(!a.getelem(x,b) ){
		cout<<"location is out of bounds.\ninvalid.please input again:\n";
		cin>>b;
	}
	cout<<"the value of "<<b<<" in the link list is:"<<x<<endl;
	cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar();
	
}
void search2(){
	int b;
	cout<<"please input a number to search:";
	cin>>b;
	cout<<"the location of "<<b<<" in the link list is:"<<a.locateelem(b)<<endl;
	cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar();
}
void insertl(){
	int b,x;
	cout<<"please input the location to be inserted:\n";cin>>b;
	cout<<"please input a number to be inserted:\n";cin>>x;
	if(a.insert1(x,b)) cout<<"insertion success.\n";
	show();
	
}
void deletel(){
	int b,x;
	cout<<"please input a location to delete:";cin>>b;
	if(a.delete1(x,b)) cout<<"the location of "<<b<<" in the link list has been deleted:"<<x<<endl;
	cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar();
}
void delete22(){
	int x;
	cout<<"please input a number to be deleted:";cin>>x;	
    cout<<"\nthere are "<<a.delete2(x) <<" of "<<x<<" deleted in the link list."<<endl;	
	cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar(); 
	
}
void duplicate(){
	int a1,a2,i;
	for(int j=1;j<=a.length() ;j++)
	for(i=1;i<=a.length()-j ;i++){
		a.getelem(a1,i);a.getelem(a2,i+1);
		if(a1>a2){
			a.setelem(a2,i);
			a.setelem(a1,i+1); 
		}   
	}
	a.dup() ;
	show();
}

void PartitionList()
{
	int v;
	cout<<"Please input the partition value:";
	cin>>v;
	cout<<"\nThe link before partition:"<<endl;
	int b,i=1;
	while(i<a.length() ){
		if(a.getelem(b,i)) cout<<b<<"\t" ;
		i++;
	}
	cout<<endl;
	cout<<"the length of the link is:"<<a.length() <<endl;
	cout<<"\nThe link after partition by"<<v<<":"<<endl;
	string s;
	i=1;
	while(i<a.length() ){
		if(a.getelem(b,i)&&b>=v) cout<<b<<"\t" ;
		else if(a.getelem(b,i)&&b<v) s=s+"\t"+to_string(b);
		i++;
	}
	cout<<s;
	cout<<endl;
	cout<<"the length of the link is:"<<a.length() <<endl;
	cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar();
}

void reserve(){
	int b,i=1;
	cout<<"The link before inversion is:"<<endl;
	while(i<a.length() ){
		if(a.getelem(b,i)) cout<<b<<"\t" ;
		i++;
	}
	cout<<endl;
	cout<<"the length of the link is:"<<a.length() <<endl;
	a.traverse() ;
	cout<<"The link after inversion is:"<<endl;
	show();
}
void import1(){
	a.clear1() ;
	ifstream in;
	in.clear();
	in.open("liandata.txt");
	if(!in) cout<<"error"<<endl;
	string t1;
	cout<<"data imported from the liandata.txt success."<<endl;
	while(in>>t1){
		int t=stoi(t1);
		a.append(t);
	} 
	 cout<<endl;
	 in.close() ;
	show();
}
void export1(){
	cout<<"data output to the file success"<<endl;
	ofstream out;int n,i=1;
	out.open("liandata.txt");
	if(!out) cout<<"error"<<endl;
	while(a.getelem(n,i) ){
		out<<n<<"\t";
		i++;
	}
	out.close() ;
	cout<<endl<<"press any key to return to the menu."<<endl;
	getchar();getchar();
}
void maxplat(){
	int n1,n2,i=1,max=1,flag=0,plat;
	while(i<a.length() ){
		a.getelem(n1,i); a.getelem(n2,i+1);
		if(n1==n2){
			switch(flag){
				case 0:{
					plat=2;
			        flag=1;
			        i++;
			        if(plat>max) max=plat;
					break;
				}
				case 1:{
					plat++;
			        i++;
			        if(plat>max) max=plat;
					break;
				}
				
			}
					
		}
		else{
			flag=0;
		}
		i++;
		
	}
	cout<<"the max plat is: "<<max<<endl;
	cout<<endl<<"press any key to return to the menu."<<endl;
	getchar();getchar();
}
