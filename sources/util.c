/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** util.c
*/

#include "../include/my_sokoban.h"

int counter_rows(char *str)
{
    int rows = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n') {
            rows++;
        }
    return (rows);
}

int counter_cols(char *str)
{
    int i = 0;

    while (str[i] != '\n')
        i++;
    return (i);
}

void init_game(int argc, char **argv, game_t *game)
{
    game->xp = 0;
    game->yp = 0;
    game->str = load_map(argc, argv);
    game->cols = counter_cols(game->str) + 1;
    game->rows = counter_rows(game->str) + 1;
    game->map_2d = str_to_2d(game->str, game->rows, game->cols);
    game->backup_map = game->map_2d;
    game->nb_o = nb_o(game);
    game->nb_x = nb_x(game);
    game->arr_o = mem_int_2d_array(game->nb_o, 2);
    game->arr_x = mem_int_2d_array(game->nb_x, 2);
    pos_p(game);
    pos_o(game);
    pos_x(game);
}