#include <iostream>
using namespace std;
#define Mvnum 10
struct aGraph
{
	char vex[Mvnum];
	int arc[Mvnum][Mvnum];
	int vexnum,arcnum;
};
struct Queue
{
	int *base;
	int front,rear;
};
bool visited[Mvnum]={0};
void Init(Queue &Q);
void Enqueue(Queue &Q,int e);
void Dequeue(Queue &Q,int &e);
void Delete(Queue &Q);
bool Empty(Queue Q);
void Create(aGraph &G);
void dfs(aGraph G,char v);
void bfs(aGraph G,char v);
int locate(aGraph G,char v);
void traverse(aGraph G);
int main()
{
	aGraph G;
	char v;
	Create(G);
	traverse(G);
	cout<<"输入深度遍历的首顶点名称"<<endl;
	cin>>v;
	dfs(G,v);
	cout<<endl;
	cout<<"输入广度遍历的首顶点名称"<<endl;
	cin>>v;
	bfs(G,v);
	return 0;
}
void Init(Queue &Q)
{
	Q.base=new int [Mvnum];
	Q.front=Q.rear=0;
}
void Enqueue(Queue &Q,int e)
{
	if((Q.rear+1)%Mvnum==Q.front) return;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%Mvnum;
}
void Dequeue(Queue &Q,int &e)
{
	if(Q.front==Q.rear) return;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%Mvnum;
}
void Delete(Queue &Q)
{
	delete Q.base;
}
bool Empty(Queue Q)
{
	if(Q.front==Q.rear)return 1;
	else return 0;
}
void Create(aGraph &G)
{
	int i,j,k;
	char v1,v2;
	cout<<"输入总顶点数和总边数"<<endl;
	cin>>G.vexnum>>G.arcnum;
	for(i=0;i<G.vexnum;i++)
	{
		cout<<"输入第"<<i+1<<"个顶点名称"<<endl;
		cin>>G.vex[i];
	} 
	for(i=0;i<G.vexnum;i++)
	 for(j=0;j<G.vexnum;j++)
		G.arc[i][j]=0;
	for(k=0;k<G.arcnum;k++)
		{
		 cout<<"输入边的两个顶点名称"<<endl;
		 cin>>v1>>v2;
		 i=locate(G,v1);
		 j=locate(G,v2);
		 G.arc[i][j]=1;
		 G.arc[j][i]=1;
		}
}
void dfs(aGraph G,char v)
{
	int i,j;
	i=locate(G,v);
	cout<<G.vex[i]<<" ";
	visited[i]=1;
	for(j=0;j<G.vexnum;j++)
	 if(G.arc[i][j]&&(!visited[j]))
	  dfs(G,G.vex[j]);
}
void bfs(aGraph G,char v)
{
	int i,j,u;
	Queue Q;
	for(i=0;i<Mvnum;i++)
	 visited[i]=0;
	i=locate(G,v);
	cout<<G.vex[i]<<" ";
	visited[i]=1;
	Init(Q);
	Enqueue(Q,i);
	while(!Empty(Q))
	{
		Dequeue(Q,u);
		for(i=0;i<G.vexnum;i++)
		 if(G.arc[u][i]&&(!visited[i]))
		 {
		 	cout<<G.vex[i]<<" ";
		 	visited[i]=1;
		 	Enqueue(Q,i);
		 }
	}
	Delete(Q);
}
int locate(aGraph G,char v)
{
	int i;
	for(i=0;i<G.vexnum;i++)
	 if(v==G.vex[i]) return i;
	 return -1;
}
void traverse(aGraph G)
{
	int i,j;
	for(i=0;i<G.vexnum;i++)
	 for(j=0;j<G.vexnum;j++)
	 {
	 	if(j%G.vexnum==0) cout<<endl;
	 	cout<<G.arc[i][j]<<" ";
	 }
	cout<<endl;
}
