/*
** EPITECH PROJECT, 2023
** requirement
** File description:
** aa
*/

#include "../include/my.h"
#include <stdbool.h>
#include <string.h>

void changer(int nb, flags_t flags)
{
    int i = (nb == 0) ? flags.imin : 0;
    int solution_found = 0;
    char *str = transform_basic(nb, flags.base, 0);
    char *str_two = reverter_string(strdup(str));
    for (; i < flags.imax && nb > 0; i++) {
        int str_cmp_result = strcmp(str, str_two);
        if (str_cmp_result == 0 && i >= flags.imin) {
            solution_found = 1;
            break;
        }
        nb = transform_baseten(str, flags.base) +
            transform_baseten(str_two, flags.base);
        free_all(str, str_two, NULL);
        str = transform_basic(nb, flags.base, 0);
        str_two = reverter_string(strdup(str));
    } if (!solution_found || i < flags.imin) {
        printer(2, "invalid argument\n", 84);
    } else {
        ret_iterations(flags.nb, nb, i, flags.base);
    } free_all(str, str_two, NULL);
}

int changer_base(int nb, flags_t flags)
{
    char *str = transform_basic(nb, flags.base, 0);
    char *str_two = reverter_string(strdup(str));
    char *palin_str = transform_basic(flags.pal, flags.base, 0);
    int i = (nb == 0) ? flags.imin : 0;
    int check = 0;
    while (!(strcmp(str, palin_str) == 0 && i >= flags.imin) &&
        i < flags.imax && nb > 0) {
        nb = transform_baseten(str, flags.base) +
            transform_baseten(str_two, flags.base);
        free_all(str, str_two, NULL);
        str = transform_basic(nb, flags.base, 0);
        str_two = reverter_string(strdup(str));
        i++;
    }
    if (i >= flags.imin && strcmp(str, palin_str) == 0) {
        check = 1;
        ret_iterations(flags.nb, nb, i, flags.base);
    }
    free_all(str, palin_str, str_two);
    return check;
}

bool is_palindrome(const char *str)
{
    int length = strlen(str);
    int i = 0;
    int j = length - 1;
    while (i < j) {
        if (str[i] != str[j]) {
            return 0;
        }
        i = i + 1;
        j = j - 1;
    }
    return EXIT_FAILURE;
}

void palindrome(flags_t flags)
{
    char *str = transform_basic(flags.pal, flags.base, 0);
    int check = 0;
    if (!is_palindrome(str)) {
        free_all(str, NULL, NULL);
        printer(2, "invalid argument\n", 84);
    }
    for (int a = 0; a <= flags.pal; a = a + 1) {
        flags.nb = a;
        check += changer_base(a, flags);
    }
    if (check == 0) {
        printf("no solution\n");
    }
    free_all(str, NULL, NULL);
}
