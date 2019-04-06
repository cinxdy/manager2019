CC = gcc
FLAGS = -W -Wall

TARGET = manager
OBJECT = main.o menu.o user.o
D_TARGET = manager_d
D_OBJECT = main_d.o menu_d.o user_d.o

TARGET_SHELL = manager_shell
OBJECT_SHELL = main_shell.o menu_shell.o user.o
D_TARGET_SHELL = manager_shell_d
D_OBJECT_SHELL = main_shell_d.o menu_shell_d.o user_d.o

all : $(TARGET)

$(TARGET) : $(OBJECT)
	$(CC) $(FLAGS) -o $@ $^
$(D_TARGET) : $(D_OBJECT)
	$(CC) $(FLAGS) -o $@ $^

$(TARGET_SHELL) : $(OBJECT_SHELL)
	$(CC) $(FLAGS) -o $@ $^
$(D_TARGET_SHELL) : $(D_OBJECT_SHELL)
	$(CC) $(FLAGS) -o $@ $^

main_shell.o : main.c
	$(CC) -c $(FLAGS) -o $@ $^ -DSHELL

menu_shell.o : menu.c
	$(CC) -c $(FLAGS) -o $@ $^ -DSHELL

main_shell_d.o : main.c
	$(CC) -c $(FLAGS) -o $@ $^ -DSHELL -DDEBUG

menu_shell_d.o : menu.c
	$(CC) -c $(FLAGS) -o $@ $^ -DSHELL -DDEBUG

main_d.o : main.c
	$(CC) -c $(FLAGS) -o $@ $^ -DDEBUG
menu_d.o : menu.c
	$(CC) -c $(FLAGS) -o $@ $^ -DDEBUG
user_d.o : user.c
	$(CC) -c $(FLAGS) -o $@ $^ -DDEBUG

clean :
	rm *.o manager*

