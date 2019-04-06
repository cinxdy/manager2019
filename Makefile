CC = gcc
TARGET = manager
D_TARGET = manager_d
OBJECT = main.o menu.o user.o
D_OBJECT = main_d.o menu_d.o user_d.o
FLAGS = -W -Wall

all : $(TARGET) $(D_TARGET)

$(TARGET) : $(OBJECT)
	$(CC) $(FLAGS) -o $@ $^
$(D_TARGET) : $(D_OBJECT)
	$(CC) $(FLAGS) -o $@ $^
main_d.o : main.c
	$(CC) -c $(FLAGS) -o $@ $^ -DDEBUG
menu_d.o : menu.c
	$(CC) -c $(FLAGS) -o $@ $^ -DDEBUG
user_d.o : user.c
	$(CC) -c $(FLAGS) -o $@ $^ -DDEBUG

clean :
	rm *.o manager manager_d

