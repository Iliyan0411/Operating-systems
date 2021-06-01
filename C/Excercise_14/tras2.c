#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

#define COM "ps"

int main()
{
    int i = 2, status;
    if(fork()) {
        wait(&status); 
        --i;
        printf("Stoinostta na i = %d;", i);
    }
    else { 
        i++; 
        if(execlp(COM, COM, (char *)0) == -1) { 
            i=i+2;
            printf("Stoinostta na i = %d;", i);
        }
    }
    printf("Stoinostta na i = %d;", --i);

    return 0;
}