/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** run_shell
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell2.h"
#include "utils.h"
#include "get_input.h"

int run_shell(char **envp_cpy)
{
    char *input;
    size_t input_size;
    int return_value;

    while (RUNNING) {
        if (isatty(STDIN_FILENO)) display_prompt(envp_cpy);
        if (get_input(&input, &input_size) == -1) {
            my_putstr("exit\n");
            break;
        }
        if (!clean_input(&input))
            return_value = parse_from_semicolon(input, &envp_cpy);
        else return 84;
        if (return_value == MALLOC_ERROR) return 84;
        if (return_value == ERROR_COMMAND) return ERROR_COMMAND;
        free(input);
    }
    free(input);
    return return_value;
}

//OK
