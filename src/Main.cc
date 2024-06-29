#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "myhead.h"//实现功能的函数在里面

char *argv[50];//用来存放命令和参数
int argc = 0;//用于记录命令和参数的总个数，空格分开
int falg;//用于无限循环
char **route;//用于存放路径
char hist[10][100];//用来存储每行命令的内容
int count = 0;//历史个数

void do_exec(void);//执行命令

void analysis(char *str, int size)//将命令分开并保存在argc和argv[]中
{
    if (str == NULL)
        return;
    int i = 0;
    char *ptr = str;
    while (str[size - 1] == ' ') {//找是否为空格
        str[size - 1] = '\0';
        size--;
    }

    while (i < size - 1) {
        if ((str[i] == ' ') && (i != 0) && (str[i + 1] != ' ')) {
            str[i] = '\0';
            i++;
            argv[argc++] = ptr;
            ptr = str + i;
        } else
            i++;
    }

    argv[argc++] = ptr;
    argv[argc] = NULL;

    do_exec();
}

void do_exec(void)//进行命令匹配
{
    if (strcmp(argv[0], "ls") == 0)//ls命令
    {
        shell_ls(argc, argv);
    } else if (strcmp(argv[0], "echo") == 0)//echo命令
    {
        shell_echo(argc, argv);
    } else if (strcmp(argv[0], "cat") == 0)//cat命令
    {
        shell_cat(argc, argv);
    } else if (strcmp(argv[0], "mkdir") == 0)//mkdir命令
    {
        shell_mkdir(argc, argv);
    } else if (strcmp(argv[0], "rm") == 0)//rm命令
    {
        shell_rm(argc, argv);
    } else if (strcmp(argv[0], "cd") == 0)//cd命令
    {
        char ***a = &route;
        shell_cd(argc, argv, a);
    } else if (strcmp(argv[0], "pwd") == 0)//pwd命令
    {
        shell_pwd(argc, argv);
    } else if (strcmp(argv[0], "wc") == 0)//wc命令
    {
        shell_wc(argc, argv);
    } else if (strcmp(argv[0], "help") == 0)//help命令
    {
        shell_help(argc, argv);
    } else if (strcmp(argv[0], "history") == 0)//history命令
    {
        for (int i = 0; i < count; i++) {
            printf("%d: %s\n", i + 1, hist[i]);
        }
    } else if (strcmp(argv[0], "clist") == 0)//clist命令
    {
        shell_clist(argc, argv);
    } else if (strcmp(argv[0], "exit") == 0)//exit命令
    {
        printf("-----------------------goodbye-----------------------------\n");
        exit(0);
    } else {
        printf("No such command!\n");
    }

}

int main(void) {
    int falg = 0;
    route = (char **) malloc(sizeof(char *) * 2);//为二维数组分配3行
    for (int i = 0; i < 2; ++i) {//为每列分配4个大小空间
        route[i] = (char *) malloc(sizeof(char) * 100);
    }
    strcpy(route[0], getcwd(NULL, 0));//把后面的复制到前面
    strcpy(route[1], getcwd(NULL, 0));//getcwd()当前工作目录的绝对路径复制
    while (1)//无限循环
    {
        int len = 0;
        char buff[1024] = {0};
        printf("MyShell>");
        scanf("%[^\n]%*c", buff);//表示读入一行字符串。
        if (count < 10) {
            strcpy(hist[count], buff);//将命令放入整行中，最多放10个历史
            count++;
        } else//最近的10个命令
        {
            for (int i = 0; i < 10; i++) {
                strcpy(hist[i], hist[i + 1]);//命令整行对前一行进行覆盖
            }
            strcpy(hist[9], buff);
        }
        analysis(buff, strlen(buff));//这里面调用了do_exec();
        argc = 0;
    }
    return 0;
}