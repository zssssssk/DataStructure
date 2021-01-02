//https://www.cnblogs.com/WindSun/p/10859055.html
#include<iostream>
#include <stack>
#include <queue>
#include<cstring>
#include<cmath>
using namespace std;

struct SqBiTree
{
  char *base;   //�洢�ռ��ַ
  int nodeNum;      //�������н����
};	

//����������ṹ
struct BinTreeNode
{
    char Data;
    BinTreeNode *leftChild , *rightChild ;
}; 	 

class BinaryTree
{
	private:
		BinTreeNode *root; //���ڵ�
        char RefValue;//��������ֹͣ�ı�־����Ҫһ�����캯��
		char b[1000];//˳��洢��һ������ 
		
    public:
    	//==========����������������==========//

    //���캯��
    BinaryTree() : root(NULL) {}
    


    //��������


//==========�������Ĵ���==========//


     //˳��洢�Ĵ��򴴽�������
	 void CreatBTarray(BinTreeNode* &p,int i){
	 	if(b[i]!='\0'){
	 		if(b[i]!='#') {
	 		p=new BinTreeNode;
	 		p->Data =b[i];
	 		CreatBTarray(p->leftChild ,2*i);
	 		CreatBTarray(p->rightChild ,2*i+1);
		 }
		 else p=NULL;
		 }
	 	else p=NULL;
	 }
	 
	 //���� ˳��洢�Ĵ��򴴽�������
	 void transCreatBTarray(int i){
	 	cout<<"������˳��洢����<�磺~ABD#EI###F#CG##>:(������һ��~)";cin>>b;
	 	CreatBTarray(root,i);
	 }
	 
	  
    //ǰ���������������(ǰ�������Ӧ��)����#��ʾ�ս��
    void CreateBinTree_PreOrder(BinTreeNode* &subTree)//&&&&&&&&���ò��ܶ� 
    {
        char item;
        if (cin >> item)
        {
        	
            if(item !='#')//��if����������while 
            {
            	subTree=new BinTreeNode;
                subTree->Data=item;
                CreateBinTree_PreOrder(subTree->leftChild);    //�ݹ鴴��������
                CreateBinTree_PreOrder(subTree->rightChild);    //�ݹ鴴��������
            }
            else{
                subTree=NULL;
            }
        }
    }
void transfer1(){
	char t;
	cin>>t;
	root=new BinTreeNode;
	root->Data =t;
	CreateBinTree_PreOrder(root->leftChild);
	CreateBinTree_PreOrder(root->rightChild);
}


    //ʹ����������������������������
    void CreateBinTreeBy_Pre_In(BinTreeNode* &cur, const char *pre, const char *in, int n)
    {
        if (n <= 0)
        {
            cur = NULL;
            return;
        }
        int k = 0;
        while (pre[0] != in[k]) //���������ҵ�pre[0]��ֵ
        {
            k++;
        }
        cur = new BinTreeNode; //�������
        cur->Data=in[k];
        CreateBinTreeBy_Pre_In(cur->leftChild, pre + 1, in, k);
        CreateBinTreeBy_Pre_In(cur->rightChild, pre + k + 1, in + k + 1, n - k - 1);
    }
    void transferCreateBinTreeBy_Pre_In(){
    	char first[100]={'A','B','D','H','L','E','K','C','F','G'};char in[100]={'H','L','D','B','E','K','A','F','C','G'};
	    int sum=0,i=0;
	    cout<<"ǰ���������<�磺ABDHLEKCFG>:";cin>>first;
	    cout<<"\n�����������<�磺HLDBEKAFCG>:";cin>>in; 
	    while(in[i]!='\0'){
		sum++;i++;
	   }
	cout<<"\n�����������ɹ���\n";
	root=new BinTreeNode;
	root->Data =first[0];
	CreateBinTreeBy_Pre_In( root , first, in, sum);
	}
	
	
    //ʹ�ú�������������������������
    void CreateBinTreeBy_Post_In(BinTreeNode *&cur, const char *post, const char *in, int n)
    {
        if (n == 0)
        {
            cur = NULL;
            return;
        }

        char r = *(post + n - 1);    //�����ֵ
        cur = new BinTreeNode; //���쵱ǰ���
        cur->Data =r;
        int k = 0;
        const char *p = in;
        while (*p != r)
        {
            k++;
            p++;
        }
        CreateBinTreeBy_Post_In(cur->leftChild, post, in, k);
        CreateBinTreeBy_Post_In(cur->rightChild, post + k, p + 1, n - k - 1);
    }
    void transferCreateBinTreeBy_Post_In(){
    	char post[100];char in[100];
	    int sum=0,i=0;
	    cout<<"�����������<�磺ABDEIFCGH>:";cin>>in;
	    cout<<"\n�����������<�磺ABDEIFCGH>:";cin>>post; 
	    while(in[i]!='\0'){
		sum++;i++;
	   }
	cout<<"\n�����������ɹ���\n";
	root=new BinTreeNode;
	root->Data =post[sum-1];
	CreateBinTreeBy_Pre_In( root , post, in, sum);
	}

//==========�������ı���==========//

    //����������ݹ飩
    void PreOrder(BinTreeNode *subTree)
    {
        if (subTree != NULL)
        {
            cout << subTree->Data << " ";
            PreOrder(subTree->leftChild);
            PreOrder(subTree->rightChild);
        }
    }

    //�������(�ݹ�)
    void InOrder(BinTreeNode *subTree)
    {
        if (subTree != NULL)
        {
            InOrder(subTree->leftChild);
            cout << subTree->Data << " ";
            InOrder(subTree->rightChild);
        }
    }

    //����������ݹ飩
    void PostOrder(BinTreeNode *subTree)
    {
        if (subTree != NULL)
        {
            PostOrder(subTree->leftChild);
            PostOrder(subTree->rightChild);
            cout << subTree->Data << " ";
        }
    }


    //�������Ĳ�α���(�ǵݹ����)
   // �����˳����ʶ������Ĵ�����Ҫ����һ�����С��ڷ��ʶ�������ĳһ����ʱ������һ����ָ��Ԥ�ȼ����ڶ����У����ö��а��������ʵĴ�����ˣ�ÿ������һ�����ʱ����������Ů���μӵ����еĶ�β��Ȼ���ٷ������ڶ��ж�ͷ�Ľ�㡣��������ʵ�ֶ��������İ�����ʡ�
    void LevelOrder(BinTreeNode *p)
    {
        queue<BinTreeNode*> Q;
        Q.push(p);    //���ڵ����
        BinTreeNode* t;
        while (!Q.empty())
        {
            t = Q.front();    //t�ȼ�ס��ͷ,�ٽ���ͷ����
            Q.pop();
            cout << t->Data << " ";    //���ʶ�ͷԪ�ص�����

            if (t->leftChild != NULL)
            {
                Q.push(t->leftChild);
            }

            if (t->rightChild != NULL)
            {
                Q.push(t->rightChild);
            }
        }
    }
    
    //���������N��Ľ��
    /*
���������k��Ľڵ���
�ݹ鷽ʽ���裺
�������ڵ�p��
���pΪ�գ����߲���k_Level <= 0����Ϊ�������߲���Ҫ���򷵻�0��
���p��Ϊ�գ��Ҵ�ʱ���� k_Level==1�����ʱpΪ��K��ڵ�֮һ���򷵻�1��
���p��Ϊ�գ��Ҵ�ʱ���� k_Level > 1�����ʱ��Ҫ��root��������k_Level - 1 ����ڵ�����proot��������k_Level-1����ڵ�����

/*�ݹ�ʵ�����������k��Ľڵ���*/
	int nodeOf_n_Layer(BinTreeNode *p,int k){
	   if(p==NULL||k<=0) return 0;
	   if(p!=NULL &&k==1) return 1;
	   return (nodeOf_n_Layer(p->leftChild ,k-1)+nodeOf_n_Layer(p->rightChild ,k-1));
	}
	 

//==========��ȡ���==========//

    //��ȡ�������ĸ��ڵ�
    BinTreeNode *getRoot() const
    {
        return root;
    }


//==========��Ա����==========//

    //���ٺ���
    void Destroy() ;
    
    //ɾ��ĳ�����
	void deleteNode(char e){
		cout<<"���������"<<e<<"��ɾ��."<<endl;
		queue<BinTreeNode*> Q;
        Q.push(root);    //���ڵ����
        BinTreeNode* t=new BinTreeNode;
        int flag=1;
        if(root->Data ==e) root=NULL;
        else{
        	while (flag)
           {
            t = Q.front();    //t�ȼ�ס��ͷ,�ٽ���ͷ����
            Q.pop();
            	if (t->leftChild != NULL)
            {
			if(t->leftChild->Data  ==e){
            	t->leftChild =NULL;
            	flag=0;
			}
                Q.push(t->leftChild);
            }

                if (t->rightChild != NULL)
            {
			if(t->rightChild->Data ==e){
				t->rightChild =NULL;
				flag=0;
			}
                Q.push(t->rightChild);
            }
           }
		}
        
	} 
	
    
    //�����������subTreeΪ���Ľ��ĸ���
    int Size(BinTreeNode *subTree) 
    {
        if (subTree == NULL)    //�ݹ����������������Ϊ0
        {
            return 0;
        }
        return 1 + Size(subTree->leftChild) + Size(subTree->rightChild);
    }
    
    //�����������subTreeΪ������Ҷ�ĸ���
    int leaf(BinTreeNode *subTree) 
    {
    	if (subTree == NULL)    //�ݹ����������������Ϊ0
        {
            return 0;
        }
        else if (subTree->leftChild  == NULL && subTree->rightChild ==NULL)    //�ݹ����������������+1 ��ע�⣡����Ҫ��else if����if���У�����ǰ�����ì�ܣ� 
        {
            return 1;
        }
        
        return leaf(subTree->leftChild) + leaf(subTree->rightChild);
    }
    
    //�����������subTreeΪ���Ķ�Ϊ1���ĸ���
    int degree1(BinTreeNode *subTree) 
    {
        if (subTree == NULL)    //�ݹ����
        {
            return 0;
        }
        if(subTree->leftChild!=NULL && subTree->rightChild==NULL){
        	return  degree1(subTree->leftChild) + 1;
		}
		if(subTree->leftChild==NULL && subTree->rightChild!=NULL){
        	return  degree1(subTree->rightChild) + 1;
		}
        return degree1(subTree->leftChild) + degree1(subTree->rightChild);
    }
    
    //�����������subTreeΪ���Ķ�Ϊ2���ĸ���
    int degree2(BinTreeNode *subTree) 
    {
        if (subTree == NULL)    //�ݹ����
        {
            return 0;
        }
        if(subTree->leftChild!=NULL && subTree->rightChild!=NULL) return  1 + degree2(subTree->leftChild) + degree2(subTree->rightChild);
        return degree2(subTree->leftChild) + degree2(subTree->rightChild);
    }
    
    //��ն�����
	void clear(){
		root=NULL;
		cout<<"�����������"<<endl;
	} 



    //�ж϶������Ƿ�Ϊ��
    bool Empty() { return (root == NULL) ? true : false; }

    //�����������subTreeΪ���ĸ߶�
    int Height(BinTreeNode *subTree)
    {
        if (subTree == NULL)    //�ݹ�����������߶�Ϊ0
        {
            return 0;
        }
        int i = Height(subTree->leftChild);
        int j = Height(subTree->rightChild);
        return i < j ? j + 1 : i + 1;
    }
    
    //����ĳ���ĸ߶�(��Ҫ�ȱ�֤������㣩 
	int nodeHeight(BinTreeNode *p){
		int i=1;char m=p->Data ;
		while(p->Data !=root->Data ){
		     p=parents(p);
		     i++;
		}
		p->Data =m;
		return i;
	} 
    
    //�ж��Ƿ��������� 
	int ifhavenode(BinTreeNode *p){
		queue<BinTreeNode*> Q;
		Q.push(root);
		BinTreeNode* t;
        while (!Q.empty())
        {
            t = Q.front();    //t�ȼ�ס��ͷ,�ٽ���ͷ����
            Q.pop();
            if(t->Data ==p->Data ) return 1;

            if (t->leftChild != NULL)
            {
                Q.push(t->leftChild);
            }

            if (t->rightChild != NULL)
            {
                Q.push(t->rightChild);
            }
        }
		return 0;
	} 
	
	//���ĳ����������Ϣ(��jio���Ƿֿ��ã� 
	/*void getinformation(BinTreeNode *p){
		quene<BinTreeNode*> Q;
		BinTreeNode *t=root;
		int h=1;int flag=1;
		while(flag){
			Q.push(t);
			if(p->Data ==Q.front()->Data){
				flag=0;
				cout<<"���ĸ߶�Ϊ"<<h;
			}
		}
	}*/
    
    //�����˫��(�������Ľ��ˣ����Ҫ���ص���˫�׵�ָ�������Data����������᷽��ࣩܶ 
    //�ĸĸģ��������� 
	BinTreeNode* parents(BinTreeNode *p){
		if(p->Data ==root->Data ){
			return NULL;
		}
		else{
		queue<BinTreeNode*> Q;
		Q.push(root);
		BinTreeNode *t;
		while(!Q.empty() ){
			t=Q.front();
			
			if (t->leftChild != NULL)
            {
            	if(p->Data==t->leftChild->Data ) return t;
                Q.push(t->leftChild);
            }

            if (t->rightChild != NULL)
            {
            	if(p->Data ==t->rightChild->Data ) return t;
                Q.push(t->rightChild);
            }
            Q.pop();
		}
		}
		
	} 
	
	//�����·������Ҫ���ж��Ƿ���ڣ�
	void pathNode(BinTreeNode* p){
		int i=1;char c[100];
		c[0]=p->Data ;
		while(p->Data !=root->Data ){
		     p=parents(p);
		     c[i]=p->Data ;
		     i++;
		}
		c[i]=root->Data ;
		while(i--){
			if(i!=0) cout<<c[i]<<"->";
			else cout<<c[i];
		}

	} 
	
	//�����нڵ��·��
	void everynodepath(){
		queue<BinTreeNode*> Q;
		Q.push(root);
		BinTreeNode *t;
		while(!Q.empty() ){
			t=Q.front();
			pathNode(t);cout<<endl;

			if (t->leftChild != NULL)
            {
                Q.push(t->leftChild);
            }

            if (t->rightChild != NULL)
            {
                Q.push(t->rightChild);
            }
            Q.pop();
		}
		
	} 
	
	//���������
	BinTreeNode *leftchild(BinTreeNode* p) {
		queue<BinTreeNode*> Q;
        Q.push(root);    //���ڵ����
        BinTreeNode* t;
        while (!Q.empty())
        {
            t = Q.front();    //t�ȼ�ס��ͷ,�ٽ���ͷ����
            Q.pop();
            if(t->Data == p->Data){
            	return t->leftChild ;
			}
            if (t->leftChild != NULL)
            {
                Q.push(t->leftChild);
            }

            if (t->rightChild != NULL)
            {
                Q.push(t->rightChild);
            }
        }
        return NULL;
	}
	
	//������Һ���
	BinTreeNode *rightchild(BinTreeNode* p) {
		queue<BinTreeNode*> Q;
        Q.push(root);    //���ڵ����
        BinTreeNode* t;
        while (!Q.empty())
        {
            t = Q.front();    //t�ȼ�ס��ͷ,�ٽ���ͷ����
            Q.pop();
            if(t->Data == p->Data){
            	return t->rightChild  ;
			}
            if (t->leftChild != NULL)
            {
                Q.push(t->leftChild);
            }

            if (t->rightChild != NULL)
            {
                Q.push(t->rightChild);
            }
        }
        return NULL;
	}
	
	//��������ֵ�
	BinTreeNode *leftbrother(BinTreeNode *p){
		queue<BinTreeNode*> Q;
        Q.push(root);         //���ڵ����
        BinTreeNode* t=new BinTreeNode;
        while (!Q.empty())
        {
            t = Q.front();    //t�ȼ�ס��ͷ,�ٽ���ͷ����
            Q.pop();
            if(t->leftChild->Data==p->Data ){
            	cout<<"t->leftChild->Data==p->Data"<<endl;
            	return NULL;
			}
			if(t->rightChild->Data==p->Data ){
				cout<<"t->rightChild->Data==p->Data"<<endl;
            	if(t->leftChild ==NULL) return NULL;
            	else return t->leftChild ;
			}
            if (t->leftChild != NULL)
            {
                Q.push(t->leftChild);
            }

            if (t->rightChild != NULL)
            {
                Q.push(t->rightChild);
            }
        }
        
        return NULL;
	}
	
	//��������ֵ�
 	BinTreeNode *rightbrother(BinTreeNode *p){
		queue<BinTreeNode*> Q;
        Q.push(root);    //���ڵ����
        BinTreeNode* t=new BinTreeNode;
        while (!Q.empty())
        {
            t = Q.front();    //t�ȼ�ס��ͷ,�ٽ���ͷ����
            Q.pop();
            if(t->rightChild->Data==p->Data ){
            	cout<<"t->rightChild->Data==p->Data"<<endl;
            	return NULL;
			}
			if(t->leftChild->Data==p->Data ){
				cout<<"t->leftChild->Data==p->Data "<<endl;
				if(t->rightChild ==NULL) return NULL;
            	else return t->rightChild;
			}
            if (t->leftChild != NULL)
            {
                Q.push(t->leftChild);
            }

            if (t->rightChild != NULL)
            {
                Q.push(t->rightChild);
            }
        }
        return NULL;
	}
	
	//����ĳ�����
	void insertNode(char r,char n,int w){
		cout<<"����������ɹ�"<<endl;
		queue<BinTreeNode*> Q;
		Q.push(root);
		BinTreeNode* t;int flag=1;
		while(flag) {
			t=Q.front() ;
			Q.pop() ;
			if(t->Data ==r){
				flag=0;
				if(w==0){
					if(t->leftChild ==NULL){
						t->leftChild =new BinTreeNode;
						t->leftChild->Data =n;
						t->leftChild->leftChild =NULL;
						t->leftChild->rightChild =NULL;
					}
					else{
						t->leftChild->Data =n;
					}
				}
				else{
					if(t->rightChild ==NULL){
						t->rightChild =new BinTreeNode;
						t->rightChild->Data =n;
						t->rightChild->leftChild =NULL;
						t->rightChild->rightChild =NULL;
					}
					else{
						t->rightChild->Data =n;
					}
				}
			}
			if(t->leftChild !=NULL) Q.push(t->leftChild );
			if(t->rightChild !=NULL) Q.push(t->rightChild );  
		}
	}
	
	//����p���������������ȫ��������
	void swapTree(BinTreeNode *p){
		if(p!=NULL){
		  BinTreeNode *t;
		   if(!(p->leftChild ==NULL && p->rightChild ==NULL)){
		  	if(p->leftChild ==NULL){
		  		p->leftChild =p->rightChild ;p->rightChild =NULL;
		  		swapTree(p->leftChild  );
			  }
			else if(p->rightChild ==NULL){
				p->rightChild =p->leftChild ;p->leftChild =NULL;
				swapTree(p->rightChild );
			}
			else{
				t=p->leftChild ;p->leftChild =p->rightChild ;p->rightChild =t;
				swapTree(p->leftChild );swapTree(p->rightChild );
			}
		  }
		}	
	} 
	
	//�����������ж�(���Դ�p֮���жϣ���1��ʾ�ǣ� 
	int isFullTree(){
		if(pow(2,Height(root))-1==Size(root)) return 1;
		else return 0;
	} 
	
	//��ȫ���������ж�(�ȸ�����ʽת˳��洢�� (1��ʾ�ǣ� 
	int iscompleteTree(){
		 int i=1,j=1;
		 transSequeueStorage1(root,j);
		 while(b[i]!='#'){
		 	i++;
		 }
		for(int j=i;j<pow(2,Height(root));j++){
			if(b[j]!='#') return 0;
		}
		return 1;
	} 
	
	//ƽ����������жϣ�0��ʾ�ǣ�
	int isbalanceTree(BinTreeNode *p){
		if(p==NULL) return 0;
		else if(abs(Height(p->leftChild )-Height(p->rightChild ))>1) return 1;
		else return isbalanceTree(p->leftChild )+isbalanceTree(p->rightChild );
	} 
	
	//������������жϣ�1��ʾ�ǣ�
	int isregular(){
		if(degree1(root)==0) return 1;
		else return 0;
	} 
	
   //���˳��洢����b(˳��洢�ṹa������Ԫ����Ϊ��#������ʾ�ս�㣩)
    void clearb(){
    	memset(b,'#',sizeof(b));
	}
	 
	
	// ��ʽת˳��洢(�����) 
	void transSequeueStorage(BinTreeNode *p,int i){
		if(p!=NULL){
			b[i]=p->Data ;
		    transSequeueStorage(p->leftChild ,2*i);
		    transSequeueStorage(p->rightChild ,2*i+1);
		}
	}
	
	
	//�ϲ���������
	void  transSequeueStorage1(BinTreeNode *p,int i){
		clearb();
		transSequeueStorage(p,i);
	}

	
	//���˳��洢�Ķ�����
	void showSequeueStorage(){
	    int k=pow(2,Height(root));
	    for(int i=1;i<k;i++) cout<<b[i];
	}
	
	
	//��ӡ����
	void treePrinting(){
		int i,k,e;
		k=Height(root);e=pow(2,k);
		for(i=1;i<=k;i++){
			for(int j=1;j<=e-pow(2,i-1);j++) cout<<" ";
			for(int j=pow(2,i-1);j<pow(2,i);j++) cout<<b[j]<<" ";
			cout<<endl;
		}
	} 
	
};


void showmenu();
void showmenu1();
void creat1();
void traverse();
void pre_inCreat();
void post_inCreat();
void Clear();
void showstatus();
void getElement();
void shownodepath();
void deletenode();
void insertnode(); 
void swaptree();
void judgeshape();
void creatBTarray();
void showsequeuestorage();
void treeprinting();
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
		        creat1() ;
		        break;
		    case 2:
		    	traverse();
		    	break;
		    case 3:
		    	pre_inCreat();
		    	break;
		    case 4:
		    	post_inCreat();
		    	break;
		    case 5:
		    	Clear();
		    	break;
		    case 6:
		    	showstatus();
		    	break;
		    case 7:
		    	getElement();
		    	break;
		    case 8:
		    	shownodepath();
		    	break;
		    case 9:
		    	deletenode();
		    	break;
		    case 10:
		    	insertnode();
		    	break;
		    case 11:
		    	swaptree();
		    	break;
		    case 12:
		    	judgeshape();
		    	break;
		    case 13:
		    	creatBTarray();
		    	break;
		    case 14:
		    	showsequeuestorage();
		    	break;
		    case 15:
		    	treeprinting();
		    	break;
		}
	}
	return 0;
}
void showmenu(){//showMenu
	cout<<"                   ************************************************************************"<<endl;
	cout<<"                   *         1.create BT<pre-order>        2.traverse binary tree         *"<<endl;
	cout<<"                   *         3.creat BT<pre-in order>      4.creat BT<post-in order>      *"<<endl;
	cout<<"                   *         5.clear binary tree           6.show stauts                  *"<<endl;
	cout<<"                   *         7.search node information     8.show every node path         *"<<endl;
	cout<<"                   *         9.delete node                 10.insert node                 *"<<endl;
	cout<<"                   *         11.swap tree chlidren         12. judge tree shape           *"<<endl;
	cout<<"                   *         13.creat BT<array>            14.show sequence storage       *"<<endl;
	cout<<"                   *         15.print tree shape(14....)   16.exit (0 for Chinese menu)   *"<<endl;
	cout<<"                   *                                                                      *"<<endl;
	cout<<"                   ************************************************************************"<<endl;
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
BinaryTree a;
void creat1(){
	BinTreeNode *b;
	cout<<"ǰ������������������������<��#��ʾ��ָ��,��ABD#EI##F##CG#H####>"<<endl;
	a.transfer1();
	cout<<"\n�����������ɹ���";
	cout<<"\n��������ǰ�������";a.PreOrder(a.getRoot() );
	cout<<"\n�����������������";a.InOrder (a.getRoot() );
	cout<<"\n�������ĺ��������";a.PostOrder (a.getRoot() );
	cout<<"\n�������Ĳ�α�����";a.LevelOrder(a.getRoot() ); 
	cout<<"\n�������ĸ�:"<<a.Height(a.getRoot() ); 
	cout<<"\npress any key to return to menu"<<endl;
	getchar();getchar();
}
void traverse(){
	if(a.getRoot() ==NULL) cout<<"������Ϊ��"<<endl;
	else{
	cout<<"\n��������ǰ�������";a.PreOrder(a.getRoot() );
	cout<<"\n�����������������";a.InOrder (a.getRoot() );
	cout<<"\n�������ĺ��������";a.PostOrder (a.getRoot() );
	cout<<"\n�������Ĳ�α�����";a.LevelOrder(a.getRoot() ); 
	cout<<"\n�������ĸ�:"<<a.Height(a.getRoot() );
	} 
	 
	cout<<"\npress any key to return to menu"<<endl;
	getchar();getchar();
}
void pre_inCreat(){
	a.transferCreateBinTreeBy_Pre_In();
	traverse();
}
void post_inCreat(){
	a.transferCreateBinTreeBy_Post_In();
	traverse();
}
void Clear(){
	a.clear() ;
	cout<<"\npress any key to return to menu"<<endl;
	getchar();getchar();
}
void showstatus(){
	if(a.getRoot() ==NULL) cout<<"������Ϊ��"<<endl;
	else{
	cout<<"\n��������ǰ�������";a.PreOrder(a.getRoot() );
	cout<<"\n�����������������";a.InOrder (a.getRoot() );
	cout<<"\n�������ĺ��������";a.PostOrder (a.getRoot() );
	cout<<"\n�������Ĳ�α�����";a.LevelOrder(a.getRoot() ); 
	cout<<"\n�������ĸ�:"<<a.Height(a.getRoot() );
	cout<<"\n�������ĸ�:"<<a.getRoot()->Data ;
	cout<<"\n��ǰ�������Ľ������:"<<a.Size(a.getRoot() );
	cout<<"\n��ǰ������Ҷ�ӽ����:"<<a.leaf(a.getRoot() );
	cout<<"\n��ǰ��������Ϊ1�Ľ����:"<<a.degree1(a.getRoot());
	cout<<"\n��ǰ��������Ϊ2�Ľ����:"<<a.degree2(a.getRoot());
	cout<<"\n��ǰ����������Ľ�����ֱ���:\n";
	for(int i=1;i<=a.Height(a.getRoot() );i++ ){
		cout<<"��"<<i<<"��Ľ����Ϊ:"<<a.nodeOf_n_Layer(a.getRoot() ,i)<<endl; 
	 }
	} 
	 
	cout<<"\npress any key to return to menu"<<endl;
	getchar();getchar();
}
void getElement(){
	char e;BinTreeNode *b=new BinTreeNode;//����ǹ��BinTreeNode *b�Ͳ��У�struct����newһ���ȽϺ� 
	cout<<"������Ҫ���ҵĽ���ֵ(�˲���ǰ���Ƕ���������Ϊ��):";
	if(a.getRoot() ==NULL) cout<<"\nǿ��������"<<endl;
	else{
	cin>>e;
	(*b).Data =e; 
	if(!a.ifhavenode(b) ) cout<<"����û��ֵΪ"<<e<<"�Ľ��."<<endl;
    else{
    	cout<<"������ֵΪ"<<e<<"�Ľ��."<<endl;
    	cout<<"�ý���˫��Ϊ:"<<a.parents(b);
    	cout<<"\n�����ý���·��Ϊ:";a.pathNode(b); 
    	cout<<"\n���ĸ߶�Ϊ:"<<a.nodeHeight(b)<<endl;
		if(a.leftchild(b)==NULL) cout<<"�õ�û������."<<endl;
		else cout<<"�õ��������:"<<a.leftchild(b)->Data <<endl;
		if(a.rightchild(b)==NULL) cout<<"�õ�û���Һ���."<<endl;
		else cout<<"�õ���Һ�����:"<<a.rightchild(b)->Data <<endl;
	}
	}
		
	cout<<"\npress any key to return to menu"<<endl;
	getchar();getchar();
}
void shownodepath(){
	cout<<"�������������ڵ��·��Ϊ��"<<endl;
	a.everynodepath() ;
	cout<<"\npress any key to return to menu"<<endl;
	getchar();getchar();
}
void deletenode(){
	char e;
	cout<<"������Ҫɾ���Ľڵ�:";cin>>e;
	a.deleteNode(e);
	traverse();
	
}
void insertnode(){
	char r,n;int w;
	cout<<"�����뽫������ĸ��ڵ��ַ�:";cin>>r;
	cout<<"�����뽫��������ַ���";cin>>n;
	cout<<"�����뽫�������λ��<0-��1-��>��";cin>>w;
	a.insertNode(r,n,w);
	traverse();
}
void swaptree(){
	cout<<"����ǰ�Ķ�����Ϊ:"<<endl;
	cout<<"\n��������ǰ�������";a.PreOrder(a.getRoot() );
	cout<<"\n�����������������";a.InOrder (a.getRoot() );
	cout<<"\n�������ĺ��������";a.PostOrder (a.getRoot() );
	cout<<"\n�������Ĳ�α�����";a.LevelOrder(a.getRoot() ); 
	cout<<"\n�������ĸ�:"<<a.Height(a.getRoot() );
	cout<<"\n������Ķ�����Ϊ:"<<endl;
	a.swapTree(a.getRoot() );
	traverse(); 
}
void judgeshape(){
	if(a.isFullTree() ) cout<<"��ǰ����������������"<<endl;
	else cout<<"��ǰ������������������" <<endl;
	if(a.iscompleteTree() ) cout<<"��ǰ����������ȫ������"<<endl;
	else cout<<"��ǰ������������ȫ������"<<endl;
	if(!a.isbalanceTree(a.getRoot() ) ) cout<<"��ǰ��������ƽ�������"<<endl;
	else cout<<"��ǰ����������ƽ�������"<<endl;
	if(a.isregular() ) cout<<"��ǰ�����������������"<<endl;
	else cout<<"��ǰ�������������������"<<endl;
	cout<<"\npress any key to return to menu"<<endl;
	getchar();getchar();
}
void creatBTarray(){
	int i=1;
	a.transCreatBTarray(i); 
	traverse();
}
void showsequeuestorage(){
	int i=1;
	a.transSequeueStorage1(a.getRoot() ,i);
	a.showSequeueStorage();
	cout<<"\npress any key to return to menu"<<endl;
	getchar();getchar();
}
void treeprinting(){
	a.treePrinting();
	cout<<"\npress any key to return to menu"<<endl;
	getchar();getchar();	
}
