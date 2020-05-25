/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** clean_input
*/

#include <stdlib.h>
#include "utils.h"

static int count_printable_characters(char const *input)
{
    int printable_characters_number = 0;

    for (int i = 0; input[i]; i++) {
        if (input[i] >= 33 && input[i] <= 126)
            printable_characters_number++;
        if (input[i] == ' ' && (input[i + 1] >= 33 && input[i + 1] <= 126)
        && input[i + 1] != ';' && input[i + 1] != '|'
        && input[i + 1] != '<' && input[i + 1] != '>')
            printable_characters_number++;
        if (input[i] == '\t' && (input[i + 1] >= 33 && input[i + 1] <= 126)
        && input[i + 1] != ';' && input[i + 1] != '|'
        && input[i + 1] != '<' && input[i + 1] != '>')
            printable_characters_number++;
    }
    return printable_characters_number;
}

static int count_spaces_and_tabs(char const *input)
{
    int i = 0;

    while (input[i] && (input[i] == ' ' || input[i] == '\t'))
        i++;
    return i;
}

static void fill_clean_input(char *clean_input, char const *input)
{
    int j = 0;

    for (int i = count_spaces_and_tabs(input); input[i]; i++) {
        if (input[i] >= 33 && input[i] <= 126) {
            clean_input[j] = input[i];
            j++;
        } if (input[i] == ' ' && (input[i + 1] >= 33 && input[i + 1] <= 126)
        && input[i + 1] != ';' && input[i + 1] != '|'
        && input[i + 1] != '<' && input[i + 1] != '>') {
            clean_input[j] = input[i];
            j++;
        } if (input[i] == '\t' && (input[i + 1] >= 33 && input[i + 1] <= 126)
        && input[i + 1] != ';' && input[i + 1] != '|'
        && input[i + 1] != '<' && input[i + 1] != '>') {
            clean_input[j] = ' ';
            j++;
        }
    }
    clean_input[j] = '\0';
}

int clean_input(char **input)
{
    char *clean_input = malloc(count_printable_characters(*input) + 1);

    if (!clean_input) {
        my_puterr("Error : malloc returns NULL.\n");
        return 1;
    }
    fill_clean_input(clean_input, *input);
    free(*input);
    *input = clean_input;
    return 0;
}

//OK
