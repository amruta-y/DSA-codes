#include<stdio.h>
typedef struct node
{
    int a;
    struct node *next;

}LIST;

int main()
{
    LIST *newnode,*p,*pp,*head;
    int wish;
    head=NULL;

    do
    {
        newnode=(LIST*)malloc(sizeof(LIST));
        newnode->next=NULL;
        printf("Enter the data:\n");
        scanf("%d",&newnode->a);
        if(head==NULL)
        {
            head=newnode;
            newnode->next=head;
            p=head;
        }
        else
        {
            p->next=newnode;
            newnode->next=head;
            p=newnode;
        }
        printf("Wish to continue[1/0];\n");
        scanf("%d",&wish);

    }while(wish==1);
    p=head;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        do
        {
            printf("%d ",p->a);
            p=p->next;
        }while(p!=head);
        printf("\n");
    }
    //insert at front//
  /*  p=head;

    newnode=(LIST*)malloc(sizeof(LIST));
     printf("Enter the data:\n");
    scanf("%d",&newnode->a);


      p=head;
      do
      {
          p=p->next;

     }while(p->next!=head);
     p->next=newnode;
     newnode->next=head;
     head=newnode;


        p=head;
        if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        do
        {
            printf("%d ",p->a);
            p=p->next;
        }while(p!=head);
        printf("\n");


     }
     //insert at end//
     p=head;
     newnode=(LIST*)malloc(sizeof(LIST));
     printf("Enter the data:\n");
    scanf("%d",&newnode->a);
     if(head==NULL)
     {
         head=newnode;
         newnode->next=head;
     }
     else
     {
         do
         {
             p=p->next;

         }while(p->next!=head);
         p->next=newnode;
         newnode->next=head;
     }

        p=head;
        if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        do
        {
            printf("%d ",p->a);
            p=p->next;
        }while(p!=head);
        printf("\n");

     }*/
   /*  //deletion at front
     p=head;
     LIST *pp=head;
     if(head==NULL)
     {
         printf("LIST is empty\n");

     }
     else if(head->next==head)
     {
         p=head;
         head=NULL;
         free(p);
         printf("The list is deleted\n");

     }
     else
     {

         do
         {
             p=p->next;
         }while(p->next!=head);
         p->next=head->next;
         head=head->next;
         free(pp);
     }

    p=head;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        do
        {
            printf("%d ",p->a);
            p=p->next;
        }while(p!=head);
        printf("\n");


     }
     //deletion at end

     p=head;
     pp=head;
     if(head==NULL)
     {
         printf("LIST is empty\n");

     }
     else if(head->next==head)
     {
         p=head;
         head=NULL;
         free(p);
         printf("The list is deleted\n");
         exit(0);
     }
     else
     {

         do
         {    pp=p;
             p=p->next;
         }while(p->next!=head);
         pp->next=head;

         free(p);
     }

    p=head;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        do
        {
            printf("%d ",p->a);
            p=p->next;
        }while(p!=head);
        printf("\n");


     }*/
     //insert at position//
    / int pos;
     newnode=head;
    int cnt=0;
   if(newnode==NULL)
    {
        printf("No nodes are formed\n");
    }
    do
    {
        cnt++;
        newnode=newnode->next;
    }while(newnode!=head);


    printf("Number of nodes: %d\n",cnt);
     printf("Enter the position:\n");
     scanf("%d",&pos);
      newnode=(LIST*)malloc(sizeof(LIST));
     printf("Enter the data:\n");
    scanf("%d",&newnode->a);
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
                newnode->next=head;
            }
            else if(cnt==1)
            {
                newnode->next=head;
                head=newnode;
                head->next->next=newnode;
            }
            else
            {
                p=head;
                do
                {
                    p=p->next;
                }while(p->next!=head);
                newnode->next=head;
                head=newnode;
                p->next=head;
            }
        }

        else if(pos==cnt-1)
        {     do
                {
                   p=p->next;

                }while(p->next!=head);
                    p->next=newnode;
                   newnode->next=head;

        }
        else
        {
                int i;
                p=head;LIST *pp=head;
                for(i=0;i<pos;i++)
                {    pp=p;
                    p=p->next;
                }
                pp->next=newnode;
                newnode->next=p;

        }

    }


    //display//
     p=head;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        do
        {
            printf("%d ",p->a);
            p=p->next;
        }while(p!=head);


     }*/
     //deletion based on position//
      int pos;

     newnode=head;
  int cnt=0;
   if(newnode==NULL)
    {
        printf("No nodes are formed\n");
    }
    do
    {
        cnt++;
        newnode=newnode->next;
    }while(newnode!=head);


    printf("Number of nodes: %d\n",cnt);
    printf("Enter the position:\n");
    scanf("%d",&pos);

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
                printf("NO nodes to delete\n");
            }
            else if(cnt==1)
            {
                free(head);
                head=NULL;

            }
            else
            {
                pp=head;
                p=head;
                do
                {
                    p=p->next;
                }while(p->next!=head);
                head=pp->next;
                p->next=head;
                free(pp);
            }
        }
        else if(pos==cnt-1)
        {    pp=head;
             p=head;
             do
         {    pp=p;
             p=p->next;
         }while(p->next!=head);
         pp->next=head;
         free(p);
        }
        else
        {    pp=head;
        int i;
             p=head;
            for(i=0;i<pos;i++)
            {   pp=p;
                p=p->next;
            }
            pp->next=p->next;
            free(p);
        }
    }
     p=head;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        do
        {
            printf("%d ",p->a);
            p=p->next;
        }while(p!=head);
        printf("\n");


     }


}
