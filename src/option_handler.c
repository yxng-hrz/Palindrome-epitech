/*
** EPITECH PROJECT, 2023
** requirement
** File description:
** aa
*/

#include "../include/my.h"

void set_flag_value(flags_t *flags, char *arg, int nb_flag)
{
    switch (nb_flag) {
        case 0:
            flags->nb = atoi(arg);
            break;
        case 1:
            flags->pal = atoi(arg);
            break;
        case 2:
            flags->base = atoi(arg);
            break;
        case 3:
            flags->imin = atoi(arg);
            break;
        default:
            break;
    }
}

int manager_atoi_flags(int nb_flag, flags_t *flags, char *arg)
{
    int error = 0;
    if (nb_flag >= 0 && nb_flag <= 3) {
        set_flag_value(flags, arg, nb_flag);
    } else if (nb_flag == 4) {
        flags->imax = atoi(arg);
    } else {
        error = EXIT_FAILED;
    }
    return error;
}

static const char *flag[] = {"-n", "-p", "-b", "-imin", "-imax"};

static void sort_manager(char **argv, flags_t *flags, int *i)
{
    int b = 0;
    while (b < 5) {
        if (strcmp(argv[*i], flag[b]) == 0) {
            manager_atoi_flags(b, flags, argv[*i + 1]);
            (*i)++;
            return;
        }
        b = b + 1;
    }
    printer(2, "invalid argument\n", 84);
}

flags_t information_option(int argc, char **argv)
{
    flags_t flags = {-1, -1, 10, 0, 100};
    if (argc % 2 == 0 || argc == 1)
        printer(2, "invalid argument\n", 84);
    int i = 1;
    while (i < argc) {
        sort_manager(argv, &flags, &i);
        i = i + 1;
    } if ((flags.nb == -1 && flags.pal == -1) ||
        (flags.nb != -1 && flags.pal != -1) ||
        flags.base < 2 || flags.base > 10 ||
        flags.imin < 0 || flags.imax < 0 ||
        flags.imin > flags.imax) {
            printer(2, "invalid argument\n", 84);
    }
    return flags;
}
