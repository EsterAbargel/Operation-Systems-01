#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <unistd.h>
#include <sched.h>

#define STACK_SIZE 10000

char childStack[STACK_SIZE+1];

int first()
{
    char * args[2] = {"./first",NULL};
    execvp(args[0], args);
    return 0;
}

int second()
{
    char * args[2] = {"./second",NULL};
    execvp(args[0], args);
    return 0;
}

int third()
{
    char * args[2] = {"./third",NULL};
    execvp(args[0], args);
    return 0;
}

int main()
{
    int result1, result2, result3;
    result1 = clone(first, childStack + STACK_SIZE, CLONE_PARENT, 0);
    result2 = clone(second, childStack + STACK_SIZE, CLONE_PARENT, 0);
    result3 = clone(third, childStack + STACK_SIZE, CLONE_PARENT, 0);
    return 0;
}