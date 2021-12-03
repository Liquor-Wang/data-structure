#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;

#define MAXSIZE 100

struct Sqstack
{
	int *base,*top;
	int stacksize;
};
void Init(Sqstack &s);
void pop(Sqstack &s,int &e);
void push(Sqstack &s,int e);
void destroy(Sqstack &s);

int main()
{
	Sqstack s;
	int n,e,i,j,a[6];
	Init(s);
	cout<<"������12��25��7��42��19��38"<<endl;
	for(i=0;i<6;i++)
	{
		cin>>a[i];
	}
	cout<<"�������"<<"���վ��Ԫ��"<<endl; 
	for(i=0;i<6;i++){
		e=a[i];
		cout<<e<<"��Ӧ������Ϊ";
		while(e)
		{
			push(s,e%2);
			e=e/2;
		}
		for(j=0;s.top-s.base>0;j++)
		{
			pop(s,e);
			cout<<e<<" ";
		}
		cout<<endl;
	}
	cout<<"������"<<endl;
	destroy(s); 
	return 0;
}
void Init(Sqstack &s)
{
	s.base = new int[MAXSIZE];
	if(!s.base) exit(0);
	s.top = s.base;
	s.stacksize = MAXSIZE;
}
void push(Sqstack &s,int e)
{
	if(s.top-s.base==s.stacksize) printf("ջ��");
	else{
		*s.top++=e;
	}
 }
void pop(Sqstack &s,int &e)
{
	if(s.top==s.base) printf("ջ��");
	else {
		e=*--s.top;
	}
}
void destroy(Sqstack &s)
{
	delete s.base;
	printf("���ٳɹ�");
}
