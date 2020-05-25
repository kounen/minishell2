/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_setenv
*/

#include "minishell2.h"
#include "utils.h"

static void display_setenv_error(int what_error)
{
    switch (what_error) {
    case 1:
        my_puterr("setenv: Too many arguments.\n");
        break;
    case 2:
        my_puterr("setenv: Variable name must begin with a letter.\n");
        break;
    case 3:
        my_puterr("setenv: Variable name must contain alphanumeric");
        my_puterr(" characters.\n");
        break;
    default:
        break;
    }
}

static int is_alpha_first_character(char const *string)
{
    if ((string[0] < 'A' || string[0] > 'Z')
    && (string[0] < 'a' || string[0] > 'z'))
        return 0;
    return 1;
}

static int is_alphanumeric_string(char const *string)
{
    for (int i = 0; string[i]; i++)
        if ((string[i] < 'A' || string[i] > 'Z')
        && (string[i] < 'a' || string[i] > 'z')
        && string[i] != '_'
        && (string[i] < '0' || string[i] > '9'))
            return 0;
    return 1;
}

int my_setenv(char **command, char ***envp_cpy)
{
    if (my_strcmp(command[0], "setenv") == 0 && !command[1])
        return my_env(envp_cpy);
    if (command[1] && command[2] && command[3]) {
        display_setenv_error(1);
        return ERROR_COMMAND;
    } if (!is_alpha_first_character(command[1])) {
        display_setenv_error(2);
        return ERROR_COMMAND;
    } if (!is_alphanumeric_string(command[1])) {
        display_setenv_error(3);
        return ERROR_COMMAND;
    }
    command[2] = (command[2]) ? command[2] : "";
    *envp_cpy = update_env(*envp_cpy, command[1], command[2]);
    return SUCCESS_COMMAND;
}

//OK
