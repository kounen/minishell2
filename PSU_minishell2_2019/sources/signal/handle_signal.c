/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** handle_signal
*/

#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "utils.h"
#include "minishell2.h"
#include "unused.h"

static void my_ctrl_c(UNUSED int status)
{
    if (isatty(STDIN_FILENO)) {
        if (write(1, "\n", 1) == -1)
            perror("write");
        display_prompt(envp_cpy);
    }
}

void handle_signal(void)
{
    if (signal(SIGINT, my_ctrl_c) == SIG_ERR)
        my_puterr("Error : signal returns SIG_ERR.\n");
}

//OK
