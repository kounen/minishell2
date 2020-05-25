/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** run_father_process
*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include "utils.h"
#include "minishell2.h"

int run_father_process(int fork_number, int return_value)
{
    int status = return_value;

    if (return_value == ERROR_COMMAND)
        return ERROR_COMMAND;
    while (fork_number) {
        status = 0;
        if (wait(&status) == -1)
            perror("wait");
        if (WIFSIGNALED(status)) {
            display_process_error(status);
            if (WCOREDUMP(status))
                my_puterr(" (core dumped)");
            else
                status += 128;
            if (write(2, "\n", 1) == -1)
                perror("write");
        }
        status = (WIFEXITED(status)) ? (WEXITSTATUS(status)) : status;
        fork_number--;
    }
    return status;
}

//OK
