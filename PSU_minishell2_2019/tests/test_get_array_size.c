/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** test_get_array_size
*/

#include <criterion/criterion.h>
#include "utils.h"

Test(get_array_size, simpleTest)
{
    char *array[4] = {"string1", "string2", "string3", NULL};

    cr_assert_eq(get_array_size(array), 3);
}

Test(get_array_size, nullArray)
{
    char **array = NULL;

    cr_assert_eq(get_array_size(array), -1);
}

//OK
