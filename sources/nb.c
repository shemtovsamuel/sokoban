/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** nb.c
*/

#include "../include/my_sokoban.h"

int nb_o(game_t *game)
{
    int count_o = 0;

    for (int j = 0; j < game->rows; j++)
        for (int i = 0; i < game->cols; i++) {
            if (game->map_2d[j][i] == 'O')
                count_o++;
        }
    return (count_o);
}

int nb_x(game_t *game)
{
    int count_x = 0;

    for (int j = 0; j < game->rows; j++)
        for (int i = 0; i < game->cols; i++) {
            if (game->map_2d[j][i] == 'X')
                count_x++;
        }
    return (count_x);
}

int nb_p(game_t *game)
{
    int count_p = 0;

    for (int j = 0; j < game->rows; j++)
        for (int i = 0; i < game->cols; i++) {
            if (game->map_2d[j][i] == 'P')
                count_p++;
        }
    return (count_p);
}