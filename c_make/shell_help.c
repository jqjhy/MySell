#include<stdio.h>
#include <string.h>

int shell_help(int argc,char *argv[])
{
    if(argc==2)
    {
        if(strcmp(argv[1],"ls")==0)
        {
            printf("%s命令:\n",argv[1]);
            printf("ls [-a] [-l] [路径]：用来显示目标目录列表（路径只能是文件夹且路径必须以”/”结尾：例如：ls -l /home/）\n");
            printf("语法:\n");
            printf("ls（选项）（参数）\n");
            printf("[路径]：显示目标目录下的非隐藏文件名\n");
            printf("-a[路径]：显示目标目录下的所有文件名\n");
            printf("-l[路径]：显示目标目录下文件的详细信息\n");

        }
        else if(strcmp(argv[1],"cat")==0)
        {
            printf("%s命令:\n",argv[1]);
            printf("cat [-n] [路径]：用来显示文件的内容.\n");
            printf("语法:\n");
            printf("cat(选项)(参数)\n");
            printf("[路径]：显示指定文件的内容\n");
            printf("-n[路径]：显示指定文件的内容，显示的时候在每行行首的位置加上行号\n");
        }
        else if(strcmp(argv[1],"mkdir")==0)
        {
            printf("%s命令:\n",argv[1]);
            printf("mkdir [路径]：用来创建文件夹\n");
            printf("语法:\n");
            printf("mkdir (参数)\n");
            printf("[路径]：创建指定路径的文件夹\n");
        }
        else if(strcmp(argv[1],"rm")==0)
        {
            printf("%s命令:\n",argv[1]);
            printf("rm -r [路径]：用来删除一个文件或者一个文件夹\n");
            printf("语法:\n");
            printf("rm (选项)(参数)\n");
            printf("[路径]：删除指定路径的文件\n");
            printf("-r [路径]：删除指定路径的文件夹\n");
        }
        else if(strcmp(argv[1],"wc")==0)
        {
            printf("%s命令:\n",argv[1]);
            printf("wc -c -l -w [路径]：用来统计一个文件的行数，字符数和单词数\n");
            printf("语法:\n");
            printf("wc (选项)(参数)\n");
            printf("-c [路径]：统计一个文件的字符数\n");
            printf("-l [路径]：统计一个文件的行数\n");
            printf("-w [路径]：统计一个文件的单词数\n");
        }
        else if(strcmp(argv[1],"pwd")==0)
        {
            printf("%s命令:\n",argv[1]);
            printf("pwd：用来显示当前工作路径\n");
            printf("语法:\n");
            printf("pwd\n");
            printf("注：该命令无任何参数\n");
        }
        else if(strcmp(argv[1],"echo")==0)
        {
            printf("%s命令:\n",argv[1]);
            printf("echo [字符串(可带空格)]：用来直接输出指定的字符串\n");
            printf("语法:\n");
            printf("echo (参数)\n");
            printf("[字符串]：直接打印出指定的字符串\n");
        }
        else if(strcmp(argv[1],"cd")==0)
        {
            printf("%s命令:\n",argv[1]);
            printf("cd [路径]|~|-：用来切换工作目录\n");
            printf("语法:\n");
            printf("cd (参数)\n");
            printf("[路径]：切换到指定路径\n");
            printf("-：切换到上一个工作目录\n");
            printf("~：切换到家目录\n");
        }
        else if(strcmp(argv[1],"history")==0)
        {
            printf("%s命令:\n",argv[1]);
            printf("history：用来显示最新执行的前10条历史命令\n");
            printf("语法:\n");
            printf("history\n");
            printf("注：该命令无任何参数\n");
        }
        else if(strcmp(argv[1],"clist")==0)
        {
            printf("%s命令:\n",argv[1]);
            printf("clist：用来显示所有命令\n");
            printf("语法:\n");
            printf("clist\n");
            printf("注：该命令无任何参数\n");
        }
        else if(strcmp(argv[1],"exit")==0)
        {
            printf("%s命令:\n",argv[1]);
            printf("exit：退出Myshell\n");
            printf("语法:\n");
            printf("exit\n");
            printf("注：该命令无任何参数\n");
        }

        else if(strcmp(argv[1],"help")==0)
        {
            printf("%s命令:\n",argv[1]);
            printf("help [命令名]：用来提命令帮助\n");
            printf("语法:\n");
            printf("help (参数)\n");
            printf("[命令名]：显示指定命令名的基本帮助信息\n");
            printf("支持命令：cat，cd，clist，echo，exit，help，ls，mkdir，pwd，rm，wc，history\n");
            
        }
         else
       {
        printf("No such parameter!\n");   
       }
    }
    else
    {
        printf("No such command!\n");   
    }
    
    return 0;
    
}