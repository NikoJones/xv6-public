#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    printf(1, "uptime: %d\n", uptime());

    // argument
    if (argc < 2){
        printf(2, "usage: exectime command argument-list\n");
        exit();
    }

    int pid = fork();

    if (pid == -1){
        printf(2, "fork error\n");
        exit();
    }

    if (pid == 0){
        exec(argv[1], argv+1);
        printf(2, "child error\n");
        exit();
    }

    wait();
    
    // end time
    printf(1, "uptime: %d\n", uptime());
    exit();
}