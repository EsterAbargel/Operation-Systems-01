#include "hello_ariel.h"
#include <stdio.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <stddef.h>

void ( * msg)();

bool initLibrary(){
    void *hdl = dlopen("lib.so", RTLD_LAZY);
    if(hdl == NULL){
        return false;
    }
    msg = (void(*))dlsym(hdl,"sayHello");
    if(msg == NULL){
        return false;
    }
    return true;
}

int main(){
    if(initLibrary()){
        msg();
    }
    else{
        printf("The library was not loaded\n");
    }
    return 0;
}