# include <iostream>
# include <cstdlib>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <algorithm>

using namespace std;
#define MAXSIZE 8
#define ElemType int
#define Status int

typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;
//初始化 
Status InitList(SqList &L)
{
	memset(L.data,0,sizeof(L));
	L.length = 0;
	return 0;
}
//创建顺序表
bool CreateList(SqList &L,int n)
{
	if(n <0||n > MAXSIZE)
	return false;
	for (int i = 0;i < n;i++)
	{
		scanf("%d",&L.data[i]);
		L.length++;
	}
	return true;
 } 
void PrintList(SqList L)
{
	for(int i = 0;i<L.length;i++)
	{
		printf("%d ",L.data[i]);
	}
}
void Create(SqList &L)
{
	int n;
	bool flag;
	L.length = 0;
	flag = CreateList(L,n);
	if(flag)
	{
		printf("顺序表创建成功！\n");
		PrintList(L);
	}
}

//插入 
bool InsertList(SqList &L,int i,ElemType e)
{
	if(i < 1||i > L.length +1)
	{
		printf("位置无效！\n");
		return false; 
	}
	if(L.length >= MAXSIZE)
	{
		printf("存储空间已满！\n");
		return false;
	}
	for(int j=L.length;j >= i;j--)
	{
		L.data[j] = L.data[j-1];
	}
	L.data[i-1] = e;
	L.length++;
	return true;
}
void Insert(SqList &L)
{
	int place;
	int i;
	ElemType e;
	bool flag;
	for (i = 1;i < 8;){
	scanf("%d",&e);
	flag = InsertList(L,place,e);	
	}
		
	if(flag){
	printf("插入成功！\n");
	PrintList(L);
    }
}
//删除
bool ListDelete(SqList &L,int i)
{
	if(i < 1||i > L.length)
	{
		printf("位置无效！\n");
		return false; 
	}
	for (int j=i;j<=L.length-1;j++)
	{
		L.data[j-1] = L.data[j];
	}
	L.length--;
	return true;
 } 
void Delete(SqList &L)
{
	int place;
	bool flag;
	flag = ListDelete(L,place);
	if(flag){
	printf("删除成功！\n");
	PrintList(L);
}
}
int main()
{
	SqList L;
	int i;
	int n;
	Create (L);
	printf("请依次输入：12，25，7，42，19，38\n");
	for(i = 1;i < 7;i++){
		scanf("%d",&n);
	    InsertList(L,i,n);
	    if(i == 6){
	    	continue;
		}
	}
	PrintList(L);
	printf("3位置插入："); 
	InsertList(L,1,3);
	/*
	InsertList(L,8,21);
	InsertList(L,12,99);
	InsertList(L,1,3);
	*/
	
	
	return 0;
}

