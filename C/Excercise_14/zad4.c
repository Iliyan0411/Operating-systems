#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char **argv)
{
    int fd = open(argv[3], O_CREAT | O_WRONLY, 0644);

    for(int i = 1; i < 3; ++i)
    {
        int pid = fork();

        if(pid == -1){
            perror("Error with fork() command!\n");
        }
        else if(pid > 0){
            int status;
            wait(&status);

            if(i == 1){
                if(status == 0){
                    write(fd, argv[i], strlen(argv[i]));
                }
                else{
                    printf("Problem with first command!\n");
                }
            }
        }
        else if(pid == 0){
            execlp(argv[i], argv[i], (char *)0);
        }
    }

    close(fd);

    return 0;
}