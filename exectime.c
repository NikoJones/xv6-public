#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    int start = uptime();

    printf(1, "%d ", start);

    // argument
    if (argc < 2){
        printf(1, "usage: exectime command argument-list\n");
        exit();
    }

    int pid = fork();

    if (pid == -1){
        printf(1, "fork error\n");
    }

    if (pid == 0){
        exec(argv[1], argv+1);
    }

    if (pid > 0) {
        wait();
    }
    
    
    // end time
    int myTime = uptime();
    printf(1, "%d", myTime);
    exit();
}