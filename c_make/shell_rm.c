#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>  
#include <sys/stat.h>
#include <dirent.h> 
#include <string.h>

int remove_dir(const char *dir);

int shell_rm(int argc,char *argv[])
{
    if(argc==2)//rm 1724.txt
    {
        struct stat st;
        if(stat(argv[1],&st))
        {
            printf("No such file!\n");
            return 1;
        }
        if(!S_ISDIR(st.st_mode))
        {
            remove(argv[1]);
        }
        else
        {
            printf("rm: cannot remove '%s': Is a directory\n",argv[1]);
        }
        
    }
    else if(argc==3)//rm -r 1724目录
    {
        
        if(strcmp(argv[1],"-r")==0)
        {
            remove_dir(argv[2]);
        }
    }
    return 0;
}

int remove_dir(const char *dir)
{
    DIR *dira;
    struct dirent *dirent;
    struct stat st;
    char newName[100];
    if(stat(dir,&st))
    {
        printf("No such file or directory!\n");
        return 1;
    }

    if(!S_ISDIR(st.st_mode))
    {
        remove(dir);
    }
    else if(S_ISDIR(st.st_mode))
    {
        dira=opendir(dir);
        while((dirent=readdir(dira))!=NULL)
        {
            if(strcmp(dirent->d_name,".")==0||strcmp(dirent->d_name,"..")==0)
            {
                continue;
            }
            sprintf(newName, "%s/%s",dir,dirent->d_name);
            remove_dir(newName);
        }
        closedir(dira);
        remove(dir);
    }

    return 0;
}