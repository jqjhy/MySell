objects = head.h shell_cat.o shell_echo.c shell_ls.o shell_pwd.o shell_rm.o  shell_cd.o shell_help.o shell_mkdir.o shell_wc.o  shell_clist.c Main.c 
1724_mysh:$(objects)
	gcc -o 1724_mysh $(objects)
%.o: %.c
	gcc -c $<
clean:
	rm *.o
	rm 1724_mysh
