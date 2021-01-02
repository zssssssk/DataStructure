#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
using namespace std;
template <class ElemType>	// ����һ����ģ��
class SqQueue
{
public:     
    SqQueue(int m = 100);	// ���캯��
    ~SqQueue();	// ��������
    void Clear();	// ��ն���
    bool Empty() const;		// �ж��п�
    int getfront(){
    	return m_front;
	} 
    int getrear(){
    	return m_rear;
	}
	int getsize(){
		return m_size;
	}
    ElemType & GetHead() const;	// ȡ��ͷԪ��ֵ
    ElemType & GetLast() const;	// ȡ��βԪ��ֵ
    ElemType & Getn(int n) const;	// ȡnλ��Ԫ��ֵ
    void Append(const ElemType &e); 	// ���
    void Remove();	// ����
    void show();
private: 
    ElemType *m_base;  	// ����ַָ��
    int m_front;        	// ��ͷָ��
    int m_rear;         	// ��βָ��
    int m_size;         	// �����ռ��С
};
template <class ElemType>
ElemType & SqQueue <ElemType>::Getn(int n) const
{
    return m_base[n];
}
template<class ElemType>
void SqQueue <ElemType>::show(){
	int i=m_front,sum=0;
	while(i!=m_rear){
		cout<<m_base[i]<<"\t";
		i=(i+1)%m_size;sum++;
	}
	cout<<"\nthe length of the link is:"<<sum<<endl;
}
// ���캯��������m������˳��ռ䣬����һ���յ�ѭ������
template <class ElemType>
SqQueue <ElemType>::SqQueue(int m)
{
    m_front = m_rear = 0;
    m_base = new ElemType[m];
    m_size = m;
}
// ���������������нṹ����
template <class ElemType>
SqQueue <ElemType>::~SqQueue()
{
delete[] m_base;
}
// ��ն���
template <class ElemType>
void SqQueue <ElemType>::Clear()
{
m_front = m_rear = 0;
}
// �ж����Ƿ�Ϊ�գ���Ϊ�գ��򷵻�true�����򷵻�false
template <class ElemType>
bool SqQueue <ElemType>::Empty() const
{
return m_front == m_rear;
}
// ȡ��ͷԪ�ص�ֵ���Ⱦ������Ƕ��зǿ�
template <class ElemType>
ElemType & SqQueue <ElemType>::GetHead() const
{
return m_base[m_front];
}
// ȡ��βԪ�ص�ֵ���Ⱦ������Ƕ��зǿ�
template <class ElemType>
ElemType & SqQueue <ElemType>::GetLast() const
{
    return m_base[(m_rear - 1 + m_size) % m_size];
}
// ��ӣ�����e����β
template <class ElemType>
void SqQueue <ElemType>::Append(const ElemType &e)
{
int j, k;
if (m_front == (m_rear + 1) % m_size) {  // ����������չ�ռ䡣
ElemType *newbase;
newbase = new ElemType[m_size + 10];  // �����¿ռ�
        for (j = m_front, k = 0; j < m_rear; j = (j + 1) % m_size, k++) 
            newbase[k] = m_base[j];   // ����Ԫ�ص��¿ռ�
delete[] m_base;               // �ͷ�ԭ�ռ�
m_base = newbase;
m_front = 0;                   	// ���ö�ͷָ��
m_rear = k;                     	// ���ö�βָ��
m_size += 10;                  	// ���������ռ��С
    }
    m_base[m_rear] = e;
    m_rear = (m_rear + 1) % m_size;
}
// ���ӡ��Ⱦ������Ƕ��зǿ�
template <class ElemType>
void SqQueue <ElemType>::Remove()
{
    m_front = (m_front + 1) % m_size;
}
void showmenu1();
void showmenu();
void creat();
void show1();
void en();
void de();
void clear();
void gethead();
void import();
void export1();
void partner();
void game();
SqQueue<int> a(10);
int main(){
	system("color 3f");

	int choice=1;
	int flag=1;
	while(choice!=12){
		if(flag) showmenu();
		else showmenu1();
		while(!(cin>>choice)||(choice<0)||(choice>16)){
			cout<<"����������������룺";
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
		    	show1();
		    	break;
		    case 3:
		    	en();
		    	break;
			case 4:
			     de();
				 break;
			case 5:
			     clear();
				 break;	
			case 6:
				gethead();
				break;
			case 7:
				import();
				break;
			case 8:
				export1();
				break;
			case 9:
				partner();
				break;
			case 10:
				game();
				break;
		}
	}
	return 0;
}
void showmenu(){
	cout<<"                   *********************************************************************"<<endl;
	cout<<"                   *                                                                   *"<<endl;
	cout<<"                   *         1.create quene             2.show quene                   *"<<endl;
	cout<<"                   *         3.enquene                  4.dequene                      *"<<endl;
	cout<<"                   *         5.clear quene              6.get head                     *"<<endl;
	cout<<"                   *         7.import from file         8.export to file               *"<<endl;
	cout<<"                   *         9.partner problem          10.game problem                *"<<endl;
	cout<<"                   *         11.train carriage problrm  12. exit(0 for Chinese menu)   *"<<endl;
	cout<<"                   *                                                                   *"<<endl;
	cout<<"                   *********************************************************************"<<endl;
}
void showmenu1(){
	cout<<"                   *********************************************************************"<<endl;
	cout<<"                   *                                                                   *"<<endl;
	cout<<"                   *         1.��������          2.��ʾ����                            *"<<endl;
	cout<<"                   *         3.���              4.����                                *"<<endl;
	cout<<"                   *         5.��ն���          6.��ȡ��ͷԪ��                        *"<<endl;
	cout<<"                   *         7.���ļ��е���      8.�������ļ�                          *"<<endl;
	cout<<"                   *         9.�������          10.�˶�������                         *"<<endl;
	cout<<"                   *         11.�𳵳�������     12.�˳�����0��ʾӢ�Ĳ˵���            *"<<endl;
	cout<<"                   *                                                                   *"<<endl;
	cout<<"                   *********************************************************************"<<endl;
}
void creat(){
	int n,m=rand();
	cout<<"the quene has been created and initiated by:"<<endl;
	for(int i=0;i<m;i++){
		a.Append(i);cout<<i<<"\t"; 
	}
	cout<<endl;
	cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar();
} 
void show1(){
    a.show();
    cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar();
} 
void en(){
	int n;
	cout<<"please input a number to append:";
	cin>>n;
	cout<<"\nappend "<<n<<" to the quene success."<<endl;
    a.Append(n);
    show1();
}
void de(){
	cout<<"the first element "<<a.GetHead()<<" pop success."<<endl;
	a.Remove();
	show1();
}
void clear(){
	cout<<"the quene has been clear."<<endl;
	a.Clear();
	cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar();
}
void gethead(){
	cout<<"the head of the quene is:"<<a.GetHead()<<endl;
	cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar();
}
void import(){
	a.Clear() ;
	ifstream in;
	in.open("duiliedata.txt");
	if(!in) cout<<"error"<<endl;
	int t1,sum=0;
	while(in>>t1){
		a.Append(t1);sum++;
	} 
	 cout<<"there are "<<sum<<" data imported to the quene."<<endl;
	 in.close();
	show1();
}
void export1(){
	ofstream out;
	out.open("duiliedata.txt");
	if(!out) cout<<"error"<<endl;
	int i=a.getfront(),sum=0;
	while(i!=a.getrear()){
		out<<a.Getn(i)<<"\t";sum++;
		i=(i+1)%a.getsize();
	} 
	out.close() ;
	cout<<"there are "<<sum<<" data exported to the file."<<endl;
	show1();
}
void partner(){
	int x,y,z,i,t,k,ma,mi,j=1;
	SqQueue<int> p1,p2;
	cout<<"At the dance hall, boys (M) and girls (N) line up in a line when they enter the ballroom. At the beginning of the dance, one person from the top of the boys' team and one from the girls' team will be assigned as partners. Unpaired people will wait for the next round of dance music. Now it is required to write an algorithm to simulate the above-mentioned dance partner problem. Assuming that a total of k songs will been danced, find the matching status of boys and girls in each song.\n";
	cout<<"\nEnter a number t to display:"<<endl;
	cout<<"\n(1). The matching situation of the t-th song;"<<endl;
	cout<<"(2). All dancing partners of the t-th boy;"<<endl;
	cout<<"(3). All dancing partners of the t-th girl."<<endl;
	cout<<"\nplease input the number of the boys:";cin>>x;
	cout<<"\nplease input the number of the girls:";cin>>y;
	cout<<"\nplease input the number of the songs:";cin>>z;
	;
	for(k=1;k<=z;k++){
		mi=min(x,y);ma=max(x,y);
		cout<<"the partners of NO."<<k<<" song are:"<<endl;
		for(i=1;i<=mi;i++){
			if(j>ma) j=1;
			cout<<"<"<<j<<","<<i<<">"<<"  ";j++;
		}
		cout<<endl;
	}
	cout<<"please input the number of the girls or boys or songs to search:";cin>>t;
	while(z--){
		for(i=1;i<=x;i++) p1.Append(i);
		for(i=1;i<=y;i++) p2.Append(i);  
	}
	cout<<"\nthe NO."<<t<<" girl has danced with boys of NO.";
	int c=min(p1.getrear() ,p2.getrear() );
	for(i=t-1;i<c;i=i+y){
		cout<<p1.Getn(i)<<" ";
	}
	cout<<"\nthe NO."<<t<<" boy has danced with boys of NO.";
	for(i=t-1;i<c;i=i+x){
		cout<<p2.Getn(i)<<" ";
	}
	cout<<"\nthe partners of NO."<<t<<" song are:"<<endl;
	for(i=(t-1)*mi;i<t*mi;i++){
		cout<<"<"<<p1.Getn(i)<<","<<p2.Getn(i)<<">  ";  
	}
	cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar();
	
}   
//���˼·������ѭ��ɸѡ�ķ��������Ե�һ��Ԫ�ؿ�ʼ�������һ��Ԫ���޳�ͻ��Ԫ�ػ���һ�飬�ٽ�ʣ�µ�Ԫ�������ҳ�������ͻ�Ļ���ڶ��飬�Դ����ƣ�ֱ�����е�Ԫ�ض����顣�ڼ����ʵ��ʱ������Ҫ��������Ԫ�صĳ�ͻ��ϵ����һ����ͻ������һ����ά����R[1:n, 1:n]��ʾ������i���j Ԫ���г�ͻ����R[i, j]=1,����R[i, j]=0��
void game(){
	int b[11][11],i,j,result[11],aa[11],ans,acnt,cnt,x;
	SqQueue<int> q;
	cout<<"Suppose that there are N sports in Olympic Game, and each athlete can take part in 1 to 3 sports. How to arrange the competition schedule that:"<<endl;
	cout<<"(1). Sports involving the same athlete are not scheduled to take place on the same day."<<endl;
	cout<<"(2). Make the overall competition days the minimum."<<endl;
    cout<<"\nthere are 7 athletes and 9 sports:\n"<<endl;
    cout<<"NO.1 athlete takes part in sports of:1 4 8"<<endl;
    cout<<"NO.2 athlete takes part in sports of:1 7"<<endl;
    cout<<"NO.3 athlete takes part in sports of:8 3"<<endl;
    cout<<"NO.4 athlete takes part in sports of:1 9 5"<<endl;
    cout<<"NO.5 athlete takes part in sports of:3 4"<<endl;
    cout<<"NO.6 athlete takes part in sports of:5 6 2"<<endl;
    cout<<"NO.7 athlete takes part in sports of:6 4"<<endl;
    cout<<"the conflicting maxrix is:"<<endl;
    memset(b,0,sizeof(b));
    b[1][4]=1;b[1][8]=1;b[4][8]=1;
    b[1][7]=1;
    b[8][3]=1;
    b[1][9]=1;b[1][5]=1;b[5][9]=1;
    b[3][4]=1;
    b[5][6]=1;b[5][2]=1;b[6][2]=1;
    b[6][4]=1;
    for(i=1;i<10;i++)
      for(j=1;j<10;j++) 
        if(b[i][j]==1) b[j][i]=1;
    for(i=1;i<10;i++){
    	cout<<"\t"<<i;
    	b[i][i]=1;
	}
    cout<<endl;
    for(i=1;i<10;i++){
    	cout<<i<<"row\t";
    	for(j=1;j<10;j++) cout<<b[i][j]<<"\t";
    	cout<<endl;
	}
    for(i=1;i<10;i++) q.Append(i); 
    ans=1;//���
	while(!q.Empty() ){
		cnt=q.getrear() -q.getfront() ;//��ʾÿ��ѭ��ִ�п�ʼʱ����Ԫ�صĸ���
        //cout << cnt << endl;
		acnt=0;//a��Ԫ�ظ���
		for(i=0;i<cnt;i++){
			x=q.GetHead() ;
			q.Remove() ;
			if(acnt==0){//��a��û��Ԫ��ʱ֮�佫x����a
				aa[acnt++]=x;
				continue;
			}
			
			for(j=0;j<acnt;j++){//��x��a��Ԫ�س�ͻʱ�����½������
				if(b[x][aa[j]]){
					q.Append(x);
					break; 
				} 
			}
			if(j==acnt){//��x��a��Ԫ�ض��޳�ͻʱ
				aa[acnt++]=x;
				continue;
			} 
		}
		for(i=0;i<acnt;i++){//��ʱa����ɵõ�һ������ͻ���Ӽ������е�Ԫ�ر��
			result[aa[i]]=ans;
		}
		ans++;
	} 
	for(i=1;i<ans;i++){
		cout<<"NO."<<i<<" group of sport items are:";
		for( j=1;j<=9;j++){
			if(result[j]==i) cout<<j<<" ";
		}
		cout<<endl;
	}
	cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar();
}
