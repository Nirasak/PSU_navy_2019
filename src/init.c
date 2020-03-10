/*
** EPITECH PROJECT, 2020
** init.c
** File description:
** init
*/

#include <stdlib.h>
#include <signal.h>
#include "my.h"

void free_game(navy_t *navy)
{
    for (int i = 0; navy->my_map[i] != NULL; i++) {
        free(navy->my_map[i]);
        free(navy->enm_map[i]);
    }
    free(navy->my_map);
    free(navy->enm_map);
    free(sgnl);
}

bool init_sig(void)
{
    struct sigaction sig;

    if ((sgnl = malloc(sizeof(struct sg))) == NULL)
        return (false);
    sgnl->my_pid = getpid();
    sgnl->enm_pid = 0;
    sgnl->x = -1;
    sgnl->y = -1;
    sgnl->rcv = 0;
    sig.sa_sigaction = &get_signal;
    sig.sa_flags = SA_SIGINFO;
    sigemptyset(&sig.sa_mask);
    if (sigaction(SIGUSR1, &sig, NULL) == -1)
        return (false);
    if (sigaction(SIGUSR2, &sig, NULL) == -1)
        return (false);
    return (false);
}

bool init_game(navy_t *navy, int ac, char **av)
{
    if (create_map(navy) == false)
        return (false);
    navy->x = 0;
    navy->y = 0;
    init_sig();
    if (ac == 2) {
        if (open_file(navy, av[1]) == false)
            return (false);
        if (player_one(navy) == false)
            return (false);
    }
    if (ac == 3) {
        if (open_file(navy, av[2]) == false)
            return (false);
        if (player_two(navy, av[1]) == false)
            return (false);
    }
    game(navy);
    free_game(navy);
    return (true);
}
