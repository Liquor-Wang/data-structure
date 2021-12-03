# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <iostream>

using namespace std;

typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//�������Ľ���
BiTree Create(BiTree T)
{
    char ch;    //����һ���������ݵı���
    scanf("%c",&ch);
    if (ch == '#')T = NULL;    //���ý�����
    else{
        T = (BiTree)malloc(sizeof(BiTNode));    //�����½ڵ�
        T->data = ch;
        T->lchild = Create(T->lchild);
        T->rchild = Create(T->rchild);
    }
    return T;
}

//��������ǰ��ݹ����
void Preorder(BiTree T)
{
    if (T)
    {
        printf("%c",T->data);
        Preorder(T->lchild);
        Preorder(T->rchild);
    }
}

//������������ݹ����
void zhongxv(BiTree T)
{
    if(T)
    {
        zhongxv(T->lchild);
        printf("%c",T->data);
        zhongxv(T->rchild);
    }
}

//�������ĺ���ݹ����
void houxv(BiTree T)
{
     if(T)
    {
        houxv(T->lchild);
        houxv(T->rchild);
        printf("%c",T->data);
    }
}

int main()
{
    BiTree T = (BiTree)malloc(sizeof(BiTNode));
    int sum,dep;
    cout<<"�����ַ�������#��ʾΪ��"<<endl;
    T=Create(T);
    cout<<"��������ǰ�����"<<endl;
    Preorder(T);
    cout<<"\n"<<endl;
    cout<<"���������������"<<endl;
    zhongxv(T);
    cout<<"\n"<<endl;
    cout<<"�������ĺ�������"<<endl;
    houxv(T);
}


