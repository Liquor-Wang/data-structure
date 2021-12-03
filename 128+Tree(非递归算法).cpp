#include<stdio.h>
#include<stdlib.h>
 
#define STACKINITSIZE 100
#define STACKINCREASESIZE 20
 
typedef char ElemType;

typedef struct tree
{
    ElemType data;
    struct tree * lchild;
    struct tree * rchild;
    unsigned int isOut;   
}TreeNode,*Tree;
 
typedef struct stack
{
    Tree * base;
    Tree * top;
    int stacksize;
}Sqstack;
 
void InitStack( Sqstack &s );
void Push( Sqstack &s, Tree e );
void GetTop( Sqstack s, Tree &e );
void Pop( Sqstack &s, Tree &e );

int StackEmpty( Sqstack s );
void CreateTree(Tree &t);
void PreOrder1(Tree t);
void InOrder1(Tree t);
void PostOrder1(Tree t);
 
int main()
{
    Tree T;
    CreateTree(T);
    printf("\n�ǵݹ���������Ľ����");
    PreOrder1(T);
    printf("\n�ǵݹ���������Ľ����");
    InOrder1(T);
    printf("\n�ǵݹ��������Ľ����");
    PostOrder1(T);
    printf("\n");
 
}
 
void InitStack( Sqstack &s )
{
    s.base = (Tree *)malloc(STACKINITSIZE*sizeof(Tree));
    if ( !s.base )
    {
    }    
    s.top = s.base;
    s.stacksize = STACKINITSIZE;
}

void Push( Sqstack &s, Tree e )
{
    if ( s.top - s.base >= s.stacksize )
    {
    s.base = (Tree *)realloc(s.base,(s.stacksize+STACKINCREASESIZE)*sizeof(Tree));
    if ( !s.base )
        {
        return ;
        }
    
     s.top = s.base + s.stacksize;
    s.stacksize += STACKINCREASESIZE;
    }
    e->isOut = 0;
    *s.top++ = e;
}
 
void GetTop( Sqstack s, Tree &e )
{
    e = *(s.top - 1);
}
 
void Pop( Sqstack &s, Tree &e )
{
    if ( s.top == s.base )
    {
    printf("ջΪ��\n");
    return ;
    }
    e = *(--s.top);
}
 
int StackEmpty( Sqstack s )
{
    if ( s.top == s.base )
    return 1;
    return 0;
}

void CreateTree(Tree &t)
{
    char ch;
    scanf("%c",&ch);
    if ( ch == '#' )
    t = NULL;
    else
    {
    t = (Tree)malloc(sizeof(TreeNode));
        if ( !t )
    {
        return ;
    }
    t->data = ch;
    CreateTree(t->lchild);
    CreateTree(t->rchild);
    }
}
 
//�ǵݹ��������
void PreOrder1(Tree t)
{
    Tree p = t;
    Sqstack s;
    InitStack(s);
 
    while ( p || !StackEmpty(s) )
    {
    if ( p )
    {
        printf("%c",p->data);
        Push(s,p);
        p = p->lchild;    
    }
    else
    {
        Pop(s,p); 
        p = p->rchild;
    }
    }
 
}

//�ǵݹ��������
void InOrder1(Tree t)
{
    Tree p = t;
    Sqstack s;
    InitStack(s);  
    
    while ( p || !StackEmpty(s) )
    {
    if ( p )
        {
        Push(s,p);
        p = p->lchild;
    }    
    else
    {
        Pop(s,p);
        printf("%c",p->data);
        p = p->rchild;
    } 
    }
}

//�ǵݹ�������
void PostOrder1(Tree t)
{
    t->isOut = 0;
    Tree p = t;
    Sqstack s;
    InitStack(s); 
 
    while ( p || !StackEmpty(s) )
    {
    if ( p )
        {
        if ( p->isOut )
            {       
            Pop(s,p);
            printf("%c",p->data);
        if (!StackEmpty(s))
                GetTop(s,p);
            else
            p = NULL;
        }
        else
        {    
            if ( (p->lchild) && (p->lchild->isOut == 1) )
            {         
            p->isOut = 1;
            p = p->rchild;   
              }
            else
            {
            Push(s,p);
            p = p->lchild;
            }          
        }
        }
        else
        {
        if (!StackEmpty(s))
            GetTop(s,p); 
        else
        p = NULL;
 
        if ( p->rchild )
        {
            p = p->rchild;
        }
        else
        {
           Pop(s,p);
            printf("%c",p->data);
            p->isOut = 1;
            if (!StackEmpty(s))
            {
            GetTop(s,p);
            if ( p->lchild == NULL )
                p->isOut = 1; 
        }
            else
            p = NULL;
        }
        
        }
    }
    
}
 
 
