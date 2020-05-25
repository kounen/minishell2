/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** close_file_descriptor
*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>

void close_file_descriptor(int const *pipefd)
{
    for (int i = 0; pipefd && pipefd[i]; i++)
        if (close(pipefd[i]) == -1)
            perror("close");
}

//OK
