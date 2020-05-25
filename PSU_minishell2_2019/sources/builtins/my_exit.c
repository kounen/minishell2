/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_exit
*/

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "minishell2.h"
#include "colours.h"

static int is_valid_exit_command(char **command)
{
    if (command[1] && command[2]) {
        my_puterr("exit: Expression Syntax.\n");
        return 0;
    } if (command[1] && (command[1][0] < '0' || command[1][0] > '9')) {
        my_puterr("exit: Expression Syntax\n");
        return 0;
    } if (command[1] && (command[1][0] >= '0' || command[1][0] <= '9')
    && !my_str_isnum(command[1])) {
        my_puterr("error: Badly formed number.\n");
        return 0;
    }
    return 1;
}

static void display_exit(void)
{
    if (isatty(STDIN_FILENO)) {
        my_putstr("exit\n");
        my_putstr(HI_YELLOW);
        my_putstr("See you soon to michel, the friendly interactive shell\n");
        my_putstr(DEFAULT);
    }
}

int my_exit(char **command, char ***envp_cpy)
{
    int exit_return;

    if (my_strcmp(command[0], "exit") == 0 && !command[1]) {
        free_array(*envp_cpy);
        display_exit();
        exit(SUCCESS_COMMAND);
    } if (command[1] && my_str_isnum(command[1]) && !command[2]) {
        exit_return = my_atoi(command[1]);
        free_array(*envp_cpy);
        display_exit();
        exit(exit_return);
    } if (is_valid_exit_command(command))
        return SUCCESS_COMMAND;
    else
        return ERROR_COMMAND;
}

//OK
