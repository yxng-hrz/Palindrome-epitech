/*
** EPITECH PROJECT, 2023
** aa
** File description:
** aa
*/

#ifndef aa
    #define aa

    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <errno.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdbool.h>
    #include <ctype.h>
    #include <stdbool.h>
    #include <string.h>

    #define EXIT_FAILED 84
    #define EXIT_GREAT 0


    typedef struct flags_s {
        int nb;
        int pal;
        int base;
        int imin;
        int imax;
    } flags_t;

    int my_strlen(char const *str);
    int helper_files(void);
    void my_checker(char *str);
    void palindrome(flags_t flags);
    void changer(int nb, flags_t flags);
    int changer_base(int nb, flags_t flags);
    bool is_palindrome(const char *str);
    char *reverter_string(char *str);
    int calc_puiss(int nb, int pow);
    int transform_baseten(char *str, int base);
    char *transform_basic(unsigned int nb, int base, int maj);
    flags_t information_option(int argc, char **argv);
    void printer(int fd, char *str, int rtn);
    void free_all(void *one, void *two, void *three);
    void ret_iterations(int tested, int end, int iteration, int base);

#endif /* !aa */
