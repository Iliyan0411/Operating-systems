#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>


int main()
{
    int fd = open("abc", O_CREAT | O_WRONLY, 0644);
    int pid = fork(), status;

    if(pid == 0){
        write(fd, "hello", 5);
    }
    else{
        wait(&status);
        write(fd, "hello", 5);
        close(fd);
    }

    return 0;
}