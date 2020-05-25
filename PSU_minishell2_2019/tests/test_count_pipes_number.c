/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** test_count_pipes_number
*/

#include <criterion/criterion.h>
#include "utils.h"

Test(count_pipes_number, simpleTest)
{
    char *array[4] = {"string1", "string2", "string3", NULL};

    cr_assert_eq(count_pipes_number(array), 2);
}

//OK
