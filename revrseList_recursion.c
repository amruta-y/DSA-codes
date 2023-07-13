#include<stdio.h>
typedef struct node
{
    int data;
    char n[20];

    struct node *next;
}LIST;
void insert_front(LIST *head,LIST *newnode,LIST *p)
{
    p=head;
    newnode=(LIST*)malloc(sizeof(LIST));
     printf("Enter the new data:\n");
        scanf("%d",&newnode->data);
        if(head==NULL)
        {
            head=newnode;

        }
        else
           {
               head=newnode;
             newnode->next=p;
           }
}
void display(LIST *head)
{
    LIST *p=head;
    printf("The list is:\n");
    if(p==NULL)
    {
        printf("empty list\n");
    }
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}

void revDisplay(LIST *head)
{


   if(head->next!=NULL)
      {

       revDisplay(head->next);
      }
    printf("%d ",head->data);


}
int main()
{
    LIST *head,*newnode,*p;
    head=NULL;

    int wish;
    do
    {
        newnode=(LIST*)malloc(sizeof(LIST));
        printf("Enter the data:\n");
        scanf("%d",&newnode->data);
        gets(newnode->n);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            p=newnode;
        }
        else
        {
            p->next=newnode;
            p=newnode;
        }
        printf("Wish to continue[1/0];\n");
        scanf("%d",&wish);

    }while(wish==1);
    display(head);
     revDisplay(head);
}
