#include<stdio.h>
#define MAX 20
typedef struct
{
    char a[MAX];
    int top;
}STACK;
int balancedpara(char inf[20])
{
    int i,cnt1=0,cnt2=0;
    for(i=0;inf[i]!='\0';i++)
    {
        if(inf[i]=='(')
            cnt1++;
        else if(inf[i]==')')
            cnt2++;
    }
    if(cnt1==cnt2)
        return 0;
    else
        return 1;
}
int isfull(STACK p)
{
    if(p.top==MAX-1)
        return 1;
    else
        return 0;
}
int isempty(STACK p)
{
    if(p.top==-1)
        return 1;
    else
        return 0;
}
char peek(STACK p)
{
      return (p.a[p.top]);
}
char pop(STACK *p)
{   int y;
    if(isempty(*p))
    {
        printf("Stack is empty...\n");
        y=-1;
    }
    else
    {
        y=p->a[p->top--];
    }
    return y;
}
void push(STACK *p,char inf)
{
    if(isfull(*p))
    {
        printf("Stack overflow\n");
    }
    else
    {
        p->a[++p->top]=inf;
    }
}
int isoperand(char inf)
{
    if((inf>='a'&&inf<='z')||(inf>='A'&&inf<='Z'))
        return 1;

    else
        return 0;
}
int isoperator(char inf)
{
    switch(inf)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return 1;
        default: return 0;
    }
}
int getprecedence(char inf)
{
    switch(inf)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
}
void convert(char inf[20],char pof[20])
{
      STACK s;
      s.top=-1;
      int i,j=0;
      for(i=0;inf[i]!='\0';i++)
      {
          if(inf[i]=='(')
          {
              push(&s,inf[i]);
          }
          else if(isoperand(inf[i]))
          {
              pof[j++]=inf[i];
          }
          else if(isoperator(inf[i])&&isempty(s))
          {
              push(&s,inf[i]);
          }
          else if(isoperator(inf[i]))
          {
              int p1=getprecedence(inf[i]);
              int p2=getprecedence(peek(s));
              if(p1<=p2 && p2!='(')
              {
                  //pop all the elements
                  while(p1<=p2 && p2!='(')
                  {
                      int x=pop(&s);
                      pof[j++]=x;
                      p2=getprecedence(peek(s));
                  }
                  push(&s,inf[i]);
              }
              else
              {
                  push(&s,inf[i]);
              }
          }
          else if(inf[i]==')')
          {
              //pop all until (
              do
              {
                  int x=pop(&s);
                 if(x!='(')
                        pof[j++]=x;
                 else
                    break;

              }while(1);
           }
           else
           {
               printf("Invalid operator...%c\n",inf[i]);
               exit(0);
           }
      }
      for(i=s.top;i>=0;i--)
      {
          int x=pop(&s);
          if(x!='(')
                pof[j++]=x;
      }
      pof[j]='\0';
}
int main()
{

    char inf[20],pof[20];int i;
    printf("Enter the infix expression:\n");
    gets(inf);
    if(balancedpara(inf)!=0)
        exit(0);
    else
        printf("The given infix expression is balanced\n");

    convert(&inf,&pof);
    printf("Postfix expression is :\n");
    for(i=0;pof[i]!='\0';i++)
    {
        printf("%c",pof[i]);
    }
}
