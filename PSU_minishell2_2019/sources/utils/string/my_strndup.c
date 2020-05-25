/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_strndup
*/

#include <stdlib.h>
#include "utils.h"

char *my_strndup(char *source, int size)
{
    char *destination = malloc(size + 1);

    if (!destination) {
        my_puterr("Error : malloc returns NULL.\n");
        return NULL;
    }
    for (int i = 0; i < size; i++)
        destination[i] = source[i];
    destination[size] = '\0';
    return destination;
}

//OK
