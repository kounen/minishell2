/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** initialise_input_array
*/

#include <stddef.h>
#include "minishell2.h"

void initialise_input_array(input_t **input, char **cmd, int *a, int *b)
{
    for (*a = 0; (*input)->command[*a]; (*a)++)
        (*input)->command[*a] = NULL;
    for (*a = 0, *b = 0; cmd[*b][0] != '<' && cmd[*b][0] != '>'; (*a)++, (*b)++)
        (*input)->command[*a] = cmd[*b];
}

//OK
