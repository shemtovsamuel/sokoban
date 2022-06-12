/*
** EPITECH PROJECT, 2020
** my_sokoban
** File description:
** my_sokoban.h
*/

#ifndef MY_SOKOBAN_H_
#define MY_SOKOBAN_H_
#define _GNU_SOURCE

#include <stdarg.h>
#include <ncurses.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct game_s {
    int xp;
    int yp;
    int cols;
    int rows;
    char *str;
    char **map_2d;
    char **backup_map;
    int nb_o;
    int nb_x;
    int **arr_o;
    int **arr_x;
} game_t;

void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
void key_up(game_t *game);
void key_down(game_t *game);
void key_left(game_t *game);
void key_right(game_t *game);
void check_key(int key, game_t *game);
int size_map (int argc, char **argv);
char **mem_char_2d_array(int rows, int cols);
int **mem_int_2d_array(int rows, int cols);
void loop(game_t *game);
char *load_map(int argc, char **argv);
char **str_to_2d(char const *str, int rows, int cols);
void check_game(int key, game_t *game);
void check_o(game_t *game);
void check_map(game_t *game);
void management_h(void);
void check_end_game(game_t *game);
int check_game_over(game_t *game);
int check_victory(game_t *game);
void pos_p(game_t *game);
int nb_o(game_t *game);
int nb_x(game_t *game);
int nb_p(game_t *game);
void pos_o(game_t *game);
void pos_x(game_t *game);
int counter_rows(char *str);
int counter_cols(char *str);
void init_game(int argc, char **argv, game_t *game);
#endif