#include<stdio.h>
typedef struct node
{
    int t;
    char s[20];
    struct node *next;
}LIST;
void menu()
{
    printf("Menu:\n");
    //printf("1.Create list\n");
    printf("1.Display the current list\n");
    printf("2.Split the list\n");
    printf("3.Display list 1\n");
    printf("4.Display list 2\n");
    printf("5.Exit\n");


}

//Create the List//
LIST  *createlist(LIST * head,int tn,char sn[20])
{
    LIST *newnode=(LIST*)malloc(sizeof(LIST));
    newnode->t=tn;
        strcpy(newnode->s,sn);
        newnode->next=NULL;

    if(head==NULL)
        {
            head=newnode;
        }

        else
        {
           LIST *p=head;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=newnode;
        }

    return head;
}
void display(LIST *head)
{
    LIST *p=head;
    if(head==NULL)
    {
        printf("List is empty\n");

    }
    else
    {
        while(p!=NULL)
        {
            printf("%d %s\n",p->t,p->s);
            p=p->next;
        }
    }
}
void split(LIST *head,LIST **head1,LIST **head2)
{    LIST *p=head;LIST *p1=*head1;LIST *p2=*head2;
    if(head==NULL)
    {
        printf("LIST is empty\n");

    }
    char s1[20],s2[20];
    strcpy(s1,head->s);
    while(p!=NULL)
    {
          LIST *newnode=(LIST*)malloc(sizeof(LIST));
            if(newnode==NULL)
            {
                printf("Overflow..\n");
                exit(0);
            }
            newnode->t=p->t;
            strcpy(newnode->s,p->s);
             newnode->next=NULL;

        if(strcmp(s1,p->s)==0)
        {


            if(*head1==NULL)
            {
                *head1=newnode;
                p1=newnode;
            }

            else
            {
                 p1->next=newnode;
                 p1=newnode;
            }


         }
         else
         {
              if(*head2==NULL)
            {
                *head2=newnode;
                p2=newnode;
            }

            else
            {
                 p2->next=newnode;
                 p2=newnode;
            }
         }
      p=p->next;
    }//end
}
void display1(LIST **head1,int a)
{
    LIST *x=*head1;
    if(*head1==NULL)
    {
        printf("LIST is empty\n");
    }
    else
    {    printf("LIST %d is:\n",a);
        while(x!=NULL)
        {
            printf("%d %s\n",x->t,x->s);
            x=x->next;
        }
    }
}

int main()
{
    LIST *head,**head1,**head2;
    head=NULL;
    head1=NULL;
    head2=NULL;
    int tn,wish,ch;
    char sn[20];
    head=NULL;
    do
    {   printf("Enter the track number:\n");
        scanf("%d",&tn);
        fflush(stdin);
        printf("Enter the singer name:\n");
        gets(sn);

        head=createlist(head,tn,sn);
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

         case 1:display(head);
                break;
        case 2:split(head,&head1,&head2);
                break;

        case 3:display1(&head1,1);
                break;

       case 4:display1(&head2,2);
                break;
        case 5: exit(0);

        }
}while(1);
}
