#include<iostream>
#include<cmath>
#include<sstream>
using namespace std;
template <class ElemType>    	// ����һ����ģ��
class SqStack               // ˳��ջ��
{
public:
    SqStack(int m);             	   // ���캯��
    ~SqStack();               	   // ��������
    void Clear();             	   // ���ջ
    bool Empty() const;   	   // ��ջ��
    int Length() const;             // �󳤶�
    ElemType & Top() const;         // ȡջ��Ԫ��
    void Push(const ElemType &e);   // ��ջ
    void Pop();                     // ��ջ
    void Show();
	void Eachdo(void (*visit)(const ElemType& e),int w[]);//���������õ������W[i];
private:	
    ElemType *m_base;    	// ����ַָ��
    int m_Top;           // ջ��ָ��
    int m_size;          // �����ռ��С
};

//��ջ��չʾ��ջ��
template <class ElemType>
void SqStack <ElemType>::Show()
{
    for(int i=m_Top-1;i>=0;i--) cout<<m_base[i]<<"  ";
    cout<<endl;
}

template <class ElemType>// ���캯��������m������˳��ռ䣬����һ���յ�˳��ջ
SqStack <ElemType>::SqStack(int m)
{
    m_Top = 0;
    m_base = new ElemType[m];
    m_size = m;
} 

// ������������ջ�ṹ����
template <class ElemType>
SqStack <ElemType>::~SqStack()
{
    if (m_base != NULL) delete[] m_base;
}

// ���ջ
template <class ElemType>
void SqStack <ElemType>::Clear()
{
    m_Top = 0;
}

// ��ջΪ�գ��򷵻�true�����򷵻�false
template <class ElemType>
bool SqStack <ElemType>::Empty() const
{
    return m_Top == 0;
}

// ��ջ��Ԫ�صĸ���
template <class ElemType>
int SqStack <ElemType>::Length() const
{
    return m_Top;
}

// ȡջ��Ԫ�ص�ֵ���Ⱦ�������ջ����
template <class ElemType>
ElemType & SqStack <ElemType>::Top() const
{
    return m_base[m_Top - 1];
}

// ��ջ����ջ����������չ�ռ䡣����e��ջ��
template <class ElemType>
void SqStack <ElemType>::Push(const ElemType &e)
{
    if (m_Top >= m_size) {	// ��ջ��������չ�ռ�
      ElemType *newbase;
       newbase = new ElemType[m_size + 10]; // ����10��Ԫ�ؿռ�
       for(int j = 0; j < m_Top; j++)       // ����Ԫ�ص��¿ռ�
           newbase[j] = m_base[j];   
       delete[] m_base;                     // �ͷ�ԭ�ռ�
       m_base = newbase;   	            // ���û���ַ
        m_size += 10;
    }
    m_base[m_Top++] = e;
}

// ��ջ������ջ��Ԫ�ء��Ⱦ�������ջ����
template <class ElemType>
void SqStack <ElemType>::Pop()
{
    m_Top--;
}

template <class ElemType>
void SqStack <ElemType>::Eachdo(void (*visit)(const ElemType& e),int w[])
{
    for(int i=0;i<m_Top;i++)
	{
        visit(w[m_base[i]]);
	}
}

void input(const int& e)
{
	cout<<e<<" ";
}

void showmenu1();
void showmenu();
void creat();
void show1();
void push();
void Pop();
void getTop();
void clearstack();
void palindromestring();
void NumberSystemConversion();
void palindronumber();
void BracketsMatching();
void hanoiTower();
void ExpressionValues();
void BackpackProblem();
SqStack<int> a(60);
SqStack<char> ac(60);
int main(){
	system("color 3f");

	int choice=1;
	int flag=1;
	while(choice!=16){
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
		    	push();
		    	break;
			case 4:
			    Pop();
				break;
			case 5:
			    getTop();
				break;
			case 6:
			    clearstack();
				break;
		    case 7:
			    palindromestring();
				break;
			case 8:
			    NumberSystemConversion();
				break;
			case 9:
			    palindronumber();
				break;
			case 10:
			    BracketsMatching();
				break;
			case 11:
			    hanoiTower();
				break;
			case 12:
			    ExpressionValues();
				break;
			case 13:
			    BackpackProblem();
				break;
		}
	}
	return 0;
}
void showmenu(){
	cout<<"                   ********************************************************************"<<endl;
	cout<<"                   *                                                                  *"<<endl;
	cout<<"                   *         1.create stack            2.show stak                    *"<<endl;
	cout<<"                   *         3.push to stack           4.Pop from stack               *"<<endl;
	cout<<"                   *         5.get Top of stack        6.clear stack                  *"<<endl;
	cout<<"                   *         7.palindrome string       8.number system conversion     *"<<endl;
	cout<<"                   *         9.palindrome number       10.brackets matching           *"<<endl;
	cout<<"                   *         11.hanoi tower            12.expression values           *"<<endl;
	cout<<"                   *         13.backpack problem       14.N queens problem            *"<<endl;
	cout<<"                   *         15.maze problem           16.exit(0 for Chinese menu)    *"<<endl;
	cout<<"                   *                                                                  *"<<endl;
	cout<<"                   ********************************************************************"<<endl;
}
void showmenu1(){
	cout<<"                   *********************************************************************"<<endl;
	cout<<"                   *                                                                   *"<<endl;
	cout<<"                   *         1.����˳��ջ        2.��ʾ˳��ջ                          *"<<endl;
	cout<<"                   *         3.��ջ              4.��ջ                                *"<<endl;
	cout<<"                   *         5.����ջ��Ԫ��      6.�ÿ�˳��ջ                          *"<<endl;
	cout<<"                   *         7.��������          8.����ת������                        *"<<endl;
	cout<<"                   *         9.���ֻ�������      10.����ƥ������                       *"<<endl;
	cout<<"                   *         11.��ŵ������       12.���ʽ��ֵ                         *"<<endl;
	cout<<"                   *         13.��������         14.N-�ʺ�����                         *"<<endl;
	cout<<"                   *         15.�Թ�����         16.�˳�����0��ʾӢ�Ĳ˵���            *"<<endl;
	cout<<"                   *                                                                   *"<<endl;
	cout<<"                   *********************************************************************"<<endl;
}

void creat(){
	a.Clear();
	int i;
	cout<<"a stack has been created and initialized as:"<<endl;
	for(i=0;i<60;i++){
		a.Push(i);
	}
	a.Show();
	cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar();
}

void show1(){
	cout<<"the current status of the stack is:"<<endl;
	a.Show();
	cout<<"the size of the stack is:"<<a.Length()<<endl;
	cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar();
}

void push(){
	int n;
	cout<<"please input a number:";
	cin>>n;
	a.Push(n);
	cout<<"push data success.the current status of the stack is:"<<endl;
	a.Show();
	cout<<"the size of the stack is:"<<a.Length()<<endl;
	cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar();
}

void Pop()
{
    int num;
	if(a.Empty()) cout<<"ջ�գ��޷�ִ�д˲���"<<endl;
	else
	{
		num=a.Top();
		cout<<"Pop data "<<num<<" success.The current status of the stack is:"<<endl;
		a.Pop();
		a.Show();
		cout<<"The size of the stack is:"<<a.Length()<<endl;
	}
	cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar();
}

void getTop()
{
    int num;
	num=a.Top();
	cout<<"The Top data of stack is:"<<num<<endl;
	a.Show();
	cout<<"\nThe size of the stack is:"<<a.Length();
	cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar();
}

void clearstack()
{
	a.Clear();
	cout<<"The current stack has been cleared."<<endl;
	cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar();
}

void palindromestring()
{
	cout<<"A palindrome string is a sequence of characters which reads the same backward as forward, such as madam or racecar or abba."<<endl;
	cout<<"please check if a string is a palindrome string."<<endl;
	string s;
	while(1)
	{
		int i;
		int flag=1;
		cout<<"Please 0 to return to the menu.Please input a string."<<endl;
		cin>>s;
        if(s=="0") break;
        i=s.length()-1;
		for(int j=0;j<=i;j++,i--)
		{
            if(s[j]!=s[i])
			{
				cout<<"NO.It is not a palindrome string."<<endl;
				flag=0;
				break;
			}
		}
        if(flag==1)
		{
			cout<<"Yes.It is a palindrome string."<<endl;
		}
	}
}

void NumberSystemConversion()
{
	SqStack<char> sq(100);
	SqStack<string> sqs(100);
	int sb,ob,l,t;
	int sum=0,z=0;
	string s;
	cout<<"To convert a number from source base to objective base. Each base of a number is between 2 and 62. Characters a-z stand for 10-35 and A-Z stand for 36-61."<<endl;
	cout<<"Please input the source base<2-62>:";cin>>sb;
	cout<<"Please input the objective base<2-62>:";cin>>ob;
	cout<<"Please input a number of Base "<<sb<<":";cin>>s;
    l=s.length()-1;
	for(int j=0;j<=l;j++)
	{
		sq.Push(s[j]);
	}
	while(!sq.Empty())
	{
		if(sq.Top()<'A') t=sq.Top()-48;
		else if(sq.Top()<'a')  t=sq.Top()-29;
		else t=sq.Top()-87;
		sum+=t*pow(sb,z);
		z++;
		sq.Pop();

	}
	cout<<"The decimal number of "<<s<<"("<<sb<<") is "<<sum<<" ."<<endl;
	cout<<"The number "<<s<<"("<<sb<<") in base "<<ob<<" is:";
	//ʮ����ת��Ϊob���ƵĲ���
	while(sum!=0)
	{
		int yushu;char c;
		yushu=sum%ob;
		if(yushu<10) sqs.Push(to_string(yushu));
		else if(yushu<36)
		{
			c='a'+yushu-10;
			string ss;
			ss=ss+c;
			sqs.Push(ss);
		}
		else
		{
			c='A'+yushu-36;
			string ss;
			ss+=c;
			sqs.Push(ss);
		}
		sum=sum/ob;

	}
    while(!sqs.Empty())
	{
		string k=sqs.Top();
		cout<<k;
		sqs.Pop();
	}
	cout<<".";
	cout<<"\npress any key to return to the menu."<<endl;
	getchar();getchar();
}

void palindronumber()
{
    cout<<"A palindrome number reads the same backward as forward, such as 121 and 232. Of course, the property depends on the basis in which the number is represented."<<endl;

    cout<<"For example, the number 75457 is a palindrome. The number 17 is not a palindrome in base 10, but its representation in base 2 (10001) is a palindrome."<<endl;

    cout<<"The objective of this program is to verify if a given number is palindrome in any base from 2 to 62."<<endl;
	cout<<"-------press 888 to return to the menu-------"<<endl;
	int p;
	while(1)
	{
		cout<<"\nPlease input a number:";
		cin>>p;
		cout<<p<<" is a palindrome number at base: ";
		int fla=1;
        for(int ob=2;ob<63;ob++)
		{
			int p1=p;
			int flag=1;
			string s;
			while(p1!=0)
			{
				char c;
				int yushu;
				yushu=p1%ob;
				if(yushu<10) s+=to_string(yushu);
				else if(yushu<36)
				{
					c='a'+yushu-10;
					s+=c;
				}
				else
				{
					c='A'+yushu-36;
					s+=c;
				}
				p1/=ob;
			}
			for(int i=s.length()-1;i>=0;i--)
			{
                if(s[i]!=s[s.length()-i-1]) flag=0;
			}
			if(flag==1)
			{
				cout<<s<<"<"<<ob<<"> ";//������ɧ����
				fla=0;
			} 
			
		}
		if(p==888) break;
		if(fla==1) cout<<"None! ";
	}
	cout<<"\nPlease press any key to return to the number ";
	getchar();getchar();
}


void BracketsMatching()
{
	cout<<"Check wheter the brackets in the input string are matched exactly. The brackets include {,},[,],(,)."<<endl;
	cout<<"-------press 0 to return to the menu-------"<<endl;
	int p;
	string s;
	while(1)
	{
		cout<<"Please input a string"<<endl;
		cin>>s;
        SqStack<char> sq(100);
		int lhua=0,rhua=0,lzhong=0,rzhong=0,ljian=0,rjian=0;
		for(int i=0;i<s.length();i++)
		{
			sq.Push(s[i]);
			switch(s[i])
			{
				case '{':
				    lhua++;
					break;
			    case '}':
				    rhua++;
					break;
				case '[':
				    lzhong++;
					break;
				case ']':
				    rzhong++;
					break;
			    case '<':
				    ljian++;
					break;
				case '>':
				    rjian++;
					break;
				default:
				    break;
			}
			if(lhua<rhua)
			{
				cout<<"the brackets cannot match."<<endl;
				break;
			}
			if(lzhong<rzhong)
			{
				cout<<"the brackets cannot match."<<endl;
				break;
			}
			if(ljian<rjian)
			{
				cout<<"the brackets cannot match."<<endl;
				break;
			}
		}
		if(ljian==rjian&&lzhong==rzhong&&ljian==rjian)
		{
			cout<<"the brackets can exactly match."<<endl;
		}
		else
		{
			cout<<"the brackets cannot match."<<endl;
		}
		if(s=="0") break;
	}
	cout<<"\nPlease press any key to return to the number ";
	getchar();getchar();

}

struct movestate
{
	int first,end;
	char start,through,distance;
	movestate(int f,int e,char s,char t,char d):start(s),through(t),distance(d),first(f),end(e){}
	movestate(){}
};

void hanoi(int n,char start,char through,char distance,int& cnt)
{
	SqStack<movestate> sqs(1000);
	movestate temp;
	sqs.Push(movestate(1,n,start,through,distance));
	while(!sqs.Empty())
	{
		temp=sqs.Top();
		sqs.Pop();
		if(temp.first!=temp.end)
		{
			//*״̬ѹ�룬��Ϊ��ջ����Ҫ������
			// sqs.Push(movestate(temp.first,temp.end-1,start,distance,through));
			// sqs.Push(movestate(temp.first,temp.first,start,through,distance));
			// sqs.Push(movestate(temp.first,temp.end-1,through,start,distance));
            sqs.Push(movestate(temp.first,temp.end-1,through,start,distance));
			sqs.Push(movestate(temp.end,temp.end,start,through,distance));
			sqs.Push(movestate(temp.first,temp.end-1,start,distance,through));
		}
		else
		{
			cout<<"Move disk "<<temp.first<<" from "<<start<<" to "<<distance<<endl;
            cnt++;
		}

	}
}


void hanoiTower()
{
    cout<<"You have 3 rods and N disks of different sizes which can slide onto any tower. The disks are sorted in ascending order of size from Top to bottom. You have the following constraints:"<<endl;

    cout<<"* (A) Only one disk can be moved at a time."<<endl;

    cout<<"* (B) A disk is slid off the Top of one rod onto the next rod."<<endl;

    cout<<"* (C) A disk can only be placed on Top of a larger disk."<<endl;

    cout<<"Write a program to move the N disks from the first rod to the last rod."<<endl;
	cout<<"--------press 0 to return to the menu--------------"<<endl;

	int p;
    while(1)
	{
		cout<<"\nPlease input a number:";
		cin>>p;
        if(p==0) break;
		int cnt=0;
		hanoi(p,'A','B','C',cnt);
		cout<<"\nThe total steps are "<<cnt<<endl;
	}

}


/*�ƶϷ��ż�����ȹ�ϵ����
*1��ʾ>,0��ʾ=,-1��ʾ<
*c1ջ�ڵ������c2ջ������
*/
int Judge(char c1,char c2)
{
	int a1,a2;
	if('+'==c1||'-'==c1) a1 = 3;
	if('*'==c1||'/'==c1)a1 = 5;
	if('('==c1) a1 = 1;
	if(')'==c1) a1 = 7;
	if('#'==c1) a1 = 0;

	if('+'==c2||'-'==c2)a2 = 2;
	if('*'==c2||'/'==c2)a2 = 4;
	if('('==c2) a2 = 6;
	if(')'==c2) a2 = 1;
	if('#'==c2) a2 = 0;
	if(a1>a2) return 1;
	else if(a1==a2) return 0;
	else return -1;
}

//�������㺯��
double run(char c ,double d1,double d2)
{
	switch (c)
	{
	case '+':
		return d1+d2;
		break;
	case '-':
		return d1-d2;
		break;
	case '*' :
		return d1*d2;
		break;
	case '/':
		return d1/d2;
		break;
	default:
		return 0.0;
		break;
	}
}

void calculator(string& str)
{
	string s = "+-*/()#";
	//�����ʽ�ַ���str����'#'������ʶ��
	str.append(1,'#');
	SqStack<char> OPTR(100);//�����ջ
	SqStack<double> OPND(100);//������ջ
	int a = -1;
	//�Ƚ�#������ջ
	OPTR.Push('#');
	while(true)
	{
	 int b = a+1;
	 a = str.find_first_of(s,a+1);//*��һ���ַ���s�в�����һ���ַ���str,���str�к���s�е��κ��ַ�����ͻ���ҳɹ�(�����κ�һ����str���״γ��ֵ�λ�ã�����find��ͬ
	 if(a==string::npos) break;//*string::npos�����Ϊһ������ֵ��ʾû���ҵ�ƥ����
	 if(a!=b)
	 {
	 string ss(str,b,a-b);
	 double d=stod(ss);
	 //��������ջ
	 OPND.Push(d);
	 }
	 //��������ȼ��Ƚ�
	 int ju = Judge(OPTR.Top(),str[a]);
	 if(-1==ju)//ջ�����ȼ���ֱ����ջ
	 {
	     OPTR.Push(str[a]);
	 }
	 else if(0==ju)//ջ�������ȼ�������ջ
	 {
		 OPTR.Pop();
	 }
	 else//ջ�����ȼ���,��ջ��������
	 {
		 double d1 = OPND.Top();
		 OPND.Pop();
		 double d2 = OPND.Top();
		 OPND.Pop();
		 d1 = run(OPTR.Top(),d2,d1);
		 //��������ջ
		 OPND.Push(d1);
		 OPTR.Pop();
		 a--;
	 }
	}
	//ɾ�����ʽ����'#'������ʶ��
	str.erase(str.length()-1,1);//*erase(pos,n),ɾ�����±�pos��ʼ��n���ַ�
	cout<<str<<" = "<<OPND.Top()<<endl;
}


void ExpressionValues()
{
	cout<<"Enter an expression with +-*/ and (), then caculate its value."<<endl;
	cout<<"----------press 0 to return to the menu(����ΪӢ�ĵ�)-------------"<<endl;

	string s;
	while(1)
	{
		cout<<"\nPlease input a expression is:";
		cin>>s;
		if(s=="0") break;
		calculator(s);

	}
}

//tΪ������,nΪ����
void knapsack(int w[],int t,int n)
{
    SqStack<int> s(100);
	int k=0;
	do
	{
		while(t>0&&k<n)
		{
			if(t-w[k]>=0)
			{
				s.Push(k);
				t-=w[k];
			}
			k++;
		}
		//���һ���             
		if(t==0)
		{
            s.Eachdo(input,w);
			cout<<endl;
		}
        k=s.Top();
		s.Pop();
		t+=w[k];
		k++;
	} while (!s.Empty()||k!=n);
	
}




void BackpackProblem()
{
	cout<<"A backpack has a volume of T. There are N items with volumes of W0, W1...Wn-1. Ask if you can put some of these N items into the backpack so that the sum of their volumes is exactly T. For example:"<<endl;

    cout<<"(A)The volume of the backpack is T=10."<<endl;

    cout<<"(B)The number of the items is N=6."<<endl;

    cout<<"(C)Each volume of the items is W[6]={1,8,4,3,5,2}."<<endl;

    cout<<"(D)The solutions are: (1,4,3,2) (1,4,5) (8,2) (3,5,2)"<<endl;

	cout<<"---------press any key to show the solutions----------"<<endl;
    int t=10,n=6;
	int flag;
	int w[]={1,8,4,3,5,2};
	knapsack(w,t,n);
	
	while(1)
	{
		cout<<"\n��(1)��(0)ѡ���Զ�������:";
	    cin>>flag;
		if(flag==0) break;
		else
		{
			cout<<"Please input the volume of the backpack:";
			cin>>t;
			cout<<"Please input number of the items:";
			cin>>n;
			cout<<"Please input each volume of the items:";
			for(int i=0;i<n;i++) cin>>w[i];
			knapsack(w,t,n);
		}
		
	}

	

}