/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** parse_from_redirection
*/

#include "minishell2.h"
#include "utils.h"

static void count_redirections(char **input_array, int *redirec_nbr, int *i)
{
    for (*i = 0; input_array[*i]; (*i)++)
        if (input_array[*i][0] == '<' || input_array[*i][0] == '>')
            (*redirec_nbr)++;
}

static int is_redirec_valid(char **input, int *redirec_nbr, char **message)
{
    int i;

    count_redirections(input, redirec_nbr, &i);
    if (input[i - 1][0] == '<' || input[i - 1][0] == '>') {
        *message = "Missing name for redirect.\n";
        return 0;
    }
    i = 0;
    if ((input[i][0] == '<' || input[i][0] == '>')
    && input[i + 1][0] != '<' && input[i + 1][0] != '>') {
        *message = "Invalid null command.\n";
        return 0;
    }
    return 1;
}

int parse_from_redirection(input_t **input, char **message)
{
    char **input_array;
    int redirections_number;

    while ((*input)) {
        redirections_number = 0;
        if (split_from_redirection((*input)->command, &input_array))
            return MALLOC_ERROR;
        initialise_input_redirection_structure(input);
        if (!is_redirec_valid(input_array, &redirections_number, message))
            return ERROR_COMMAND;
        if (redirections_number)
            if (engine_redirection(input, input_array))
                return MALLOC_ERROR;
        *input = (*input)->next;
    }
    return 0;
}

//OK
