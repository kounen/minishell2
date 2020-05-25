/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** test_get_variable_position
*/

#include <criterion/criterion.h>
#include "utils.h"

Test(get_variable_position, simpleTest)
{
    char *envp[4] = {"PATH", "USER", "PWD", NULL};
    char environment_variable[] = "USER";

    cr_assert_eq(get_variable_position(envp, environment_variable), 1);
}

Test(get_variable_position, unknownEnvironmentVariable)
{
    char *envp[4] = {"PATH", "USER", "PWD", NULL};
    char environment_variable[] = "HOME";

    cr_assert_eq(get_variable_position(envp, environment_variable), -1);
}

//OK
