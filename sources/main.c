/*
** EPITECH PROJECT, 2020
** Project
** File description:
** Project
*/

#include <signal.h>
#include <sys/types.h>
#include "../include/my_sokoban.h"

void handle_resize(int sig)
{
    if (sig != SIGWINCH)
        return;
    endwin();
    wresize(stdscr, LINES, COLS);
    refresh();
    clear();
}

int longest_line(char * str)
{
    int a = 0;
    int b = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n')
            a = 0;
        a++;
        if (a > b)
            b = a;
    }
    return (b);
}

void loop(game_t *game)
{
    int key = -1;
    struct sigaction s;

    s.sa_handler = handle_resize;
    while (key != 1) {
        check_game(key, game);
        if (LINES >= longest_line(game->str) && COLS >= game->cols)
            for (int i = 0; i < game->rows; i++)
                mvprintw(LINES / 2 - (game->rows / 2) + i, COLS / 2 -
                (longest_line(game->str) / 2), game->map_2d[i]);
        else
            mvprintw(LINES / 2, COLS / 2 - 4, "Too small");
        refresh();
        sigaction(SIGWINCH, &s, NULL);
        check_end_game(game);
        key = getch();
    }
}

void game_loop(game_t *game, int argc, char **argv)
{
    init_game(argc, argv, game);
    check_map(game);
    initscr();
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    loop(game);
    endwin();
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        write(2, "Wrongs arguments.\n", 19);
        return (84);
    }
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')  {
        management_h();
        return (0);
    }
    game_t *game = malloc(sizeof(game_t));
    game_loop(game, argc, argv);
    return (1);
}