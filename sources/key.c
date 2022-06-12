/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** key.c
*/

#include "../include/my_sokoban.h"

void key_up(game_t *game)
{
    if (game->map_2d[game->yp - 1][game->xp] == 'X') {
        if (game->map_2d[game->yp - 2][game->xp] == ' ' ||
        game->map_2d[game->yp - 2][game->xp] == 'O') {
            game->map_2d[game->yp - 1][game->xp] = 'P';
            game->map_2d[game->yp - 2][game->xp] = 'X';
            game->map_2d[game->yp][game->xp]  = ' ';
        }
    }
    else {
        game->map_2d[game->yp - 1][game->xp] = 'P';
        game->map_2d[game->yp][game->xp]  = ' ';
    }
    pos_p(game);
    pos_x(game);
}

void key_down(game_t *game)
{
    if (game->map_2d[game->yp + 1][game->xp] == 'X') {
        if (game->map_2d[game->yp + 2][game->xp] == ' ' ||
        game->map_2d[game->yp + 2][game->xp] == 'O') {
            game->map_2d[game->yp + 1][game->xp] = 'P';
            game->map_2d[game->yp + 2][game->xp] = 'X';
            game->map_2d[game->yp][game->xp] = ' ';
        }
    }
    else {
        game->map_2d[game->yp + 1][game->xp] = 'P';
        game->map_2d[game->yp][game->xp]  = ' ';
    }
    pos_p(game);
    pos_x(game);
}

void key_left(game_t *game)
{
    if (game->xp > 0 && game->map_2d[game->yp][game->xp - 1] == 'X') {
        if (game->map_2d[game->yp][game->xp - 2] == ' ' ||
        game->map_2d[game->yp][game->xp - 2] == 'O') {
            game->map_2d[game->yp][game->xp - 1] = 'P';
            game->map_2d[game->yp][game->xp - 2] = 'X';
            game->map_2d[game->yp][game->xp] = ' ';
        }
    }
    else {
        game->map_2d[game->yp][game->xp - 1] = 'P';
        game->map_2d[game->yp][game->xp]  = ' ';
    }
    pos_p(game);
    pos_x(game);
}

void key_right(game_t *game)
{
    if (game->map_2d[game->yp][game->xp + 1] == 'X') {
        if (game->map_2d[game->yp][game->xp + 2] == ' ' ||
        game->map_2d[game->yp][game->xp + 2] == 'O') {
            game->map_2d[game->yp][game->xp + 1] = 'P';
            game->map_2d[game->yp][game->xp + 2] = 'X';
            game->map_2d[game->yp][game->xp] = ' ';
        }
    }
    else {
        game->map_2d[game->yp][game->xp + 1] = 'P';
        game->map_2d[game->yp][game->xp]  = ' ';
    }
    pos_p(game);
    pos_x(game);
}

void check_key(int key, game_t *game)
{
    if ((game->yp > 0 && game->yp < game->rows) &&
    (key == KEY_UP && game->map_2d[game->yp - 1][game->xp] != '#'))
        key_up(game);
    if ((game->yp >= 0 && game->yp < game->rows - 2) &&
    (key == KEY_DOWN && game->map_2d[game->yp + 1][game->xp] != '#'))
        key_down(game);
    if ((game->xp > 0 && game->xp < game->cols) &&
    (key == KEY_LEFT && game->map_2d[game->yp][game->xp - 1] != '#'))
        key_left(game);
    if ((game->xp >= 0 && game->xp < game->cols - 2) &&
    (key == KEY_RIGHT && game->map_2d[game->yp][game->xp + 1] != '#'))
        key_right(game);
    if (key == ' ') {
        game->map_2d = str_to_2d(game->str, game->rows, game->cols);
        pos_p(game);
        refresh();
    }
}