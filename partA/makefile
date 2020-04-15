.PHONY: all

all: task1 task2 task3 lib

task1: main1_1.c hello_ariel.c hello_ariel.h
	   gcc -o hello1 hello_ariel.c main1_1.c

task2: hello_ariel.h main1_1.c lib
	   gcc main1_1.c ./lib.so -o hello2

task3: hello_ariel.h main1_3.c lib
	   gcc main1_3.c -fPIC -ldl -o hello3

lib: hello_ariel.h hello_ariel.c
	 gcc -shared hello_ariel.c -o -fPIC -o lib.so

.PHONY: clean 
clean:
		-rm *.o *.so hello1 hello2 hello3 