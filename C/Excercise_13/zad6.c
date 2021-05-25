#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>


int main(int argc, char **argv)
{
    int status_1, status_2;
    int pid[2];
    pid[0] = fork();

    if(pid[0] == -1){
        perror("Problem with first fork() command!\n");
        exit(-1);
    }
    else if(pid[0] > 0){
        wait(&status_1);

        pid[1] = fork();

        if(pid[1] == -1){
            perror("Problem with second fork() command!\n");
            exit(-1);
        }
        else if(pid[1] > 0){
            wait(&status_2);
        }
        else{
            exit(execlp(argv[2], argv[2], (char *)0));
        }
    }
    else{
        exit(execlp(argv[1], argv[1], (char *)0));
    }

    printf("\nResult: %d\n", !status_1 || !status_2);

    return 0;
}