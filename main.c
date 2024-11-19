#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main()
{
	char *str;
	int i = 0;
	int a = open("deneme.txt", O_RDONLY);

	while(i < 5)
	{
		printf("%s", str = get_next_line(a));
		free(str);
		i++;
	}
}