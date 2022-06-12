/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** management_map.c
*/

#include "../include/my_sokoban.h"

int size_map (int argc, char **argv)
{
    char c = 0;
    int fd = open(argv[1], O_RDONLY);
    int i = 0;

    while (read(fd, &c, 1) > 0) {
        i++;
    }
    return (i);
}

char **mem_char_2d_array(int rows, int cols)
{
    char **arr = malloc(sizeof(char *) * rows);

    for (int i = 0; i < rows; i++) {
        arr[i] = malloc(sizeof(char) * cols);
        if (arr == NULL)
            return (NULL);
    }
    return (arr);
}

int **mem_int_2d_array(int rows, int cols)
{
    int **arr = malloc(sizeof(int *) * rows);

    if (arr == NULL)
        return (NULL);
    for (int i = 0; i < rows; i++) {
        arr[i] = malloc(sizeof(int) * cols);
        if (arr == NULL)
            return (NULL);
    }
    return (arr);
}

char *load_map(int argc, char **argv)
{
    int fd;
    int value = 0;
    struct stat buff;
    char *map = NULL;

    fd =  open(argv[1], O_RDONLY);
    if (fd == -1)
        exit (84);
    stat(argv[1], &buff);
    map = malloc(sizeof(char) * buff.st_size);
    value = read(fd, map, buff.st_size);
    if (value == -1)
        exit (84);
    close(fd);
    return (map);
}

char **str_to_2d(char const *str, int rows, int cols)
{
    int i_str = 0;
    char **arr = mem_char_2d_array(rows, cols);

    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < cols; i++) {
            arr[j][i] = str[i_str];
            i_str++;
        }
    }
    return (arr);
}