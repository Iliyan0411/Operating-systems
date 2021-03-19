/*
Създава нов процес, който изпълнява командата ls -l
*/


#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
int pid;
pid = fork();
if (pid > 0) wait(NULL);
char* args[] = {"ls", "-l", (char*)0};
if (pid == 0) execvp(args[0], args);
if (pid < 0) perror("fork");
}
