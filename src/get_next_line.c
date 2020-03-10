/*
** EPITECH PROJECT, 2019
** get_next_line.c
** File description:
** get next line
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "my.h"

bool check_end(char *str, int size)
{
    for (int i = 0; i < size; i++) {
        if (str[i] == '\0' || str[i] == '\n')
            return (true);
    }
    return (false);
}

char *my_strdupn(char *str, int i)
{
    char *dest = malloc(sizeof(char) * (READ_SIZE + 1));
    int j = 0;

    if (dest == NULL)
        return (NULL);
    for (; str[i] != '\0'; i++) {
        dest[j] = str[i];
        j++;
    }
    dest[j] = '\0';
    return (dest);
}

char *my_strcat(char *str, char *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(str) + my_strlen(src) + 1));
    int i = 0;

    if (dest == NULL)
        return (NULL);
    if (str != NULL)
        for (; str[i] != '\0' && str[i] != '\n'; i++)
            dest[i] = str[i];
    if (src != NULL) {
        for (int j = 0; src[j] != '\0' && src[j] != '\n'; j++) {
            dest[i] = src[j];
            i++;
        }
    }
    dest[i] = '\0';
    return (dest);
}

char *get_next_line(int fd)
{
    static char buff[READ_SIZE + 1];
    char *str = NULL;
    int size = 0;

    for (int i = 0; i < READ_SIZE; i++)
        if (buff[i] == '\n') {
            str = my_strdupn(buff, i + 1);
            buff[i] = '\0';
            if (check_end(str, my_strlen(str)) == true)
                return (my_strcat(str, NULL));
        }
    if (fd == -1 || READ_SIZE <= 0)
        return (NULL);
    if ((size = read(fd, buff, READ_SIZE)) <= 0)
        return (NULL);
    buff[size] = '\0';
    if (check_end(buff, READ_SIZE) == true)
        return (my_strcat(str, buff));
    str = my_strcat(str, buff);
    return (my_strcat(str, get_next_line(fd)));
}
