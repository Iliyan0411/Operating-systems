#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void zad4(const char *fname1, const char *fname2)
{
    int fd1 = open(fname1, O_RDONLY);
    
    int size = lseek(fd1, 0, SEEK_END);
    lseek(fd1, 0, SEEK_SET);
    
    char *str = (char *)calloc(size+1, sizeof(char));
    read(fd1, str, size);
    str[size] = '\0';

    printf("%s \n", str);
    close(fd1);

    char *new_str = (char *)calloc(size+1, sizeof(char));
    int curr = 0, counter = 0, i = 0;
    while(i < strlen(str))
    {
        if(counter < 3){
            new_str[curr] = str[i];
            curr += 1;
            counter += 1;

            if(str[i] == '\n'){
                counter = 0;
            }
        }
        else{
            while(str[i] != '\n' && i < strlen(str))
            {
                i += 1;
            }
            counter = 0;
        }
        i += 1;
    }
    new_str[curr] = '\0';
    free(str);

    int fd2 = open(fname2, O_WRONLY, O_TRUNC);
    write(fd2, new_str, strlen(new_str));

    close(fd2);
    free(new_str);
}

int main()
{
    zad4("f1", "f2");

    return 0;
}