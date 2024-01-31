/*
** EPITECH PROJECT, 2023
** requirement
** File description:
** aa
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int a = 0;
    while (str[a] != '\0') {
        a = a + 1;
    }
    return a;
}

void free_all(void *a, void *b, void *c)
{
    if (a)
        free(a);
    if (b)
        free(b);
    if (c)
        free(c);
}

void ret_iterations(int tested, int end, int iteration, int base)
{
    char buffer[100];
    int len = sprintf(buffer, "%d leads to %d in %d iteration(s) in base %d\n",
        tested, end, iteration, base);
    write(1, buffer, len);
}

void printer(int fd, char *str, int rtn)
{
    write(fd, str, strlen(str));
    exit(rtn);
}
