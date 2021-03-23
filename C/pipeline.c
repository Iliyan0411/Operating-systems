#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
    int pid, pid1, fd[2];
    char* args1[] = {"ps", "-a", (char*)0};
    char* args2[] = {"grep", "gnome", (char*)0};
    pid = fork();
    
    if (pid > 0) wait(NULL);

    if(pid == 0){ // child shell
        pipe(fd); // create pipe
        pid1 = fork(); 
        
        if (pid1 == 0){ // process for cmd1
            close(fd[0]);
            dup2(fd[1], STDOUT_FILENO);
            close(fd[1]);
            execvp(args1[0], args1);
        }
        if (pid1 > 0){
            close(fd[1]);
            dup2(fd[0], STDIN_FILENO);
            close(fd[0]);
            execvp(args2[0], args2);
        }
    }
    if (pid < 0) perror("fork");
}
