/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_unsetenv
*/

#include "minishell2.h"
#include "utils.h"

int my_unsetenv(char **command, char ***envp_cpy)
{
    if (command[0] && !command[1]) {
        my_puterr("unsetenv: Too few arguments.\n");
        return ERROR_COMMAND;
    }
    *envp_cpy = remove_environment_variable(*envp_cpy, command[1]);
    return SUCCESS_COMMAND;
}

//OK
