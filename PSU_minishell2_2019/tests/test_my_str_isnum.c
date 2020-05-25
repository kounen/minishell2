/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** test_my_str_isnum
*/

#include <criterion/criterion.h>
#include "utils.h"

Test(my_str_isnum, numericString)
{
    cr_assert_eq(my_str_isnum("123457890"), 1);
}

Test(my_str_isnum, wrongNumericString_CharacterLowerThanZero)
{
    cr_assert_eq(my_str_isnum("1234+=*/57890"), 0);
}

Test(my_str_isnum, wrongNumericString_CharacterHighterThanNine)
{
    cr_assert_eq(my_str_isnum("1234azerty57890"), 0);
}

//OK
