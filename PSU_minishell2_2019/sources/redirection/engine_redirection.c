/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** engine_redirection
*/

#include <stdlib.h>
#include "minishell2.h"
#include "utils.h"
#include "size_max.h"

static int control_last_redirection(input_t **input, char **cmd, int a, int *b)
{
    if (cmd[a + PIPE] && cmd[a + PIPE][0] != '<' && cmd[a + PIPE][0] != '>')
        a += PIPE;
    if (cmd[a][0] && cmd[a][0] != '<' && cmd[a][0] != '>')
        for (int i; cmd[a]; (*b)++, a++) {
            i = 0;
            (*input)->command[*b] = malloc(SIZE_MAX);
            if (!(*input)->command[*b]) {
                my_puterr("Error : malloc returns NULL.\n");
                return 1;
            }
            while (cmd[a][i]) {
                (*input)->command[*b][i] = cmd[a][i];
                i++;
            }
            (*input)->command[*b][i] = '\0';
        }
    return 0;
}

static int fill_redirection_element(input_t **input, char **cmd, int i, int j)
{
    int a, b;

    if (initialise_redirection_structure(input, j))
        return 1;
    if (cmd[i + 1])
        if (my_str_to_word_array(cmd[i + 1], &(*input)->redirection[j]->cmd))
            return 1;
    initialise_input_array(input, cmd, &a , &b);
    if (control_last_redirection(input, cmd, a, &b))
        return 1;
    (*input)->command[a] = NULL;
    return 0;
}

static int fill_redirection_structure(input_t **input, char **input_array)
{
    for (int i = 0, index = 0; input_array[i]; i++) {
        if (input_array[i][0] == '<' || input_array[i][0] == '>') {
            if (fill_redirection_element(input, input_array, i, index))
                return 1;
            if (input_array[i][0] == '<' && input_array[i][1] != '<') {
                (*input)->redirection[index]->lower = ON_VALUE;
                continue;
            } if (input_array[i][0] == '<' && input_array[i][1] == '<') {
                (*input)->redirection[index]->lower_lower = ON_VALUE;
                continue;
            } if (input_array[i][0] == '>' && input_array[i][1] != '>') {
                (*input)->redirection[index]->higher = ON_VALUE;
                continue;
            } if (input_array[i][0] == '>' && input_array[i][1] == '>') {
                (*input)->redirection[index]->higher_higher = ON_VALUE;
                continue;
            }
            index++;
        }
    }
    return 0;
}

static int malloc_redirection_structure(input_t **input)
{
    (*input)->redirection = malloc(sizeof(redirection_t *) * SIZE_MAX);
    if (!(*input)->redirection) {
        my_puterr("Error : malloc returns NULL.\n");
        return 1;
    }
    return 0;
}

int engine_redirection(input_t **input, char **input_array)
{
    if (malloc_redirection_structure(input))
        return 1;
    if (fill_redirection_structure(input, input_array))
        return 1;
    return 0;
}

//OK
