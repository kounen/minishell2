/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** initialise_input_redirection_structure
*/

#include <stddef.h>
#include "minishell2.h"

void initialise_input_redirection_structure(input_t **input_settings)
{
    (*input_settings)->redirections_number = 0;
    (*input_settings)->redirection = NULL;
}

//OK
