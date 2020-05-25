/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** implement_redirection
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include "minishell2.h"
#include "utils.h"

static void run_redirection(redirection_t *settings, int fd2, int options)
{
    int file_descriptor = open(settings->cmd[0], options, MODE);

    if (file_descriptor == -1) {
        if (fd2 == STDIN_FILENO) {
            my_puterr(settings->cmd[0]);
            my_puterr(": No such file or directory.\n");
        } else
            perror("open");
    } if (dup2(file_descriptor, fd2) == -1)
        perror("dup2");
    if (close(file_descriptor) == -1)
        perror("close");
}

static void duplicate_file_descriptor(input_t *input)
{
    if (input->stdin != DEFAULT_VALUE)
        if (dup2(input->stdin, STDIN_FILENO) == -1)
            perror("dup2");
    if (input->stdout != DEFAULT_VALUE)
        if (dup2(input->stdout, STDOUT_FILENO) == -1)
            perror("dup2");
}

static void set_redirection(input_t *input)
{
    for (int i = 0; i < input->redirections_number; i++) {
        if (input->redirection[i]->lower == ON_VALUE) {
            run_redirection(input->redirection[i], STDIN_FILENO, L_FLAGS);
            continue;
        } if (input->redirection[i]->lower_lower == ON_VALUE) {
            continue;
        } if (input->redirection[i]->higher == ON_VALUE) {
            run_redirection(input->redirection[i], STDOUT_FILENO, H_FLAGS);
            continue;
        } if (input->redirection[i]->higher_higher == ON_VALUE) {
            run_redirection(input->redirection[i], STDOUT_FILENO, HH_FLAGS);
            continue;
        }
    }
}

void implement_redirection(input_t *input)
{
    duplicate_file_descriptor(input);
    if (input->redirection) {
        set_redirection(input);
    }
}

//OK
