#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>  
#include <sys/stat.h>
int shell_mkdir(int argc,char *argv[])
{
    if(argc==2)
    {
        mkdir(argv[1],S_IRWXU);
    }
    else
    {
        printf("The name of directory is not correct!\n");
    }
    
    return 0;
}