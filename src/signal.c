/*
** EPITECH PROJECT, 2020
** send_signal.c
** File description:
** send signal
*/

#include "my.h"

void send_signal_2(int j)
{
    for (; j > 0; j--) {
        kill(sgnl->enm_pid, SIGUSR1);
        while (sgnl->x < 1);
        sgnl->x = 0;
        usleep(5000);
    }
    kill(sgnl->enm_pid, SIGUSR2);
    while (sgnl->y < 1);
    sgnl->y = 0;
    usleep(5000);
}

void send_signal(int i, int j)
{
    for (; i > 0; i--) {
        kill(sgnl->enm_pid, SIGUSR1);
        while (sgnl->x < 1);
        sgnl->x = 0;
        usleep(5000);
    }
    kill(sgnl->enm_pid, SIGUSR2);
    while (sgnl->y < 1);
    sgnl->y = 0;
    usleep(5000);
    send_signal_2(j);
}

int take_signal_2(navy_t *navy, int status)
{
    if (sgnl->x == 1 && status == 1) {
        usleep(5000);
        kill(sgnl->enm_pid, SIGUSR1);
        navy->y += 1;
        sgnl->x = 0;
    }
    if (sgnl->y == 1) {
        usleep(5000);
        kill(sgnl->enm_pid, SIGUSR2);
        status += 1;
        sgnl->y = 0;
    }
    return (status);
}

void take_signal(navy_t *navy)
{
    int status = 0;

    while (status != 2) {
        if (sgnl->x == 1 && status == 0) {
            usleep(5000);
            kill(sgnl->enm_pid, SIGUSR1);
            navy->x += 1;
            sgnl->x = 0;
        }
        status = take_signal_2(navy, status);
    }
}
