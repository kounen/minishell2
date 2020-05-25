/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_getenv
*/

#include <stdlib.h>
#include "utils.h"

static char *get_variable_content(char const *environement_variable)
{
    char *variable_content;
    int i = 0;
    int size_variable_content;

    while (environement_variable[i] != '=')
        i++;
    i += 1;
    size_variable_content = my_strlen(environement_variable) - i;
    variable_content = malloc(size_variable_content + 1);
    if (!variable_content) {
        my_puterr("Error : malloc returns NULL.\n");
        return NULL;
    }
    variable_content[size_variable_content] = '\0';
    for (int j = 0; environement_variable[i]; i++, j++)
        variable_content[j] = environement_variable[i];
    return variable_content;
}

char *my_getenv(char *envp_cpy[], char const *name_variable)
{
    int size_name_variable = my_strlen(name_variable);

    for (int i = 0; i < get_array_size(envp_cpy); i++)
        if (my_strncmp(envp_cpy[i], name_variable, size_name_variable) == 0)
            return get_variable_content(envp_cpy[i]);
    return NULL;
}

//OK
