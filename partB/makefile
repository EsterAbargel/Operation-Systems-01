all: task1 task2 task3

task1: main2_1.c
	   gcc main2_1.c -o fork

task2: main2_2.c
	   gcc main2_2.c -o clone 

task3: main2_3.c
	   gcc main2_3.c -o deamon

task4: main2_1.c main2_2.c main2_3.c main2_4.c
	   gcc main2_4.c -o allFour

clean:
	   -rm fork clone deamon allFour