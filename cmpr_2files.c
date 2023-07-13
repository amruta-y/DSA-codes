#include<stdio.h>


int cpmr(FILE *fp1,FILE *fp2)
{
     char x,y;int flag=0;
    do
    {
        x=getc(fp1);
        y=getc(fp2);
       if(x!=EOF&&y!=EOF)
        {
        if(x==y)
        {
            flag=1;
        }
        else
        {
            flag=0;
            break;
        }

    }
    else
        break;
    }while(1);
    fclose(fp1);
    fclose(fp2);
    return flag;

}
int main()
{    int x;
    FILE *fp1=fopen("input.txt","r");
    FILE *fp2=fopen("output.txt","r");

    x=cpmr(fp1,fp2);

    if(x==1)
    {
        printf("Files are same\n");
    }
    else
    {
        printf("Files are not same\n");
    }
}
