#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

char cloneStack[10000+1];

void print(const char * text)
{
    for(int i = 0; i < 30; i++)
    {
        printf("The thread is %s\n", text);
         usleep(1000000);
    }
}

int childFunction(void * c)
{
    print("child");
}

int main()
{
    int result1 = clone(childFunction, cloneStack+10000, CLONE_PARENT, 0);
    printf("clone result = %d \n", result1); 
    
    print("parent");
    
    return 0;
}
