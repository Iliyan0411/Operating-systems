#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main()
{
    int fd = open("f25", O_RDONLY);

    int st = 1;
    int offset = 0;
    while(st > 0)
    {
        char *str = (char *) calloc(15, sizeof(char));
        st = read(fd, str, 10);
        offset += 10;
        lseek(fd, offset, SEEK_SET);

        printf("%d \n", st);
    }
    
    close(fd);


    return 0;
}