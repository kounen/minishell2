/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** test_count_words_from_turner
*/

#include <criterion/criterion.h>
#include "utils.h"

Test(count_words_from_turner, simpleTestOne)
{
    char string[] = "Salut;ca;va Salut;oui;et;toi";

    cr_assert_eq(count_words_from_turner(string, ';', ' '), 22);
}

Test(count_words_from_turner, simpleTestTwo)
{
    char string[] = "; ; ; ; ";

    cr_assert_eq(count_words_from_turner(string, ';', ' '), 0);
}

//OK
