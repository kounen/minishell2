/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** free_array
*/

#include <stdlib.h>

void free_array(char *array[])
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

//OK
