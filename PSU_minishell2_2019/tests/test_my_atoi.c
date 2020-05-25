/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** test_my_atoi
*/

#include <criterion/criterion.h>
#include "utils.h"

Test(my_atoi, positiveNumber)
{
    cr_assert_eq(my_atoi("10"), 10);
}

Test(my_atoi, negativeNumber)
{
    cr_assert_eq(my_atoi("-3"), -3);
}

Test(my_atoi, wrongCharacter_lowerThanZero)
{
    cr_assert_eq(my_atoi("2-7"), 0);
}

Test(my_atoi, wrongCharacter_highterThanNine)
{
    cr_assert_eq(my_atoi("67L98"), 0);
}

//OK
