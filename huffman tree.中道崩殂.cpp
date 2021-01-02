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

typedef struct LNode //字符链表结点
{
    char ch;
    unsigned int weight;
    char *code;
    struct LNode *next;
}LNode, *huffmancharslist;

class Huffman
{
    private:
        ifstream indata;   //输入文件流
        ofstream outdata;   //输出文件流
        string huffmancode, text;
        int number;    //字符链表结点个数
        HuffmanTree huffmantree;
        huffmancharslist l;  //头节点 (不放任何东西，从l->next开始工作）
    public:
        Huffman() {    //初始化
            l = (huffmancharslist) malloc (sizeof(LNode));
            l -> next = NULL;
        }
        void savetext(char *file); //保存数据到文件
        void readtext1(char *file); //读取文件中的数据，包括空格
        void readtext2(string s);  //读取从键盘输入的数据 
        void readcode(char *file); //读取代码 
        void savecode(char *file); //保存代码 
        void countchars();   //统计输入的字符各数及各字符权值
        void HuffmanCoding(); //huffman树的建立 
        void select(int n, int &s1, int &s2); //选取n个元素中权值最小的两个元素
        void Encode(); //编码 
        void Decode(); //解码 
        void printcode();  //输出编完的码 
        void treeprint();
        void PrintCharWeight(); //输出各字符及其权值（检验时用）
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
{   //huffman树的建立
    if (number <= 1)
        return;
    int m = 2 * number - 1;     //哈弗曼树所需节点数
    huffmantree = new HTNode[m + 1];        //0号单元未使用
    huffmancharslist p;
    p = l -> next;
    int i;
    for (i = 1; i <= number; ++i)//初始化
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
    for (i = number + 1; i <= m; ++i)//建哈弗曼树
    {
        int s1, s2;
        select(i-1, s1, s2);
        huffmantree[s1].parent = huffmantree[s2].parent = i;
        huffmantree[i].lchild = s1;
        huffmantree[i].rchild = s2;
        huffmantree[i].weight = huffmantree[s1].weight + huffmantree[s2].weight;
    }
    
    p = l -> next;                  //从叶子到根节点逆向求每个字符的哈弗曼编码
    char *cd = new char[number];    //分配求编码的工作空间（每个字符编码结果最长n-1再加上'/0'）
    cd[number - 1] = '/0';          //编码结束符
    for (i = 1; i <= number; ++i)       //逐个字符求哈弗曼编码
    {
        int start = number - 1;
        int c, f;
        for (c = i, f = huffmantree[i].parent; f != 0; c = f, f = huffmantree[f].parent)//从叶子到根逆向求编码
        {
            if (huffmantree[f].lchild == c) //左孩子编码为0
                cd[--start] = '0';
            else                            //右孩子编码为1
                cd[--start] = '1';
        }
        /*char *a;
        a= (char *) malloc ((number - start) * sizeof(char));
        strcpy(a, &cd[start]);
		垃圾代码毁我青春，真不爽喂*/
        char *a=new char[number-start];
        strcpy(a,&cd[start]);
        p -> code = a;
        cout <<p->ch <<":"<< p -> code << endl;
        p = p -> next;
    }
    delete[] cd;   //清除缓存
}

void Huffman::select(int n,int &s1,int &s2){ //选取n个元素中权值最小的两个元素 
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

void Huffman::PrintCharWeight() { //输出各字符及其权值（检验时用）
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

void Huffman::printtext() { //输出文本 
	cout<<text<<endl;
}

void Huffman::printcode() { //输出代码 
	cout<<huffmancode<<endl;
}

void Huffman::Encode() { //编码 
	huffmancharslist p;
	for(int i=0;i<text.size() ;i++){
		p=l->next ;
		for(int j=1;j<=number;j++){
			if(text[i]==p->ch ) huffmancode+=p->code ;
			p=p->next ;
		}
	}
}

void Huffman::Decode() { //解码 
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
	//统计输入的字符及各字符权值
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
			cout<<"输入错误，请重新输入："<<endl;
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
	cout<<"                   *         1.前序创建二叉树              2.遍历二叉树                   *"<<endl;
	cout<<"                   *         3.前-中序构造二叉树           4.后-中序构造二叉树            *"<<endl;
	cout<<"                   *         5.清空二叉树                  6.显示二叉树的状态             *"<<endl;
	cout<<"                   *         7.查找结点                    8.显示结点路径                 *"<<endl;
	cout<<"                   *         9.删除结点                    10.插入结点                    *"<<endl;
	cout<<"                   *         11.左右交换孩子               12.二叉树形状判断              *"<<endl;
	cout<<"                   *         13.顺序存储创建二叉树         14.链式转顺序存储              *"<<endl;
	cout<<"                   *         15.树型打印                   16.退出（按0显示英文菜单）     *"<<endl;
	cout<<"                   *                                                                      *"<<endl;
	cout<<"                   ************************************************************************"<<endl;
}
void inputtext(){
	string s;
	cout<<"请输入文本:";getchar();
	getline(cin,s);
	cout<<"当前的哈夫曼编码为:"<<endl;
	a.readtext2(s);
	a.countchars() ;
	a.HuffmanCoding() ;
	a.Encode()  ;
	cout<<"\n编码后的结果："<<endl;
	a.printcode() ;
	cout<<"\npress any key to return the menu"<<endl;
	getchar(); 
}
