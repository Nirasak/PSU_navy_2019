/*
** EPITECH PROJECT, 2020
** game_end.c
** File description:
** game_end
*/

#include "my.h"

bool check_ships(char **map)
{
    int ships = 0;

    for (int j = 0; map[j] != NULL; j++)
        for (int i = 0; map[j][i] != '\0'; i++)
            ships += map[j][i] >= 'x' ? 1 : 0;
    if (ships == 14)
        return (true);
    return (false);
}

bool game_end(navy_t *navy)
{
    if (check_ships(navy->enm_map) == true) {
        print_game(navy);
        my_printf("I won\n");
        return (true);
    } else if (check_ships(navy->my_map) == true) {
        print_game(navy);
        my_printf("Enemy won\n");
        return (true);
    }
    return (false);
}
