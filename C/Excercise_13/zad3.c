#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int status = 0;
    int pid = fork();
    
    if(pid == -1){
        perror("Problem with fork command!\n");
        exit(-1);
    }
    else if(pid > 0){
        wait(&status);

        if(status == 0){
            printf("%s\n", argv[1]);
        }
    }
    else{
        exit(execlp(argv[1], argv[1], (char *)0));
    }

    return 0;
}