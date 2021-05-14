#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main()
{
	int fd = open("f1", O_RDONLY);
	
	int size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	char *str = (char *) calloc(size+1, sizeof(char));
	read(fd, str, size);
	str[size] = '\0';

	int lines = 0;
	for (int i = 0; i < strlen(str); i += 1)
	{
		if(str[i] == '\n')
		{
			lines += 1;
		}
	}

	close(fd);
	printf("%d \n", lines+1);


	return 0;
}
