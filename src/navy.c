/*
** EPITECH PROJECT, 2020
** navy.c
** File description:
** navy
*/

#include <stdlib.h>
#include <signal.h>
#include "my.h"

bool attack(navy_t *navy)
{
    char *atk = NULL;

    if ((atk = get_attack()) == NULL)
        return (false);
    send_signal(atk[0] - 64, atk[1] - 48);
    take_signal(navy);
    my_printf("%s: ", atk);
    update_map(navy, atk[0] - 65, atk[1] - 49);
    free(atk);
    return (true);
}

void defend(navy_t *navy)
{
    my_printf("waiting for enemy's attack...\n");
    take_signal(navy);
    send_signal(attack_hit(navy), 0);
    usleep(5000);
}

bool game(navy_t *navy)
{
    for (int i = 0; game_end(navy) == false; i++) {
        if (i % 2 == 0)
            print_game(navy);
        if (navy->who == 0)
            attack(navy);
        if (navy->who == 1)
            defend(navy);
        navy->who = (navy->who + 1) % 2;
        navy->x = 0;
        navy->y = 0;
    }
    return (true);
}
