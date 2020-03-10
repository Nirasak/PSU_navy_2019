/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "my.h"

int print_descr(char *exe)
{
    my_printf("USAGE\n\t./%s [first_player_pid] navy_positions\n", exe);
    my_printf("DESCRIPTION\n\tfirst_player_pid:  only for the 2nd player.");
    my_printf("  pid of the first player.\n\tnavy_positions:  ");
    my_printf("file representing the positions of the ships.\n");
    return (0);
}

int main(int ac, char **av)
{
    navy_t navy;

    if (ac < 2 || ac > 3)
        return (84);
    if (my_strcmp("-h", av[1]) == 0)
        return (print_descr(av[1]));
    if (init_game(&navy, ac, av) == false)
        return (84);
    return (0);
}
