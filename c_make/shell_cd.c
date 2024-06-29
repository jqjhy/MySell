#include <stdio.h>
#include <string.h>
#include <unistd.h>

int shell_cd(int argc,char *argv[],char **r[])
{
    if(argc==2)
    {
        if(strcmp(argv[1],"-")==0)//切换到上一层目录
        {
            chdir((*r)[1]);//将当前的工作目录改变成以参数path 所指的目录
        }
        else if(strcmp(argv[1],"~")==0)//切换到家目录
        {
            chdir("/home/stu1724/");
        }
        else
        {
            if(chdir(argv[1]))
            {
                printf("No such path!\n");
                return 1;
            }
        }
    }
    if(argc==1)
    {
        chdir("/home/stu1724/");
    }
    printf("当前工作目录:%s\n",getcwd(NULL,0));
    (*r)[1]=(*r)[0];
    (*r)[0]=getcwd(NULL,0);
    return 0;
}