/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** duplicate_array
*/

#include <stdlib.h>
#include "utils.h"

static int fill_string(char const *source, char **destination)
{
    *destination = malloc(my_strlen(source) + 1);
    if (!(*destination)) {
        my_puterr("Error : malloc returns NULL.\n");
        return 1;
    }
    (*destination)[my_strlen(source)] = '\0';
    for (int i = 0; source[i]; i++)
        (*destination)[i] = source[i];
    return 0;
}

int duplicate_array(char *source[], char ***destination)
{
    int size_source = get_array_size(source);

    if (size_source == -1) {
        my_puterr("Error : environment doesn't exist.\n");
        return 1;
    }
    *destination = malloc(sizeof(char *) * (size_source + 1));
    if (!(*destination)) {
        my_puterr("Error : malloc returns NULL.\n");
        return 1;
    }
    (*destination)[size_source] = NULL;
    for (int i = 0; source[i]; i++)
        if (fill_string(source[i], &(*destination)[i])) {
            free_array(*destination);
            return 1;
        }
    return 0;
}

//OK
