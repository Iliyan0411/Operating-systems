#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>


int main(int argc, char **argv)
{
    int pid[2], status[2]; 
    pid[0] = fork();

    if(pid[0] > 0){
        wait(&status[0]);

        pid[1] = fork();

        if(pid[1] > 0){
            wait(&status[1]);
            printf("Status = %d\n", status[1]);
        }
        else{
            char **args = (char **)malloc(argc * sizeof(char));
            for(int i = 0; i < argc-1; i++)
            {
                args[i] = argv[i+2];
            }
            char end[5] = "NULL";
            args[argc-1] = end;

            execvp(argv[2], args);
        }
    }
    else{
        execlp("grep", "grep", "int", argv[1], (char *)0);
    }
}