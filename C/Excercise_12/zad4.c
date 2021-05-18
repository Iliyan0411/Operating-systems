#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char **argv)
{
    for(int i = 1; i < strlen(*argv)-3; i += 1)
    {
        int fd = open(argv[i], O_RDONLY);
        int size = lseek(fd, 0, SEEK_END);
        lseek(fd, 0, SEEK_SET);
        char *str = (char *)malloc(sizeof(char) * (size+1));
        read(fd, str, size);
        str[size] = '\0';

        printf("\n%s\n~~~~~~~~~~~~~\n%s", argv[i], str);

        free(str);
        close(fd);
    }

    return 0;
}