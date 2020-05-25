/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** initialise_redirection_structure
*/

#include <stdlib.h>
#include "minishell2.h"
#include "utils.h"

static int malloc_redirection_structure_element(input_t **input, int index)
{
    (*input)->redirection[index] = malloc(sizeof(redirection_t));
    if (!(*input)->redirection[index]) {
        my_puterr("Error : malloc returns NULL.\n");
        return 1;
    }
    return 0;
}

int initialise_redirection_structure(input_t **input, int index)
{
    if (malloc_redirection_structure_element(input, index))
        return 1;
    (*input)->redirection[index]->cmd = NULL;
    (*input)->redirection[index]->lower = OFF_VALUE;
    (*input)->redirection[index]->lower_lower = OFF_VALUE;
    (*input)->redirection[index]->higher = OFF_VALUE;
    (*input)->redirection[index]->higher_higher = OFF_VALUE;
    (*input)->redirections_number += 1;
    return 0;
}

//OK
