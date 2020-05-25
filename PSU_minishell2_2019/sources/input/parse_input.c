/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** parse_input
*/

#include <stdlib.h>
#include "utils.h"
#include "minishell2.h"

int parse_input(char *input, char ***envp_cpy, char **error_redirection)
{
    chain_t list;
    int *pipefd = NULL;
    int return_value;
    int fork_number = 0;

    initialise_list(&list);
    return_value = parse_from_pipe(input, &list, &pipefd, error_redirection);
    if (return_value == MALLOC_ERROR) return MALLOC_ERROR;
    else if (return_value == ERROR_COMMAND) return PIPE_OR_REDIRECTION_ERROR;
    for (input_t *current = list.head; current; current = current->next) {
        return_value = run_command(current, envp_cpy, pipefd);
        if (return_value == FORK_USED) {
            return_value = SUCCESS_COMMAND;
            fork_number++;
        }
    }
    close_file_descriptor(pipefd);
    return_value = run_father_process(fork_number, return_value);
    free(pipefd);
    return return_value;
}

//OK
