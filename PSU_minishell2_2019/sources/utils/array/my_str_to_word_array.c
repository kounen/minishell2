/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "utils.h"

static int count_letters(char const *string)
{
    int letters_number = 0;

    while (string[letters_number] && string[letters_number] != ' ')
        letters_number++;
    return letters_number;
}

static int fill_array_from_string(char const *string, char ***array)
{
    int i = 0;
    int y = 0;
    int x;

    while (string[i]) {
        x = 0;
        (*array)[y] = malloc(count_letters(&string[i]) + 1);
        if (!(*array)[y]) {
            my_puterr("Error : malloc returns NULL.\n");
            return 1;
        }
        while (string[i] && string[i] != ' ')
            (*array)[y][x++] = string[i++];
        (*array)[y][x] = '\0';
        i += (string[i]) ? 1 : 0;
        y += (string[i]) ? 1 : 0;
    }
    (*array)[y + 1] = NULL;
    return 0;
}

static int count_words(char const *string)
{
    int words_number = 0;

    for (int i = 0; string[i]; i++) {
        while (string[i] && string[i] == ' ')
            i++;
        words_number += (string[i]) ? 1 : 0;
    }
    return words_number;
}

static int malloc_array(char const *string, char ***array)
{
    *array = malloc(sizeof(char *) * (count_words(string) + 1));

    if (!(*array)) {
        my_puterr("Error : malloc returns NULL.\n");
        return 1;
    }
    return 0;
}

int my_str_to_word_array(char const *string, char ***array)
{
    if (malloc_array(string, array))
        return 1;
    if (fill_array_from_string(string, array)) {
        free_array(*array);
        return 1;
    }
    return 0;
}

//OK
