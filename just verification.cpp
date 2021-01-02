//https://blog.csdn.net/foreverling/article/details/43340677
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

enum GraphStyle       // 图的类型
    {
        DG, // 有向图
        DN, // 有向网
        UDG, // 无向图
        UDN // 无向网
    };

//全局动态数组
vector<vector<string> > array;
vector<string> v;

// 定义邻接表的表结点（边结点）
class EdgeNode
{
public:
    EdgeNode(int=-1, int=0); // 默认参数的构造函数
    int adjVertex; // 该边或弧关联的顶点在图中的序号
    int weight; // 该边或弧的权值
    EdgeNode *next; // 指向下一条边或弧的指针
};

// 构造这个顶点的邻接表（用参数初始化表对数据成员初始化）
// 参数a为邻接顶点的序号；参数w为边的权值，默认权值为0
EdgeNode::EdgeNode(int a, int w):adjVertex(a), weight(w),next(NULL){}

// 定义邻接表的头结点（后面的指针全是EdgeNode即边的信息）
template <class VertexType>
class VertexNode
{
public:
    void ClearEdgeList(); // 删除这个顶点的邻接表
    bool AppendEdge(int, int=0); // 在这个顶点的邻接表中加入一条边
    bool RemoveEdge(int); // 在这个顶点的邻接表中删除一条边
    VertexType data;      // 顶点的数据信息
    EdgeNode *edgeList;   // 指向第一条依附该顶点的边的指针
};

//删除这个顶点的邻接表。清空这个顶点的邻接表中的各结点，并把头结点的edgeList值设为空。
template<class VertexType>
void VertexNode<VertexType>::ClearEdgeList()
{
    EdgeNode *p, *q;
    p=edgeList;
    while(p!=NULL) {
    q=p->next;
    delete p;//震惊！！！delete一个正常的指针
    p=q;
    }
    edgeList=NULL;
}

//在这个顶点的邻接表的最后加入一条边，若发现邻接表中已存在这条边，则返回值为false。
// 参数v 为加入边中邻接顶点序号，wgh 为加入边的权值
template<class VertexType>
bool VertexNode<VertexType>::AppendEdge(int v, int wgh)
{
    EdgeNode *p=edgeList;
    EdgeNode *q=NULL;
// 找到链接表中末结点，末结点的指针赋值给q。如果发现有一个结点的adjVex 的值与v 相同，则返回false
    while(p!=NULL){
        if(p->adjVertex==v)
            return false;
        q=p;
        p=p->next;
    }
// 在邻接表的最后加上一条边
    p=new EdgeNode(v, wgh);
    if(q==NULL)
        edgeList=p;
    else
        q->next=p;
    return true;
}

//在这个顶点的邻接表中删除一条边。在遍历邻接表过程中若发现这条边，则删除该边的表结点。
// 参数v 为要删除边的邻接顶点序号
template <class VertexType>
bool VertexNode<VertexType>::RemoveEdge(int v)
{
    EdgeNode *p=edgeList;
    EdgeNode *q=NULL;  // 遍历邻接表，如果发现这条边，则删除
    while(p!=NULL){
        if(p->adjVertex==v){
            if(p==edgeList)
                edgeList=p->next;
            else
                q->next=p->next;
            delete p;
            return true;
        }
        q=p;
        p=p->next;
    }
    return false;
}

// VertexType是顶点的数据类型，如果VertexType不是简单的数据类型，在定义VertexType时，必须重载==运算符，用于判断两个顶点数据是否相等
template <class VertexType>
class ALGraph
{
  public:
    ALGraph(int = 0, GraphStyle = UDG);
       // 构造函数，默认图的类型为无向图
    ~ALGraph();
    int LocateVertex(const VertexType&);
       // 根据顶点的数据，找到顶点在顶点表中的序号
    inline int GetNumVertices();            
        // 取得图中的顶点数目
    inline int GetNumEdges();                                  
          // 取得图中的边数
    bool GetVertex(int, VertexType&);    
        // 根据序号，取得顶点的数据
    bool SetVertex(int, const VertexType&);
         // 根据序号，设置顶点的数据
    bool InsertVertex(const VertexType&);    
         // 插入一个顶点
    bool DeleteVertex(const VertexType&);    
         // 删除一个顶点
    bool IfConnected(int,int,int& wgh);
         //判断两个点（序号表示)之间是否相连（有向为1指向2）有权值返回权值
    bool InsertEdge(const VertexType&, const VertexType&, int = 0);
         // 插入一条边
    bool DeleteEdge(const VertexType&, const VertexType&);   // 删除一条边
    int GetFirstAdjVex(int);                                  
           // 根据序号，取得顶点的第一个邻接顶点的序号
    int GetNextAdjVex(int v, int w);                          
          // 根据序号，取得v(相对于w)的下一个邻接顶点序号
    bool GetEdge(int, int,EdgeNode*&);                          
          // 根据顶点序号，取得两顶点之间的边
    void GetDetail();
         //获得顶点、边的数量，并统计每个点的度、入度与出度
    void DFSTraverse(void (*Visit)(const VertexType&));          
         // 深度优先遍历图
    void BFSTraverse(void (*Visit)(const VertexType&));          
        // 广度优先遍历图
    void DFS(void (*Visit)(const VertexType&), int);
         // 从一个顶点出发深度优先遍历图
    void Print();
         //显示存储矩阵
    void New(int,GraphStyle);
         //将数据重新输入
 private:
    VertexNode<VertexType> *vertices;   // 顶点表(此表为顺序存储结构)
    int numVertices;                                    // 顶点个数
    int numEdges;                                        // 边数
    int maxVertices;                                    // 最多可存放的顶点个数
    GraphStyle style;                                 // 图的类型
    bool *visited;                        // 在遍历时存放是否访问过的标志
};

template<class VertexType>
void ALGraph<VertexType>::New(int s,GraphStyle gs)
{
    for (int i = 0; i < numVertices; i++)
    {
        vertices[i].ClearEdgeList();
    }
    if (maxVertices != 0)
    {
        delete [] vertices;
    }
    vertices=new VertexNode<VertexType>[s];
    numVertices=0;
    numEdges=0;
    style=gs;
}

template<class VertexType>
ALGraph<VertexType>::ALGraph(int s, GraphStyle gs):numVertices(0),numEdges(0),maxVertices(s),style(gs)
{
    if (s > 0)
    {
        vertices = new VertexNode<VertexType>[s];
    }
}
 
template<class VertexType>
ALGraph<VertexType>::~ALGraph()
{
    for (int i = 0; i < numVertices; i++)
    {
        vertices[i].ClearEdgeList();
    }
    if (maxVertices != 0)
    {
        delete [] vertices;
    }
}

template<class VertexType>
inline int ALGraph<VertexType>::GetNumEdges()
{
    return numEdges;
}

template<class VertexType>
inline int ALGraph<VertexType>::GetNumVertices()
{
    return numVertices;
}

// 根据序号，取得顶点的数据
template<class VertexType> 
bool ALGraph<VertexType>::GetVertex(int v, VertexType& vex)
{
	if (v < 0 || v >= numVertices)
	{
		return false;
	}
	vex = vertices[v].data;
	return true;
}
 
template<class VertexType> 
bool ALGraph<VertexType>::SetVertex(int v, const VertexType& vex)
{
	if (v < 0 || v >= numVertices)
	{
		return false;
	}
	vertices[v].data = vex;
	return true;
}

template<class VertexType>
bool ALGraph<VertexType>::InsertVertex(const VertexType& vex)
{
    if (numVertices >= maxVertices)
    {
        return false;
    }
    for (int i = 0; i < numVertices; i++)
    {
        if (vertices[i].data == vex)
        {
            return false;
        }
    }
    vertices[numVertices].data = vex;
    vertices[numVertices++].edgeList = NULL;
    return true;
}
 
//节点遍布每一个表，都要逐一删除
template<class VertexType>
bool ALGraph<VertexType>::DeleteVertex(const VertexType& vex)
{
    int i, v;
    if ((v = LocateVertex(vex)) == -1)
    {
        return false;
    }
 
    for (int i = 0; i < numVertices; i++)
    {
        if (i != v)
        {
            if (vertices[i].RemoveEdge(v))
            {
                numEdges--;
            }
        }
    }
//大于表结点vertice[v]的存储实物空间纷纷往下调一
    vertices[v].ClearEdgeList();
    for (i = v; i < numVertices - 1; i++)
    {
        vertices[i] = vertices[i + 1];
    }
    numVertices--;
 //大于表结点vertice[v]的表结点的序号纷纷减一
    EdgeNode* p;
    for(int i = 0; i < numVertices; i++)
    {
        p = vertices[i].edgeList;
        while(p != NULL)
        {
            if (p->adjVertex >= v) //判断邻接顶点号是否大于要删除的顶点号
            {
                p->adjVertex--;
            }
            p = p->next;
        }
    }
    return true;
}

template<class VertexType>
int ALGraph<VertexType>::LocateVertex(const VertexType& vex)
{
    for (int i = 0; i < numVertices; i++)
    {
        if (vertices[i].data == vex)
        {
            return i;
        }
    }
    return -1;
}

//边的信息为两个顶点的数据信息与它的权重
//如果是有向图，默认为vex2为弧头 （即箭头所在处）
template<class VertexType>
bool ALGraph<VertexType>::InsertEdge(const VertexType& vex1,const VertexType& vex2,int wgh)
{
    int v1 = LocateVertex(vex1);
    int v2 = LocateVertex(vex2);
    if (v1 == -1 || v2 == -1)
    {
        return false;
    }
 
    vertices[v1].AppendEdge(v2,wgh);
    if (style == UDG || style == UDN)
    {
        vertices[v2].AppendEdge(v1,wgh);
    }
    numEdges++;
 
    return true;
}
 
//同上理
template<class VertexType>
bool ALGraph<VertexType>::DeleteEdge(const VertexType& vex1,const VertexType& vex2)
{
    int v1 = LocateVertex(vex1);
    int v2 = LocateVertex(vex2);
    if (v1 == -1 || v2 == -1)
    {
        return false;
    }
 
    vertices[v1].RemoveEdge(v2);
    if (style == UDG || style == UDN)
    {
        vertices[v2].RemoveEdge(v1);
    }
    numEdges--;
    return true;
}

template<class VertexType>
bool ALGraph<VertexType>::IfConnected(int v1,int v2,int& wgh)
{
    EdgeNode *p;
    p=vertices[v1].edgeList;
    while(p!=NULL)
    {
        if(p->adjVertex==v2)
        {
            wgh=p->weight;
            return true;
        }
        p=p->next;
    }
    return false;
}


//十分精简，简直完美  
template<class VertexType>
void ALGraph<VertexType>::Print()
{
    array.clear();
    for(int i=0;i<numVertices;i++)
    {
        v.clear();
        for(int j=0;j<numVertices;j++)
        {
            int w;
            if(style==UDG||style==DG)
            {
            	
            if(IfConnected(i,j,w))
            {
                v.push_back("1");
            }
            else v.push_back("0");
           
            }
            else
            {
            	
            if(IfConnected(i,j,w))
            {
                string str=std::to_string(w);
                v.push_back(str);
            }
            else v.push_back("#");
			}
        }
        array.push_back(v);
    }
    cout<<" ";
    for(int i=0;i<numVertices;i++) cout<<"  "<<vertices[i].data;
    cout<<endl;
    for(int i=0;i<numVertices;i++)
    {
        cout<<vertices[i].data<<"  ";
        for(int j=0;j<numVertices;j++)
        {
            cout<<array[i][j]<<"  ";
        }
        cout<<endl;
    }
}

template<class VertexType>
void ALGraph<VertexType>::GetDetail()
{
	cout<<"当前图共有"<<numVertices<<"个顶点，"<<numEdges<<"条边"<<endl;
	cout<<"\n图各顶点的度分别为:"<<endl;
	for(int i=0;i<numVertices;i++)
	{
		int numRU=0;
		int numCHU=0;
		int num=0;
		if(style==UDG||style==DG)
		{
			for(int j=0;j<numVertices;j++)
			{
				if(array[i][j]!="0") num++;
			}
			cout<<"顶点"<<i<<"的度为"<<num<<endl;
		}
		else
		{
			for(int j=0;j<numVertices;j++)
			{
				if(array[i][j]!="#") numCHU++;
				if(array[j][i]!="#") numRU++;
			}
			cout<<"顶点"<<i<<"的度为:"<<numRU+numCHU<<" 其中，入度为:"<<numRU<<"; 出度为："<<numCHU<<endl;
		}	
	}
 }

//用函数指针进行操作，（*Visit）传入的实参函数可自定义
template<class VertexType> 
void ALGraph<VertexType>::DFS(void (*Visit)(const VertexType&), int v)
{
	visited[v] = true;
	Visit(vertices[v].data);//进行自己想要的操作
	EdgeNode* p = vertices[v].edgeList;
	while(p != NULL)
	{
		int w = p->adjVertex;
		if (!visited[w])
		{
			DFS(Visit,w);
		}
		p = p->next;
	}
}

//写一个给（*Visit)用的函数，这里仅为打印出来
void cmp(const char& cm)
{
    cout<<cm<<" ";
}


template<class VertexType> 
void ALGraph<VertexType>::DFSTraverse(void (*Visit)(const VertexType&))
{
	int v;
	visited = new bool[numVertices];
	for (v = 0; v < numVertices; v++)
	{
		visited[v] = false;
	}
	
	for (v = 0; v < numVertices; v++)
	{
		if (!visited[v])
		{
			DFS(Visit,v);
		}
	}
	delete [] visited;
}

template<class VertexType> 
void ALGraph<VertexType>::BFSTraverse(void (*Visit)(const VertexType&))
{
	int v;
	queue<int> vertexQueue;
	EdgeNode* p;
	visited = new bool[numVertices];
	for (v = 0; v < numVertices; v++)
	{
		visited[v] = false;
	}
 
	for (v = 0; v < numVertices; v++)
	{
		if (visited[v])
		{
			continue;
		}
		visited[v] = true;
		Visit(vertices[v].data);
		vertexQueue.push(v);
 
		while (!vertexQueue.empty())
		{
			int u = vertexQueue.front();
			vertexQueue.pop();
			p = vertices[v].edgeList;
			while (p != NULL)
			{
				int w = p->adjVertex;
				if (!visited[w])
				{
					visited[w] = true;
					Visit(vertices[w].data);
					vertexQueue.push(w);
				}
				p = p->next;
			}
		}
	}
	delete [] visited;
}

// 根据顶点序号，取得两顶点之间的边
template<class VertexType>
bool ALGraph<VertexType>::GetEdge(int m,int n,EdgeNode*& p)
{
    EdgeNode *q;
    p=new EdgeNode;
    q=vertices[m].edgeList;
    while(q!=NULL)
    {
        if(q->adjVertex==n)
        {
            p->adjVertex=q->adjVertex;
            p->next=q->next;
            p->weight=q->weight;
            return true;
        }
        q=q->next;
    }
    return false;
}

// 根据序号，取得顶点的第一个邻接顶点的序号
template<class VertexType>
int ALGraph<VertexType>::GetFirstAdjVex(int i)
{
    if(i>=numVertices) return -1;
    else
    {
        if(vertices[i].edgeList==NULL) return -1;
        else return vertices[i].edgeList->adjVertex;
    }
    
}

// 根据序号，取得v(相对于w)的下一个邻接顶点序号
template<class VertexType>
int ALGraph<VertexType>::GetNextAdjVex(int v,int w)
{
    EdgeNode *p,*q;
    if(v>=numVertices) return -1;
    p=vertices[v].edgeList;q=p->next;
    while(q!=NULL)
    {
        if(p->adjVertex==w)
        {
            return q->adjVertex;
        }
        p=q;q=p->next;
    }
    return -1;
}

//返回给定数组中，非0最小元素的下标值
int Minimum(int arr[], int n)
{
	int i;
	int min = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0)
		{
			min = i;
			break;
		}
	}
	for (i = min; i < n; i++)
	{
		if (arr[i] > 0 && arr[i] < arr[min])
		{
			min = i;
		}
	}
 
	return min;
}

//--------------------------Prim算法----------start--------------------------------

//设两个辅助数组U 和lowcost，数组U 用于记录形成最小生成树过程中集合U 的顶点，数组lowcost 用于记录集合U 中每个顶点在加入集合U 时所关联的最小代价的边的权值（此时该边两个顶点中的一个在集合U 中，另一个在集合V-U 中）。爷悟，傲天也，对面带IA黄帽的小姐姐真好看，看了两三眼我直接思路如泉水般涌来，金框眼镜，笑起来真好看wuwuuwuwuw，英语书

//从第0个顶点出发，计算并打印网g的最小生成树
template<class VertexType> 
void Prim(ALGraph<VertexType>& g)
{
	if (g.GetNumVertices() == 0)
	{
		cout<<"图中无顶点"<<endl;
		return;
	}
 
	int i, j, k = 0;
    int sum=0;
	VertexType vex;
	EdgeNode* edge = NULL;
	int* lowcost = new int[g.GetNumEdges()];
	VertexType* U = new VertexType[g.GetNumVertices()];
 
	for (i = 0; i < g.GetNumVertices(); i++)
	{
		lowcost[i] = INT_MAX;
	}
 
	for (i = 0; i <g.GetNumVertices(); i++)
	{
        //所有和k顶点相连的都搞上去,初始化
		if (i != k && g.GetEdge(k,i,edge))
		{
			lowcost[i] = edge->weight;
			g.GetVertex(k,U[i]);
		}
	}
 
	g.GetVertex(k, U[k]);
	lowcost[k] = 0;
 
	for (i = 1; i < g.GetNumVertices(); i++)
	{
		k = Minimum(lowcost,g.GetNumVertices());
		g.GetVertex(k,vex);
		cout<<U[k]<<"-->"<<vex<<":"<<lowcost[k]<<endl;
        sum+=lowcost[k];
		lowcost[k] = 0;
 
		for (j = 0; j < g.GetNumVertices(); j++)
		{
			if (g.GetEdge(k,j,edge) && edge->weight < lowcost[j])
			{
				lowcost[j] = edge->weight;
				g.GetVertex(k,U[j]);
			}
		}
	}
    cout<<"生成树的总代价为:"<<sum<<endl;
	//delete [] lowcost;
	delete [] U;
}
//--------------------prim算法------------end--------


//--------------------Kruskal算法---------start--------
struct NotusedW
{
    int front;//front->back
    int back;
    int wei;
};


bool cmmp(NotusedW n1,NotusedW n2)
{
    return n1.wei<n2.wei;
}
//非连通分量m[i]=i;未用过的最小权值用notusedW类型表示
template<class VertexType> 
void Kruskal(ALGraph<VertexType>& g)
{
    int m[g.GetNumVertices()],k=0,sum=0;
    NotusedW notusedw[g.GetNumEdges()];
    for(int i=0;i<g.GetNumVertices();i++)
    {
        m[i]=i;
    }
    for(int i=0;i<g.GetNumVertices();i++)
      for(int j=0;j<g.GetNumVertices();i++)
      {
          if(array[i][j]!="#"&&array[i][j]!="0")
          {
              notusedw[k].wei=std::stoi(array[i][j]);
              notusedw[k].front=i;
              notusedw[k].back=j;
          }
      }
    /*sort(notusedw,notusedw+g.GetNumEdges(),cmmp);
    for(int i=0;i<g.GetNumEdges();i++)
    {
        if(m[notusedw[i].front]!=m[notusedw[i].back])
        {
            m[notusedw[i].front]=m[notusedw[i].back];
            cout<<notusedw[i].front<<"->"<<notusedw[i].back<<",权值:"<<notusedw[i].wei<<endl;
            sum+=notusedw[i].wei;
        }
    }*/ 
    cout<<"最小生成树的总代价为:"<<sum<<endl;
}












//---------------------Kruskal算法--------end-----------


//---------------------拓扑排序------------start----------
template<class VertexType> 
void FindInDegree(ALGraph<VertexType>& g, int inArr[])
{
	int i,v;
	for (i = 0; i < g.GetNumVertices(); i++)
	{
		inArr[i] = 0;
	}
	for (i = 0; i < g.GetNumVertices(); i++)
	{
		v = g.GetFirstAdjVex(i);
		while(v != -1)
		{
			inArr[v]++;
			v = g.GetNextAdjVex(i,v);
		}
	}
}
 
template<class VertexType> 
bool TopologicalSort(ALGraph<VertexType>& g, int* topoArr)
{
	queue<int> q; //存放度为0的顶点的序号
	VertexType vex;
	int count = 0;
	int i;
	int w;
	int* inDegree = new int[g.GetNumVertices()];
 
	FindInDegree(g,inDegree);
	for (i = 0; i < g.GetNumVertices(); i++)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);
		}
	}
 
	i = 0;
	while(!q.empty())
	{
		topoArr[i++] = q.front();
		for (w = g.GetFirstAdjVex(q.front()); w != -1;
			w = g.GetNextAdjVex(q.front(),w))
		{
			if (--inDegree[w] == 0)
			{
				q.push(w);
			}
		}
		q.pop();
		count++;
	}
 
	delete [] inDegree;
	return count == g.GetNumVertices();
}
//---------------------拓扑排序-------------end-----------------------

//---------------------Dijkstra算法---------start------------------------

struct TableEntry
{
    bool known;      //标识该顶点是否已经在集合S中
    int dist;        //是源点到该顶点的最短路径长度
    int preVertex;   //该顶点的前驱路径的终点编号
};

// 返回table(长度为n) 中known 为false 且dist 最小的元素的位置
int SmallestUnknownDistIndex(TableEntry table[], int n)
{
    int min=INT_MAX;
    int i;
    int index=-1;
    for(i=0; i<n; i++){
        if(table[i].known)
            continue;
        if(table[i].dist<min){
            min=table[i].dist;
            index=i;
         }
    }
    return index;
}

// 用Dijkstra算法求有向图g的顶点vex到其余顶点的最短路径，返回TableEntry类型数组
template <class VertexType>
TableEntry* ShortestPath_DIJ(ALGraph<VertexType>& g, VertexType vex)
{
    int i, v, w;
    int start=g.LocateVertex(vex);
    EdgeNode* edge;
    TableEntry* table=new TableEntry[g.GetNumVertices()];
    //init table
    for(i=0; i<g.GetNumVertices(); i++){
        table[i].known=false;
        table[i].dist=INT_MAX;
        table[i].preVertex=-1;
    }
    table[start].dist=0;
    //看似少了一些东西，实则没有，一切尽在掌握之中，因为a->b,a->c...第一次就把最小的dist找了出来，并把所有都赋了一步到位的值
    while(true){
        v=SmallestUnknownDistIndex(table, g.GetNumVertices());
        if(v==-1)
            break;
        table[v].known=true;
        for(w=g.GetFirstAdjVex(v); w!=-1; w=g.GetNextAdjVex(v,w)){
            if(!table[w].known){
                g.GetEdge(v, w, edge);
                if(table[v].dist+edge->weight<table[w].dist){
                    table[w].dist=table[v].dist+edge->weight;
                    table[w].preVertex=v;
                }
            }
        }
    }
    return table;
}

//-----------------Dijkstra算法-------------end---------------------------



ALGraph<char> a(20,UDG);
void showmenu();
void showmenu1();
void creatUDG();
void creatUDN();
void creatDG();
void creatDN();
void showMatrix();
void BDFS();
void insertvertex();
void insertedge();
void deletevertex();
void deleteedge();
void MinSpanningTree();
void TopologicalSorting();
void SPA_Dijkstra();
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
                creatUDG();
                break;
            case 2:
                creatUDN();
                break;
            case 3:
            	creatDG();
            	break;
            case 4:
            	creatDN();
            	break;
            case 5:
            	showMatrix();
            	break;
            case 6:
                BDFS();
                break;
            case 7:
                insertvertex();
                break;
            case 8:
                insertedge();
                break;
            case 9:
                deletevertex();
                break;
            case 10:
                deleteedge();
                break;
            case 11:
                MinSpanningTree();
                break;
            case 12:
                TopologicalSorting();
                break;
            case 13:
                SPA_Dijkstra();
                break;
        }
    }
    return 0;
}

void showmenu()
{
    cout<<"                  ZSSSSSSK           "<<endl;
    cout<<"      1.创建无向图            2.创建无向网"<<endl;
    cout<<"      3.创建有向图            4.创建有向网"<<endl;
    cout<<"      5.显示存储矩阵          6.图的遍历（BFS&DFS)"<<endl;
    cout<<"      7.插入顶点              8.插入边"<<endl;
    cout<<"      9.删除顶点              10.删除边"<<endl;
    cout<<"      11.最小生成树           12.拓扑排序"<<endl;
    cout<<"      13.最短路径（Dijkstrea）14.最短路径（Floyd）"<<endl;
    cout<<"      15.最优选址             16.退出（0切换英文菜单）"<<endl;
}

void showmenu1()
{
    cout<<"帅的人不用英文!（0换回主菜单）"<<endl;
}

void creatUDG()
{
    int dd;
    char i,ii;
    cout<<"请输入图的顶点数（若大于10则为默认构造）：";cin>>dd;
    if(dd<10)
    {
        //cout<<"依次输入点的数据";
        cout<<"建议用默认的"<<endl;
        //cout<<"请输入哪两个点之间相连：";
    }
    else
    {
        a.New(5,UDG);
        for(i='A';i<='E';i++)
        {
            if(a.InsertVertex(i)) cout<<"加入值为"<<i<<"的顶点"<<endl;
        }
        for(i='A';i<='D';i++)
        {
            ii=i+1;
            if(a.InsertEdge(i,ii))
                cout<<i<<"与"<<ii<<"相连"<<endl;
        }
        a.Print();
        
    }
    cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
}

void creatUDN()
{
    int dd;
    char i,ii;
    cout<<"请输入图的顶点数（若大于10则为默认构造）：";cin>>dd;
    if(dd<10)
    {
        cout<<"建议用默认的"<<endl;
    }
    else
    {
        a.New(5,UDN);
        for(i='A';i<='E';i++)
        {
            if(a.InsertVertex(i)) cout<<"加入值为"<<i<<"的顶点"<<endl;
        }
        for(i='A';i<='D';i++)
        {
            ii=i+1;
            int m=rand()%9+1;
            if(a.InsertEdge(i,ii,m))
                cout<<i<<"与"<<ii<<"相连"<<endl;
        }
        a.Print();
        
    }
    cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
}

void creatDG()
{
	int dd;
    char i,ii;
    cout<<"请输入图的顶点数（若大于10则为默认构造）：";cin>>dd;
    if(dd<10)
    {
        cout<<"建议用默认的"<<endl;
    }
    else
    {
        a.New(5,DG);
        for(i='A';i<='E';i++)
        {
            if(a.InsertVertex(i)) cout<<"加入值为"<<i<<"的顶点"<<endl;
        }
        for(i='A';i<='D';i++)
        {
            ii=i+1;
            if(a.InsertEdge(i,ii))
                cout<<i<<"指向"<<ii<<endl;
        }
        a.Print();
        
    }
    cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
 }
 
 void creatDN()
 {
 	int dd;
    char i,ii;
    cout<<"请输入图的顶点数（若大于10则为默认构造）：";cin>>dd;
    if(dd<10)
    {
        cout<<"建议用默认的"<<endl;
    }
    else
    {
        a.New(5,DN);
        for(i='A';i<='E';i++)
        {
            if(a.InsertVertex(i)) cout<<"加入值为"<<i<<"的顶点"<<endl;
        }
        for(i='A';i<='D';i++)
        {
            ii=i+1;
            int m=rand()%9+1;
            if(a.InsertEdge(i,ii,m))
                cout<<i<<"指向"<<ii<<endl;
        }
        a.Print();
        
   }
    cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
 }

void showMatrix()
{
	cout<<"当前图的邻接矩阵为："<<endl;
    a.Print();
	a.GetDetail();
	cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
 }

 void BDFS()
 {
	 cout<<"当前的邻接矩阵为："<<endl;
     a.Print();
     cout<<"图的深度优先遍历:";
     a.DFSTraverse(cmp);
     cout<<"\n图的广度优先遍历:";
     a.BFSTraverse(cmp);
     cout<<"\npress any key to return to the menu"<<endl;
     getchar();getchar();
 }

 void insertvertex()
 {
     char c;
     cout<<"请输入将插入的顶点信息:";
     cin>>c;
     while(!a.InsertVertex(c))
     {
         cout<<"顶点已存在，请重新输入:";
         cin>>c;
     }
     a.Print();
     cout<<"当前图共有"<<a.GetNumVertices()<<"个顶点，"<<a.GetNumEdges()<<"条边。";
     cout<<"\npress any key to return to the menu"<<endl;
     getchar();getchar();
 }

//边只有最简单的检验机制
void insertedge()
{
    char c1,c2;
    int w;
    cout<<"请输入边的起止顶点：";
    cin>>c1>>c2;
    cout<<"请输入边的权值(若是图输入1)：";
    cin>>w;
    a.InsertEdge(c1,c2,w);
    a.Print();
    cout<<"当前图共有"<<a.GetNumVertices()<<"个顶点，"<<a.GetNumEdges()<<"条边。";
    cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
}

void deletevertex()
{
    char c;
    cout<<"请输入将删除的顶点信息:";
    cin>>c;
    while(!a.DeleteVertex(c))
    {
        cout<<"顶点不存在，请重新输入:";
        cin>>c;
    }
    cout<<"顶点删除成功"<<endl;
    a.Print();
    cout<<"当前图共有"<<a.GetNumVertices()<<"个顶点，"<<a.GetNumEdges()<<"条边。";
    cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
}

void deleteedge()
{
    char c1,c2;
    cout<<"请输入边的起止顶点：";
    cin>>c1>>c2;;
    a.DeleteEdge(c1,c2);
    a.Print();
    cout<<"当前图共有"<<a.GetNumVertices()<<"个顶点，"<<a.GetNumEdges()<<"条边。";
    cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
}

void MinSpanningTree()
{
    cout<<"当前的邻接矩阵为:"<<endl;
    a.Print();
    cout<<"当前图共有"<<a.GetNumVertices()<<"个顶点，"<<a.GetNumEdges()<<"条边。"<<endl;
    cout<<"最小生成树Prim算法:"<<endl;
    Prim(a);
    cout<<"最小生成树Kruscal算法："<<endl;
    Kruskal(a);
    cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
}

void TopologicalSorting()
{
    int arr[100];
    cout<<"当前的邻接矩阵为:"<<endl;
    a.Print();
    cout<<"当前图共有"<<a.GetNumVertices()<<"个顶点，"<<a.GetNumEdges()<<"条边。"<<endl;
    if(TopologicalSort(a,arr))
    {
         cout<<"拓扑排序的结果为：";
         for(int i=0;i<a.GetNumVertices();i++)
         {
             char va;
             if(a.GetVertex(arr[i],va)) cout<<va<<" ";
             else cout<<"根据序号获得值失败"<<" ";
         }
    }
    else
    {
        cout<<"该图不为有向无环图"<<endl;
    }
    cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
}

void SPA_Dijkstra()
{
    TableEntry* ta=new TableEntry[a.GetNumVertices()];
    char vex;
    cout<<"Dijkstra算法求得顶点之间得最短路径"<<endl;
    cout<<"请输入一个顶点";
    cin>>vex;
    ta=ShortestPath_DIJ(a,vex);
    for(int i=0;i<a.GetNumVertices();i++)
    {
        if(ta[i].known==true)
        {
            char c;
            int p;
            a.GetVertex(i,c);
            cout<<vex<<"->"<<c<<" 的最短距离："<<ta[i].dist<<"   ";
            cout<<"最短路径为："<<c;
            p=ta[i].preVertex;
            while(p!=-1)
            {
                a.GetVertex(p,c);
                cout<<"-"<<c;
                p=ta[p].preVertex;
            }
        }
        else
        {
            char c;
            a.GetVertex(i,c);
            cout<<vex<<"->"<<c<<"的距离为无限大"<<endl;
        }
        cout<<endl;
    }
    cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
}

