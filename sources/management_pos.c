/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** management_pos.c
*/

#include "../include/my_sokoban.h"

void pos_p(game_t *game)
{
    for (int j = 0; j < game->rows; j++)
        for (int i = 0; i < game->cols; i++) {
            if (game->map_2d[j][i] == 'P') {
                game->xp = i;
                game->yp = j;
            }
        }
}

void pos_o(game_t *game)
{
    int a = 0;

    for (int j = 0; j < game->rows; j++)
        for (int i = 0; i < game->cols; i++) {
            if (game->map_2d[j][i] == 'O') {
                game->arr_o[a][1] = i;
                game->arr_o[a][0] = j;
                a++;
            }
        }
}

void pos_x(game_t *game)
{
    int a = 0;

    for (int j = 0; j < game->rows; j++)
        for (int i = 0; i < game->cols; i++) {
            if (game->map_2d[j][i] == 'X') {
                game->arr_x[a][1] = i;
                game->arr_x[a][0] = j;
                a++;
            }
        }
}