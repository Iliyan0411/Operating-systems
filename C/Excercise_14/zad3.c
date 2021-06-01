#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>


int main(int argc, char **argv)
{
    int good = 0, bad = 0;
    for(int i = 1; i < argc; i++)
    {
        int pid = fork(), status;

        if(pid == -1){
            perror("Error with fork() command!\n");
        }
        else if(pid > 0){
            wait(&status);

            if(status == 0){
                good++;
            }
            else{
                bad++;
            }
        }
        else{
            execlp(argv[i], argv[i], (char *)0);
        }    
    }

    printf("\n$ Completed commands are %d.\n", good);
    printf("$ Uncompleted commands are %d.\n", bad);

    return 0;
}