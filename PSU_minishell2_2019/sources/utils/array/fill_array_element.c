/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** fill_array_element
*/

#include <stdlib.h>
#include "utils.h"

static char *malloc_element(char const *source, int size)
{
    char *destination_element;
    int i;

    while (source[size - 1] == ' ')
        size--;
    destination_element = malloc(size + 1);
    if (!destination_element) {
        my_puterr("Error : malloc returns NULL.\n");
        return NULL;
    }
    for (i = 0; source[i] && i < size; i++)
        destination_element[i] = source[i];
    destination_element[i] = '\0';
    return destination_element;
}

char *fill_element(char const *src, int *index, char turner1, char turner2)
{
    int i;
    int j = 0;

    for (i = 0; src[i] == turner1 || src[i] == turner2; i++)
        j++;
    for (i = 0; src[i] && ((src[i] != turner1 && src[i] != turner2)); i++)
        (*index)++;
    while (j) {
        (*index)++;
        i++;
        j--;
    }
    (*index) -= 1;
    return malloc_element(src, i);
}

//OK
