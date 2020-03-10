/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <signal.h>
#include <stdbool.h>
#include <unistd.h>

#define ABS(x) (x) > 0 ? (x) : -(x)

struct sg *sgnl;

typedef struct navy
{
    int who;
    char **my_map;
    char **enm_map;
    int x;
    int y;
} navy_t;

typedef struct sg
{
    pid_t my_pid;
    pid_t enm_pid;
    int x;
    int y;
    int rcv;
} signal_t;

int my_strcmp(char *s1, char *s2);
void my_printf(char *str, ...);
bool player_one(navy_t *navy);
bool player_two(navy_t *navy, char *str);
int my_strlen(char const *str);
bool create_map(navy_t *navy);
void print_map(char **map);
bool open_file(navy_t *navy, char *file);
int my_atoi(char *str);
bool init_game(navy_t *navy, int ac, char **av);
void get_signal(int sig, siginfo_t *siginfo, void *ucontext);
bool my_navy(navy_t *navy);
void print_game(navy_t *navy);
char *get_attack(void);
void send_signal(int i, int j);
void take_signal(navy_t *navy);
int attack_hit(navy_t *navy);
void update_map(navy_t *navy, int pos_x, int pos_y);
bool game_end(navy_t *navy);
bool game(navy_t *navy);

#endif
