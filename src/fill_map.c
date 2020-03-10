/*
** EPITECH PROJECT, 2020
** fill_file.c
** File description:
** fill file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "get_next_line.h"

bool fill_map(int i, navy_t *navy, char *str)
{
    int x = (str[2] - str[5] > 0) ? (str[2] - 65) : (str[5] - 65);
    int y = (str[3] - str[6]) > 0 ? (str[3] - 49) : (str[6] - 49);
    int error = 0;

    if (ABS(str[2] - str[5]) != 0)
        for (int j = i; j > 0; j--) {
            error += navy->my_map[y][x - j + 1] == '.' ? 0 : 1;
            navy->my_map[y][x - j + 1] = i + 48;
        }
    if (ABS(str[3] - str[6]) != 0)
        for (int j = i; j > 0; j--) {
            error += navy->my_map[y - j + 1][x] == '.' ? 0 : 1;
            navy->my_map[y - j + 1][x] = i + 48;
        }
    if (error != 0)
        return (false);
    return (true);
}

bool check_file(int i, navy_t *navy, char *str)
{
    int j = 0;

    for (; str[j] != '\0'; j++);
    if (j != 7)
        return (false);
    if (str[0] - 48 != i)
        return (false);
    if (str[1] != ':' || str[4] != ':')
        return (false);
    if ((ABS(str[2] - str[5]) != i - 1 || (str[3] - str[6]) != 0)
        && (ABS(str[3] - str[6]) != i - 1 || (str[2] - str[5]) != 0))
        return (false);
    if (((str[2] - 64) < 1 || (str[2] - 64) > 8)
        || ((str[3] - 48) < 1 || (str[3] - 48) > 8)
        || ((str[5] - 64) < 1 || (str[5] - 64) > 8)
        || ((str[6] - 48) < 1 || (str[6] - 48) > 8))
        return (false);
    return (fill_map(i, navy, str));
}

bool open_file(navy_t *navy, char *file)
{
    int fd = open(file, O_RDONLY);
    char *str = get_next_line(fd);
    int i = 2;

    for (; str; i++) {
        if (check_file(i, navy, str) == false)
            return (false);
        free(str);
        str = get_next_line(fd);
    }
    if (i != 6)
        return (false);
    return (true);
}
