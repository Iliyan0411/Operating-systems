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
    else if(pid == 0){
        sleep(1);
        printf("Child's ID is %d: \n", getpid());
        printf("Bye from the child.\n");
    }
    else{
        printf("Hello from parent.\n");
        printf("Parent's ID is %d: \n", getpid());
    }

    return 0;
}