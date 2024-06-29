#ifndef HEAD_H
#define HEAD_H

int shell_ls(int argc, char *argv[]);
int shell_cat(int argc,char *argv[]);
int shell_echo(int argc,char *argv[]);
int shell_mkdir(int argc,char *argv[]);
int shell_rm(int argc,char *argv[]);
int shell_cd(int argc,char *argv[],char **route[]);
int shell_pwd(int argc,char *argv[]);
int shell_wc(int argc,char *argv[]);
int shell_help(int argc,char *argv[]);
int shell_clist(int argc,char *argv[]);

#endif
