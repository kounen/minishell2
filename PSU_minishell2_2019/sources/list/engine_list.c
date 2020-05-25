/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** engine_list
*/

#include <stdlib.h>
#include "minishell2.h"
#include "utils.h"

static int malloc_list_element(input_t **current)
{
    *current = malloc(sizeof(input_t));
    if (!(*current)) {
        my_puterr("Error : malloc returns NULL.\n");
        return 1;
    }
    return 0;
}

static int add_element_into_list(input_t *input, chain_t *list)
{
    input_t *current;

    if (malloc_list_element(&current))
        return 1;
    current->command = input->command;
    current->file_descriptor = input->file_descriptor;
    current->stdin = input->stdin;
    current->stdout = input->stdout;
    current->next = NULL;
    current->previous = list->feet;
    (list->feet) ? (list->feet->next = current) : (list->head = current);
    list->feet = current;
    return 0;
}

int fill_list_of_pipe(chain_t *list, input_t *input, int **pipefd, char **cmd)
{
    int i, pipe_index;
    int file_descriptor[2];
    int pipe_nbr = count_pipes_number(cmd);

    for (i = 0, pipe_index = 0; pipe_nbr; i++, pipe_index += PIPE, pipe_nbr--) {
        if (put_pipe(file_descriptor, input, pipefd, pipe_index)) return 1;
        if (my_str_to_word_array(cmd[i], &input->command)) return 1;
        if (add_element_into_list(input, list)) return 1;
        input->stdin = file_descriptor[0];
    }
    input->stdout = DEFAULT_VALUE;
    if (my_str_to_word_array(cmd[i], &input->command))
        return 1;
    if (add_element_into_list(input, list))
        return 1;
    return 0;
}

//OK
