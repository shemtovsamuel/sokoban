/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** check_2.c
*/

#include "../include/my_sokoban.h"

void check_end_game(game_t *game)
{
    if (check_victory(game) == 1) {
        endwin();
        exit(0);
    }
    else if (check_game_over(game) == 1) {
        endwin();
        exit(1);
    }
}

void check_map(game_t *game)
{
    if (game->nb_o != game->nb_x)
        exit(84);
    if (nb_p(game) != 1)
        exit(84);
    for (int j = 0; j < game->rows - 1; j++)
        for (int i = 0; i < game->cols; i++) {
            if (game->map_2d[j][i] != 'P' && game->map_2d[j][i] != 'O'
            && game->map_2d[j][i] != 'X' && game->map_2d[j][i] != ' '
            && game->map_2d[j][i] != '#' && game->map_2d[j][i] != '\n')
                exit(84);
        }
}

void management_h(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t   ./my_sokoban map1.txt\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\t   '#' for walls\n");
    my_putstr("\t   'P' for player\n");
    my_putstr("\t   'X' for boxes\n");
    my_putstr("\t   'O' for storage locations\n\n");
    my_putstr("KEYS\n");
    my_putstr("\t   'space' for reset map\n");
    my_putstr("\t   'key up' for up\n");
    my_putstr("\t   'key down' for down\n");
    my_putstr("\t   'key left' for left\n");
    my_putstr("\t   'key right' for right\n");
}