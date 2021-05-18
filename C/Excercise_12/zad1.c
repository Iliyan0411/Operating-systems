#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char **argv)
{
    char *str = (char *)calloc(255, sizeof(char));
    read(0, str, 254);
    write(1, str, strlen(str));
    free(str);


    return 0;
}