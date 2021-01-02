//https://www.cnblogs.com/WindSun/p/10859055.html
#include<iostream>
#include <stack>
#include <queue>
#include<cstring>
#include<cmath>
using namespace std;

struct SqBiTree
{
  char *base;   //存储空间基址
  int nodeNum;      //二叉树中结点数
};	

//二叉链表结点结构
struct BinTreeNode
{
    char Data;
    BinTreeNode *leftChild , *rightChild ;
}; 	 

class BinaryTree
{
	private:
		BinTreeNode *root; //根节点
        char RefValue;//数据输入停止的标志，需要一个构造函数
		char b[1000];//顺序存储的一个数组 
		
    public:
    	//==========二叉树构造与析构==========//

    //构造函数
    BinaryTree() : root(NULL) {}
    


    //析构函数


//==========二叉树的创建==========//


     //顺序存储的次序创建二叉树
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
	 
	 //调用 顺序存储的次序创建二叉树
	 void transCreatBTarray(int i){
	 	cout<<"请输入顺序存储序列<如：~ABD#EI###F#CG##>:(先输入一个~)";cin>>b;
	 	CreatBTarray(root,i);
	 }
	 
	  
    //前序遍历创建二叉树(前序遍历的应用)，用#表示空结点
    void CreateBinTree_PreOrder(BinTreeNode* &subTree)//&&&&&&&&引用不能丢 
    {
        char item;
        if (cin >> item)
        {
        	
            if(item !='#')//是if，而不能是while 
            {
            	subTree=new BinTreeNode;
                subTree->Data=item;
                CreateBinTree_PreOrder(subTree->leftChild);    //递归创建左子树
                CreateBinTree_PreOrder(subTree->rightChild);    //递归创建右子树
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


    //使用先序遍历和中序遍历创建二叉树
    void CreateBinTreeBy_Pre_In(BinTreeNode* &cur, const char *pre, const char *in, int n)
    {
        if (n <= 0)
        {
            cur = NULL;
            return;
        }
        int k = 0;
        while (pre[0] != in[k]) //再中序中找到pre[0]的值
        {
            k++;
        }
        cur = new BinTreeNode; //创建结点
        cur->Data=in[k];
        CreateBinTreeBy_Pre_In(cur->leftChild, pre + 1, in, k);
        CreateBinTreeBy_Pre_In(cur->rightChild, pre + k + 1, in + k + 1, n - k - 1);
    }
    void transferCreateBinTreeBy_Pre_In(){
    	char first[100]={'A','B','D','H','L','E','K','C','F','G'};char in[100]={'H','L','D','B','E','K','A','F','C','G'};
	    int sum=0,i=0;
	    cout<<"前序遍历次序<如：ABDHLEKCFG>:";cin>>first;
	    cout<<"\n中序遍历次序<如：HLDBEKAFCG>:";cin>>in; 
	    while(in[i]!='\0'){
		sum++;i++;
	   }
	cout<<"\n二叉树创建成功！\n";
	root=new BinTreeNode;
	root->Data =first[0];
	CreateBinTreeBy_Pre_In( root , first, in, sum);
	}
	
	
    //使用后序遍历和中序遍历创建二叉树
    void CreateBinTreeBy_Post_In(BinTreeNode *&cur, const char *post, const char *in, int n)
    {
        if (n == 0)
        {
            cur = NULL;
            return;
        }

        char r = *(post + n - 1);    //根结点值
        cur = new BinTreeNode; //构造当前结点
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
	    cout<<"中序遍历次序<如：ABDEIFCGH>:";cin>>in;
	    cout<<"\n后序遍历次序<如：ABDEIFCGH>:";cin>>post; 
	    while(in[i]!='\0'){
		sum++;i++;
	   }
	cout<<"\n二叉树创建成功！\n";
	root=new BinTreeNode;
	root->Data =post[sum-1];
	CreateBinTreeBy_Pre_In( root , post, in, sum);
	}

//==========二叉树的遍历==========//

    //先序遍历（递归）
    void PreOrder(BinTreeNode *subTree)
    {
        if (subTree != NULL)
        {
            cout << subTree->Data << " ";
            PreOrder(subTree->leftChild);
            PreOrder(subTree->rightChild);
        }
    }

    //中序遍历(递归)
    void InOrder(BinTreeNode *subTree)
    {
        if (subTree != NULL)
        {
            InOrder(subTree->leftChild);
            cout << subTree->Data << " ";
            InOrder(subTree->rightChild);
        }
    }

    //后序遍历（递归）
    void PostOrder(BinTreeNode *subTree)
    {
        if (subTree != NULL)
        {
            PostOrder(subTree->leftChild);
            PostOrder(subTree->rightChild);
            cout << subTree->Data << " ";
        }
    }


    //二叉树的层次遍历(非递归遍历)
   // 按层次顺序访问二叉树的处理需要利用一个队列。在访问二又树的某一层结点时，把下一层结点指针预先记忆在队列中，利用队列安排逐层访问的次序。因此，每当访问一个结点时，将它的子女依次加到队列的队尾，然后再访问已在队列队头的结点。这样可以实现二又树结点的按层访问。
    void LevelOrder(BinTreeNode *p)
    {
        queue<BinTreeNode*> Q;
        Q.push(p);    //根节点进队
        BinTreeNode* t;
        while (!Q.empty())
        {
            t = Q.front();    //t先记住队头,再将队头出队
            Q.pop();
            cout << t->Data << " ";    //访问队头元素的数据

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
    
    //求二叉树第N层的结点
    /*
求二叉树第k层的节点数
递归方式步骤：
给定根节点p：
如果p为空，或者层数k_Level <= 0，则为空树或者不合要求，则返回0；
如果p不为空，且此时层数 k_Level==1，则此时p为第K层节点之一，则返回1；
如果p不为空，且此时层数 k_Level > 1，则此时需要求root左子树（k_Level - 1 ）层节点数和proot右子树（k_Level-1）层节点数；

/*递归实现求二叉树第k层的节点数*/
	int nodeOf_n_Layer(BinTreeNode *p,int k){
	   if(p==NULL||k<=0) return 0;
	   if(p!=NULL &&k==1) return 1;
	   return (nodeOf_n_Layer(p->leftChild ,k-1)+nodeOf_n_Layer(p->rightChild ,k-1));
	}
	 

//==========获取结点==========//

    //获取二叉树的根节点
    BinTreeNode *getRoot() const
    {
        return root;
    }


//==========成员函数==========//

    //销毁函数
    void Destroy() ;
    
    //删除某个结点
	void deleteNode(char e){
		cout<<"二叉树结点"<<e<<"已删除."<<endl;
		queue<BinTreeNode*> Q;
        Q.push(root);    //根节点进队
        BinTreeNode* t=new BinTreeNode;
        int flag=1;
        if(root->Data ==e) root=NULL;
        else{
        	while (flag)
           {
            t = Q.front();    //t先记住队头,再将队头出队
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
	
    
    //计算二叉树以subTree为根的结点的个数
    int Size(BinTreeNode *subTree) 
    {
        if (subTree == NULL)    //递归结束，空树结点个数为0
        {
            return 0;
        }
        return 1 + Size(subTree->leftChild) + Size(subTree->rightChild);
    }
    
    //计算二叉树以subTree为根的树叶的个数
    int leaf(BinTreeNode *subTree) 
    {
    	if (subTree == NULL)    //递归结束，空树结点个数为0
        {
            return 0;
        }
        else if (subTree->leftChild  == NULL && subTree->rightChild ==NULL)    //递归结束，空树结点个数+1 （注意！！！要用else if，用if不行，会于前面的有矛盾） 
        {
            return 1;
        }
        
        return leaf(subTree->leftChild) + leaf(subTree->rightChild);
    }
    
    //计算二叉树以subTree为根的度为1结点的个数
    int degree1(BinTreeNode *subTree) 
    {
        if (subTree == NULL)    //递归结束
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
    
    //计算二叉树以subTree为根的度为2结点的个数
    int degree2(BinTreeNode *subTree) 
    {
        if (subTree == NULL)    //递归结束
        {
            return 0;
        }
        if(subTree->leftChild!=NULL && subTree->rightChild!=NULL) return  1 + degree2(subTree->leftChild) + degree2(subTree->rightChild);
        return degree2(subTree->leftChild) + degree2(subTree->rightChild);
    }
    
    //清空二叉树
	void clear(){
		root=NULL;
		cout<<"二叉树已清空"<<endl;
	} 



    //判断二叉树是否为空
    bool Empty() { return (root == NULL) ? true : false; }

    //计算二叉数以subTree为根的高度
    int Height(BinTreeNode *subTree)
    {
        if (subTree == NULL)    //递归结束，空树高度为0
        {
            return 0;
        }
        int i = Height(subTree->leftChild);
        int j = Height(subTree->rightChild);
        return i < j ? j + 1 : i + 1;
    }
    
    //计算某结点的高度(需要先保证有这个点） 
	int nodeHeight(BinTreeNode *p){
		int i=1;char m=p->Data ;
		while(p->Data !=root->Data ){
		     p=parents(p);
		     i++;
		}
		p->Data =m;
		return i;
	} 
    
    //判断是否有这个结点 
	int ifhavenode(BinTreeNode *p){
		queue<BinTreeNode*> Q;
		Q.push(root);
		BinTreeNode* t;
        while (!Q.empty())
        {
            t = Q.front();    //t先记住队头,再将队头出队
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
	
	//获得某结点的所有信息(感jio还是分开好） 
	/*void getinformation(BinTreeNode *p){
		quene<BinTreeNode*> Q;
		BinTreeNode *t=root;
		int h=1;int flag=1;
		while(flag){
			Q.push(t);
			if(p->Data ==Q.front()->Data){
				flag=0;
				cout<<"结点的高度为"<<h;
			}
		}
	}*/
    
    //求结点的双亲(懒得来改进了，最好要返回的是双亲的指针而不是Data，这样后面会方便很多） 
    //改改改！！！！！ 
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
	
	//求结点的路径（需要先判断是否存在）
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
	
	//求所有节点的路径
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
	
	//求结点的左孩子
	BinTreeNode *leftchild(BinTreeNode* p) {
		queue<BinTreeNode*> Q;
        Q.push(root);    //根节点进队
        BinTreeNode* t;
        while (!Q.empty())
        {
            t = Q.front();    //t先记住队头,再将队头出队
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
	
	//求结点的右孩子
	BinTreeNode *rightchild(BinTreeNode* p) {
		queue<BinTreeNode*> Q;
        Q.push(root);    //根节点进队
        BinTreeNode* t;
        while (!Q.empty())
        {
            t = Q.front();    //t先记住队头,再将队头出队
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
	
	//求结点的左兄弟
	BinTreeNode *leftbrother(BinTreeNode *p){
		queue<BinTreeNode*> Q;
        Q.push(root);         //根节点进队
        BinTreeNode* t=new BinTreeNode;
        while (!Q.empty())
        {
            t = Q.front();    //t先记住队头,再将队头出队
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
	
	//求结点的右兄弟
 	BinTreeNode *rightbrother(BinTreeNode *p){
		queue<BinTreeNode*> Q;
        Q.push(root);    //根节点进队
        BinTreeNode* t=new BinTreeNode;
        while (!Q.empty())
        {
            t = Q.front();    //t先记住队头,再将队头出队
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
	
	//插入某个结点
	void insertNode(char r,char n,int w){
		cout<<"二叉树插入成功"<<endl;
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
	
	//交换p后面的左右子树（全部交换）
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
	
	//满二叉树的判断(可以从p之后判断）（1表示是） 
	int isFullTree(){
		if(pow(2,Height(root))-1==Size(root)) return 1;
		else return 0;
	} 
	
	//完全二叉树的判断(先搞完链式转顺序存储） (1表示是） 
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
	
	//平衡二叉树的判断（0表示是）
	int isbalanceTree(BinTreeNode *p){
		if(p==NULL) return 0;
		else if(abs(Height(p->leftChild )-Height(p->rightChild ))>1) return 1;
		else return isbalanceTree(p->leftChild )+isbalanceTree(p->rightChild );
	} 
	
	//正则二叉树的判断（1表示是）
	int isregular(){
		if(degree1(root)==0) return 1;
		else return 0;
	} 
	
   //清空顺序存储数组b(顺序存储结构a中所有元素置为‘#’（表示空结点）)
    void clearb(){
    	memset(b,'#',sizeof(b));
	}
	 
	
	// 链式转顺序存储(先清空) 
	void transSequeueStorage(BinTreeNode *p,int i){
		if(p!=NULL){
			b[i]=p->Data ;
		    transSequeueStorage(p->leftChild ,2*i);
		    transSequeueStorage(p->rightChild ,2*i+1);
		}
	}
	
	
	//合并以上两个
	void  transSequeueStorage1(BinTreeNode *p,int i){
		clearb();
		transSequeueStorage(p,i);
	}

	
	//输出顺序存储的二叉树
	void showSequeueStorage(){
	    int k=pow(2,Height(root));
	    for(int i=1;i<k;i++) cout<<b[i];
	}
	
	
	//打印树型
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
			cout<<"输入错误，请重新输入：";
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
BinaryTree a;
void creat1(){
	BinTreeNode *b;
	cout<<"前序次序输入二叉树各结点的数据<用#表示空指针,如ABD#EI##F##CG#H####>"<<endl;
	a.transfer1();
	cout<<"\n二叉树创建成功！";
	cout<<"\n二叉树的前序遍历：";a.PreOrder(a.getRoot() );
	cout<<"\n二叉树的中序遍历：";a.InOrder (a.getRoot() );
	cout<<"\n二叉树的后序遍历：";a.PostOrder (a.getRoot() );
	cout<<"\n二叉树的层次遍历：";a.LevelOrder(a.getRoot() ); 
	cout<<"\n二叉树的高:"<<a.Height(a.getRoot() ); 
	cout<<"\npress any key to return to menu"<<endl;
	getchar();getchar();
}
void traverse(){
	if(a.getRoot() ==NULL) cout<<"二叉树为空"<<endl;
	else{
	cout<<"\n二叉树的前序遍历：";a.PreOrder(a.getRoot() );
	cout<<"\n二叉树的中序遍历：";a.InOrder (a.getRoot() );
	cout<<"\n二叉树的后序遍历：";a.PostOrder (a.getRoot() );
	cout<<"\n二叉树的层次遍历：";a.LevelOrder(a.getRoot() ); 
	cout<<"\n二叉树的高:"<<a.Height(a.getRoot() );
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
	if(a.getRoot() ==NULL) cout<<"二叉树为空"<<endl;
	else{
	cout<<"\n二叉树的前序遍历：";a.PreOrder(a.getRoot() );
	cout<<"\n二叉树的中序遍历：";a.InOrder (a.getRoot() );
	cout<<"\n二叉树的后序遍历：";a.PostOrder (a.getRoot() );
	cout<<"\n二叉树的层次遍历：";a.LevelOrder(a.getRoot() ); 
	cout<<"\n二叉树的高:"<<a.Height(a.getRoot() );
	cout<<"\n二叉树的根:"<<a.getRoot()->Data ;
	cout<<"\n当前二叉树的结点数有:"<<a.Size(a.getRoot() );
	cout<<"\n当前二叉树叶子结点数:"<<a.leaf(a.getRoot() );
	cout<<"\n当前二叉树度为1的结点数:"<<a.degree1(a.getRoot());
	cout<<"\n当前二叉树度为2的结点数:"<<a.degree2(a.getRoot());
	cout<<"\n当前二叉树各层的结点数分别是:\n";
	for(int i=1;i<=a.Height(a.getRoot() );i++ ){
		cout<<"第"<<i<<"层的结点数为:"<<a.nodeOf_n_Layer(a.getRoot() ,i)<<endl; 
	 }
	} 
	 
	cout<<"\npress any key to return to menu"<<endl;
	getchar();getchar();
}
void getElement(){
	char e;BinTreeNode *b=new BinTreeNode;//如果是光光BinTreeNode *b就不行，struct还是new一个比较好 
	cout<<"请输入要查找的结点的值(此操作前提是二叉树不能为空):";
	if(a.getRoot() ==NULL) cout<<"\n强制跳过！"<<endl;
	else{
	cin>>e;
	(*b).Data =e; 
	if(!a.ifhavenode(b) ) cout<<"树中没有值为"<<e<<"的结点."<<endl;
    else{
    	cout<<"树中有值为"<<e<<"的结点."<<endl;
    	cout<<"该结点的双亲为:"<<a.parents(b);
    	cout<<"\n根到该结点的路径为:";a.pathNode(b); 
    	cout<<"\n结点的高度为:"<<a.nodeHeight(b)<<endl;
		if(a.leftchild(b)==NULL) cout<<"该点没有左孩子."<<endl;
		else cout<<"该点的左孩子是:"<<a.leftchild(b)->Data <<endl;
		if(a.rightchild(b)==NULL) cout<<"该点没有右孩子."<<endl;
		else cout<<"该点的右孩子是:"<<a.rightchild(b)->Data <<endl;
	}
	}
		
	cout<<"\npress any key to return to menu"<<endl;
	getchar();getchar();
}
void shownodepath(){
	cout<<"二叉树根到各节点的路径为："<<endl;
	a.everynodepath() ;
	cout<<"\npress any key to return to menu"<<endl;
	getchar();getchar();
}
void deletenode(){
	char e;
	cout<<"请输入要删除的节点:";cin>>e;
	a.deleteNode(e);
	traverse();
	
}
void insertnode(){
	char r,n;int w;
	cout<<"请输入将插入结点的父节点字符:";cin>>r;
	cout<<"请输入将插入结点的字符：";cin>>n;
	cout<<"请输入将插入结点的位置<0-左；1-右>：";cin>>w;
	a.insertNode(r,n,w);
	traverse();
}
void swaptree(){
	cout<<"交换前的二叉树为:"<<endl;
	cout<<"\n二叉树的前序遍历：";a.PreOrder(a.getRoot() );
	cout<<"\n二叉树的中序遍历：";a.InOrder (a.getRoot() );
	cout<<"\n二叉树的后序遍历：";a.PostOrder (a.getRoot() );
	cout<<"\n二叉树的层次遍历：";a.LevelOrder(a.getRoot() ); 
	cout<<"\n二叉树的高:"<<a.Height(a.getRoot() );
	cout<<"\n交换后的二叉树为:"<<endl;
	a.swapTree(a.getRoot() );
	traverse(); 
}
void judgeshape(){
	if(a.isFullTree() ) cout<<"当前二叉树是满二叉树"<<endl;
	else cout<<"当前二叉树不是满二叉树" <<endl;
	if(a.iscompleteTree() ) cout<<"当前二叉树是完全二叉树"<<endl;
	else cout<<"当前二叉树不是完全二叉树"<<endl;
	if(!a.isbalanceTree(a.getRoot() ) ) cout<<"当前二叉树是平衡二叉树"<<endl;
	else cout<<"当前二叉树不是平衡二叉树"<<endl;
	if(a.isregular() ) cout<<"当前二叉树是正则二叉树"<<endl;
	else cout<<"当前二叉树不是正则二叉树"<<endl;
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
