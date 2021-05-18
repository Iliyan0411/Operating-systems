#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>



int main(int argc, char **argv)
{
    char *str = (char *)malloc(sizeof(char)*(255));
    read(0, str, 254);
    int fd = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    
    write(fd, str, strlen(str));

    close(fd);
    free(str);


    return 0;
}