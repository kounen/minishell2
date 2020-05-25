/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** initialise_list
*/

#include <stddef.h>
#include "minishell2.h"

void initialise_list(chain_t *list)
{
    list->head = NULL;
    list->feet = NULL;
}

//OK
