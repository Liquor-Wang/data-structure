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
	QueuePtr front;   //ͷָ�� 
	QueuePtr rear;   //βָ�� 
}LinkQueue;

//��ʼ��
void InitQueue(LinkQueue &Q)
{
	Q.front = new QNode;
	Q.rear = Q.front;
	Q.front ->next = NULL;
 } 
 
//���
int EnQueue(LinkQueue &Q,QElemType e) 
{
	QNode *p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return 1;
}

//���� 
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

//�������
void printQueue(LinkQueue Q)
{
	printf("��ͷ->");
	QNode *p = Q.front->next;
	while (p){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("<-��β\n");
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
	printf("����������ݣ�"); 
	printQueue(Q); 
}
