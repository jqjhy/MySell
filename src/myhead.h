#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include<stdio.h>
#include <string.h>
#include<stdio.h>
#include<stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

#define MAXPATH 1000

int sh_cat(int argc, char *argv[]);
int shell_cat(int argc, char *argv[]);
int shell_cd(int argc, char *argv[], char **r[]);
int shell_clist(int argc, char *argv[]);
int shell_echo(int argc, char *argv[]);
int shell_help(int argc, char *argv[]);
void shell_ls_l(char *file, struct stat st);
int shell_ls(int argc, char *argv[]);
int shell_mkdir(int argc, char *argv[]);
int shell_pwd(int argc, char *argv[]);
int shell_rm(int argc, char *argv[]);
int remove_dir(const char *dir);
int shell_wc(int argc, char *argv[]);
int wcline(char a[100]);
int wcword(char a[100]);
int wcchar(char a[100]);
//-------------------------------------------------------------------------
int sh_cat(int argc, char *argv[]) {
    if (argc == 2)//灏嗘枃浠朵腑鐨勬墦鍗板埌鏍囧噯杈撳嚭
    {
        FILE *fp;
        if (!(fp = fopen(argv[1], "r"))) {
            printf("No such file or directory!");
            return 1;
        }
        int c;
        while ((c = fgetc(fp)) != EOF) {
            fputc(c, stdout);
        }
        fclose(fp);
    }
    if (argc == 3 && strcmp(argv[1], "-n") == 0) {
        FILE *fp;
        char StrLine[1024];
        if (!(fp = fopen(argv[2], "r"))) {
            printf("No such file or directory!");
            return 1;
        }
        int c;
        int count = 1;
        while (fgets(StrLine, 1024, fp) != NULL) {
            if (count < 10) {
                printf("   %d  %s", count++, StrLine);
            } else if (count < 100) {
                printf("  %d  %s", count++, StrLine);
            } else if (count < 1000) {
                printf(" %d  %s", count++, StrLine);
            }

        }
        fclose(fp);
    }
    return 0;
}
int shell_cat(int argc, char *argv[]) {
    if (argc == 2)//灏嗘枃浠朵腑鐨勬墦鍗板埌鏍囧噯杈撳嚭
    {
        FILE *fp;
        if (!(fp = fopen(argv[1], "r"))) {
            printf("No such file or directory!");
            return 1;
        }
        int c;
        while ((c = fgetc(fp)) != EOF) {
            fputc(c, stdout);
        }
        fclose(fp);
    }
    if (argc == 3 && strcmp(argv[1], "-n") == 0) {
        FILE *fp;
        char StrLine[1024];
        if (!(fp = fopen(argv[2], "r"))) {
            printf("No such file or directory!");
            return 1;
        }
        int c;
        int count = 1;
        while (fgets(StrLine, 1024, fp) != NULL) {
            if (count < 10) {
                printf("   %d  %s", count++, StrLine);
            } else if (count < 100) {
                printf("  %d  %s", count++, StrLine);
            } else if (count < 1000) {
                printf(" %d  %s", count++, StrLine);
            }

        }
        fclose(fp);
    }
    return 0;
}
int shell_cd(int argc, char *argv[], char **r[]) {
    if (argc == 2) {
        if (strcmp(argv[1], "-") == 0)//切换到上一层目录
        {
            chdir((*r)[1]);//将当前的工作目录改变成以参数path 所指的目录
        } else if (strcmp(argv[1], "~") == 0)//切换到家目录
        {
            chdir("/home/stu1724/");
        } else {
            if (chdir(argv[1])) {
                printf("No such path!\n");
                return 1;
            }
        }
    }
    if (argc == 1) {
        chdir("/home/stu1724/");
    }
    printf("当前工作目录:%s\n", getcwd(NULL, 0));
    (*r)[1] = (*r)[0];
    (*r)[0] = getcwd(NULL, 0);
    return 0;
}

int shell_clist(int argc, char *argv[]) {
    printf("-------所有功能菜单如下---------\n");
    printf("---------------clist---------------\n");
    printf("------------ls [-a] [-l]------------\n");
    printf("---------------echo-------------\n");
    printf("--------------cat [-n]------------\n");
    printf("--------------mkdir-------------\n");
    printf("--------------rm [-r]------------\n");
    printf("----------------cd---------------\n");
    printf("---------------pwd--------------\n");
    printf("----------wc [-l] [-c] [-w]--------\n");
    printf("---------------history------------\n");
    printf("----------------exit---------------\n");
    printf("-------------help [^]-------------\n");
    return 0;

}

int shell_echo(int argc, char *argv[]) {
    argc--;
    while (argc) {
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
        argc--;
    }
    printf("\n");
    return 0;
}


int shell_help(int argc, char *argv[]) {
    if (argc == 2) {
        if (strcmp(argv[1], "ls") == 0) {
            printf("%s命令:\n", argv[1]);
            printf("ls [-a] [-l] [路径]：用来显示目标目录列表（路径只能是文件夹且路径必须以”/”结尾：例如：ls -l /home/）\n");
            printf("语法:\n");
            printf("ls（选项）（参数）\n");
            printf("[路径]：显示目标目录下的非隐藏文件名\n");
            printf("-a[路径]：显示目标目录下的所有文件名\n");
            printf("-l[路径]：显示目标目录下文件的详细信息\n");

        } else if (strcmp(argv[1], "cat") == 0) {
            printf("%s命令:\n", argv[1]);
            printf("cat [-n] [路径]：用来显示文件的内容.\n");
            printf("语法:\n");
            printf("cat(选项)(参数)\n");
            printf("[路径]：显示指定文件的内容\n");
            printf("-n[路径]：显示指定文件的内容，显示的时候在每行行首的位置加上行号\n");
        } else if (strcmp(argv[1], "mkdir") == 0) {
            printf("%s命令:\n", argv[1]);
            printf("mkdir [路径]：用来创建文件夹\n");
            printf("语法:\n");
            printf("mkdir (参数)\n");
            printf("[路径]：创建指定路径的文件夹\n");
        } else if (strcmp(argv[1], "rm") == 0) {
            printf("%s命令:\n", argv[1]);
            printf("rm -r [路径]：用来删除一个文件或者一个文件夹\n");
            printf("语法:\n");
            printf("rm (选项)(参数)\n");
            printf("[路径]：删除指定路径的文件\n");
            printf("-r [路径]：删除指定路径的文件夹\n");
        } else if (strcmp(argv[1], "wc") == 0) {
            printf("%s命令:\n", argv[1]);
            printf("wc -c -l -w [路径]：用来统计一个文件的行数，字符数和单词数\n");
            printf("语法:\n");
            printf("wc (选项)(参数)\n");
            printf("-c [路径]：统计一个文件的字符数\n");
            printf("-l [路径]：统计一个文件的行数\n");
            printf("-w [路径]：统计一个文件的单词数\n");
        } else if (strcmp(argv[1], "pwd") == 0) {
            printf("%s命令:\n", argv[1]);
            printf("pwd：用来显示当前工作路径\n");
            printf("语法:\n");
            printf("pwd\n");
            printf("注：该命令无任何参数\n");
        } else if (strcmp(argv[1], "echo") == 0) {
            printf("%s命令:\n", argv[1]);
            printf("echo [字符串(可带空格)]：用来直接输出指定的字符串\n");
            printf("语法:\n");
            printf("echo (参数)\n");
            printf("[字符串]：直接打印出指定的字符串\n");
        } else if (strcmp(argv[1], "cd") == 0) {
            printf("%s命令:\n", argv[1]);
            printf("cd [路径]|~|-：用来切换工作目录\n");
            printf("语法:\n");
            printf("cd (参数)\n");
            printf("[路径]：切换到指定路径\n");
            printf("-：切换到上一个工作目录\n");
            printf("~：切换到家目录\n");
        } else if (strcmp(argv[1], "history") == 0) {
            printf("%s命令:\n", argv[1]);
            printf("history：用来显示最新执行的前10条历史命令\n");
            printf("语法:\n");
            printf("history\n");
            printf("注：该命令无任何参数\n");
        } else if (strcmp(argv[1], "clist") == 0) {
            printf("%s命令:\n", argv[1]);
            printf("clist：用来显示所有命令\n");
            printf("语法:\n");
            printf("clist\n");
            printf("注：该命令无任何参数\n");
        } else if (strcmp(argv[1], "exit") == 0) {
            printf("%s命令:\n", argv[1]);
            printf("exit：退出Myshell\n");
            printf("语法:\n");
            printf("exit\n");
            printf("注：该命令无任何参数\n");
        } else if (strcmp(argv[1], "help") == 0) {
            printf("%s命令:\n", argv[1]);
            printf("help [命令名]：用来提命令帮助\n");
            printf("语法:\n");
            printf("help (参数)\n");
            printf("[命令名]：显示指定命令名的基本帮助信息\n");
            printf("支持命令：cat，cd，clist，echo，exit，help，ls，mkdir，pwd，rm，wc，history\n");

        } else {
            printf("No such parameter!\n");
        }
    } else {
        printf("No such command!\n");
    }

    return 0;

}


void shell_ls_l(char *file, struct stat st) {
    char limit[11] = {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '\0'};
    int link = st.st_nlink;
    char user[20];
    char group[20];
    long size = st.st_size;
    char time[50];

    if (S_ISDIR(st.st_mode)) {
        limit[0] = 'd';
    }
    if (S_ISBLK(st.st_mode)) {
        limit[0] = 'b';
    }
    if (S_ISCHR(st.st_mode)) {
        limit[0] = 'c';
    }
    if (S_ISLNK(st.st_mode)) {
        limit[0] = 'l';
    }
    if ((S_IRUSR & st.st_mode)) {
        limit[1] = 'r';
    }
    if ((S_IWUSR & st.st_mode)) {
        limit[2] = 'w';
    }
    if ((S_IXUSR & st.st_mode)) {
        limit[3] = 'x';
    }
    if ((S_IRGRP & st.st_mode)) {
        limit[4] = 'r';
    }
    if ((S_IWGRP & st.st_mode)) {
        limit[5] = 'w';
    }
    if ((S_IXGRP & st.st_mode)) {
        limit[6] = 'x';
    }
    if ((S_IROTH & st.st_mode)) {
        limit[7] = 'r';
    }
    if ((S_IWOTH & st.st_mode)) {
        limit[8] = 'w';
    }
    if ((S_IXOTH & st.st_mode)) {
        limit[9] = 'x';
    }

    strcpy(user, getpwuid(st.st_uid)->pw_name);
    strcpy(group, getgrgid(st.st_gid)->gr_name);
    char swap[50];
    strcpy(swap, ctime(&(st.st_mtime)));
    int i;
    for (i = 0; i < (strlen(swap) - 1); i++) {
        time[i] = swap[i];
    }
    time[i] = '\0';

    printf("%s", limit);
    printf("%3d", link);
    printf("%10s", user);
    printf("%10s", group);
    printf("%7ld", size);
    printf("%s", time);
    printf("%s\n", file);


}

int shell_ls(int argc, char *argv[]) {
    if (argc == 1 || argv[1][0] != '-')//*****没有参数的输出
    {
        DIR *dir;
        char str[100];
        char res[1000][100];
        struct dirent *rent;
        if (argc == 1) {
            dir = opendir(".");
        }
        if (argc == 2) {
            dir = opendir(argv[argc - 1]);
        }
        int cnt = 0;
        while ((rent = readdir(dir)) != NULL) {
            strcpy(str, rent->d_name);
            if (str[0] == '.')
                continue;
            if (!str)
                continue;
            strcpy(res[cnt++], str);
        }
        for (int i = 0; i < cnt; i++) {
            printf("%-15s", res[i]);
            if ((i + 1) % 7 == 0) {
                printf("\n");
            }
        }
        printf("\n");
        closedir(dir);
    } else if (argc == 2 || argc == 3)//*****有参数的输出**********
    {
        if (strcmp(argv[1], "-l") == 0)//********-l参数******
        {
            DIR *dir;
            char str[100];
            char res[1000][100];
            struct dirent *rent;
            if (argc == 2) {
                dir = opendir(".");
            }
            if (argc == 3) {
                dir = opendir(argv[argc - 1]);
            }
            int cnt = 0;
            while ((rent = readdir(dir)) != NULL) {
                strcpy(str, rent->d_name);
                if (str[0] == '.')
                    continue;
                if (!str)
                    continue;
                strcpy(res[cnt++], str);
            }
            printf("\n");
            for (int i = 0; i < cnt; i++) {
                struct stat st;
                char r[100];
                if (argc == 2) {
                    strcpy(r, "./");
                }
                if (argc == 3) {
                    strcpy(r, argv[argc - 1]);
                }

                strcat(r, res[i]);
                stat(r, &st);
                shell_ls_l(res[i], st);
            }
            printf("\n");
            closedir(dir);

        }
        if (strcmp(argv[1], "-a") == 0)//******-a参数*****
        {
            DIR *dir;
            char str[100];
            char res[1000][100];
            struct dirent *rent;
            if (argc == 2) {
                dir = opendir(".");
            }
            if (argc == 3) {
                dir = opendir(argv[argc - 1]);
            }
            int cnt = 0;
            while ((rent = readdir(dir)) != NULL) {
                strcpy(str, rent->d_name);
                if (!str)
                    continue;
                strcpy(res[cnt++], str);
            }
            for (int i = 0; i < cnt; i++) {
                printf("%-15s", res[i]);
                if ((i + 1) % 7 == 0) {
                    printf("\n");
                }
            }
            printf("\n");
            closedir(dir);
        }
    } else {

    }
    return 0;
}


int shell_mkdir(int argc, char *argv[]) {
    if (argc == 2) {
        mkdir(argv[1], S_IRWXU);
    } else {
        printf("The name of directory is not correct!\n");
    }

    return 0;
}

int shell_pwd(int argc, char *argv[]) {
    if (argc == 1) {
        char buffer[MAXPATH];
        getcwd(buffer, MAXPATH);
        printf("%s\n", buffer);
    }
    return 0;
}

int shell_rm(int argc, char *argv[]) {
    if (argc == 2)//rm 1724.txt
    {
        struct stat st;
        if (stat(argv[1], &st)) {
            printf("No such file!\n");
            return 1;
        }
        if (!S_ISDIR(st.st_mode)) {
            remove(argv[1]);
        } else {
            printf("rm: cannot remove '%s': Is a directory\n", argv[1]);
        }

    } else if (argc == 3)//rm -r 1724目录
    {

        if (strcmp(argv[1], "-r") == 0) {
            remove_dir(argv[2]);
        }
    }
    return 0;
}

int remove_dir(const char *dir) {
    DIR *dira;
    struct dirent *dirent;
    struct stat st;
    char newName[100];
    if (stat(dir, &st)) {
        printf("No such file or directory!\n");
        return 1;
    }

    if (!S_ISDIR(st.st_mode)) {
        remove(dir);
    } else if (S_ISDIR(st.st_mode)) {
        dira = opendir(dir);
        while ((dirent = readdir(dira)) != NULL) {
            if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
                continue;
            }
            sprintf(newName, "%s/%s", dir, dirent->d_name);
            remove_dir(newName);
        }
        closedir(dira);
        remove(dir);
    }

    return 0;
}

int shell_wc(int argc, char *argv[]) {
    char a1[100], a2[80];
    int i;
    FILE *p;
    if (argc == 3) {
        p = fopen(argv[2], "r");
        if (p == NULL) {
            printf("No such file or directory!\n");
            return 1;
        }
        if (strcmp(argv[1], "-l") == 0) {
            wcline(argv[2]);
            printf("%s\n", argv[2]);
        } else if (strcmp(argv[1], "-c") == 0) {
            wcchar(argv[2]);
            printf("%s\n", argv[2]);
        } else if (strcmp(argv[1], "-w") == 0) {
            wcword(argv[2]);
            printf("%s\n", argv[2]);
        } else {
            printf("No command %s %s found!\n", argv[0], argv[1]);
        }
    } else if (argc == 2) {
        p = fopen(argv[1], "r");
        if (p == NULL) {
            printf("No such file or directory!\n");
            return 1;
        }
        wcline(argv[1]);
        wcword(argv[1]);
        wcchar(argv[1]);
        printf("%s\n", argv[1]);

    } else
        printf("No command found!\n");
    return 0;
}

int wcline(char a[100])    //统计行数
{
    char temp;
    int count = 0;
    FILE *fp = fopen(a, "r");
    temp = fgetc(fp);
    while (temp != EOF) {

        if (temp == '\n')
            count++;
        temp = fgetc(fp);

    }
    printf("%d ", count);
    fclose(fp);
    return 0;
}

int wcword(char a[100])       //统计单词数
{
    char temp;
    int count = 0;
    FILE *fp = fopen(a, "r");
    temp = fgetc(fp);
    while (temp != EOF) {
        if (temp != ' ' && temp != '\n') {
            while (temp != ' ' && temp != '\n') {
                temp = fgetc(fp);
            }
            count++;
            temp = fgetc(fp);
        } else
            temp = fgetc(fp);
    }
    printf("%d ", count);
    fclose(fp);
    return 0;
}

int wcchar(char a[100])     //统计字符数
{
    char temp;
    int count = 0;
    FILE *fp = fopen(a, "r");
    temp = fgetc(fp);
    while (temp != EOF) {
        count++;
        temp = fgetc(fp);
    }
    printf("%d ", count);
    fclose(fp);
    return 0;
}

