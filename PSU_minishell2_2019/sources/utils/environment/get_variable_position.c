/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** get_variable_position
*/

#include "utils.h"

int get_variable_position(char **envp_cpy, char *environment_variable)
{
    int size_variable = my_strlen(environment_variable);
    int i;

    for (i = 0; envp_cpy[i]; i++)
        if (my_strncmp(envp_cpy[i], environment_variable, size_variable) == 0)
            break;
    return (envp_cpy[i]) ? i : -1;
}

//OK
