# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <iostream>

using namespace std;

typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//二叉树的建立
BiTree Create(BiTree T)
{
    char ch;    //设置一个接受数据的变量
    scanf("%c",&ch);
    if (ch == '#')T = NULL;    //设置结束符
    else{
        T = (BiTree)malloc(sizeof(BiTNode));    //生成新节点
        T->data = ch;
        T->lchild = Create(T->lchild);
        T->rchild = Create(T->rchild);
    }
    return T;
}

//二叉树的前序递归遍历
void Preorder(BiTree T)
{
    if (T)
    {
        printf("%c",T->data);
        Preorder(T->lchild);
        Preorder(T->rchild);
    }
}

//二叉树的中序递归遍历
void zhongxv(BiTree T)
{
    if(T)
    {
        zhongxv(T->lchild);
        printf("%c",T->data);
        zhongxv(T->rchild);
    }
}

//二叉树的后序递归遍历
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
    cout<<"输入字符，输入#表示为空"<<endl;
    T=Create(T);
    cout<<"二叉树的前序遍历"<<endl;
    Preorder(T);
    cout<<"\n"<<endl;
    cout<<"二叉树的中序遍历"<<endl;
    zhongxv(T);
    cout<<"\n"<<endl;
    cout<<"二叉树的后续遍历"<<endl;
    houxv(T);
}


