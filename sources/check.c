/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** check.c
*/

#include "../include/my_sokoban.h"

void check_game(int key, game_t *game)
{
    check_key(key, game);
    check_o(game);
}

void check_o(game_t *game)
{
    for (int j = 0; j < game->nb_o; j++)
        if (game->map_2d[game->arr_o[j][0]][game->arr_o[j][1]] == ' ')
            game->map_2d[game->arr_o[j][0]][game->arr_o[j][1]] = 'O';
}

int pos_game_over(game_t * game)
{
    int i = 0;

    for (int j = 0; j < game->nb_x; j++)
        if ((((game->map_2d[game->arr_x[j][0]][game->arr_x[j][1] - 1] == '#')
        || (game->map_2d[game->arr_x[j][0]][game->arr_x[j][1] - 1] == 'X'))
        && ((game->map_2d[game->arr_x[j][0] + 1][game->arr_x[j][1]] == '#')
        || (game->map_2d[game->arr_x[j][0] + 1][game->arr_x[j][1]] == 'X')))
        || (((game->map_2d[game->arr_x[j][0]][game->arr_x[j][1] - 1] == '#')
        || (game->map_2d[game->arr_x[j][0]][game->arr_x[j][1] - 1] == 'X'))
        && ((game->map_2d[game->arr_x[j][0] - 1][game->arr_x[j][1]] == '#')
        || (game->map_2d[game->arr_x[j][0] - 1][game->arr_x[j][1]] == 'X')))
        || (((game->map_2d[game->arr_x[j][0]][game->arr_x[j][1] + 1] == '#')
        || (game->map_2d[game->arr_x[j][0]][game->arr_x[j][1] + 1] == 'X'))
        && ((game->map_2d[game->arr_x[j][0] + 1][game->arr_x[j][1]] == '#')
        || (game->map_2d[game->arr_x[j][0] + 1][game->arr_x[j][1]] == 'X')))
        || (((game->map_2d[game->arr_x[j][0]][game->arr_x[j][1] + 1] == '#')
        || (game->map_2d[game->arr_x[j][0]][game->arr_x[j][1] + 1] == 'X'))
        && ((game->map_2d[game->arr_x[j][0] - 1][game->arr_x[j][1]] == '#')
        || (game->map_2d[game->arr_x[j][0] - 1][game->arr_x[j][1]] == 'X'))))
            i++;
    return (i);
}

int check_game_over(game_t *game)
{
    if (game->nb_x == pos_game_over(game))
        return (1);
    return (0);
}

int check_victory(game_t *game)
{
    int count = 0;

    for (int j = 0; j < game->nb_o; j++)
        if (game->map_2d[game->arr_o[j][0]][game->arr_o[j][1]] == 'X')
            count++;
    if (count == game->nb_o)
        return (1);
    return (0);
}