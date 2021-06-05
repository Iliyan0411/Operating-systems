#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



int main()
{
    int fd1 = open("f1", O_RDONLY);
    int fd2 = open("f2", O_WRONLY);
    
    int size = lseek(fd1, 0, SEEK_END);
    lseek(fd1, 0, SEEK_SET);
    
    char *str = (char *) calloc(size+1, sizeof(char));
    read(fd1, str, size);
    str[size] = '\0';

    write(fd2, str, size);

    close(fd1); 
    close(fd2);


    return 0;
}