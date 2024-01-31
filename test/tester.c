/*
** EPITECH PROJECT, 2023
** requirement
** File description:
** aa
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "../include/my.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(printer, test1, .init = redirect_all_stdout, .exit_code = 84)
{
    printer(2, "invalid argument\n", 84);
    cr_assert_stderr_eq_str("invalid argument\n");
}

Test(information_option, test2, .init = redirect_all_stdout, .exit_code = 84)
{
    int argc = 1;
    char *argv[] = {"./palindrome"};
    flags_t flag = information_option(argc, argv);
    cr_assert_stderr_eq_str("invalid argument\n");
}

Test(information_option, test3, .init = redirect_all_stdout, .exit_code = 84)
{
    int argc = 2;
    char *argv[] = {"./palindrome", "-n"};
    flags_t flag = information_option(argc, argv);
    cr_assert_stderr_eq_str("invalid argument\n");
}

Test(information_option, test4)
{
    int argc = 3;
    char *argv[] = {"./palindrome", "-n", "555"};
    flags_t flag = information_option(argc, argv);
    cr_assert_eq(flag.nb, 555);
}

Test(information_option, test6)
{
    int argc = 3;
    char *argv[] = {"./palindrome", "-p", "121"};
    flags_t flag = information_option(argc, argv);
    cr_assert_eq(flag.pal, 121);
}

Test(information_option, test8, .init = redirect_all_stdout, .exit_code = 84)
{
    int argc = 3;
    char *argv[] = {"./palindrome", "-b", "10"};
    flags_t flag = information_option(argc, argv);
    cr_assert_stderr_eq_str("invalid argument\n");
}

Test(information_option, test9, .init = redirect_all_stdout, .exit_code = 84)
{
    int argc = 5;
    char *argv[] = {"./palindrome", "-n", "123", "-p", "121"};
    flags_t flag = information_option(argc, argv);
    cr_assert_stderr_eq_str("invalid argument\n");
}

Test(information_option, test10, .init = redirect_all_stdout, .exit_code = 84)
{
    int argc = 5;
    char *argv[] = {"./palindrome", "-n", "123", "-b", "121"};
    flags_t flag = information_option(argc, argv);
    cr_assert_stderr_eq_str("invalid argument\n");
}

Test(information_option, test11, .init = redirect_all_stdout, .exit_code = 84)
{
    int argc = 5;
    char *argv[] = {"./palindrome", "-n", "123", "-b", "1"};
    flags_t flag = information_option(argc, argv);
    cr_assert_stderr_eq_str("invalid argument\n");
}

Test(information_option, test12, .init = redirect_all_stdout, .exit_code = 84)
{
    int argc = 5;
    char *argv[] = {"./palindrome", "-n", "123", "-imin", "-1"};
    flags_t flag = information_option(argc, argv);
    cr_assert_stderr_eq_str("invalid argument\n");
}

Test(information_option, test13, .init = redirect_all_stdout, .exit_code = 84)
{
    int argc = 5;
    char *argv[] = {"./palindrome", "-n", "123", "-imax", "-1"};
    flags_t flag = information_option(argc, argv);
    cr_assert_stderr_eq_str("invalid argument\n");
}

Test(information_option, test14, .init = redirect_all_stdout, .exit_code = 84)
{
    int argc = 7;
    char *argv[] = {"./palindrome", "-n", "123", "-imin", "10", "-imax", "5"};
    flags_t flag = information_option(argc, argv);
    cr_assert_stderr_eq_str("invalid argument\n");
}

Test(information_option, test15, .init = redirect_all_stdout)
{
    int argc = 7;
    char *argv[] = {"./palindrome", "-n", "123", "-b", "3", "-imax", "5"};
    flags_t flag = information_option(argc, argv);
    changer(flag.nb, flag);
    cr_assert_stdout_eq_str("123 leads to 448 in 3 iteration(s) in base 3\n");
}

Test(information_option, test16, .init = redirect_all_stdout, .exit_code = 84)
{
    int argc = 11;
    char *argv[] = {"./palindrome", "-n", "123", "-imin", "10", "-imax", "5", "-b", "5", "-p", "55", "-h"};
    flags_t flag = information_option(argc, argv);
    cr_assert_stderr_eq_str("invalid argument\n");
}

Test(information_option, test17, .init = redirect_all_stdout, .exit_code = 84)
{
    int argc = 3;
    char *argv[] = {"./palindrome", "-niopas", "4865"};
    flags_t flag = information_option(argc, argv);
    cr_assert_stderr_eq_str("invalid argument\n");
}

Test(information_option, test18, .init = redirect_all_stdout, .exit_code = 84)
{
    int argc = 3;
    char *argv[] = {"./palindrome", "-o", "78"};
    flags_t flag = information_option(argc, argv);
    cr_assert_stderr_eq_str("invalid argument\n");
}

Test(information_option, test19, .init = redirect_all_stdout)
{
    int argc = 3;
    char *argv[] = {"./palindrome", "-n", "78"};
    flags_t flag = information_option(argc, argv);
    cr_assert_eq(flag.nb, 78);
}

Test(information_option, test20, .init = redirect_all_stdout, .exit_code = 84)
{
    int argc = 7;
    char *argv[] = {"./palindrome", "-n", "78", "-b", "5", "-p", "515"};
    flags_t flag = information_option(argc, argv);
    cr_assert_stderr_eq_str("invalid argument\n");
}

Test(information_option, test21, .init = redirect_all_stdout, .exit_code = 84)
{
    int argc = 2;
    char *argv[] = {"./palindrome", "-z"};
    flags_t flag = information_option(argc, argv);
    cr_assert_stderr_eq_str("invalid argument\n");
}

Test(information_option, test22, .init = redirect_all_stdout)
{
    int argc = 7;
    char *argv[] = {"./palindrome", "-p", "363", "-b", "10", "-imin", "6"};
    flags_t flag = information_option(argc, argv);
    palindrome(flag);
    cr_assert_stdout_eq_str("3 leads to 363 in 6 iteration(s) in base 10\n");
}

Test(information_option, test23, .init = redirect_all_stdout, .exit_code = 84)
{
    int argc = 6;
    char *argv[] = {"./palindrome", "-p", "363", "-b", "imin", "7"};
    flags_t flag = information_option(argc, argv);
    cr_assert_stderr_eq_str("no solution\n");
}
