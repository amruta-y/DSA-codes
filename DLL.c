#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int a;
    struct node *prev;
    struct node *next;
}LIST;
void menu()
{
    printf("Menu:\n");
    printf("1.Insert at front\n");
    printf("2.Insert at position\n");
    printf("3.Insert at end\n");
    printf("4.Delete from front\n");
    printf("5.Delete at end\n");
    printf("6.Reverse the list\n");
    printf("7.Display\n");
    printf("8.Exit\n");
}
LIST *createlist(LIST *head,int x)
{   LIST *newnode,*p;
    newnode=(LIST*)malloc(sizeof(LIST));
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->a=x;

        if(head==NULL)
        {
            head=newnode;
            p=head;
        }
        else
        {
             newnode->prev=p;
            p->next=newnode;
            p=p->next;


        }

    return head;
}
LIST *insert_front(LIST *head,int x)
{
    LIST *newnode=(LIST*)malloc(sizeof(LIST));
    printf("Enter the data to insert at front:\n");
    scanf("%d",&newnode->a);
    newnode->next=NULL;
    newnode->prev=NULL;
    LIST *p=head;
        if(head==NULL)
        {
            head=newnode;
            p=head;
        }
        else
        {

            newnode->next=p;
            p->prev=newnode;
            head=newnode;
            newnode->prev=NULL;
        }
        return head;
}
LIST *insert_end(LIST *head,int x)
{
   LIST *newnode=(LIST*)malloc(sizeof(LIST));
    printf("Enter the data to insert at end:\n");
    scanf("%d",&newnode->a);
    newnode->next=NULL;
    newnode->prev=NULL;
    LIST *p=head;
        if(head==NULL)
        {
            head=newnode;
            p=head;
        }
        else
        {
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=newnode;
            newnode->prev=p;

        }
        return head;
}
LIST *delete_front(LIST *head)
{
     LIST *p=head;
    if(head==NULL)
    {
        printf("Empty list\n");
        return NULL;
    }
    else
    {
        head=p->next;
        p->next->prev=head;

        free(p);
    }
    return head;
}
LIST *delete_end(LIST *head)
{
    LIST *p=head;
    if(head==NULL)
    {
        printf("Empty list\n");
        return NULL;
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->prev->next=NULL;
        free(p);

    }
    return head;
}
int cnt(LIST *head)
{
    LIST *newnode=head;
    int cnt=0;
   if(newnode==NULL)
    {
        printf("No nodes are formed\n");
    }
    do
    {
        cnt++;
        newnode=newnode->next;
    }while(newnode!=NULL);
    printf("Number of nodes: %d\n",cnt);
}
LIST *insert_pos(LIST *head,int pos)
{
    LIST *newnode=(LIST*)malloc(sizeof(LIST));
    printf("Enter the data:\n");
    scanf("%d",&newnode->a);
    newnode->next=NULL;
    newnode->prev=NULL;
    LIST *p=head;
     if(pos<0||pos>cnt)
    {
        printf("Invalid position\n");
        exit(0);
    }
    else
    {
        if(pos==0)
        {
            if(cnt==0)
            {

            head=newnode;
            p=head;
            }
            else if(cnt==1)
            {
                newnode->next=p;
                p->prev=newnode;
                head-newnode;
            }
            else
            {
                 newnode->next=p;
                 p->prev=newnode;
                 head=newnode;
                 newnode->prev=NULL;
             }
          }
          else if(pos==cnt-1)
          {
              while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=newnode;
            newnode->prev=p;
          }
          else
          {
              int i;LIST *pp=head;
              for(i=0;i<pos;i++)
              {
                  pp=p;
                  p=p->next;
              }
              pp->next=newnode;
              newnode->next=p;
              p->prev=newnode;
          }
        }
        return head;
}
void reverse_list(LIST *head)
{
     LIST *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    //print in reverse
    do
    {
        printf("%d ",p->a);
        p=p->prev;
    }while(p!=NULL);
     printf("\n");
}
void display(LIST *head)
{
    LIST *p=head;
    while(p!=NULL)
    {
        printf("%d ",p->a);
        p=p->next;
    }
    printf("\n");
}
main()
{
    LIST *head,*p,*newnode;
    int wish,x,ch,pos;
    head=NULL;
    p=NULL;
    do
    {

        printf("Enter the data:\n");
        scanf("%d",&x);
        head=createlist(head,x);
        printf("Wish to continue[1/0]:\n");
        scanf("%d",&wish);


    }while(wish==1);
     do
    {
        menu();
        printf("Enter the choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
         case 1:printf("Enter the data:\n");
                scanf("%d",&x);
                head=insert_front(head,x);
                break;
         case 2:
                printf("Enter the pos:\n");
                scanf("%d",&pos);
                head=insert_pos(head,pos);
                break;
        case 3:printf("Enter the data:\n");
                scanf("%d",&x);
                head=insert_end(head,x);
                break;

        case 4:
                head=delete_front(head);
                break;

       case 5:
                head=delete_end(head);
                break;
        case 6:reverse_list(head);
                break;
        case 7:display(head);
                break;

        default:exit(0);
        }


        }while(1);


}

