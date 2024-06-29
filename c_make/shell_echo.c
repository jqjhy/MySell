#include<stdio.h>
int shell_echo(int argc,char *argv[])
{
    argc--;
    while(argc)
    {
        printf("%s%s",*++argv,(argc > 1)? " ":"");
        argc--;
    }
    printf("\n");
    return 0;
}
