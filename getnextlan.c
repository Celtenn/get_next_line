#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

int ft_strdiff(char *str, char a)
{
    if (!str)
        return (0);
    int i = 0;
    while (str[i])
    {
        if (str[i] == a)
        {
            return (1);
        }
        i++;
    }
    return (0);
}

char *ft_strjoin(char *first, char *second)
{
    char *buffer;
    int i = 0;
    int s = 0;
    if (!first)
    {
        first = malloc(1);
        first[0] = '\0';
    }
    buffer = malloc (ft_strlen(first) + ft_strlen(second) + 1);
    while (first[i])
    {
        buffer[i] = first[i];
        i++;
    }
    while (second[s])
    {
        buffer[i] = second[s];
        i++;
        s++;
    }
    buffer[i] = '\0';
    free(first);
    return (buffer);
}

char *kalan(char *str)
{
    int i = 0;
    int a = 0;
    char *buffer;

    while (str[i] && str[i] != '\n')
    {
        i++;
    }
    if (!str[i])
    {
        free(str);
        return (NULL);
    }
    buffer = malloc(ft_strlen(str) - i + 1);
    if (str[i] == '\n')
        i++;
    while (str[i])
    {
        buffer[a] = str[i];
        i++;
        a++;
    }
    buffer[a] = '\0';
    free(str);
    return (buffer);
}

char *satir(char *str)
{
    int i = 0;
    int a = 0;
    char *buffer;
    
    if (!str[i])
        return (NULL);
    while (str[i] && str[i] != '\n')
    {
        i++;
    }
    buffer = malloc(i + 2);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        buffer[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        buffer[i] = '\n';
        i++;
    }
    if (!str[i - 1])
        free(str);
    buffer[i] = '\0';
    return (buffer);
}

char *oku(char *str, int fd)
{
    char *buffer;
    int i = 1;

    buffer = malloc(5 + 1);
    while (!ft_strdiff(str, '\n') && i != 0)
    {
        i = read(fd, buffer, 5);
        buffer[i] = '\0';
        str = ft_strjoin(str, buffer);
    }
    free(buffer);
    return (str);
}

char *getnextline(int fd)
{
    static char *last;
    char *line;

    if (fd < 0)
        return (NULL);
    last = oku(last, fd);

    line = satir(last);
    if (!last)
        return (NULL);
    last = kalan(last);
    return (line);
}

int main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    char *str;

    str = getnextline(fd);
    while (str)
    {
        printf("satir : %s", str);
        free(str);
        str = getnextline(fd);
    }
    str = getnextline(fd);
    printf("%s", str);
    free(str);
    str = getnextline(fd);
    printf("%s", str);
    free(str);
}
