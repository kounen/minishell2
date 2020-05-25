/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** split_from_redirection
*/

#include <stdlib.h>
#include "utils.h"
#include "size_max.h"

static int malloc_destination(char **source, char ***destination)
{
    int words_number = count_words_from_turner(source[0], '<', '>');

    *destination = malloc(sizeof(char *) * (words_number + SIZE_MAX));
    if (!(*destination)) {
        my_puterr("Error : malloc returns NULL.\n");
        return 1;
    }
    return 0;
}

int split_from_redirection(char **src, char ***dest)
{
    int x;
    int	i = -1;

    if (malloc_destination(src, dest))
        return 1;
    for (int y = 0; src[y]; y++) {
        x = 0;
        while (src[y][x]) {
            while (src[y][x] && src[y][x] == ' ')
                x++;
            if (src[y][x])
                (*dest)[++i] = fill_element(&(src[y][x]), &x, '<', '>');
            else
                (*dest)[++i] = NULL;
            x += (src[y][x]) ? 1 : 0;
        }
    }
    (*dest)[i + 1] = NULL;
    return 0;
}

//OK
