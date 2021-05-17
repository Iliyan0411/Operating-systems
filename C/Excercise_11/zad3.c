#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void zad3(const char *fname)
{
    char *str = (char *) calloc(255, sizeof(char));
    fgets(str, 255, stdin);

    int fd = open(fname, O_WRONLY, O_TRUNC);
    write(fd, str, strlen(str));
    close(fd);

    char* new_str = (char *)calloc(255, sizeof(char));
    int curr = 0;

    for(int i = 0; i < strlen(str); i+= 1)
    {
        if(str[i] == '\t'){
            new_str[curr] = '>';
            new_str[curr+1] = '>';
            new_str[curr+2] = '>';
            curr += 3;
        }
        else{
            new_str[curr] = str[i];
            curr += 1;
        }
    }
    new_str[curr] = '\0';
    free(str);

    write(2, new_str, strlen(new_str));
    free(new_str);
}


int main()
{
    zad3("tabulations");

    return 0;
}