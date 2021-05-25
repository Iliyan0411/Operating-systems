#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
    int pid = fork();

    if(pid == -1){
        perror("Problem with fork() command!\n");
        exit(-1);
    }
    if(pid == 0){
        for(int i = 0; i < 50000; i++)
        {

        }
        printf("Bye from the children.\n");
    }
    else{
        printf("Parent's ID is %d: \n", getppid());
        printf("Child's ID is %d: \n", getpid());
        printf("Hello from parent.\n");
    }


    return 0;
}