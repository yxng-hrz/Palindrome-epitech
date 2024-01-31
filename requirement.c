/*
** EPITECH PROJECT, 2023
** requirement
** File description:
** aa
*/

#include <stdlib.h>
#include <stdio.h>

int my_factrec_synthesis(int nb)
{
    if (nb == 0)
        return 1;
    else if (nb < 0 || nb >= 13)
        return 0;

    int result = 1;
    for (int a = 1; a <= nb; a = a + 1) {
        result *= a;
    }
    return result;
}

int my_squareroot_synthesis(int nb)
{
    if (nb < 0)
        return -1;
    else if (nb == 0 || nb == 1)
        return nb;

    int sqr = 1;
    int a = nb;

    while (a > sqr) {
        a = (a + sqr) / 2;
        sqr = nb / a;
    }
    if (a * a != nb)
        return -1;
    return a;
}
