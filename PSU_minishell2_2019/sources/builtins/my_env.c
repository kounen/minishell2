/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_env
*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "utils.h"
#include "minishell2.h"

int my_env(char ***envp_cpy)
{
    for (int i = 0; (*envp_cpy)[i]; i++) {
        my_putstr((*envp_cpy)[i]);
        if (write(1, "\n", 1) == -1)
            perror("write");
    }
    return SUCCESS_COMMAND;
}

//OK
