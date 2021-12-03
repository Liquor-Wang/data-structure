# include <iostream>
# include <cstdlib>
using namespace std;
typedef struct Lnode
{
	int data;
	struct Lnode *next;
}Lnode,*Linklist;
void Initlist(Linklist &L,int n);
void Destroy(Linklist &L);
int Listinsert(Linklist &L,int i,int e);
int Listdelete(Linklist &L,int i);
void traverse(Linklist &l);
int length = 0;
int main()
{
	Linklist L;
	int i,e;
	cout<<"��������ֵ"<<"12,25,7,42,19,38"<<endl;
	Initlist(L,6);
	cout<<"λ��1����3"<<endl;
	cin>>e;
	if(Listinsert(L,1,e)) cout<<"�������"<<endl;
	traverse(L);
	cout<<"λ��8����21"<<endl;
	cin>>e;
	Listinsert(L,8,e);
	traverse(L);
	cout<<"λ��4����15"<<endl;
	cin>>e;
	Listinsert(L,4,e);
	traverse(L);
	cout<<"λ��12����99"<<endl;
	cin>>e;
	Listinsert(L,12,e);
	traverse(L);
	cout<<"ɾ��λ��1"<<endl;
	cin>>i;
	Listdelete(L,i);
	traverse(L);
	cout<<"ɾ��λ��9"<<endl;
	cin>>i;
	Listdelete(L,i);
	traverse(L);
	cout<<"ɾ��λ��12"<<endl;
	cin>>i;
	Listdelete(L,i);
	traverse(L);
	Destroy(L);
	return 0;
}
void Initlist(Linklist &L,int n)
{
	int i;
	Lnode *p;
	L = new Lnode;
	L->next=NULL;
	for(i=0;i<n;i++){
		p=new Lnode;
		cout<<"������ֵ���"<<i+1<<endl;
		cin>>p->data;
		p->next=L->next;
		L->next=p;
		length++;
	}
	cout<<"�����ɹ�"<<endl; 
}
void Destroy(Linklist &L)
{
	Lnode *p,*s;
	p=s=L;
	while(s)
	{
		p=p->next;
		delete s;
		s=p;
	}
	cout<<"�������"<<endl;
	 
}
int Listinsert(Linklist,int i,int e)
{
	Lnode *p,*s;
	p=L;
	if(i>length+1||i<1) cout<<"λ�ò��Ϸ�"<<endl;
	else
	{
		int j = 0;
		while(p &&(j<i-1))
		{
			p=p->next;
			j++;
			
		}
		if(!p||j>i-1){
			return 0;
		}
		s=new Lnode;
		s->data=e;
		s->next=p->next;
		p->next=s;
		length++;
		return 1;
	}
}
int Listdelete(Linklist &L,int i)
{
	Lnode *p,*q;
	p=L;
	if(i>length||i<1) cout<<"λ�ò��Ϸ�"<<endl;
    int j=0;
    while ((p->next)&&(j<i-1))
    {
    	p=p->next;
    	j++;
	}
	if(!(p->next))||(j>i-1)) return 0;
	q = p->next;
	p->next=q->next;
	delete q;
	length--;
	return 1;
}
void traverse(Linklist &L)
{
	Lnode *p;
	p=L->next;
	while(p)
	{
		cout<<p->data<<end;
		p=p->next;
	}
}
