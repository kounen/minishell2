/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** engine_pipe
*/

#include <stdlib.h>
#include "minishell2.h"
#include "utils.h"

static void initialise_input_structure(input_t *input_settings)
{
    input_settings->command = NULL;
    input_settings->file_descriptor = DEFAULT_VALUE;
    input_settings->stdin = DEFAULT_VALUE;
    input_settings->stdout = DEFAULT_VALUE;
    initialise_input_redirection_structure(&input_settings);
    input_settings->next = NULL;
    input_settings->previous = NULL;
}

static int malloc_input_structure(input_t **input_settings)
{
    *input_settings = malloc(sizeof(input_t));
    if (!(*input_settings)) {
        my_puterr("Error : malloc returns NULL.\n");
        return 1;
    }
    return 0;
}

int engine_pipe(chain_t *list, int **pipefd, char **input_array)
{
    input_t *input_settings;

    if (malloc_input_structure(&input_settings))
        return 1;
    initialise_input_structure(input_settings);
    if (fill_list_of_pipe(list, input_settings, pipefd, input_array))
        return 1;
    return 0;
}
