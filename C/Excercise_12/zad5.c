#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char **argv)
{
    int m, n;
    scanf("%d %d", &m, &n);

    if(m > n)
    {
        return 0;
    }

    int size = n - m + 1;
    char *str = (char *)malloc(sizeof(char) * (size+1));

    int fd = open(argv[1], O_RDONLY);
    lseek(fd, m, SEEK_SET);
    
    read(fd, str, size);
    str[size] = '\0';
    printf("%s\n", str);

    close(fd); 
    free(str);

    return 0;
}