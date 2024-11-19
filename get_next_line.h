#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3
#endif

#include <stdlib.h>
#include <unistd.h>



int	ft_strlen(const char *str);
char *ft_strchr(char *str, int c);
char *ft_strjoin(const char *str, const char *nbr);
char *get_next_line(int fd);





#endif