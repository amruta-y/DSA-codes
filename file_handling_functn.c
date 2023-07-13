#include<stdio.h>
#include<stdio.h>

void write(char *filename)
{
    FILE *fp=fopen(filename,"w");
    char ch;
    printf("Enter the data, CTRL Z to exit\n");
    do
    {
        ch=getchar();
        if(ch!=EOF)
        {
            fputc(ch,fp);
        }
        else
        {
            break;
        }
    }while(1);
    fclose(fp);
    printf("File saved...\n");
}

void read(char *filename)
{
    FILE *fp=fopen(filename,"r");
    char ch;
    do
    {
        ch=fgetc(fp);
        if(ch!=EOF)
        {
            printf("%c",ch);
        }
        else
        {
            break;
        }
    }while(1);
    printf("\n");
    fclose(fp);
}
int count_char(char *filename)
{    int cnt=0;
     FILE *fp=fopen(filename,"r");
    char ch;
    do
    {
        ch=fgetc(fp);
        if(ch!=EOF)
        {
            cnt++;
        }
        else
        {
            break;
        }
    }while(1);
    fclose(fp);
    return cnt;
}

int main()
{   int c;
    char a[50];
    printf("Enter the filename:");
    gets(a);
    write(a);
    read(a);
    c=count_char(a);
    printf("No of characters read from a file:%d",c);
}
