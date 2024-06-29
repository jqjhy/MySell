#include <stdio.h>
#include <unistd.h>
#define MAXPATH 1000

int shell_pwd(int argc,char *argv[])
{
    if(argc==1)
    {
        char buffer[MAXPATH];
        getcwd(buffer,MAXPATH);
        printf("%s\n",buffer);
    }
    return 0;
}