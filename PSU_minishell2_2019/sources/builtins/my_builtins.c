/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_builtins
*/

#include "minishell2.h"
#include "utils.h"

int my_builtins(input_t *input, char ***envp_cpy)
{
    if (my_strcmp(input->command[0], "exit") == 0)
        return my_exit(input->command, envp_cpy);
    if (my_strcmp(input->command[0], "env") == 0 && !input->command[1])
        return my_env(envp_cpy);
    if (my_strcmp(input->command[0], "cd") == 0)
        return my_cd(input->command, envp_cpy);
    if (my_strcmp(input->command[0], "setenv") == 0)
        return my_setenv(input->command, envp_cpy);
    if (my_strcmp(input->command[0], "unsetenv") == 0)
        return my_unsetenv(input->command, envp_cpy);
    if (my_strcmp(input->command[0], "echo") == 0)
        return my_echo(input->command);
    return OTHER_COMMAND;
}

//OK
