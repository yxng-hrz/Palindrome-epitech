/*
** EPITECH PROJECT, 2023
** requirement
** File description:
** aa
*/

#include "../include/my.h"

int helper_files(void)
{
    printf("USAGE\n");
    printf("      ./palindrome -n number -p palindrome ");
    printf("[-b base] [-imin i] [-imax i]\n\n");
    printf("DESCRIPTION\n");
    printf("      -n n      integer to be transformed (>=0)\n");
    printf("      -p pal    palindromic number to be ");
    printf("obtained (incompatible with the -n\n");
    printf("                option) (>=0)\n");
    printf("                if defined, all fitting ");
    printf("values of n will be output\n");
    printf("      -b base   base in which the procedure will ");
    printf("be executed (1<b<=10) [def: 10]\n");
    printf("      -imin i   minimum number of iterations, ");
    printf("included (>=0) [def: 0]\n");
    printf("      -imax i   maximum number of iterations, ");
    printf("included (>=0) [def: 100]\n");
    return EXIT_GREAT;
}

void my_checker(char *str)
{
    if (strcmp(str, "-h") == 0) {
        helper_files();
    }
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        my_checker(argv[1]);
    }
    flags_t flags = information_option(argc, argv);
    if (flags.nb != -1)
        changer(flags.nb, flags);
    else
        palindrome(flags);
    return EXIT_GREAT;
}
