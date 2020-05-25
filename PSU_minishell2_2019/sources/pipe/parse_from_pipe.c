/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** parse_from_pipe
*/

#include <stdlib.h>
#include "utils.h"
#include "minishell2.h"

static int malloc_pipefd(int **pipefd, char **input_array)
{
    int pipe_number = count_pipes_number(input_array);

    if (pipe_number > 0) {
        *pipefd = malloc(sizeof(int) * (pipe_number * PIPE + 1));
        if (!(*pipefd)) {
            my_puterr("Error : malloc returns NULL.\n");
            return 1;
        }
    }
    return 0;
}

static int is_valid_pipe(int return_value, char *input, char **message)
{
    if (return_value == PIPE_OR_REDIRECTION_ERROR) {
        *message = "Invalid null command.\n";
        return 0;
    } if (input[0] == '|') {
        *message = "Invalid null command.\n";
        return 0;
    }
    for (int i = 0; input[i]; i++)
        if (input[i] != '|' && input[i + 1] == '|'
        && (input[i + 2] == '<' || input[i + 2] == '>' || !input[i + 2])) {
            *message = "Invalid null command.\n";
            return 0;
        }
    return 1;
}

int parse_from_pipe(char *input, chain_t *list, int **pipefd, char **message)
{
    char **input_array;
    input_t *input_settings;
    int return_value;

    return_value = turn_str_into_array(input, &input_array, '|');
    if (return_value == MALLOC_ERROR) return MALLOC_ERROR;
    if (!is_valid_pipe(return_value, input, message)) return ERROR_COMMAND;
    if (malloc_pipefd(pipefd, input_array)) {
        free_array(input_array);
        return MALLOC_ERROR;
    } if (engine_pipe(list, pipefd, input_array)) {
        free_array(input_array);
        return MALLOC_ERROR;
    }
    input_settings = list->head;
    return_value = parse_from_redirection(&input_settings, message);
    if (return_value == MALLOC_ERROR) return MALLOC_ERROR;
    free_array(input_array);
    return return_value;
}

//OK
