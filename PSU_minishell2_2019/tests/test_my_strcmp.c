/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** test_my_strcmp
*/

#include <criterion/criterion.h>
#include "utils.h"

Test(my_strcmp, simpleTest)
{
    cr_assert_eq(my_strcmp("Same string", "Same string"), 0);
}

//OK
