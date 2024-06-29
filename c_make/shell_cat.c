#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sh_cat(int argc, char *argv[])
{
    if(argc == 2)//灏嗘枃浠朵腑鐨勬墦鍗板埌鏍囧噯杈撳嚭
    {
        FILE *fp;
        if( !(fp = fopen( argv[1], "r" )) )
        {
            printf("No such file or directory!");
            return 1;
        }
        int c;
        while( (c = fgetc(fp) ) != EOF )
        {
            fputc(c,stdout);
        }
        fclose(fp);
    }
    if(argc==3&&strcmp(argv[1],"-n")==0)
    {
        FILE *fp;
        char StrLine[1024];
        if( !(fp = fopen( argv[2], "r" )) )
        {
            printf("No such file or directory!");
            return 1;
        }
        int c;
        int count=1;
        while( fgets(StrLine,1024,fp) != NULL )
        {
            if(count<10)
            {
                printf("   %d  %s",count++,StrLine);
            }
            else if(count<100)
            {
                printf("  %d  %s",count++,StrLine);
            }
            else if(count<1000)
            {
                printf(" %d  %s",count++,StrLine);
            }

        }
        fclose(fp);
    }
    return 0;
}
