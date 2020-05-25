/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** display_welcome_message
*/

#include <unistd.h>
#include "colours.h"
#include "utils.h"
#include "minishell2.h"

void display_welcome_message(void)
{
    if (isatty(STDIN_FILENO)) {
        my_putstr(HI_YELLOW);
        my_putstr("Welcome to michel, the friendly interactive shell\n");
        my_putstr(DEFAULT);
    }
}

//OK
