#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>


int main(int argc, char **argv)
{
    int status = 0;
    int pid = fork();

    if(pid == -1){
        perror("Problem with fork() command!\n");
        exit(-1);
    }
    else if(pid > 0){
        wait(&status);
        printf("Exit code: %d\n", status);
    }
    else{
        char **args = (char **)malloc((argc+1) * sizeof(char));
        for(int i = 0; i < argc-1; i++)
        {
            args[i] = argv[i+1];
        }
        char end[5] = "NULL";
        args[argc] = end;
        
        printf("\nChild's ID: %d\n", getpid());
        exit(execvp(argv[1], args));
    }


    return 0;
}
