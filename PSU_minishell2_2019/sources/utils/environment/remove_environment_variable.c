/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** remove_environment_variable
*/

#include <stdlib.h>
#include "utils.h"

char **remove_environment_variable(char **envp_cpy, char *variable_name)
{
    int variable_position = get_variable_position(envp_cpy, variable_name);

    if (variable_position == -1)
        return envp_cpy;
    free(envp_cpy[variable_position]);
    while (envp_cpy[variable_position]) {
        envp_cpy[variable_position] = envp_cpy[variable_position + 1];
        variable_position++;
    }
    return envp_cpy;
}

//OK
