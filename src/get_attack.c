/*
** EPITECH PROJECT, 2020
** get_attack.c
** File description:
** get attack
*/

#include "get_next_line.h"
#include "my.h"

bool check_attack(char *str)
{
    if (str == NULL)
        return (false);
    if (my_strlen(str) < 2)
        return (false);
    if (str[0] < 'A' || str[0] > 'H')
        return (false);
    if (str[1] < '1' || str[1] > '8')
        return (false);
    if (str[2] != '\0' && (str[2] != '\n' || str[3] != '\0'))
        return (false);
    return (true);
}

char *get_attack(void)
{
    char *atk = NULL;

    my_printf("attack: ");
    while (check_attack(atk) == false) {
        if (atk != NULL) {
            my_printf("wrong position\n");
            my_printf("attack: ");
        }
        atk = get_next_line(0);
    }
    return (atk);
}

int attack_hit(navy_t *navy)
{
    char c = navy->my_map[navy->y - 1][navy->x - 1];

    my_printf("%c%c: ", navy->x + 64, navy->y + 48);
    if (c >= '1' && c <= '5') {
        navy->my_map[navy->y - 1][navy->x - 1] = 'x';
        my_printf("hit\n\n");
        return (1);
    }
    if (navy->my_map[navy->y - 1][navy->x - 1] != 'x')
        navy->my_map[navy->y - 1][navy->x - 1] = 'o';
    my_printf("missed\n\n");
    return (0);
}

void update_map(navy_t *navy, int pos_x, int pos_y)
{
    if (navy->x == 1) {
        navy->enm_map[pos_y][pos_x] = 'x';
        my_printf("hit\n\n");
    } else {
        if (navy->enm_map[pos_y][pos_x] != 'x')
            navy->enm_map[pos_y][pos_x] = 'o';
        my_printf("missed\n\n");
    }
}
