/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** parse_from_semicolon
*/

#include <stddef.h>
#include "utils.h"
#include "minishell2.h"

int parse_from_semicolon(char *input, char ***envp_cpy)
{
    char **input_array;
    char *message = NULL;
    int return_value = 0;

    if (!turn_str_into_array(input, &input_array, ';')) {
        for (int i = 0; input_array[i]; i++) {
            return_value = parse_input(input_array[i], envp_cpy, &message);
            if (return_value == MALLOC_ERROR)
                return MALLOC_ERROR;
            if (message)
                my_puterr(message);
            message = NULL;
            if (return_value == PIPE_OR_REDIRECTION_ERROR)
                return ERROR_COMMAND;
        }
        free_array(input_array);
    }
    return return_value;
}

//OK
