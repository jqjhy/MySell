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

void shell_ls_l(char *file,struct stat st)
{
    char limit[11]={'-','-','-','-','-','-','-','-','-','-','\0'};
    int link=st.st_nlink;
    char user[20];
    char group[20];
    long size=st.st_size;
    char time[50];

    if(S_ISDIR(st.st_mode))
    {
        limit[0]='d';
    }
    if(S_ISBLK(st.st_mode))
    {
        limit[0]='b';
    }
    if(S_ISCHR(st.st_mode))
    {
        limit[0]='c';   
    }
    if(S_ISLNK(st.st_mode))
    {
        limit[0]='l';
    }
    if((S_IRUSR & st.st_mode))
    {
        limit[1]='r';
    }
    if((S_IWUSR & st.st_mode))
    {
        limit[2]='w';
    }
    if((S_IXUSR & st.st_mode))
    {
        limit[3]='x';
    }
    if((S_IRGRP & st.st_mode))
    {
        limit[4]='r';
    }
    if((S_IWGRP & st.st_mode))
    {
        limit[5]='w';
    }
    if((S_IXGRP & st.st_mode))
    {
        limit[6]='x';
    }
    if((S_IROTH & st.st_mode))
    {
        limit[7]='r';
    }
    if((S_IWOTH & st.st_mode))
    {
        limit[8]='w';
    }
    if((S_IXOTH & st.st_mode))
    {
        limit[9]='x';
    }

    strcpy(user,getpwuid(st.st_uid)->pw_name);
    strcpy(group,getgrgid(st.st_gid)->gr_name);
    char swap[50];
    strcpy(swap,ctime(&(st.st_mtime)));
    int i;
    for( i=0;i<(strlen(swap)-1);i++)
    {
        time[i]=swap[i];
    }
    time[i]='\0';

    printf("%s",limit);
    printf("%3d",link);
    printf("%10s",user);
    printf("%10s",group);
    printf("%7ld",size);
    printf("%s",time);
    printf("%s\n",file);


}

int shell_ls(int argc, char *argv[]){
    if(argc==1||argv[1][0]!='-')//*****没有参数的输出
    {
        DIR *dir;
        char str[100];
        char res[1000][100];
        struct dirent *rent;
        if(argc==1)
        {
            dir = opendir(".");
        }
        if(argc==2)
        {
            dir = opendir(argv[argc-1]);
        }
        int cnt = 0;
        while((rent=readdir(dir))!=NULL){
            strcpy(str, rent->d_name);
            if(str[0] == '.')
                continue;
            if(!str)
                continue;
            strcpy(res[cnt++],str);
        }
        for(int i=0; i<cnt; i++)
        {
            printf("%-15s",res[i]);
            if((i+1)%7==0)
            {
                printf("\n");
            }
        }
        printf("\n");
        closedir(dir);
    }
    else if(argc==2||argc==3)//*****有参数的输出**********
    {
        if(strcmp(argv[1],"-l")==0)//********-l参数******
        {
            DIR *dir;
            char str[100];
            char res[1000][100];
            struct dirent *rent;
            if(argc==2)
            {
                dir = opendir(".");
            }
            if(argc==3)
            {
                dir = opendir(argv[argc-1]);
            }
            int cnt = 0;
            while((rent=readdir(dir))!=NULL){
                strcpy(str, rent->d_name);
                if(str[0] == '.')
                    continue;
                if(!str)
                    continue;
                strcpy(res[cnt++],str);
            }
            printf("\n");
            for(int i=0; i<cnt; i++)
            {
                struct stat st;
                char r[100];
                if(argc==2)
                {
                    strcpy(r,"./");
                }
                if(argc==3)
                {
                    strcpy(r,argv[argc-1]);
                }
                
                strcat(r,res[i]);
                stat(r,&st);
                shell_ls_l(res[i],st);
            }
            printf("\n");
            closedir(dir);
            
        }
        if(strcmp(argv[1],"-a")==0)//******-a参数*****
        {
            DIR *dir;
            char str[100];
            char res[1000][100];
            struct dirent *rent;
            if(argc==2)
            {
                dir = opendir(".");
            }
            if(argc==3)
            {
                dir = opendir(argv[argc-1]);
            }
            int cnt = 0;
            while((rent=readdir(dir))!=NULL){
                strcpy(str, rent->d_name);
                if(!str)
                    continue;
                strcpy(res[cnt++],str);
            }
            for(int i=0; i<cnt; i++)
            {
                printf("%-15s",res[i]);
                if((i+1)%7==0)
                {
                    printf("\n");
                }
            }
            printf("\n");
            closedir(dir);
        }
    }
    else
    {

    }
    return 0;
}
