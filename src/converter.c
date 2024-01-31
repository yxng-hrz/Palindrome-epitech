/*
** EPITECH PROJECT, 2023
** requirement
** File description:
** aa
*/

#include "../include/my.h"

char *reverter_string(char *str)
{
    char *start = str;
    char *end = str + strlen(str) - 1;

    while (end > start) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    return str;
}

int calc_puiss(int nb, int pow)
{
    int output = nb;
    if (pow == 0)
        return EXIT_FAILURE;
    int a = 0;
    while (a < (pow - 1)) {
        output *= nb;
        a = a + 1;
    }
    return output;
}

int transform_baseten(char *str, int base)
{
    int output = 0;
    int a = 0;
    while (str[a]) {
        output = output * base + (str[a] - '0');
        a = a + 1;
    }
    return output;
}

char *transform_basic(unsigned int nb, int base, int maj)
{
    const char *letter = (maj == 0) ? "0123456789abcdefghijklmnopqrstuvwxyz" :
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unsigned int b = nb;
    int output = (nb == 0) ? 1 : 0;
    char *c = 0;
    while (b != 0) {
        b = b / base;
        output = output + 1;
    }
    c = (nb == 0) ? strdup("0") : malloc(sizeof(char) * (output + 1));
    int a = 0;
    while (nb != 0) {
        c[a] = letter[nb % base];
        nb = nb / base;
        a = a + 1;
    }
    c[output] = '\0';
    reverter_string(c);
    return c;
}
