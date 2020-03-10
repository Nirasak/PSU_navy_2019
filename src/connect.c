/*
** EPITECH PROJECT, 2020
** connect.c
** File description:
** connect
*/

#include <stddef.h>
#include <signal.h>
#include <unistd.h>
#include "my.h"

void get_signal(int sig, siginfo_t *siginfo, void *ucontext)
{
    if (sgnl->enm_pid == 0)
        sgnl->enm_pid = siginfo->si_pid;
    if (sgnl->enm_pid != siginfo->si_pid)
        return;
    if (siginfo->si_signo == SIGUSR1)
        sgnl->x += 1;
    if (siginfo->si_signo == SIGUSR2)
        sgnl->y += 1;
}

bool player_one(navy_t *navy)
{
    navy->who = 0;
    my_printf("my_pid: %d\nwaiting for enemy connection...\n", sgnl->my_pid);
    while (sgnl->x < 0 && sgnl->y < 0);
    if (kill(sgnl->enm_pid, SIGUSR1) == -1)
        return (false);
    usleep(3000);
    if (kill(sgnl->enm_pid, SIGUSR2) == -1)
        return (false);
    usleep(3000);
    my_printf("\nenemy connected\n\n");
    return (true);
}

bool player_two(navy_t *navy, char *str)
{
    navy->who = 1;
    sgnl->enm_pid = my_atoi(str);
    my_printf("my_pid: %d\n", sgnl->my_pid);
    if (sgnl->enm_pid <= 0)
        return (false);
    if (kill(sgnl->enm_pid, SIGUSR1) == -1)
        return (false);
    usleep(3000);
    if (kill(sgnl->enm_pid, SIGUSR2) == -1)
        return (false);
    usleep(3000);
    while (sgnl->x < 0 && sgnl->y < 0);
    my_printf("successfully connected\n\n");
    return (true);
}
