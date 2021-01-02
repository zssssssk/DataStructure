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

void Huffman :: readtext1(char *file)
{           //��ȡ�ļ��е����ݣ������ո�
    indata.open(file);
    if (! indata)
    {
        cout << "ERROR!" << endl;
    }
    char temp[100];
    indata.getline(temp, 100);
    text += temp;
}

void Huffman :: savetext(char *file)
{                      //�������ݵ��ļ�
    outdata.open(file);
    if (! outdata)
    {
        cout << "ERROR" << endl;
    }
    outdata << text;
}

void Huffman :: readcode(char *file)
{                          //��ȡ����
    indata.open(file);
    indata >> huffmancode; 
}

/*void Huffman::ReadCodeFromFile(char *filename)
{                          //��ȡ���루���Ҳ�����ã�
    ifstream infile(filename);
    if (!infile)
    {
        cerr << "�޷����ļ���" << endl;
        return;
    }
    infile >> huffmancode;
    cout << huffmancode << endl;
}*/

void Huffman :: savecode(char *file)
{
    outdata.open(file);
    if (!outdata)
    {
        cout << "ERROR" << endl;
    }
    outdata << huffmancode;
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
        select(i - 1, s1, s2);
        huffmantree[s1].parent = huffmantree[s2].parent = i;
        huffmantree[i].lchild = s1;
        huffmantree[i].rchild = s2;
        huffmantree[i].weight = huffmantree[s1].weight + huffmantree[s2].weight;
    }
    p = l -> next;                  //��Ҷ�ӵ����ڵ�������ÿ���ַ��Ĺ���������
    char *cd = new char[number];    //���������Ĺ����ռ䣨ÿ���ַ��������n-1�ټ���'/0'��
    cd[number - 1]= '\0';          //���������
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
        char *a[i];
        a[i] = (char *) malloc ((number - start) * sizeof(char));
        strcpy(a[i], &cd[start]);
        p -> code = a[i];
        cout << p -> code << endl;
        p = p -> next;
    }
    delete[] cd;   //�������
}

void Huffman::select(int n, int &s1, int &s2)
{          //ѡȡn��Ԫ����Ȩֵ��С������Ԫ��
    s1 = s2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (huffmantree[i].parent != 0)
            continue;
        if (s1 == 0)
            s1 = i;
        else if (s2 == 0)
        {
            if (huffmantree[i].weight < huffmantree[s1].weight)
            {
                s2 = s1;
                s1 = i;
            }
            else
                s2 = i;
        }
        else
        {
            if (huffmantree[i].weight < huffmantree[s1].weight)
            {
                s2 = s1;
                s1 = i;
            }
            else if (huffmantree[i].weight < huffmantree[s2].weight)
                s2 = i;
        }
    }
}

void Huffman::PrintCharWeight()
{   //������ַ�����Ȩֵ������ʱ�ã�
    huffmancharslist p;
    p = l -> next;
    
        cout << "����" << p -> weight << endl;
        p = p -> next;
    
}

void Huffman :: printtext()
{      //����ı�
    cout << text << endl;
}

void Huffman :: printcode()
{       //�������
    for (int i = 0; i <= huffmancode.size(); i ++)
    {
        cout << huffmancode[i];
        if ((i + 1) % 50 == 0)
        {   //ÿ���50�����뻻��
            cout << endl;
        }
    }
}

void Huffman :: Encode()
{        //����
    huffmancharslist p;
    for (int i = 0; i < text.size(); i ++)
    {
        p = l -> next;
        for (int j = 1; j <= number; j ++)
        {
            if (text[i] == p -> ch)
            {
                huffmancode += p -> code;
            }
            p = p -> next;
        }
    }
}

void Huffman :: Decode()
{       //����
    text = "";
    string temp;
    huffmancharslist p;
    for (int i = 0; i < huffmancode.size(); i ++)
    {
        temp += huffmancode[i];
        p = l -> next;
        for (int j = 1; j <= number; j ++)
        {
            if (temp == p -> code)
            {
                text += p -> ch;
                temp = "";
            }
            p = p -> next;
        }
    }
    cout << text << endl;//�������
}

void Huffman :: countchars()
{     //ͳ��������ַ������ַ�Ȩֵ
    huffmancharslist p, q, temp;
    p = (huffmancharslist) malloc (sizeof(LNode));
    l -> next = p;
    p -> next = NULL;
    p -> ch = text[0];
    p -> weight = 1;
    number = 1;
    for (int i = 1; i != text.size(); ++i)
    {
        int j;
        p = l -> next;
        for (j = 1; j <= number; ++j)   
        {
            if (text[i] == p -> ch)
            {
                p -> weight ++;
                break;
            }
            temp = p;
            p = p -> next;
        }
        if (j > number)     
        {
            p = temp;
            ++number;
            q = (huffmancharslist) malloc (sizeof(LNode));
            q -> ch = text[i];
            q -> weight = 1;
            p -> next = q;
            q -> next = NULL;
        }
    }
}
int main()
{
    Huffman huffman;
    
    cout << "��ѡ���Ƿ����ı��� 1.yes  2.no  3.exit" << endl;
    int chose2;string s;
    cin >> chose2;
    while (chose2 == 1 || chose2 == 2)
    {
        switch (chose2)
        {
        case 1:
        	huffman.readtext1("text.txt");
            huffman.printtext();
            huffman.countchars();
            break;
        case 2:
            huffman.readtext2(s); 
            break;  
        }
        cout << "��������������" << endl;
        huffman.HuffmanCoding();
        cout << "�����С���" << endl;
        huffman.Encode();
        cout << "������롭��" << endl;
        huffman.savecode("code.txt");
        cout << "�����������";
        huffman.printcode();
        cout << endl;
        cout << "���ļ��ж�ȡ���롭��" << endl;
        huffman.readcode("code.txt");
        //huffman.ReadCodeFromFile("code.txt");
        cout << "���롭��" << endl;
        huffman.Decode();
        chose2 = 3;
    }
    while (chose2 != 1 && chose2 != 2 && chose2 != 3)
    {
        cout << "don't so stupid! just fallow my rules!" << endl;
    }
    return 0;
}
