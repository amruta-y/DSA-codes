#include<stdio.h>

typedef struct Computer
{
    int cid;
    char cname[20];
    float amnt;
}CMP;
void write(FILE *fp1,CMP c,int n)
{   int i;

    printf("Enter the details of a computer:\n");
    for(i=0;i<n;i++)
    {
      scanf("%d%s%f",&c.cid,c.cname,&c.amnt);
      fprintf(fp1,"%d %s %f\n",c.cid,c.cname,c.amnt);
    }
}
void read(FILE *fp1,CMP c)
{
    //CMP c[10];
    do
    {
        fscanf(fp1,"%d%s%f",&c.cid,c.cname,&c.amnt);
        if(!feof(fp1))//if not end of file then print the details
        {
            printf("%d\t%s\t%f\n",c.cid,c.cname,c.amnt);
        }
        else
            break;
    }while(1);
    //fclose(fp);
}
void search(FILE *fp1,int n,CMP c)
{
    //CMP c[10];
    int i;
    for(i=0;i<n;i++)
    {
        fscanf(fp1,"%d%s%f",&c.cid,c.cname,&c.amnt);
        if(strcmp(c.cname,"HP")==0)
            printf("%d\t%s\t%f\n",c.cid,c.cname,c.amnt);
    }
}

int main()
{   CMP c;
    int n;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    FILE *fp1=fopen("input.txt","w");
    write(fp1,c,n);
    fclose(fp1);
    fp1=fopen("input.txt","r");
    read(fp1,c);
    fclose(fp1);
    fp1=fopen("input.txt","r");
    search(fp1,n,c);

}
