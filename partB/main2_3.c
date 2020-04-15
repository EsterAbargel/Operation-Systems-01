#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <syslog.h>

int main()
{ 
    pid_t pid = fork();
    if(pid==0)
    {
        chdir("/");
        
        setsid();
        
        printf("start demon");
        
        close(stdin);
        close(stdout);
        close(stderr);
        
        openlog("my Demon ", LOG_PID, LOG_DAEMON);
        
        syslog(LOG_NOTICE, "start demon");
        usleep(1000000);
        syslog(LOG_NOTICE , "prosses demon");
        usleep(1000000);
        syslog(LOG_NOTICE , "finish demon");
        usleep(1000000);
    }
    
    else
        printf( " daemon pid : %d ", pid);
        
    
    return 0;
}