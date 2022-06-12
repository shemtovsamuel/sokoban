/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** lib.c
*/

#include <unistd.h>
#include "../include/my_sokoban.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int a = 0; str[a] != '\0'; a++)
        my_putchar(str[a]);
    return (0);
}

static int m_gestion(long number)
{
    int tmp = 0;

    if (number >= 10) {
        tmp = number % 10;
        number = (number - tmp) / 10;
        m_gestion(number);
        my_putchar(tmp + '0');
    } else if (number < 10)
        my_putchar(number + '0');
    return (0);
}

int my_put_nbr(int nb)
{
    long number = nb;

    if (nb < 0) {
        my_putchar('-');
        number = number * -1;
        m_gestion(number);
    } else
        m_gestion(number);
    return (0);
}

int my_strlen(char const *str)
{
    int a = 0;

    for (int b = 0; str[b] != '\0'; b++)
        a = a + 1;
    return (a);
}