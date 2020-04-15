#include <stdio.h>

void print(const char *txt){

    int i;
    for ( i = 0; i < 20; i++)
    {
       printf("Hello from %s\n", txt);
       unsleep(1000000);
    }
}

int main(){
    __pid_t pid = fork();

    if(pid == 0){
        print("grandchild");
        __pid_t pid = fork();

        if(pid == 0){
            char* args[2] = {"./friend", NULL};
            execvp(args[0], args);
        }
        else{
            print("child");
        }
    }
    else{
        print("parent");
    }
}