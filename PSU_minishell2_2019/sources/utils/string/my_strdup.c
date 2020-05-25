/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "utils.h"

char *my_strdup(char const *source)
{
    char *destination = malloc(my_strlen(source) + 1);

    if (!destination) {
        my_puterr("Error : malloc returns NULL.\n");
        return NULL;
    }
    destination = my_strcpy(destination, source);
    return destination;
}

//OK
