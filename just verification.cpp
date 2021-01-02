//https://blog.csdn.net/foreverling/article/details/43340677
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

enum GraphStyle       // ͼ������
    {
        DG, // ����ͼ
        DN, // ������
        UDG, // ����ͼ
        UDN // ������
    };

//ȫ�ֶ�̬����
vector<vector<string> > array;
vector<string> v;

// �����ڽӱ�ı��㣨�߽�㣩
class EdgeNode
{
public:
    EdgeNode(int=-1, int=0); // Ĭ�ϲ����Ĺ��캯��
    int adjVertex; // �ñ߻򻡹����Ķ�����ͼ�е����
    int weight; // �ñ߻򻡵�Ȩֵ
    EdgeNode *next; // ָ����һ���߻򻡵�ָ��
};

// �������������ڽӱ��ò�����ʼ��������ݳ�Ա��ʼ����
// ����aΪ�ڽӶ������ţ�����wΪ�ߵ�Ȩֵ��Ĭ��ȨֵΪ0
EdgeNode::EdgeNode(int a, int w):adjVertex(a), weight(w),next(NULL){}

// �����ڽӱ��ͷ��㣨�����ָ��ȫ��EdgeNode���ߵ���Ϣ��
template <class VertexType>
class VertexNode
{
public:
    void ClearEdgeList(); // ɾ�����������ڽӱ�
    bool AppendEdge(int, int=0); // �����������ڽӱ��м���һ����
    bool RemoveEdge(int); // �����������ڽӱ���ɾ��һ����
    VertexType data;      // �����������Ϣ
    EdgeNode *edgeList;   // ָ���һ�������ö���ıߵ�ָ��
};

//ɾ�����������ڽӱ�������������ڽӱ��еĸ���㣬����ͷ����edgeListֵ��Ϊ�ա�
template<class VertexType>
void VertexNode<VertexType>::ClearEdgeList()
{
    EdgeNode *p, *q;
    p=edgeList;
    while(p!=NULL) {
    q=p->next;
    delete p;//�𾪣�����deleteһ��������ָ��
    p=q;
    }
    edgeList=NULL;
}

//�����������ڽӱ��������һ���ߣ��������ڽӱ����Ѵ��������ߣ��򷵻�ֵΪfalse��
// ����v Ϊ��������ڽӶ�����ţ�wgh Ϊ����ߵ�Ȩֵ
template<class VertexType>
bool VertexNode<VertexType>::AppendEdge(int v, int wgh)
{
    EdgeNode *p=edgeList;
    EdgeNode *q=NULL;
// �ҵ����ӱ���ĩ��㣬ĩ����ָ�븳ֵ��q�����������һ������adjVex ��ֵ��v ��ͬ���򷵻�false
    while(p!=NULL){
        if(p->adjVertex==v)
            return false;
        q=p;
        p=p->next;
    }
// ���ڽӱ��������һ����
    p=new EdgeNode(v, wgh);
    if(q==NULL)
        edgeList=p;
    else
        q->next=p;
    return true;
}

//�����������ڽӱ���ɾ��һ���ߡ��ڱ����ڽӱ�����������������ߣ���ɾ���ñߵı��㡣
// ����v ΪҪɾ���ߵ��ڽӶ������
template <class VertexType>
bool VertexNode<VertexType>::RemoveEdge(int v)
{
    EdgeNode *p=edgeList;
    EdgeNode *q=NULL;  // �����ڽӱ�������������ߣ���ɾ��
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

// VertexType�Ƕ�����������ͣ����VertexType���Ǽ򵥵��������ͣ��ڶ���VertexTypeʱ����������==������������ж��������������Ƿ����
template <class VertexType>
class ALGraph
{
  public:
    ALGraph(int = 0, GraphStyle = UDG);
       // ���캯����Ĭ��ͼ������Ϊ����ͼ
    ~ALGraph();
    int LocateVertex(const VertexType&);
       // ���ݶ�������ݣ��ҵ������ڶ�����е����
    inline int GetNumVertices();            
        // ȡ��ͼ�еĶ�����Ŀ
    inline int GetNumEdges();                                  
          // ȡ��ͼ�еı���
    bool GetVertex(int, VertexType&);    
        // ������ţ�ȡ�ö��������
    bool SetVertex(int, const VertexType&);
         // ������ţ����ö��������
    bool InsertVertex(const VertexType&);    
         // ����һ������
    bool DeleteVertex(const VertexType&);    
         // ɾ��һ������
    bool IfConnected(int,int,int& wgh);
         //�ж������㣨��ű�ʾ)֮���Ƿ�����������Ϊ1ָ��2����Ȩֵ����Ȩֵ
    bool InsertEdge(const VertexType&, const VertexType&, int = 0);
         // ����һ����
    bool DeleteEdge(const VertexType&, const VertexType&);   // ɾ��һ����
    int GetFirstAdjVex(int);                                  
           // ������ţ�ȡ�ö���ĵ�һ���ڽӶ�������
    int GetNextAdjVex(int v, int w);                          
          // ������ţ�ȡ��v(�����w)����һ���ڽӶ������
    bool GetEdge(int, int,EdgeNode*&);                          
          // ���ݶ�����ţ�ȡ��������֮��ı�
    void GetDetail();
         //��ö��㡢�ߵ���������ͳ��ÿ����Ķȡ���������
    void DFSTraverse(void (*Visit)(const VertexType&));          
         // ������ȱ���ͼ
    void BFSTraverse(void (*Visit)(const VertexType&));          
        // ������ȱ���ͼ
    void DFS(void (*Visit)(const VertexType&), int);
         // ��һ���������������ȱ���ͼ
    void Print();
         //��ʾ�洢����
    void New(int,GraphStyle);
         //��������������
 private:
    VertexNode<VertexType> *vertices;   // �����(�˱�Ϊ˳��洢�ṹ)
    int numVertices;                                    // �������
    int numEdges;                                        // ����
    int maxVertices;                                    // ���ɴ�ŵĶ������
    GraphStyle style;                                 // ͼ������
    bool *visited;                        // �ڱ���ʱ����Ƿ���ʹ��ı�־
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

// ������ţ�ȡ�ö��������
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
 
//�ڵ�鲼ÿһ������Ҫ��һɾ��
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
//���ڱ���vertice[v]�Ĵ洢ʵ��ռ�׷����µ�һ
    vertices[v].ClearEdgeList();
    for (i = v; i < numVertices - 1; i++)
    {
        vertices[i] = vertices[i + 1];
    }
    numVertices--;
 //���ڱ���vertice[v]�ı������ŷ׷׼�һ
    EdgeNode* p;
    for(int i = 0; i < numVertices; i++)
    {
        p = vertices[i].edgeList;
        while(p != NULL)
        {
            if (p->adjVertex >= v) //�ж��ڽӶ�����Ƿ����Ҫɾ���Ķ����
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

//�ߵ���ϢΪ���������������Ϣ������Ȩ��
//���������ͼ��Ĭ��Ϊvex2Ϊ��ͷ ������ͷ���ڴ���
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
 
//ͬ����
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


//ʮ�־��򣬼�ֱ����  
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
	cout<<"��ǰͼ����"<<numVertices<<"�����㣬"<<numEdges<<"����"<<endl;
	cout<<"\nͼ������Ķȷֱ�Ϊ:"<<endl;
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
			cout<<"����"<<i<<"�Ķ�Ϊ"<<num<<endl;
		}
		else
		{
			for(int j=0;j<numVertices;j++)
			{
				if(array[i][j]!="#") numCHU++;
				if(array[j][i]!="#") numRU++;
			}
			cout<<"����"<<i<<"�Ķ�Ϊ:"<<numRU+numCHU<<" ���У����Ϊ:"<<numRU<<"; ����Ϊ��"<<numCHU<<endl;
		}	
	}
 }

//�ú���ָ����в�������*Visit�������ʵ�κ������Զ���
template<class VertexType> 
void ALGraph<VertexType>::DFS(void (*Visit)(const VertexType&), int v)
{
	visited[v] = true;
	Visit(vertices[v].data);//�����Լ���Ҫ�Ĳ���
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

//дһ������*Visit)�õĺ����������Ϊ��ӡ����
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

// ���ݶ�����ţ�ȡ��������֮��ı�
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

// ������ţ�ȡ�ö���ĵ�һ���ڽӶ�������
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

// ������ţ�ȡ��v(�����w)����һ���ڽӶ������
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

//���ظ��������У���0��СԪ�ص��±�ֵ
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

//--------------------------Prim�㷨----------start--------------------------------

//��������������U ��lowcost������U ���ڼ�¼�γ���С�����������м���U �Ķ��㣬����lowcost ���ڼ�¼����U ��ÿ�������ڼ��뼯��U ʱ����������С���۵ıߵ�Ȩֵ����ʱ�ñ����������е�һ���ڼ���U �У���һ���ڼ���V-U �У���ү�򣬰���Ҳ�������IA��ñ��С�����ÿ���������������ֱ��˼·��Ȫˮ��ӿ��������۾���Ц������ÿ�wuwuuwuwuw��Ӣ����

//�ӵ�0��������������㲢��ӡ��g����С������
template<class VertexType> 
void Prim(ALGraph<VertexType>& g)
{
	if (g.GetNumVertices() == 0)
	{
		cout<<"ͼ���޶���"<<endl;
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
        //���к�k���������Ķ�����ȥ,��ʼ��
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
    cout<<"���������ܴ���Ϊ:"<<sum<<endl;
	//delete [] lowcost;
	delete [] U;
}
//--------------------prim�㷨------------end--------


//--------------------Kruskal�㷨---------start--------
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
//����ͨ����m[i]=i;δ�ù�����СȨֵ��notusedW���ͱ�ʾ
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
            cout<<notusedw[i].front<<"->"<<notusedw[i].back<<",Ȩֵ:"<<notusedw[i].wei<<endl;
            sum+=notusedw[i].wei;
        }
    }*/ 
    cout<<"��С���������ܴ���Ϊ:"<<sum<<endl;
}












//---------------------Kruskal�㷨--------end-----------


//---------------------��������------------start----------
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
	queue<int> q; //��Ŷ�Ϊ0�Ķ�������
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
//---------------------��������-------------end-----------------------

//---------------------Dijkstra�㷨---------start------------------------

struct TableEntry
{
    bool known;      //��ʶ�ö����Ƿ��Ѿ��ڼ���S��
    int dist;        //��Դ�㵽�ö�������·������
    int preVertex;   //�ö����ǰ��·�����յ���
};

// ����table(����Ϊn) ��known Ϊfalse ��dist ��С��Ԫ�ص�λ��
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

// ��Dijkstra�㷨������ͼg�Ķ���vex�����ඥ������·��������TableEntry��������
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
    //��������һЩ������ʵ��û�У�һ�о�������֮�У���Ϊa->b,a->c...��һ�ξͰ���С��dist���˳������������ж�����һ����λ��ֵ
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

//-----------------Dijkstra�㷨-------------end---------------------------



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
            cout<<"����������������룺";
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
    cout<<"      1.��������ͼ            2.����������"<<endl;
    cout<<"      3.��������ͼ            4.����������"<<endl;
    cout<<"      5.��ʾ�洢����          6.ͼ�ı�����BFS&DFS)"<<endl;
    cout<<"      7.���붥��              8.�����"<<endl;
    cout<<"      9.ɾ������              10.ɾ����"<<endl;
    cout<<"      11.��С������           12.��������"<<endl;
    cout<<"      13.���·����Dijkstrea��14.���·����Floyd��"<<endl;
    cout<<"      15.����ѡַ             16.�˳���0�л�Ӣ�Ĳ˵���"<<endl;
}

void showmenu1()
{
    cout<<"˧���˲���Ӣ��!��0�������˵���"<<endl;
}

void creatUDG()
{
    int dd;
    char i,ii;
    cout<<"������ͼ�Ķ�������������10��ΪĬ�Ϲ��죩��";cin>>dd;
    if(dd<10)
    {
        //cout<<"��������������";
        cout<<"������Ĭ�ϵ�"<<endl;
        //cout<<"��������������֮��������";
    }
    else
    {
        a.New(5,UDG);
        for(i='A';i<='E';i++)
        {
            if(a.InsertVertex(i)) cout<<"����ֵΪ"<<i<<"�Ķ���"<<endl;
        }
        for(i='A';i<='D';i++)
        {
            ii=i+1;
            if(a.InsertEdge(i,ii))
                cout<<i<<"��"<<ii<<"����"<<endl;
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
    cout<<"������ͼ�Ķ�������������10��ΪĬ�Ϲ��죩��";cin>>dd;
    if(dd<10)
    {
        cout<<"������Ĭ�ϵ�"<<endl;
    }
    else
    {
        a.New(5,UDN);
        for(i='A';i<='E';i++)
        {
            if(a.InsertVertex(i)) cout<<"����ֵΪ"<<i<<"�Ķ���"<<endl;
        }
        for(i='A';i<='D';i++)
        {
            ii=i+1;
            int m=rand()%9+1;
            if(a.InsertEdge(i,ii,m))
                cout<<i<<"��"<<ii<<"����"<<endl;
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
    cout<<"������ͼ�Ķ�������������10��ΪĬ�Ϲ��죩��";cin>>dd;
    if(dd<10)
    {
        cout<<"������Ĭ�ϵ�"<<endl;
    }
    else
    {
        a.New(5,DG);
        for(i='A';i<='E';i++)
        {
            if(a.InsertVertex(i)) cout<<"����ֵΪ"<<i<<"�Ķ���"<<endl;
        }
        for(i='A';i<='D';i++)
        {
            ii=i+1;
            if(a.InsertEdge(i,ii))
                cout<<i<<"ָ��"<<ii<<endl;
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
    cout<<"������ͼ�Ķ�������������10��ΪĬ�Ϲ��죩��";cin>>dd;
    if(dd<10)
    {
        cout<<"������Ĭ�ϵ�"<<endl;
    }
    else
    {
        a.New(5,DN);
        for(i='A';i<='E';i++)
        {
            if(a.InsertVertex(i)) cout<<"����ֵΪ"<<i<<"�Ķ���"<<endl;
        }
        for(i='A';i<='D';i++)
        {
            ii=i+1;
            int m=rand()%9+1;
            if(a.InsertEdge(i,ii,m))
                cout<<i<<"ָ��"<<ii<<endl;
        }
        a.Print();
        
   }
    cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
 }

void showMatrix()
{
	cout<<"��ǰͼ���ڽӾ���Ϊ��"<<endl;
    a.Print();
	a.GetDetail();
	cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
 }

 void BDFS()
 {
	 cout<<"��ǰ���ڽӾ���Ϊ��"<<endl;
     a.Print();
     cout<<"ͼ��������ȱ���:";
     a.DFSTraverse(cmp);
     cout<<"\nͼ�Ĺ�����ȱ���:";
     a.BFSTraverse(cmp);
     cout<<"\npress any key to return to the menu"<<endl;
     getchar();getchar();
 }

 void insertvertex()
 {
     char c;
     cout<<"�����뽫����Ķ�����Ϣ:";
     cin>>c;
     while(!a.InsertVertex(c))
     {
         cout<<"�����Ѵ��ڣ�����������:";
         cin>>c;
     }
     a.Print();
     cout<<"��ǰͼ����"<<a.GetNumVertices()<<"�����㣬"<<a.GetNumEdges()<<"���ߡ�";
     cout<<"\npress any key to return to the menu"<<endl;
     getchar();getchar();
 }

//��ֻ����򵥵ļ������
void insertedge()
{
    char c1,c2;
    int w;
    cout<<"������ߵ���ֹ���㣺";
    cin>>c1>>c2;
    cout<<"������ߵ�Ȩֵ(����ͼ����1)��";
    cin>>w;
    a.InsertEdge(c1,c2,w);
    a.Print();
    cout<<"��ǰͼ����"<<a.GetNumVertices()<<"�����㣬"<<a.GetNumEdges()<<"���ߡ�";
    cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
}

void deletevertex()
{
    char c;
    cout<<"�����뽫ɾ���Ķ�����Ϣ:";
    cin>>c;
    while(!a.DeleteVertex(c))
    {
        cout<<"���㲻���ڣ�����������:";
        cin>>c;
    }
    cout<<"����ɾ���ɹ�"<<endl;
    a.Print();
    cout<<"��ǰͼ����"<<a.GetNumVertices()<<"�����㣬"<<a.GetNumEdges()<<"���ߡ�";
    cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
}

void deleteedge()
{
    char c1,c2;
    cout<<"������ߵ���ֹ���㣺";
    cin>>c1>>c2;;
    a.DeleteEdge(c1,c2);
    a.Print();
    cout<<"��ǰͼ����"<<a.GetNumVertices()<<"�����㣬"<<a.GetNumEdges()<<"���ߡ�";
    cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
}

void MinSpanningTree()
{
    cout<<"��ǰ���ڽӾ���Ϊ:"<<endl;
    a.Print();
    cout<<"��ǰͼ����"<<a.GetNumVertices()<<"�����㣬"<<a.GetNumEdges()<<"���ߡ�"<<endl;
    cout<<"��С������Prim�㷨:"<<endl;
    Prim(a);
    cout<<"��С������Kruscal�㷨��"<<endl;
    Kruskal(a);
    cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
}

void TopologicalSorting()
{
    int arr[100];
    cout<<"��ǰ���ڽӾ���Ϊ:"<<endl;
    a.Print();
    cout<<"��ǰͼ����"<<a.GetNumVertices()<<"�����㣬"<<a.GetNumEdges()<<"���ߡ�"<<endl;
    if(TopologicalSort(a,arr))
    {
         cout<<"��������Ľ��Ϊ��";
         for(int i=0;i<a.GetNumVertices();i++)
         {
             char va;
             if(a.GetVertex(arr[i],va)) cout<<va<<" ";
             else cout<<"������Ż��ֵʧ��"<<" ";
         }
    }
    else
    {
        cout<<"��ͼ��Ϊ�����޻�ͼ"<<endl;
    }
    cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
}

void SPA_Dijkstra()
{
    TableEntry* ta=new TableEntry[a.GetNumVertices()];
    char vex;
    cout<<"Dijkstra�㷨��ö���֮������·��"<<endl;
    cout<<"������һ������";
    cin>>vex;
    ta=ShortestPath_DIJ(a,vex);
    for(int i=0;i<a.GetNumVertices();i++)
    {
        if(ta[i].known==true)
        {
            char c;
            int p;
            a.GetVertex(i,c);
            cout<<vex<<"->"<<c<<" ����̾��룺"<<ta[i].dist<<"   ";
            cout<<"���·��Ϊ��"<<c;
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
            cout<<vex<<"->"<<c<<"�ľ���Ϊ���޴�"<<endl;
        }
        cout<<endl;
    }
    cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
}

