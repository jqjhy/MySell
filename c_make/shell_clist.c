#include<stdio.h>
#include <string.h>

int shell_clist(int argc,char *argv[])
{	
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