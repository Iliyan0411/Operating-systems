#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



int main()
{
    int fd1 = open("f1", O_RDONLY);
    int fd2 = open("f2", O_WRONLY);
    

    char *str = (char *) calloc(100, sizeof(char));
    int ln = read(fd1, str, 15);
    str[ln] = '\0';

    write(fd2, str, strlen(str));

    close(fd1); 
    close(fd2);


    return 0;
}