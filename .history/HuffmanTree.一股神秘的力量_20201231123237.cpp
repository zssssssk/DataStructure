/*
Name: Huffman Tree System 
Author: Seng Dewen
Date: Oct. 2020
Description: Huffman Tree System
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <iomanip>
#include <algorithm>
#include <string>  
#include <_bsd_types.h>
#include "sdw.h" //字体颜色
// #include "HMTree.h" //哈夫曼树类 

 
using namespace std;

//Huffman哈夫曼结点结构 
struct Node
{
    char ch;          //结点的值
    int weight;        //权重值，即字符出现的次数 
    string code;       //结点的哈夫曼编号 
    Node *lchild;     //左孩子结点指针
    Node *rchild;    //右孩子结点指针
    Node* parent;   //父结点指针，感觉没什么用 
};

struct CompareNode
{
    bool operator()(const Node* a, const Node* b)
    {
        return a->weight > b->weight;//小顶堆
    }
};

bool CompareWeight(const pair<char, int> &a, const pair<char, int> &b)
{
	return a.second < b.second;
}

class HuffmanTree
{

public:
	HuffmanTree()
	{
		InitHuffmanTree();
	}
	~HuffmanTree()
	{
		if(m_root)
			delete m_root;
		m_root=NULL;
	}
	void InitHuffmanTree(); //初始化 
	 
	bool CompressToFile(const char* srcfile, const char* objfile);//压缩文件的函数
	bool CompressToScreen(char *srcTxt); //压缩编码，显示在屏幕
	 
	void SaveDictToFile(const char* dictfile); //保存编码到文件 
	
	//解压缩文件 
	bool DecompressToFile(const char* srcfile, const char* objfile);
	//读取编码文件 
	void DictFromFile(const char* codeBook);
	
	//显示哈夫曼编码 
	bool ShowHuffmanCode();
	int  Depth()                                //求二叉树的高度
    {
    	return _Depth(m_root); //当前根结点的高度 
    }
    
	bool PrintTree();
	
	//对输入的文本，以当前已有的哈夫曼编码规则，进行编码(加密) 
	bool EncodeText(char *srcTxt);

private:
	char screen[40][65]; //屏幕缓冲，打印二叉树的树形
	Node* m_root; //树根结点
	
	map<char, string>  mapHCode; //字符char 对应的 Huffman 编码 
	vector<char> V;
	
	/*
	map<char,int>: STL的一个关联容器，提供一对一的数据处理能力。
	其中第一个可以称为关键字，每个关键字只能在map中出现一次，第二个可以称为该关键字的值。
	用数组方式它可以覆盖以前该关键字对应的值：dic[ch]++; 
	用于统计各类字符出现的次数。 默认的int初始值为0. 
	*/	
	map<char,int> mapCharWeight; //char: 字符； int: 字符出现的频次，即权重 
	
	vector< pair<char,int> > vecSortWeight;//按权重排过序的字符序列 
	
	/*
	priority_queue: 在优先队列中，元素被赋予优先级。
	当访问元素时，具有最高优先级的元素最先删除。优先队列具有最高级先出 （first in, largest out）的行为特征。
	
	首先要包含头文件#include<queue>, 和queue不同的就在于可以自定义其中数据的优先级, 让优先级高的排在队列前面优先出队。
	优先队列具有队列的所有特性，包括队列的基本操作，只是在这基础上添加了内部的一个排序，它本质是一个堆实现的。
	
	定义：priority_queue< Type, Container, Functional >
	
	Type 就是数据类型，Container 就是容器类型（Container必须是用数组实现的容器，比如vector, deque等等，
	但不能用 list和 map。STL里面默认用的是vector），Functional 就是比较的方式。
	所以，需要中间变量 vector  
	*/  
	priority_queue<Node*, vector<Node*>, CompareNode> qCharWeight; //优先队列：让权重值低的先出列 
	 
	//把map <char,int> 复制到 vector< pair<char,int> >中  
	//再按权重排序
	void _SortCharWeight();
	bool _CompareWeight(const pair<char, int> &a, const pair<char, int> &b);//sort()函数需要
	
	//构造结点的优先队列，让权重值低的先出列 
	void _GetNodePriority_Queue(); 
	
	bool _GetTextFromFile(const char* srcfile);
	 
	bool _GetTextFromKeyboard(const char* srcfile); //从键盘获取输入文本 
	
	//构造HuffmanTree 
	void _CreateHuffmanTree();
	
	//两个结点，构造出一个双亲结点 
	Node* _MakeParentNode(Node* &a, Node* &b);
	
	//构造哈夫曼编码 
	void _MakeHuffmandCode(Node* root);
	
	int _Draw(Node* root, int startX, int y);
	
	//求二叉树的高度
	int _Depth(Node *root)
	{
		if (root==NULL) return 0;
		
		int m=_Depth(root->lchild);
	    int n=_Depth(root ->rchild);
	    
		return m>n?(m+1):(n+1);
	}
};
 
void HuffmanTree::InitHuffmanTree()
{
	m_root=NULL; //树根结点
	
	mapHCode.clear(); //清空 
	V.clear();
	mapCharWeight.clear();
	vecSortWeight.clear();//按权重排过序的字符序列 
	
	//优先队列没有清空clear()函数，因此， 直接用空的队列对象赋值
	qCharWeight=priority_queue<Node*, vector<Node*>, CompareNode>(); //直接用空的队列对象赋值
}

bool HuffmanTree::_GetTextFromKeyboard(const char* txt) //从键盘获取输入文本 
{
    //依次读入每个字符，一个字节
	//中文占两个字节，所以分两次读入，输出的时候，要两个字节连续一起输出才可以正常显示
	//为什么存放中文时不会冲突？一个字节有八个bit位，那么范围也就是0~255，如果文字的第一个字节为65，
	//岂不是和‘A’冲突了。实际上不会，因为中文的每个字节的范围是128~256，所以不会与0-127的发生冲突。
    int i=0;
    char ch;
    
	while( (ch=txt[i++]) && (ch!='\0') ) 
    {
        mapCharWeight[ch]++;  //ch是关键字，对map<char,int>中的int部分赋值；默认的int初始值为0 
    }
    
    return true;
}

bool HuffmanTree::_GetTextFromFile(const char* srcfile)
{
    ifstream infile(srcfile);
    if(!infile)
    {
    	cout<<"\n\tFile "<<srcfile<<" open failed."<<endl;
    	return false;
    }
    
	char ch;
	
	//依次读入每个字符，一个字节
	//中文占两个字节，所以分两次读入，输出的时候，要两个字节连续一起输出才可以正常显示
	//为什么存放中文时不会冲突？一个字节有八个bit位，那么范围也就是0~255，如果文字的第一个字节为65，
	//岂不是和‘A’冲突了。实际上不会，因为中文的每个字节的范围是128~256，所以不会与0-127的发生冲突。
    while(infile.get(ch)) 
    {
        mapCharWeight[ch]++;  //ch是关键字，对map<char,int>中的int部分赋值；默认的int初始值为0 
    }
    infile.close();
    
    return true;
}

//把map <char,int> 复制到 vector< pair<char,int> >中  
//再按权重排序
void HuffmanTree::_SortCharWeight()
{
    map<char,int>::iterator p = mapCharWeight.begin();//迭代器 
    
    while(p != mapCharWeight.end())
    {
        vecSortWeight.push_back(pair<char,int>(p->first, p->second));
        p++;
    }
    sort(vecSortWeight.begin(), vecSortWeight.end(), CompareWeight); //排序 这个 CompareWeight函数还不能带下划线 
}
 
//构造结点的优先队列，让权重值低的先出列 
void HuffmanTree::_GetNodePriority_Queue()
{
    vector<pair<char,int> >::iterator q = vecSortWeight.begin();
    while(q != vecSortWeight.end())
    {
        Node* p = new Node;
        
        p->ch = q->first;       //结点的字符 
        p->weight = q->second;  //结点的权重 
       
	    p->lchild = NULL;
        p->rchild = NULL;
        p->parent = NULL;
        
		qCharWeight.push(p); //加入优先队列 
        q++;
    }
}
 
//两个结点，构造出一个双亲结点 
Node* HuffmanTree::_MakeParentNode(Node* &a, Node* &b)
{
    Node* parent = new Node;
    parent->weight = a->weight + b->weight;
    parent->ch='#';
    
	parent->lchild = a;
    parent->rchild = b;
    
	a->parent = NULL;
    b->parent = NULL;
    
    return parent;
}


/*
priority_queue: 在优先队列中，元素被赋予优先级。
当访问元素时，具有最高优先级的元素最先删除。优先队列具有最高级先出 （first in, largest out）的行为特征。
首先要包含头文件#include<queue>, 和queue不同的就在于可以自定义其中数据的优先级, 让优先级高的排在队列前面优先出队。
优先队列具有队列的所有特性，包括队列的基本操作，只是在这基础上添加了内部的一个排序，它本质是一个堆实现的。
*/ 
 
//构造HuffmanTree 
void HuffmanTree::_CreateHuffmanTree()
{
	_SortCharWeight(); //数据准备 
	_GetNodePriority_Queue();  //优先队列 
    
	while(qCharWeight.size() >= 2)
    {
        Node *x, *y; //两个最小权值的结点出列
		 
        x = qCharWeight.top(); qCharWeight.pop();
        y = qCharWeight.top(); qCharWeight.pop();
        
		qCharWeight.push(_MakeParentNode(x,y));  //构造出来的结点入列 
    }
    
    qCharWeight.top()->parent = NULL;
    
	m_root = qCharWeight.top();//最后一个结点，就是根结点 
}
 
//--------------------利用DFS求哈夫曼编码---------------------------

/*
利用二叉树先序遍历的顺序，首先设置一个vector<pair<char,string>>对象准备存储每个字符以及即将得到的编码，
接着设置一个空的string对象tmp，从根节点开始若遇到左子树则tmp+=‘0’，若遇到右子树则tmp+='1’，
若遇到叶子节点即该叶子中的字符编码已经形成，便将其复制给vector<pair<char,string>>对象中与该字符对应的string，
然后将tmp中最后一个字符删掉，返回上一层，遍历其右子树，当右子树也遍历完时，它将逐层返回，
它要访问的下一个节点将是当前子树的根节点的兄弟节点，因此在每返回一层时都需要删除tmp的最后一个字符，否则编码就会出错。
*/ 
void HuffmanTree::_MakeHuffmandCode(Node* root)
{
	//整颗树只有一颗结点的时候
	if(m_root->lchild == NULL && m_root->rchild == NULL)//叶子结点
	{
		if(m_root->ch!='\0')
			mapHCode[root->ch] = "1"; 
		
		//cout<<111<<endl;
	}
	
	 
   if(root->lchild == NULL && root->rchild == NULL)//叶子结点 
   {
       string str;
       for(int i = 0; i < V.size(); i++)
              str += V[i];
       
       //形成编码 
	   mapHCode[root->ch] = str;  //叶子结点的字符 root->ch 的编码就是 string str  
       
       V.pop_back(); //逐层返回的时候一定要删掉最后的一个字符
       return;
   }
 
   if(root->lchild)
   {
       V.push_back('0');
       _MakeHuffmandCode(root->lchild);
 
   }
   if(root->rchild)
   {
        V.push_back('1');
        _MakeHuffmandCode(root->rchild);
   }
 
   if(!V.empty())
   {
       V.pop_back(); //逐层返回的时候一定要删掉最后的一个字符
   }
}

bool HuffmanTree::CompressToScreen(char *srcTxt)
{
	if(! _GetTextFromKeyboard(srcTxt)) //从键盘输入文本，构造哈夫曼树 
	{
		return false;
	}
	
	_CreateHuffmanTree();        //构造哈夫曼树   
	_MakeHuffmandCode(m_root);  //生成哈夫曼编码  
	
	cout<<"\n\t编码后的结果为："<<endl;
	cout<<"\n\t";
	
    ofstream fout;
    char *objfile="Text_Out.txt";
    
    fout.open(objfile,ios_base::binary);//以二进制方式读入 
    char chFromFile;
    char greatch = 0;
    string str;
    int i=0;
	while(1)
    {
        chFromFile=srcTxt[i++]; 
		
        if(chFromFile=='\0') break;
        
        cout<<mapHCode[chFromFile];
        
        str += mapHCode[chFromFile];
        while(str.size() >= 8)
        {
            string str2(str,0,8);

            bitset<8> aaa(str2);

            greatch = (char)aaa.to_ulong();
			fout << greatch;
            str.erase(0,8);
        }
    }
    //
    char youxiao = str.size();
    if(youxiao) 
    for(char i = youxiao; i <= 7; i++)
    {
        str.append("0");
    }
 
    bitset<8> aaa(str);
    
    chFromFile = (char)aaa.to_ulong();
    fout << chFromFile;
    fout << youxiao;//把最后一位剩余的有效位置存起来
    
    fout.close();
    
    return true;
}

//对输入的文本，以当前已有的哈夫曼编码规则，进行编码(加密) 
bool HuffmanTree::EncodeText(char *srcTxt)
{
	if(!m_root)//如果还没有哈夫曼编码 
	{
		if(! _GetTextFromKeyboard(srcTxt)) //从键盘输入文本，构造哈夫曼树 
		{
			return false;
		}
		
		_CreateHuffmanTree();        //构造哈夫曼树   
		_MakeHuffmandCode(m_root);  //生成哈夫曼编码  
	} 
	
	cout<<"\n\t编码后的结果为："<<endl;
	cout<<"\n\t";
	
    char chFromFile;
    char greatch = 0;
    string str;
    int i=0;
	while(1)
    {
        chFromFile=srcTxt[i++]; 
		
        if(chFromFile=='\0') break;

        cout<<mapHCode[chFromFile];
    }
    return true;
} 
 
bool HuffmanTree::CompressToFile(const char* srcfile, const char* objfile)
{
	if(! _GetTextFromFile(srcfile)) //从文件中读取文本，构造哈夫曼树 
	{
		return false;
	}
	
	_CreateHuffmanTree();        //构造哈夫曼树   
	_MakeHuffmandCode(m_root);  //生成哈夫曼编码  
	
	ofstream outfile("压缩后_二进制编码.txt");
	
    ifstream fin;
    fin.open(srcfile);
    if(!fin)
    {
    	cout<<"\n\t文件打开失败."<<endl;
    }
    
    ofstream fout;
    fout.open(objfile,ios_base::binary);//以二进制方式读入 
    char chFromFile;
    char greatch = 0;
    string str;
    while(1)
    {
        fin.get(chFromFile);
        if(!fin) break;
        str += mapHCode[chFromFile];
        outfile<<str;
        
        while(str.size() >= 8)
        {
            string str2(str,0,8);
            bitset<8> aaa(str2);
            greatch = (char)aaa.to_ulong();
            fout << greatch;
            str.erase(0,8);
        }
    }
    //凑齐8个bits 
    char youxiao = str.size();
    for(char i = youxiao; i <= 7; i++)
    {
        str.append("0");
    }
 
    bitset<8> aaa(str);
    chFromFile = (char)aaa.to_ulong();
    fout << chFromFile;
    fout << youxiao;//把最后一位剩余的有效位置存起来
    fin.close();
    fout.close();
    
    return true;
}
 
void HuffmanTree::SaveDictToFile(const char* dictbook)
{
    ofstream fout(dictbook);
    map<char,int>::const_iterator pos = mapCharWeight.begin();
    while(pos != mapCharWeight.end())
    {
        fout << pos->first << " "<< pos->second << endl;
        pos++;
    }
    fout.close();
}

//解压缩文件 
bool HuffmanTree::DecompressToFile(const char* srcfile, const char* objfile)
{
	_CreateHuffmanTree();        //构造哈夫曼树   
	//_MakeHuffmandCode(m_root);  //生成哈夫曼编码  
	
	ifstream fin;
 
	ofstream fout;
	fout.open(objfile);
	if(!fout)
	{
		cout<<"\n\tFile Open Failed."<<endl;
		return false;
	}
 
	char ch;
	char quan;
	char youxiao;
	Node* ptr = m_root;
 
	fin.open(srcfile,ios_base::binary);
	if(!fin)
    {
    	cout<<"\n\t文件打开失败."<<endl;
    }
    
	fin.seekg(-1,ios_base::end);
	ifstream::pos_type pos;
	fin.get(youxiao);
    fin.seekg(-2,ios_base::end);
 
	pos = fin.tellg();
	fin.seekg(0,ios_base::beg);
 
	int i = 0;
	while(1){
		if(fin.tellg() == pos) break;
		fin.get(ch);
		bitset<8> aaa(ch);
		for(i = 7;i >= 0;i--){
			if(0 == aaa[i]){
				ptr = ptr->lchild;
				if(NULL == ptr->lchild){
					fout << ptr->ch;
					//cout << ptr->ch;
					ptr = m_root;
				}
			}else if(1 == aaa[i]){
				ptr = ptr->rchild;
				if(NULL == ptr->lchild){
					fout << ptr->ch;
					//cout << ptr->ch;
					ptr = m_root;
				}
			}
		}
	}
	fin.get(ch);
	bitset<8> last(ch);
	for(i = 7;i >= (8-youxiao);i--){
		if(0 == last[i]){
			ptr = ptr->lchild;
			if(NULL == ptr->lchild){
				fout << ptr->ch;
				ptr = m_root;
			}
		}else if(1 == last[i]){
			ptr = ptr->rchild;
			if(NULL == ptr->lchild){
				fout << ptr->ch;
				ptr = m_root;
			}
		}
	}
	fin.close();
	fout.close();
	return true;
}
 
//读取编码文件 
void HuffmanTree::DictFromFile(const char* codeBook)
{
	ifstream infile(codeBook);
	char ch;
	int num;
	while(1){
		infile.get(ch);
		if(!infile) break;
		infile >> num;
		mapCharWeight[ch] = num;
		infile.get(ch);
	}
	infile.close();
}

//显示哈夫曼编码 
bool HuffmanTree::ShowHuffmanCode()
{
	if(mapHCode.size()==0)
	{
		return false;
	}
	map<char, string>::iterator it; //字符char 对应的 Huffman 编码 
	int i=0;
	for(it=mapHCode.begin();it!=mapHCode.end();it++)
	{
		if( it->second=="")
		{
			it->second="NO CODE";
		}
		cout<<"\t"<<setw(1)<<right<<it->first<<": "<<setw(12)<<left<<it->second;
		i++;
		if(i%4==0) cout<<endl;
	} 
	return true;
}

bool HuffmanTree::PrintTree()  
{
	//screen二维数组，初始化为空格 
	int i=0,j=0;
	for(i=0;i<40;i++)
	{
		for(j=0;j<65;j++)
		{
			screen[i][j]=' ';
		}
	} 
	_Draw(m_root, 0, 0);
	//用中序遍历把二叉树的图形写入到screen二维数组中
	//screen[][]: 屏幕缓冲
	//输入screen数组
	int height=Depth()*2; //中间加一行，画斜线
	
	for(i=0;i<height;i++) //树高：打印height行 
	{
		screen[i][64]='\0'; 
		cout<<"\t"<<screen[i]<<endl;
	}
}

int HuffmanTree::_Draw(Node* root, int startX, int y)
{
	int endX=startX; //当前子树的作图右边界
	
	//中序递归，先处理左子树 
	//如果当前节点有左子树，就先打印左子树，得到其图形的右边界
	//子树高度位置y，在当前结点的下面两行 
	if(root->lchild) 
	{
		endX = _Draw(root->lchild, startX, y+2)+1; //左孩子的位置+1的位置，打印当前根结点 
	}
		
	int rootX=endX; //当前根结点的x坐标	
	//y是高度的位置，是由屏幕的行数决定
	//rootX是水平位置，由第二维的坐标决定
	screen[y][rootX]=root->ch; //当前结点的数据值，写入到screen中 
	
	//开始处理右子树
	endX++; //根结点打印之后，向右边走一个字符的位置，即右子树的起始位置
		
	if(root->rchild)
	{
		endX=_Draw(root->rchild, endX, y+2); //右子树的高度与左子树一样，y+2
	}
		
	return endX; //返回当前子树打完之后，在最右边的什么位置 
}
	
//定义一颗哈夫曼树
HuffmanTree T; 
    
void showNotice()
{
	cin.clear();
	cin.sync();
	setCayonon3f();
	cout<<"\n\tInvalid. Please input again：";
	setWhiteon3f();
}

void  showMenu()
{
	   //显示主菜单
	   cout<<"\n";
   	   cout<<"\n";
   	   cout<<"\t========================人生若只如初见========================"<<endl;
   	   cout<<"\n";
   	   cout<<"\n";
   	   cout<<"\n";
   	   cout<<"\t*********************哈夫曼编码与文件压缩*********************"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$       1. 从键盘输入文本        2. 从文件导入文本           $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$       3. 显示哈夫曼编码        4. 文本编码(加密)           $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$       5. 文件压缩(加密)        6. 解压文件(解密)           $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$       7. 显示哈夫曼树          8. 退出                     $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t******************版权所有@SENG DEWEN(僧德文)*****************"<<endl;
}

void  showEnglishMenu()
{
	   //显示英文主菜单
	   cout<<"\n";
   	   cout<<"\n";
   	   cout<<"\t========================人生若只如初见========================"<<endl;
   	   cout<<"\n";
   	   cout<<"\n";
   	   cout<<"\n";
   	   cout<<"\t**********************Binary Tree System**********************"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$    1. Input Text              2. Load Text                 $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$    3. Show Huffman Codes      4. Text to Codes             $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$    5. Compress File           6. Decompress File           $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$    7. Print Huffman Tree      8. Exit                      $"<<endl;	   
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t******************CopyRight@SENG DEWEN(僧德文)****************"<<endl;
}

void printBird()
{
       cout<<"\n";
 	   cout<<"\t                    .-'-._                                      "<<endl;
 	   cout<<"\t                   /   e <  "; setYellowon3f();cout<<"\t何事秋风悲画扇"<<endl;setCayonon3f();
 	   cout<<"\t               _.-''';  (                                       "<<endl;
 	   cout<<"\t __________.-''-._.-'  /                                        "<<endl;
 	   cout<<"\t ========---:_''-'     /  _  _     %%%%                         "<<endl;
 	   cout<<"\t              '-=. .-'` _(_)(_)   %%|/%%%                       "<<endl;
 	   cout<<"\t                _|_\\_  (_)(_)(_) %%%%%%%                       "<<endl;
 	   cout<<"\t               //\\\\//\\\\//\\\\//\\\\//\\\\%/_%               "<<endl;
 	   cout<<"\t           ____\\\\//\\//\\//\\//\\// |__|/__%%%                "<<endl;
 	   cout<<"\t  ________(___  \\\\/\\//\\\\//\\\\//\\\\//__//___%%%           "<<endl;
 	   cout<<"\t            / \\  \\_/ __ \\___//------\\--%%%%%%               "<<endl;
 	   cout<<"\t  _________/   \\____/  \\____/\\\\%SDW%%                       "<<endl;
 	   cout<<"\t                              \\_-%%%%                          "<<endl;
}

void printBear()
{
   int flags [] = {
   0,0,0,0,1,1,3,4,6,5,3,3,5,5,6,4,3,2,2,-1,
   0,0,0,0,0,2,0,0,0,6,0,0,0,0,6,0,0,1,-1,
   0,0,0,0,7,0,0,0,1,10,0,13,0,10,2,0,0,0,8,-1,
   0,0,0,0,8,0,0,0,0,1,0,0,0,2,0,0,0,0,7,-1,
   0,0,0,0,13,4,6,9,9,13,4,14,4,13,9,9,6,4,13,-1,
   0,0,7,3,11,12,4,12,4,12,96,9,12,4,12,4,12,11,3,8,-1,
   0,0,8,13,2,2,0,0,0,0,4,12,4,0,0,0,0,1,1,13,7,-1,
   0,0,0,0,12,9,0,0,15,0,15,0,15,0,0,0,12,-1,
   0,0,0,0,4,12,9,0,0,16,17,18,19,0,9,12,4,-1,
   0,0,0,0,7,0,4,12,9,0,0,0,0,0,0,9,12,4,0,8,-1,
   0,0,0,13,8,0,0,8,4,12,9,0,9,12,4,7,0,0,7,13,-1,
   0,0,1,1,1,13,13,13,2,0,4,12,4,0,1,13,13,13,2,2,2,-1,
   };
cout<<"\n\t\t\t";
int flagCount = sizeof(flags) / sizeof(flags[0]);

for(int i=0;i<flagCount;i++)
{
	switch(flags[i])
   {
      case 0 : cout << ' '; break;   //空格
      case 1 : cout << '('; break;
      case 2 : cout << ')'; break;
      case 3 : cout << '`'; break;   //数字键 1 左边的字符
      case 4 : cout << '\''; break;  //单引号
      case 5 : cout << '\"'; break;  //双引号
      case 6 : cout << '-'; break;   //连字符
      case 7 : cout << '/'; break;   
      case 8 : cout << '\\'; break;  //反斜框
      case 9 : cout << '.'; break;
      case 10 : cout << 'o'; break;  //小写字母 o
      case 11 : cout << ';'; break;
      case 12 : cout << '#'; break;
      case 13 : cout << '_'; break;  //下划线
      case 14 : cout << '='; break;
      case 15 : cout << "☆"; break; //汉字字符注意要用双引号 ""
      case 16 : cout << "I"; break;
      case 17 : cout << "LOVE"; break;
      case 18 : cout << " U"; break;
      case 19 : cout << '!'; break;
      case -1 : cout << endl<<"\t\t\t"; break; //换行
      }
   }
}

void byebye()
{
	setCayonon3f();
	printBird();
	setWhiteon3f();
	cout<<"\n\tThank you for using~byebye~\n"<<endl;
} 

void selection()
{
	cin.sync();
	setYellowon3f();
	cout<<"\n\tPress ANY key to return to the menu.";
	getchar();
	setWhiteon3f();
	cout<<"\n\n"; 
}

bool PrintTree()
{
	cout<<"\n\t=====================显示哈夫曼树====================="<<endl;
	cout<<"\n";
	cout<<"\n\t当前的哈夫曼编码为：\n"<<endl;	
	if(!T.ShowHuffmanCode())
	{
		cout<<"\n\t当前没有字符编码."<<endl;
		return false;
	}
	
	cout<<"\n\n\t构造出来的哈夫曼树为：\n"<<endl;	
	T.PrintTree();		
	return true;	
}

//显示哈夫曼编码结果
bool ShowHuffmanCode()
{
	cout<<"\n\t当前的哈夫曼编码为：\n"<<endl;	
	if(!T.ShowHuffmanCode())
	{
		cout<<"\n\t当前没有字符编码."<<endl;
		return false;
	}
	
	cout<<"\n\n\t构造出来的哈夫曼树为：\n"<<endl;	
	T.PrintTree();		
	return true;
}

//从键盘输入文本进行编码 
bool GetTextFromKeyboard()
{
	T.InitHuffmanTree(); //初始化
	
	char txt[100000];
	 
	cout<<"\n\t=====================从键盘输入文本====================="<<endl;
	
	do
	{
		cout<<"\n\t请输入文本：";
		cin.getline(txt,100000,'\n');
	}while(!txt[0]);
	
	T.CompressToScreen(txt);
	cout<<endl; 
	
	ShowHuffmanCode();
	cout<<endl; 
	return true;
}


bool LoadFromFile()
{
	T.InitHuffmanTree(); //初始化
	 
	cout<<"\n\t=====================从文件导入文本====================="<<endl;
	cout<<"\n\t请输入源文件名(\"Text.txt\")：";
	string infile;
	
	if(cin.peek()=='\n') //按回车键，获取默认值 
	{
		infile="Text.txt";
	}
	else
	{
		cin>>infile;	
	}
	
	string outfile="Text_Out";
	
	//生成压缩后随机的文件名 
	//srand(unsigned(int(time(0)))); 
	//int t=rand()%10000;  //随机值 
	//char *buf = new char[10];  //2147483647 int的最大值
    //_itoa(t, buf, 10);     
    //outfile += buf;
	outfile += ".txt";
	
	if( T.CompressToFile(infile.c_str(), outfile.c_str()) )
	{
		cout<<"\n\t文件导入成功，编码后已保存到 "<<outfile<<" 中."<<endl;
	}
	else
	{
		cout<<"\n\t源文件 "<<infile<<" 打开失败."<<endl;
		return false;
	}
    
    string codeBook="CodeBook.txt";
    
	T.SaveDictToFile(codeBook.c_str());
}

//压缩文件 
bool CompressFile()
{
	T.InitHuffmanTree(); //初始化
	 
	cout<<"\n\t=====================开始压缩(加密)文件====================="<<endl;
	cout<<"\n\t请输入源文件名(\"原文.txt\")：";
	string infile;
	
	if(cin.peek()=='\n') //按回车键，获取默认值 
	{
		infile="原文.txt";
	}
	else
	{
		cin>>infile;	
	}
	
	string outfile="压缩后";
	
	//生成压缩后随机的文件名 
	//srand(unsigned(int(time(0)))); 
	//int t=rand()%10000;  //随机值 
	//char *buf = new char[10];  //2147483647 int的最大值
    //_itoa(t, buf, 10);     
    //outfile += buf;
	outfile += ".txt";
	
	if( T.CompressToFile(infile.c_str(), outfile.c_str()) )
	{
		cout<<"\n\t文件压缩成功，已保存到 \""<<outfile<<"\" 中."<<endl;
	}
	else
	{
		cout<<"\n\t源文件 \""<<infile<<"\" 打开失败."<<endl;
		return false;
	}
    
    string codeBook="密码本.txt";
    
	T.SaveDictToFile(codeBook.c_str());
	
	return true;
} 

//对输入的文本，以当前已有的哈夫曼编码规则，进行编码(加密) 
bool EncodeText()
{
	cout<<"\n\t=====================编码(加密)====================="<<endl;
	cout<<"\n\t对输入的文本，根据当前已有的哈夫曼编码规则进行编码(加密)."<<endl;
	cout<<"\n\t请输入文本：";
	
	char txt[100000];
	cin.getline(txt,100000,'\n');
	
	T.EncodeText(txt);
	
	cout<<"\n\n\t当前的哈夫曼编码规则为：\n"<<endl;
	T.ShowHuffmanCode();
	
	return true;
}

bool DecompressFile()
{
	T.InitHuffmanTree(); //初始化
	 
	cout<<"\n\t=====================开始解压(解密)文件====================="<<endl;
	cout<<"\n\t请输入源文件名(\"压缩后.txt\")：";
	string infile;
	
	if(cin.peek()=='\n') //按回车键，获取默认值 
	{
		infile="压缩后.txt";
	}
	else
	{
		cin>>infile;	
	}
	
	string outfile="解压后";
	
	//生成压缩后随机的文件名 
	//srand(unsigned(int(time(0)))); 
	//int t=rand()%10000;  //随机值 
	//char *buf = new char[10];  //2147483647 int的最大值
    //_itoa(t, buf, 10);     
    //outfile += buf;
	outfile += ".txt";
	
	T.DictFromFile("密码本.txt");
	
	if( T.DecompressToFile(infile.c_str(), outfile.c_str()) )
	{
		cout<<"\n\t文件解压缩成功，已保存到 \""<<outfile<<"\" 中."<<endl;
	}
	else
	{
		cout<<"\n\t源文件 \""<<infile<<"\" 打开失败."<<endl;
		return false;
	}
	
	return true;
} 

int main(int argc, char *argv[])
{
	system("color 3f");
	
	int choice;  //菜单选择功能
	
	bool EnglishMenu=false;
	
	do
	{
		if(EnglishMenu)
		{
			showEnglishMenu();
		}
		else
		{
			showMenu(); //显示中文主菜单 
		} 
		cout<<"\n\tPlease choose: ";
		
   	    //以下程序，可以确保获取正确的值。否则，如果输入字符abc等字母，则会出错。 
		cin.sync();
		while (!(cin >> choice) ||(choice<0)||(choice>16))
	    {
	        showNotice();
	    }
	   
       cin.sync();
		
	   switch(choice)
	    {
		    case 0://
    	    	 EnglishMenu=!EnglishMenu;    	    	 
				 break;

		    case 1:// 
				 GetTextFromKeyboard();
				 break;
		    
			case 2:// 
				 LoadFromFile();
				 break;
		    
			case 3:// 
				 ShowHuffmanCode(); 
				 break;
		    
			case 4:// 
				 EncodeText();
				 break;
		    
			case 5://
				 CompressFile();
				 break;
		    	 
		    case 6:
		    	 DecompressFile();
				 break;
		    
			case 7: //
				 PrintTree(); 
				 break;
		    	 
		    case 8: //
			     byebye();
	    		 break;
		}
	    if(choice!=8 && choice!=0 )
	    {
    		selection(); //返回主菜单或退出程序	
    	}
	    
	}while(choice!=8);//输入16退出程序 
	
	getchar();

	return 0;
}






/*

参考： 
https://blog.csdn.net/u013445530/article/details/42364911?utm_medium=distribute.pc_relevant_download.none-task-blog-baidujs-1.nonecase&depth_1-utm_source=distribute.pc_relevant_download.none-task-blog-baidujs-1.nonecase

压缩的时候通过bitset将每8个0-1串压缩成一个字节，如果最后一个不满足8个，用0补齐，
但是要记录最后一个字节实际有多少个有效位，将其存入文件最后一个字节，
解压的时候先将文件定位到最后一个字节，取出有效位的个数，压缩文件真正有效的是倒数第二个字节，
倒数第一个字节只是记录倒数第二个字节中有几位是有效的，解压的时候根据密码本(记录每个字节的权值)建立哈夫曼树，
然后根据哈夫曼树解压文件

参考：https://www.cnblogs.com/Rcchio/p/6715583.html

可以通过计算原文件中的字符的频度之和，即所有字符的总个数，作为原文件的长度（假设用int length来保存）。
解压文件时每次向解压文件中输出一个解压出的字符，就将length--。当length为0时，表示解压结束。

先读取字符再判断是否到达文件结尾，就避免了将最后一个字符的频度多统计依次。
ifstream in("file.txt");while(true)
{
    x=in.get();
    if(in.eof()) break;
    a[x].name=x;
    a[x].weight++;
}

参考：https://blog.csdn.net/treeshy/article/details/50392535 
https://blog.csdn.net/qq_42316621/article/details/96721538

https://blog.csdn.net/yshshhgxq/article/details/83854606?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3.pc_relevant_is_cache&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3.pc_relevant_is_cache

1. 只压缩字母时成功，压缩文字会崩溃？
那是因为刚开始创建存放信息的数据是char类型的，当文件中有文字时，一个文字占两个字节，并且每个字节的范围是128~255，如果是char类型，数组的下标就会变成负数，数字越界了， 需要将存放信息的数据类型变为unsigned char

2. 为什么存放文字时依然可以找到，不会冲突？
一个字节有八个bit位，那么范围也就是0~255，如果文字的第一个字节为65，岂不是和‘A’冲突了。实际上不存在，因为文字的每个字节的范围是128~256， 所以不会发生冲突。

利用char进行8位一取，这样不管是字符类型还是汉字或者其他格式都可以进行压缩
*/


