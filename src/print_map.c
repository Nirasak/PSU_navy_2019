/*
** EPITECH PROJECT, 2020
** print_map.c
** File description:
** print map
*/

#include "my.h"

void print_map(char **map)
{
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 7; j++)
            my_printf("%c ", map[i][j]);
        my_printf("%c\n", map[i][7]);
    }
}

void print_game(navy_t *navy)
{
    my_printf("my positions:\n");
    print_map(navy->my_map);
    my_printf("\nenemy's positions:\n");
    print_map(navy->enm_map);
    my_printf("\n");
}
