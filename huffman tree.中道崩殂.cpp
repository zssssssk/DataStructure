//https://www.cnblogs.com/smile233/p/8184492.html
//https://blog.csdn.net/nicehiro/article/details/50195445 
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>
using namespace std;

typedef struct //huffmantree
{
    unsigned int weight;
    unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;

typedef struct LNode //�ַ�������
{
    char ch;
    unsigned int weight;
    char *code;
    struct LNode *next;
}LNode, *huffmancharslist;

class Huffman
{
    private:
        ifstream indata;   //�����ļ���
        ofstream outdata;   //����ļ���
        string huffmancode, text;
        int number;    //�ַ����������
        HuffmanTree huffmantree;
        huffmancharslist l;  //ͷ�ڵ� (�����κζ�������l->next��ʼ������
    public:
        Huffman() {    //��ʼ��
            l = (huffmancharslist) malloc (sizeof(LNode));
            l -> next = NULL;
        }
        void savetext(char *file); //�������ݵ��ļ�
        void readtext1(char *file); //��ȡ�ļ��е����ݣ������ո�
        void readtext2(string s);  //��ȡ�Ӽ������������ 
        void readcode(char *file); //��ȡ���� 
        void savecode(char *file); //������� 
        void countchars();   //ͳ��������ַ����������ַ�Ȩֵ
        void HuffmanCoding(); //huffman���Ľ��� 
        void select(int n, int &s1, int &s2); //ѡȡn��Ԫ����Ȩֵ��С������Ԫ��
        void Encode(); //���� 
        void Decode(); //���� 
        void printcode();  //���������� 
        void treeprint();
        void PrintCharWeight(); //������ַ�����Ȩֵ������ʱ�ã�
        void printtext();
        //void ReadCodeFromFile(char *filename);
};

void Huffman::readtext1(char *file){
	indata.open(file);
	if(!indata) cout<<"error!"<<endl;
	text="";
	char temp[100];
	indata.getline(temp,100);
	text+=temp; 
} 

void Huffman::readtext2(string s){
	huffmancode="";
	text="";
	text+=s;
} 

void Huffman::savetext(char *file){
	outdata.open(file);
	if(!outdata){
		cout<<"error"<<endl;
	}
	outdata<<text;
}

void Huffman::readcode(char *file){
	indata.open(file);
	indata>>huffmancode; 
}


void Huffman::savecode(char *file){
	outdata.open(file);
	if(!outdata) cout<<"error"<<endl;
	outdata<<huffmancode;
}  

void Huffman::HuffmanCoding()
{   //huffman���Ľ���
    if (number <= 1)
        return;
    int m = 2 * number - 1;     //������������ڵ���
    huffmantree = new HTNode[m + 1];        //0�ŵ�Ԫδʹ��
    huffmancharslist p;
    p = l -> next;
    int i;
    for (i = 1; i <= number; ++i)//��ʼ��
    {
        huffmantree[i].weight = p -> weight;
        huffmantree[i].parent = 0;
        huffmantree[i].lchild = 0;
        huffmantree[i].rchild = 0;
        p = p -> next;
    }
    for (i = number + 1; i <= m; ++i)
    {
        huffmantree[i].weight = 0;
        huffmantree[i].parent = 0;
        huffmantree[i].lchild = 0;
        huffmantree[i].rchild = 0;
    }
    for (i = number + 1; i <= m; ++i)//����������
    {
        int s1, s2;
        select(i-1, s1, s2);
        huffmantree[s1].parent = huffmantree[s2].parent = i;
        huffmantree[i].lchild = s1;
        huffmantree[i].rchild = s2;
        huffmantree[i].weight = huffmantree[s1].weight + huffmantree[s2].weight;
    }
    
    p = l -> next;                  //��Ҷ�ӵ����ڵ�������ÿ���ַ��Ĺ���������
    char *cd = new char[number];    //���������Ĺ����ռ䣨ÿ���ַ��������n-1�ټ���'/0'��
    cd[number - 1] = '/0';          //���������
    for (i = 1; i <= number; ++i)       //����ַ������������
    {
        int start = number - 1;
        int c, f;
        for (c = i, f = huffmantree[i].parent; f != 0; c = f, f = huffmantree[f].parent)//��Ҷ�ӵ������������
        {
            if (huffmantree[f].lchild == c) //���ӱ���Ϊ0
                cd[--start] = '0';
            else                            //�Һ��ӱ���Ϊ1
                cd[--start] = '1';
        }
        /*char *a;
        a= (char *) malloc ((number - start) * sizeof(char));
        strcpy(a, &cd[start]);
		������������ഺ���治ˬι*/
        char *a=new char[number-start];
        strcpy(a,&cd[start]);
        p -> code = a;
        cout <<p->ch <<":"<< p -> code << endl;
        p = p -> next;
    }
    delete[] cd;   //�������
}

void Huffman::select(int n,int &s1,int &s2){ //ѡȡn��Ԫ����Ȩֵ��С������Ԫ�� 
	s1=s2=0;
	for(int i=1;i<=n;i++){
		if(huffmantree[i].parent !=0) continue;
		if(s1==0) s1=i;
		else if(s2==0){
			if(huffmantree[i].weight <huffmantree[s1].weight ){
				s2=s1;
				s1=i;
			}
			else s2=i;
		}
		else{
			if(huffmantree[i].weight <huffmantree[i].weight ){
				s2=s1;
				s1=i;
			}
			else if(huffmantree[i].weight <huffmantree[s2].weight ){
				s2=i;
			}
		}
		
	}
} 

void Huffman::PrintCharWeight() { //������ַ�����Ȩֵ������ʱ�ã�
	huffmancharslist p;
	p=l->next ;
	while(p){
		/*switch(p->ch ){
			case '/t':
				cout<<"//t";
				break;
			case '/n':
				cout<<"//n";
				break;
			default:
				cout<<p->ch ;
				break;
		}*/
		cout<<p->ch <<"--"<<p->weight <<endl;
		p=p->next ;
	}
}

void Huffman::printtext() { //����ı� 
	cout<<text<<endl;
}

void Huffman::printcode() { //������� 
	cout<<huffmancode<<endl;
}

void Huffman::Encode() { //���� 
	huffmancharslist p;
	for(int i=0;i<text.size() ;i++){
		p=l->next ;
		for(int j=1;j<=number;j++){
			if(text[i]==p->ch ) huffmancode+=p->code ;
			p=p->next ;
		}
	}
}

void Huffman::Decode() { //���� 
	text="";
	string temp;
	huffmancharslist p;
	for(int i=0;i<huffmancode.size() ;i++){
		temp+=huffmancode[i];
		p=l->next ;
		for(int j=1;j<=number;j++){
			if(temp==p->code ){
				text+=p->ch ;
				temp="";
				break;
			}
			p=p->next ;
		}
	}
	cout<<text<<endl;
}

void Huffman::countchars() {
	//ͳ��������ַ������ַ�Ȩֵ
	huffmancharslist p,q,temp;
	p=(huffmancharslist)malloc(sizeof(LNode));
	l->next =p;
	p->next =NULL;
	p->ch =text[0];
	p->weight =1;
	number=1;
	for(int i=1;i!=text.size() ;i++){
		int j;
		p=l->next ;
		for(j=1;j<=number;j++){
			if(text[i]==p->ch ){
				p->weight ++;
				break;
			}
			temp=p;
			p=p->next ;
		}
		if(j>number){
			p=temp;
		    ++number;
		    q=(huffmancharslist)malloc(sizeof(LNode));
		    q->ch =text[i];
		    q->weight =1;
		    p->next =q;
			q->next =NULL; 
		}
	}
} 





Huffman a;
void showmenu();
void showmenu1();
void inputtext();
int main(){
	system("color 3f");

	int choice=1;
	int flag=1;
	while(choice!=8){
		if(flag) showmenu();
		else showmenu1();
		while(!(cin>>choice)||(choice<0)||(choice>8)){
			cout<<"����������������룺"<<endl;
			cin.clear();
			cin.sync() ;
		}
		switch(choice){
			case 0:
				flag=1-flag;
				break;
			case 1:
				inputtext();
				break;
		}
	}
	return 0;
}
void showmenu(){//showMenu
	cout<<"                   **********************************************************************"<<endl;
	cout<<"                   *         1.input text            2.load text                        *"<<endl;
	cout<<"                   *         3.show huffmantree      4.text to codes                    *"<<endl;
	cout<<"                   *         5.compress file         6.decompress file                  *"<<endl;
	cout<<"                   *         7.print huffman tree    8.exit (0 for Chinese menu)        *"<<endl;
	cout<<"                   *                                                                    *"<<endl;
	cout<<"                   **********************************************************************"<<endl;
}
void showmenu1(){
	cout<<"                   ************************************************************************"<<endl;
	cout<<"                   *                                                                      *"<<endl;
	cout<<"                   *         1.ǰ�򴴽�������              2.����������                   *"<<endl;
	cout<<"                   *         3.ǰ-�����������           4.��-�����������            *"<<endl;
	cout<<"                   *         5.��ն�����                  6.��ʾ��������״̬             *"<<endl;
	cout<<"                   *         7.���ҽ��                    8.��ʾ���·��                 *"<<endl;
	cout<<"                   *         9.ɾ�����                    10.������                    *"<<endl;
	cout<<"                   *         11.���ҽ�������               12.��������״�ж�              *"<<endl;
	cout<<"                   *         13.˳��洢����������         14.��ʽת˳��洢              *"<<endl;
	cout<<"                   *         15.���ʹ�ӡ                   16.�˳�����0��ʾӢ�Ĳ˵���     *"<<endl;
	cout<<"                   *                                                                      *"<<endl;
	cout<<"                   ************************************************************************"<<endl;
}
void inputtext(){
	string s;
	cout<<"�������ı�:";getchar();
	getline(cin,s);
	cout<<"��ǰ�Ĺ���������Ϊ:"<<endl;
	a.readtext2(s);
	a.countchars() ;
	a.HuffmanCoding() ;
	a.Encode()  ;
	cout<<"\n�����Ľ����"<<endl;
	a.printcode() ;
	cout<<"\npress any key to return the menu"<<endl;
	getchar(); 
}
