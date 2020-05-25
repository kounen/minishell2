/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** update_env
*/

#include <stdbool.h>
#include <stdlib.h>
#include "utils.h"
#include "is_in_environment.h"

char **update_env(char **envp_cp, char *name, char *content)
{
    int is_in_env = IS_IN_ENV(envp_cp, name);
    int lines_nbr = get_array_size(envp_cp);
    char **new_env = malloc(sizeof(char *) * (lines_nbr + 2 - is_in_env));
    char *tmp;

    if (!new_env) {
        my_puterr("Error : malloc returns NULL.\n");
        return NULL;
    }
    new_env[lines_nbr + 1 - is_in_env] = NULL;
    for (int i = 0; envp_cp[i]; i++)
        new_env[i] = my_strdup(envp_cp[i]);
    tmp = my_strcat(name, "=");
    if (is_in_env == true) {
        free(new_env[get_variable_position(envp_cp, name)]);
        new_env[get_variable_position(envp_cp, name)] = my_strcat(tmp, content);
    } else
        new_env[lines_nbr] = my_strcat(tmp, content);
    free(tmp);
    return new_env;
}

//OK
