/*
** EPITECH PROJECT, 2020
** create_map.c
** File description:
** create map
*/

#include "my.h"
#include <stdlib.h>

bool create_map(navy_t *navy)
{
    navy->my_map = malloc(sizeof(char *) * 9);
    navy->enm_map = malloc(sizeof(char *) * 9);
    if (navy->my_map == NULL || navy->enm_map == NULL)
        return (false);
    for (int i = 0; i < 8; i++) {
        navy->my_map[i] = malloc(sizeof(char) * 17);
        navy->enm_map[i] = malloc(sizeof(char) * 17);
        if (navy->my_map[i] == NULL || navy->enm_map[i] == NULL)
            return (false);
        for (int j = 0; j < 8; j++) {
            navy->my_map[i][j] = '.';
            navy->enm_map[i][j] = '.';
        }
        navy->my_map[i][8] = '\0';
        navy->enm_map[i][8] = '\0';
    }
    navy->my_map[8] = NULL;
    navy->enm_map[8] = NULL;
    return (true);
}
