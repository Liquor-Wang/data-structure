# include <stdio.h>
# include <stdlib.h>
# define MAXQSIZE 10
typedef int QElemType;

typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front;   //头指针 
	QueuePtr rear;   //尾指针 
}LinkQueue;

//初始化
void InitQueue(LinkQueue &Q)
{
	Q.front = new QNode;
	Q.rear = Q.front;
	Q.front ->next = NULL;
 } 
 
//入队
int EnQueue(LinkQueue &Q,QElemType e) 
{
	QNode *p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return 1;
}

//出队 
int DeQueue(LinkQueue &Q,QElemType &e)
{
	if(Q.rear == Q.front) return 0;
	QNode *p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear == p) Q.rear = Q.front;
	delete p;
	return 1; 
 } 

//遍历输出
void printQueue(LinkQueue Q)
{
	printf("队头->");
	QNode *p = Q.front->next;
	while (p){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("<-队尾\n");
 } 

int main()
{
	LinkQueue Q;
	int e;
	InitQueue(Q);
	for(int i=1;i<=6;i++){
		scanf("%d",&e);
		EnQueue(Q,e);
	}
	printf("输出队列内容："); 
	printQueue(Q); 
}
