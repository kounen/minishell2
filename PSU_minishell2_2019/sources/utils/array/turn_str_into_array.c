/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** turn_str_into_array
*/

#include <stdlib.h>
#include "utils.h"

static int malloc_array_from_string(char *string, char ***array, char turner)
{
    int words_number = count_words_from_turner(string, turner, '\0');

    *array = malloc(sizeof(char *) * (words_number + 1));
    if (!(*array)) {
        my_puterr("Error : malloc returns NULL.\n");
        return 1;
    }
    return 0;
}

static int is_only_turner_into_string(char const *string, char turner)
{
    int turner_number = 0;

    for (int i = 0; string[i]; i++)
        if (string[i] == turner)
            turner_number++;
    if (turner_number == my_strlen(string))
        return 1;
    return 0;
}

int turn_str_into_array(char *string, char ***array, char turner)
{
    int i = 0;
    int j = 0;

    if (is_only_turner_into_string(string, turner) && turner == '|')
        return 2;
    if (is_only_turner_into_string(string, turner))
        return 1;
    if (malloc_array_from_string(string, array, turner))
        return 1;
    while (string[i]) {
        while (string[i] && (string[i] == turner || string[i] == ' '))
            i++;
        if (string[i])
            (*array)[j++] = fill_element(&string[i], &i, turner, '\0');
        else
            (*array)[j++] = NULL;
        i += (string[i]) ? 1 : 0;
    }
    (*array)[j] = NULL;
    return 0;
}

//OK
