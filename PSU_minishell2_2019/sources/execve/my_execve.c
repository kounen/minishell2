/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_execve
*/

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "minishell2.h"
#include "utils.h"
#include "create_process.h"

static void display_error_execve(char *binary_not_compatible)
{
    my_puterr(binary_not_compatible);
    my_puterr(": Exec format error. Wrong Architecture.\n");
}

static void display_permission_error(DIR *directory, char *command)
{
    my_puterr(": Permission denied.\n");
    if (!is_a_file(command))
        if (closedir(directory) == -1)
            perror("closedir");
}

static int is_a_valid_binary(char *path, char *command)
{
    DIR *directory = (path) ? opendir(path) : NULL;

    if (!path || access(path, X_OK) || directory) {
        my_puterr(command);
        if (directory || is_a_file(command))
            display_permission_error(directory, command);
        else
            my_puterr(": Command not found.\n");
        return 0;
    }
    return 1;
}

static int is_a_binary(char const *string)
{
    for (int i = 0; string[i]; i++)
        if (string[i] == '/')
            return 1;
    return 0;
}

int my_execve(input_t *input, char **envp_cpy, int *pipefd)
{
    char *path = !is_a_binary(input->command[0])
    ? find_functional_path(envp_cpy, input->command) : NULL;
    pid_t pid;

    if (!path) path = my_strdup(input->command[0]);
    if (!is_a_valid_binary(path, input->command[0])) {
        free(path);
        return ERROR_COMMAND;
    }
    pid = create_process();
    if (pid == -1) perror("fork");
    else if (pid == 0) {
        implement_redirection(input);
        close_file_descriptor(pipefd);
        if (execve(path, input->command, envp_cpy) == -1) {
            display_error_execve(input->command[0]);
            exit(ERROR_COMMAND);
        }
    }
    free(path);
    return FORK_USED;
}

//OK
