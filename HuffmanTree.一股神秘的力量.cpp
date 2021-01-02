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
#include "sdw.h" //������ɫ
// #include "HMTree.h" //���������� 

 
using namespace std;

//Huffman���������ṹ 
struct Node
{
    char ch;          //����ֵ
    int weight;        //Ȩ��ֵ�����ַ����ֵĴ��� 
    string code;       //���Ĺ�������� 
    Node *lchild;     //���ӽ��ָ��
    Node *rchild;    //�Һ��ӽ��ָ��
    Node* parent;   //�����ָ�룬�о�ûʲô�� 
};

struct CompareNode
{
    bool operator()(const Node* a, const Node* b)
    {
        return a->weight > b->weight;//С����
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
	void InitHuffmanTree(); //��ʼ�� 
	 
	bool CompressToFile(const char* srcfile, const char* objfile);//ѹ���ļ��ĺ���
	bool CompressToScreen(char *srcTxt); //ѹ�����룬��ʾ����Ļ
	 
	void SaveDictToFile(const char* dictfile); //������뵽�ļ� 
	
	//��ѹ���ļ� 
	bool DecompressToFile(const char* srcfile, const char* objfile);
	//��ȡ�����ļ� 
	void DictFromFile(const char* codeBook);
	
	//��ʾ���������� 
	bool ShowHuffmanCode();
	int  Depth()                                //��������ĸ߶�
    {
    	return _Depth(m_root); //��ǰ�����ĸ߶� 
    }
    
	bool PrintTree();
	
	//��������ı����Ե�ǰ���еĹ�����������򣬽��б���(����) 
	bool EncodeText(char *srcTxt);

private:
	char screen[40][65]; //��Ļ���壬��ӡ������������
	Node* m_root; //�������
	
	map<char, string>  mapHCode; //�ַ�char ��Ӧ�� Huffman ���� 
	vector<char> V;
	
	/*
	map<char,int>: STL��һ�������������ṩһ��һ�����ݴ���������
	���е�һ�����Գ�Ϊ�ؼ��֣�ÿ���ؼ���ֻ����map�г���һ�Σ��ڶ������Գ�Ϊ�ùؼ��ֵ�ֵ��
	�����鷽ʽ�����Ը�����ǰ�ùؼ��ֶ�Ӧ��ֵ��dic[ch]++; 
	����ͳ�Ƹ����ַ����ֵĴ����� Ĭ�ϵ�int��ʼֵΪ0. 
	*/	
	map<char,int> mapCharWeight; //char: �ַ��� int: �ַ����ֵ�Ƶ�Σ���Ȩ�� 
	
	vector< pair<char,int> > vecSortWeight;//��Ȩ���Ź�����ַ����� 
	
	/*
	priority_queue: �����ȶ����У�Ԫ�ر��������ȼ���
	������Ԫ��ʱ������������ȼ���Ԫ������ɾ�������ȶ��о�����߼��ȳ� ��first in, largest out������Ϊ������
	
	����Ҫ����ͷ�ļ�#include<queue>, ��queue��ͬ�ľ����ڿ����Զ����������ݵ����ȼ�, �����ȼ��ߵ����ڶ���ǰ�����ȳ��ӡ�
	���ȶ��о��ж��е��������ԣ��������еĻ���������ֻ�����������������ڲ���һ��������������һ����ʵ�ֵġ�
	
	���壺priority_queue< Type, Container, Functional >
	
	Type �����������ͣ�Container �����������ͣ�Container������������ʵ�ֵ�����������vector, deque�ȵȣ�
	�������� list�� map��STL����Ĭ���õ���vector����Functional ���ǱȽϵķ�ʽ��
	���ԣ���Ҫ�м���� vector  
	*/  
	priority_queue<Node*, vector<Node*>, CompareNode> qCharWeight; //���ȶ��У���Ȩ��ֵ�͵��ȳ��� 
	 
	//��map <char,int> ���Ƶ� vector< pair<char,int> >��  
	//�ٰ�Ȩ������
	void _SortCharWeight();
	bool _CompareWeight(const pair<char, int> &a, const pair<char, int> &b);//sort()������Ҫ
	
	//����������ȶ��У���Ȩ��ֵ�͵��ȳ��� 
	void _GetNodePriority_Queue(); 
	
	bool _GetTextFromFile(const char* srcfile);
	 
	bool _GetTextFromKeyboard(const char* srcfile); //�Ӽ��̻�ȡ�����ı� 
	
	//����HuffmanTree 
	void _CreateHuffmanTree();
	
	//������㣬�����һ��˫�׽�� 
	Node* _MakeParentNode(Node* &a, Node* &b);
	
	//������������� 
	void _MakeHuffmandCode(Node* root);
	
	int _Draw(Node* root, int startX, int y);
	
	//��������ĸ߶�
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
	m_root=NULL; //�������
	
	mapHCode.clear(); //��� 
	V.clear();
	mapCharWeight.clear();
	vecSortWeight.clear();//��Ȩ���Ź�����ַ����� 
	
	//���ȶ���û�����clear()��������ˣ� ֱ���ÿյĶ��ж���ֵ
	qCharWeight=priority_queue<Node*, vector<Node*>, CompareNode>(); //ֱ���ÿյĶ��ж���ֵ
}

bool HuffmanTree::_GetTextFromKeyboard(const char* txt) //�Ӽ��̻�ȡ�����ı� 
{
    //���ζ���ÿ���ַ���һ���ֽ�
	//����ռ�����ֽڣ����Է����ζ��룬�����ʱ��Ҫ�����ֽ�����һ������ſ���������ʾ
	//Ϊʲô�������ʱ�����ͻ��һ���ֽ��а˸�bitλ����ô��ΧҲ����0~255��������ֵĵ�һ���ֽ�Ϊ65��
	//���Ǻ͡�A����ͻ�ˡ�ʵ���ϲ��ᣬ��Ϊ���ĵ�ÿ���ֽڵķ�Χ��128~256�����Բ�����0-127�ķ�����ͻ��
    int i=0;
    char ch;
    
	while( (ch=txt[i++]) && (ch!='\0') ) 
    {
        mapCharWeight[ch]++;  //ch�ǹؼ��֣���map<char,int>�е�int���ָ�ֵ��Ĭ�ϵ�int��ʼֵΪ0 
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
	
	//���ζ���ÿ���ַ���һ���ֽ�
	//����ռ�����ֽڣ����Է����ζ��룬�����ʱ��Ҫ�����ֽ�����һ������ſ���������ʾ
	//Ϊʲô�������ʱ�����ͻ��һ���ֽ��а˸�bitλ����ô��ΧҲ����0~255��������ֵĵ�һ���ֽ�Ϊ65��
	//���Ǻ͡�A����ͻ�ˡ�ʵ���ϲ��ᣬ��Ϊ���ĵ�ÿ���ֽڵķ�Χ��128~256�����Բ�����0-127�ķ�����ͻ��
    while(infile.get(ch)) 
    {
        mapCharWeight[ch]++;  //ch�ǹؼ��֣���map<char,int>�е�int���ָ�ֵ��Ĭ�ϵ�int��ʼֵΪ0 
    }
    infile.close();
    
    return true;
}

//��map <char,int> ���Ƶ� vector< pair<char,int> >��  
//�ٰ�Ȩ������
void HuffmanTree::_SortCharWeight()
{
    map<char,int>::iterator p = mapCharWeight.begin();//������ 
    
    while(p != mapCharWeight.end())
    {
        vecSortWeight.push_back(pair<char,int>(p->first, p->second));
        p++;
    }
    sort(vecSortWeight.begin(), vecSortWeight.end(), CompareWeight); //���� ��� CompareWeight���������ܴ��»��� 
}
 
//����������ȶ��У���Ȩ��ֵ�͵��ȳ��� 
void HuffmanTree::_GetNodePriority_Queue()
{
    vector<pair<char,int> >::iterator q = vecSortWeight.begin();
    while(q != vecSortWeight.end())
    {
        Node* p = new Node;
        
        p->ch = q->first;       //�����ַ� 
        p->weight = q->second;  //����Ȩ�� 
       
	    p->lchild = NULL;
        p->rchild = NULL;
        p->parent = NULL;
        
		qCharWeight.push(p); //�������ȶ��� 
        q++;
    }
}
 
//������㣬�����һ��˫�׽�� 
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
priority_queue: �����ȶ����У�Ԫ�ر��������ȼ���
������Ԫ��ʱ������������ȼ���Ԫ������ɾ�������ȶ��о�����߼��ȳ� ��first in, largest out������Ϊ������
����Ҫ����ͷ�ļ�#include<queue>, ��queue��ͬ�ľ����ڿ����Զ����������ݵ����ȼ�, �����ȼ��ߵ����ڶ���ǰ�����ȳ��ӡ�
���ȶ��о��ж��е��������ԣ��������еĻ���������ֻ�����������������ڲ���һ��������������һ����ʵ�ֵġ�
*/ 
 
//����HuffmanTree 
void HuffmanTree::_CreateHuffmanTree()
{
	_SortCharWeight(); //����׼�� 
	_GetNodePriority_Queue();  //���ȶ��� 
    
	while(qCharWeight.size() >= 2)
    {
        Node *x, *y; //������СȨֵ�Ľ�����
		 
        x = qCharWeight.top(); qCharWeight.pop();
        y = qCharWeight.top(); qCharWeight.pop();
        
		qCharWeight.push(_MakeParentNode(x,y));  //��������Ľ������ 
    }
    
    qCharWeight.top()->parent = NULL;
    
	m_root = qCharWeight.top();//���һ����㣬���Ǹ���� 
}
 
//--------------------����DFS�����������---------------------------

/*
���ö��������������˳����������һ��vector<pair<char,string>>����׼���洢ÿ���ַ��Լ������õ��ı��룬
��������һ���յ�string����tmp���Ӹ��ڵ㿪ʼ��������������tmp+=��0������������������tmp+='1����
������Ҷ�ӽڵ㼴��Ҷ���е��ַ������Ѿ��γɣ��㽫�临�Ƹ�vector<pair<char,string>>����������ַ���Ӧ��string��
Ȼ��tmp�����һ���ַ�ɾ����������һ�㣬����������������������Ҳ������ʱ��������㷵�أ�
��Ҫ���ʵ���һ���ڵ㽫�ǵ�ǰ�����ĸ��ڵ���ֵܽڵ㣬�����ÿ����һ��ʱ����Ҫɾ��tmp�����һ���ַ����������ͻ����
*/ 
void HuffmanTree::_MakeHuffmandCode(Node* root)
{
	//������ֻ��һ�Ž���ʱ��
	if(m_root->lchild == NULL && m_root->rchild == NULL)//Ҷ�ӽ��
	{
		if(m_root->ch!='\0')
			mapHCode[root->ch] = "1"; 
		
		//cout<<111<<endl;
	}
	
	 
   if(root->lchild == NULL && root->rchild == NULL)//Ҷ�ӽ�� 
   {
       string str;
       for(int i = 0; i < V.size(); i++)
              str += V[i];
       
       //�γɱ��� 
	   mapHCode[root->ch] = str;  //Ҷ�ӽ����ַ� root->ch �ı������ string str  
       
       V.pop_back(); //��㷵�ص�ʱ��һ��Ҫɾ������һ���ַ�
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
       V.pop_back(); //��㷵�ص�ʱ��һ��Ҫɾ������һ���ַ�
   }
}

bool HuffmanTree::CompressToScreen(char *srcTxt)
{
	if(! _GetTextFromKeyboard(srcTxt)) //�Ӽ��������ı�������������� 
	{
		return false;
	}
	
	_CreateHuffmanTree();        //�����������   
	_MakeHuffmandCode(m_root);  //���ɹ���������  
	
	cout<<"\n\t�����Ľ��Ϊ��"<<endl;
	cout<<"\n\t";
	
    ofstream fout;
    char *objfile="Text_Out.txt";
    
    fout.open(objfile,ios_base::binary);//�Զ����Ʒ�ʽ���� 
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
    fout << youxiao;//�����һλʣ�����Чλ�ô�����
    
    fout.close();
    
    return true;
}

//��������ı����Ե�ǰ���еĹ�����������򣬽��б���(����) 
bool HuffmanTree::EncodeText(char *srcTxt)
{
	if(!m_root)//�����û�й��������� 
	{
		if(! _GetTextFromKeyboard(srcTxt)) //�Ӽ��������ı�������������� 
		{
			return false;
		}
		
		_CreateHuffmanTree();        //�����������   
		_MakeHuffmandCode(m_root);  //���ɹ���������  
	} 
	
	cout<<"\n\t�����Ľ��Ϊ��"<<endl;
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
	if(! _GetTextFromFile(srcfile)) //���ļ��ж�ȡ�ı�������������� 
	{
		return false;
	}
	
	_CreateHuffmanTree();        //�����������   
	_MakeHuffmandCode(m_root);  //���ɹ���������  
	
	ofstream outfile("ѹ����_�����Ʊ���.txt");
	
    ifstream fin;
    fin.open(srcfile);
    if(!fin)
    {
    	cout<<"\n\t�ļ���ʧ��."<<endl;
    }
    
    ofstream fout;
    fout.open(objfile,ios_base::binary);//�Զ����Ʒ�ʽ���� 
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
    //����8��bits 
    char youxiao = str.size();
    for(char i = youxiao; i <= 7; i++)
    {
        str.append("0");
    }
 
    bitset<8> aaa(str);
    chFromFile = (char)aaa.to_ulong();
    fout << chFromFile;
    fout << youxiao;//�����һλʣ�����Чλ�ô�����
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

//��ѹ���ļ� 
bool HuffmanTree::DecompressToFile(const char* srcfile, const char* objfile)
{
	_CreateHuffmanTree();        //�����������   
	//_MakeHuffmandCode(m_root);  //���ɹ���������  
	
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
    	cout<<"\n\t�ļ���ʧ��."<<endl;
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
 
//��ȡ�����ļ� 
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

//��ʾ���������� 
bool HuffmanTree::ShowHuffmanCode()
{
	if(mapHCode.size()==0)
	{
		return false;
	}
	map<char, string>::iterator it; //�ַ�char ��Ӧ�� Huffman ���� 
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
	//screen��ά���飬��ʼ��Ϊ�ո� 
	int i=0,j=0;
	for(i=0;i<40;i++)
	{
		for(j=0;j<65;j++)
		{
			screen[i][j]=' ';
		}
	} 
	_Draw(m_root, 0, 0);
	//����������Ѷ�������ͼ��д�뵽screen��ά������
	//screen[][]: ��Ļ����
	//����screen����
	int height=Depth()*2; //�м��һ�У���б��
	
	for(i=0;i<height;i++) //���ߣ���ӡheight�� 
	{
		screen[i][64]='\0'; 
		cout<<"\t"<<screen[i]<<endl;
	}
}

int HuffmanTree::_Draw(Node* root, int startX, int y)
{
	int endX=startX; //��ǰ��������ͼ�ұ߽�
	
	//����ݹ飬�ȴ��������� 
	//�����ǰ�ڵ��������������ȴ�ӡ���������õ���ͼ�ε��ұ߽�
	//�����߶�λ��y���ڵ�ǰ������������ 
	if(root->lchild) 
	{
		endX = _Draw(root->lchild, startX, y+2)+1; //���ӵ�λ��+1��λ�ã���ӡ��ǰ����� 
	}
		
	int rootX=endX; //��ǰ������x����	
	//y�Ǹ߶ȵ�λ�ã�������Ļ����������
	//rootX��ˮƽλ�ã��ɵڶ�ά���������
	screen[y][rootX]=root->ch; //��ǰ��������ֵ��д�뵽screen�� 
	
	//��ʼ����������
	endX++; //������ӡ֮�����ұ���һ���ַ���λ�ã�������������ʼλ��
		
	if(root->rchild)
	{
		endX=_Draw(root->rchild, endX, y+2); //�������ĸ߶���������һ����y+2
	}
		
	return endX; //���ص�ǰ��������֮�������ұߵ�ʲôλ�� 
}
	
//����һ�Ź�������
HuffmanTree T; 
    
void showNotice()
{
	cin.clear();
	cin.sync();
	setCayonon3f();
	cout<<"\n\tInvalid. Please input again��";
	setWhiteon3f();
}

void  showMenu()
{
	   //��ʾ���˵�
	   cout<<"\n";
   	   cout<<"\n";
   	   cout<<"\t========================������ֻ�����========================"<<endl;
   	   cout<<"\n";
   	   cout<<"\n";
   	   cout<<"\n";
   	   cout<<"\t*********************�������������ļ�ѹ��*********************"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$       1. �Ӽ��������ı�        2. ���ļ������ı�           $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$       3. ��ʾ����������        4. �ı�����(����)           $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$       5. �ļ�ѹ��(����)        6. ��ѹ�ļ�(����)           $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$       7. ��ʾ��������          8. �˳�                     $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t$                                                            $"<<endl;
	   cout<<"\t******************��Ȩ����@SENG DEWEN(ɮ����)*****************"<<endl;
}

void  showEnglishMenu()
{
	   //��ʾӢ�����˵�
	   cout<<"\n";
   	   cout<<"\n";
   	   cout<<"\t========================������ֻ�����========================"<<endl;
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
	   cout<<"\t******************CopyRight@SENG DEWEN(ɮ����)****************"<<endl;
}

void printBird()
{
       cout<<"\n";
 	   cout<<"\t                    .-'-._                                      "<<endl;
 	   cout<<"\t                   /   e <  "; setYellowon3f();cout<<"\t������籯����"<<endl;setCayonon3f();
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
      case 0 : cout << ' '; break;   //�ո�
      case 1 : cout << '('; break;
      case 2 : cout << ')'; break;
      case 3 : cout << '`'; break;   //���ּ� 1 ��ߵ��ַ�
      case 4 : cout << '\''; break;  //������
      case 5 : cout << '\"'; break;  //˫����
      case 6 : cout << '-'; break;   //���ַ�
      case 7 : cout << '/'; break;   
      case 8 : cout << '\\'; break;  //��б��
      case 9 : cout << '.'; break;
      case 10 : cout << 'o'; break;  //Сд��ĸ o
      case 11 : cout << ';'; break;
      case 12 : cout << '#'; break;
      case 13 : cout << '_'; break;  //�»���
      case 14 : cout << '='; break;
      case 15 : cout << "��"; break; //�����ַ�ע��Ҫ��˫���� ""
      case 16 : cout << "I"; break;
      case 17 : cout << "LOVE"; break;
      case 18 : cout << " U"; break;
      case 19 : cout << '!'; break;
      case -1 : cout << endl<<"\t\t\t"; break; //����
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
	cout<<"\n\t=====================��ʾ��������====================="<<endl;
	cout<<"\n";
	cout<<"\n\t��ǰ�Ĺ���������Ϊ��\n"<<endl;	
	if(!T.ShowHuffmanCode())
	{
		cout<<"\n\t��ǰû���ַ�����."<<endl;
		return false;
	}
	
	cout<<"\n\n\t��������Ĺ�������Ϊ��\n"<<endl;	
	T.PrintTree();		
	return true;	
}

//��ʾ������������
bool ShowHuffmanCode()
{
	cout<<"\n\t��ǰ�Ĺ���������Ϊ��\n"<<endl;	
	if(!T.ShowHuffmanCode())
	{
		cout<<"\n\t��ǰû���ַ�����."<<endl;
		return false;
	}
	
	cout<<"\n\n\t��������Ĺ�������Ϊ��\n"<<endl;	
	T.PrintTree();		
	return true;
}

//�Ӽ��������ı����б��� 
bool GetTextFromKeyboard()
{
	T.InitHuffmanTree(); //��ʼ��
	
	char txt[100000];
	 
	cout<<"\n\t=====================�Ӽ��������ı�====================="<<endl;
	
	do
	{
		cout<<"\n\t�������ı���";
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
	T.InitHuffmanTree(); //��ʼ��
	 
	cout<<"\n\t=====================���ļ������ı�====================="<<endl;
	cout<<"\n\t������Դ�ļ���(\"Text.txt\")��";
	string infile;
	
	if(cin.peek()=='\n') //���س�������ȡĬ��ֵ 
	{
		infile="Text.txt";
	}
	else
	{
		cin>>infile;	
	}
	
	string outfile="Text_Out";
	
	//����ѹ����������ļ��� 
	//srand(unsigned(int(time(0)))); 
	//int t=rand()%10000;  //���ֵ 
	//char *buf = new char[10];  //2147483647 int�����ֵ
    //_itoa(t, buf, 10);     
    //outfile += buf;
	outfile += ".txt";
	
	if( T.CompressToFile(infile.c_str(), outfile.c_str()) )
	{
		cout<<"\n\t�ļ�����ɹ���������ѱ��浽 "<<outfile<<" ��."<<endl;
	}
	else
	{
		cout<<"\n\tԴ�ļ� "<<infile<<" ��ʧ��."<<endl;
		return false;
	}
    
    string codeBook="CodeBook.txt";
    
	T.SaveDictToFile(codeBook.c_str());
}

//ѹ���ļ� 
bool CompressFile()
{
	T.InitHuffmanTree(); //��ʼ��
	 
	cout<<"\n\t=====================��ʼѹ��(����)�ļ�====================="<<endl;
	cout<<"\n\t������Դ�ļ���(\"ԭ��.txt\")��";
	string infile;
	
	if(cin.peek()=='\n') //���س�������ȡĬ��ֵ 
	{
		infile="ԭ��.txt";
	}
	else
	{
		cin>>infile;	
	}
	
	string outfile="ѹ����";
	
	//����ѹ����������ļ��� 
	//srand(unsigned(int(time(0)))); 
	//int t=rand()%10000;  //���ֵ 
	//char *buf = new char[10];  //2147483647 int�����ֵ
    //_itoa(t, buf, 10);     
    //outfile += buf;
	outfile += ".txt";
	
	if( T.CompressToFile(infile.c_str(), outfile.c_str()) )
	{
		cout<<"\n\t�ļ�ѹ���ɹ����ѱ��浽 \""<<outfile<<"\" ��."<<endl;
	}
	else
	{
		cout<<"\n\tԴ�ļ� \""<<infile<<"\" ��ʧ��."<<endl;
		return false;
	}
    
    string codeBook="���뱾.txt";
    
	T.SaveDictToFile(codeBook.c_str());
	
	return true;
} 

//��������ı����Ե�ǰ���еĹ�����������򣬽��б���(����) 
bool EncodeText()
{
	cout<<"\n\t=====================����(����)====================="<<endl;
	cout<<"\n\t��������ı������ݵ�ǰ���еĹ��������������б���(����)."<<endl;
	cout<<"\n\t�������ı���";
	
	char txt[100000];
	cin.getline(txt,100000,'\n');
	
	T.EncodeText(txt);
	
	cout<<"\n\n\t��ǰ�Ĺ������������Ϊ��\n"<<endl;
	T.ShowHuffmanCode();
	
	return true;
}

bool DecompressFile()
{
	T.InitHuffmanTree(); //��ʼ��
	 
	cout<<"\n\t=====================��ʼ��ѹ(����)�ļ�====================="<<endl;
	cout<<"\n\t������Դ�ļ���(\"ѹ����.txt\")��";
	string infile;
	
	if(cin.peek()=='\n') //���س�������ȡĬ��ֵ 
	{
		infile="ѹ����.txt";
	}
	else
	{
		cin>>infile;	
	}
	
	string outfile="��ѹ��";
	
	//����ѹ����������ļ��� 
	//srand(unsigned(int(time(0)))); 
	//int t=rand()%10000;  //���ֵ 
	//char *buf = new char[10];  //2147483647 int�����ֵ
    //_itoa(t, buf, 10);     
    //outfile += buf;
	outfile += ".txt";
	
	T.DictFromFile("���뱾.txt");
	
	if( T.DecompressToFile(infile.c_str(), outfile.c_str()) )
	{
		cout<<"\n\t�ļ���ѹ���ɹ����ѱ��浽 \""<<outfile<<"\" ��."<<endl;
	}
	else
	{
		cout<<"\n\tԴ�ļ� \""<<infile<<"\" ��ʧ��."<<endl;
		return false;
	}
	
	return true;
} 

int main(int argc, char *argv[])
{
	system("color 3f");
	
	int choice;  //�˵�ѡ����
	
	bool EnglishMenu=false;
	
	do
	{
		if(EnglishMenu)
		{
			showEnglishMenu();
		}
		else
		{
			showMenu(); //��ʾ�������˵� 
		} 
		cout<<"\n\tPlease choose: ";
		
   	    //���³��򣬿���ȷ����ȡ��ȷ��ֵ��������������ַ�abc����ĸ�������� 
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
    		selection(); //�������˵����˳�����	
    	}
	    
	}while(choice!=8);//����16�˳����� 
	
	getchar();

	return 0;
}






/*

�ο��� 
https://blog.csdn.net/u013445530/article/details/42364911?utm_medium=distribute.pc_relevant_download.none-task-blog-baidujs-1.nonecase&depth_1-utm_source=distribute.pc_relevant_download.none-task-blog-baidujs-1.nonecase

ѹ����ʱ��ͨ��bitset��ÿ8��0-1��ѹ����һ���ֽڣ�������һ��������8������0���룬
����Ҫ��¼���һ���ֽ�ʵ���ж��ٸ���Чλ����������ļ����һ���ֽڣ�
��ѹ��ʱ���Ƚ��ļ���λ�����һ���ֽڣ�ȡ����Чλ�ĸ�����ѹ���ļ�������Ч���ǵ����ڶ����ֽڣ�
������һ���ֽ�ֻ�Ǽ�¼�����ڶ����ֽ����м�λ����Ч�ģ���ѹ��ʱ��������뱾(��¼ÿ���ֽڵ�Ȩֵ)��������������
Ȼ����ݹ���������ѹ�ļ�

�ο���https://www.cnblogs.com/Rcchio/p/6715583.html

����ͨ������ԭ�ļ��е��ַ���Ƶ��֮�ͣ��������ַ����ܸ�������Ϊԭ�ļ��ĳ��ȣ�������int length�����棩��
��ѹ�ļ�ʱÿ�����ѹ�ļ������һ����ѹ�����ַ����ͽ�length--����lengthΪ0ʱ����ʾ��ѹ������

�ȶ�ȡ�ַ����ж��Ƿ񵽴��ļ���β���ͱ����˽����һ���ַ���Ƶ�ȶ�ͳ�����Ρ�
ifstream in("file.txt");while(true)
{
    x=in.get();
    if(in.eof()) break;
    a[x].name=x;
    a[x].weight++;
}

�ο���https://blog.csdn.net/treeshy/article/details/50392535 
https://blog.csdn.net/qq_42316621/article/details/96721538

https://blog.csdn.net/yshshhgxq/article/details/83854606?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3.pc_relevant_is_cache&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3.pc_relevant_is_cache

1. ֻѹ����ĸʱ�ɹ���ѹ�����ֻ������
������Ϊ�տ�ʼ���������Ϣ��������char���͵ģ����ļ���������ʱ��һ������ռ�����ֽڣ�����ÿ���ֽڵķ�Χ��128~255�������char���ͣ�������±�ͻ��ɸ���������Խ���ˣ� ��Ҫ�������Ϣ���������ͱ�Ϊunsigned char

2. Ϊʲô�������ʱ��Ȼ�����ҵ��������ͻ��
һ���ֽ��а˸�bitλ����ô��ΧҲ����0~255��������ֵĵ�һ���ֽ�Ϊ65�����Ǻ͡�A����ͻ�ˡ�ʵ���ϲ����ڣ���Ϊ���ֵ�ÿ���ֽڵķ�Χ��128~256�� ���Բ��ᷢ����ͻ��

����char����8λһȡ�������������ַ����ͻ��Ǻ��ֻ���������ʽ�����Խ���ѹ��
*/


