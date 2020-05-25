/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** get_input
*/

#include <stdio.h>

int get_input(char **input, size_t *input_size)
{
    *input = NULL;
    *input_size = 0;
    return getline(input, input_size, stdin);
}

//OK
