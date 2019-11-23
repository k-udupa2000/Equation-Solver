CC=g++
CFLAGS=-Wall -g

repl:	REPL.cpp
	$(CC) $(CFLAGS) -o repl.o REPL.cpp

task1: Task_1.cpp
	$(CC) $(CFLAGS) -o task1.o Task_1.cpp

task2: Task2.cpp
	$(CC) $(CFLAGS) -o task2.o Base_Task2.cpp Task2.cpp Main_Task2.cpp

clean: 
	rm *.o