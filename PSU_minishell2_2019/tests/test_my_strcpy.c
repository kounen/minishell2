/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** test_my_strcpy
*/

#include <criterion/criterion.h>
#include "utils.h"

Test(my_strcpy, simpleTest)
{
    char string1[4] = {'O', 'U', 'I', '\0'};
    char string2[4] = {0};

    cr_assert_str_eq(my_strcpy(string2, string1), "OUI");
}

//OK
