/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** run_command
*/

#include "minishell2.h"

int run_command(input_t *input, char ***envp_cpy, int *pipefd)
{
    int return_value = my_builtins(input, envp_cpy);

    if (return_value == SUCCESS_COMMAND)
        return SUCCESS_COMMAND;
    else if (return_value == ERROR_COMMAND)
        return ERROR_COMMAND;
    else
        return my_execve(input, *envp_cpy, pipefd);
}

//OK
