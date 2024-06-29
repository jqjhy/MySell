#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int wcline(char a[100]);
int wcword(char a[100]);
int wcchar(char a[100]);


int shell_wc(int argc,char *argv[])
{
    char a1[100],a2[80];
    int i;
    FILE *p;
    if(argc == 3)
    {
        p = fopen(argv[2],"r");
        if(p == NULL)
        {
            printf("No such file or directory!\n");
            return 1;
        }
        if(strcmp(argv[1],"-l")==0)
        {
            wcline(argv[2]);
            printf("%s\n",argv[2]);
        }
        else if(strcmp(argv[1],"-c")==0)
        {
            wcchar(argv[2]);
            printf("%s\n",argv[2]);
        }
        else if(strcmp(argv[1],"-w")==0)
        {
            wcword(argv[2]);
            printf("%s\n",argv[2]);
        }
        else
        {
            printf("No command %s %s found!\n",argv[0],argv[1]);
        }
    } 
    else if(argc == 2)
    {
        p = fopen(argv[1],"r");
        if(p == NULL)
        {
            printf("No such file or directory!\n");
            return 1;
        }
        wcline(argv[1]);
        wcword(argv[1]);
        wcchar(argv[1]);
        printf("%s\n",argv[1]);
                
    }   
    else
        printf("No command found!\n");
    return 0; 
}

int wcline(char a[100])    //统计行数 
{
    char temp;
    int count = 0;
    FILE *fp = fopen(a,"r");
    temp = fgetc(fp);
    while(temp != EOF)
    {
        
        if(temp == '\n')
            count++;
        temp = fgetc(fp);
        
    }
    printf("%d ",count);
    fclose(fp);
    return 0;    
}

int wcword(char a[100])       //统计单词数 
{
    char temp;
    int count = 0;
    FILE *fp = fopen(a,"r");
    temp = fgetc(fp);
    while (temp != EOF)    
    {
        if (temp!=' '&&temp!='\n')
        {
            while (temp!=' '&&temp!='\n')
            {
                temp = fgetc(fp);    
            }
            count++;
            temp = fgetc(fp);
        }
        else
            temp = fgetc(fp);
    }
    printf("%d ",count);
    fclose(fp);
    return 0;
}

int wcchar(char a[100])     //统计字符数 
{
    char temp;
    int count = 0;
    FILE *fp = fopen(a,"r");
    temp = fgetc(fp);
    while(temp != EOF)                                                 
    {
        count++;
        temp = fgetc(fp);
    }
    printf("%d ",count);
    fclose(fp);
    return 0;
}    
