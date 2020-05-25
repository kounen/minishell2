/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_cd
*/

#include <sys/types.h>
#include <dirent.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "utils.h"
#include "old_path.h"
#include "minishell2.h"

static void display_opendir_error(char *directory)
{
    if (is_a_file(directory))
        my_puterr(": Not a directory.\n");
    else
        my_puterr(": No such file or directory.\n");
}

static int simple_cd(char *directory)
{
    DIR *folder = opendir(directory);

    free(old_path);
    old_path = getcwd(NULL, 0);
    if (!folder) {
        my_puterr(directory);
        display_opendir_error(directory);
        return ERROR_COMMAND;
    } else if (folder) {
        if (chdir(directory) == -1) {
            perror("chdir");
            return ERROR_COMMAND;
        }
    } if (closedir(folder) == -1) {
        perror("closedir");
        return ERROR_COMMAND;
    }
    return SUCCESS_COMMAND;
}

static int less_cd(void)
{
    char *old_path_duplicate = NULL;

    if (!old_path) {
        my_puterr(": No such file or directory.\n");
        return ERROR_COMMAND;
    }
    old_path_duplicate = my_strdup(old_path);
    free(old_path);
    old_path = getcwd(NULL, 0);
    if (chdir(old_path_duplicate) == -1) {
        free(old_path_duplicate);
        perror("chdir");
        return ERROR_COMMAND;
    }
    free(old_path_duplicate);
    return SUCCESS_COMMAND;
}

static int home_cd(char **envp_cpy)
{
    char *home = my_getenv(envp_cpy, "HOME");

    free(old_path);
    old_path = getcwd(NULL, 0);
    if (!home) {
        my_puterr("cd: No home directory.\n");
        return ERROR_COMMAND;
    } if (chdir(home) == -1) {
        perror("chdir");
        free(home);
        return ERROR_COMMAND;
    }
    free(home);
    return SUCCESS_COMMAND;
}

int my_cd(char **cmd, char ***envp_cp)
{
    int return_value;
    char buffer[PATH_MAX + 1];

    cmd[1] = (cmd[1]) ? cmd[1] : "";
    if (my_strcmp(cmd[1], "") && cmd[2]) {
        my_puterr("cd: Too many arguments.\n");
        return ERROR_COMMAND;
    } if (my_strcmp(cmd[1], "") == 0 || my_strcmp(cmd[1], "~") == 0) {
        return_value = home_cd(*envp_cp);
        *envp_cp = update_env(*envp_cp, "PWD", getcwd(buffer, sizeof(buffer)));
    } if (my_strcmp(cmd[1], "-") == 0) {
        return_value = less_cd();
        *envp_cp = update_env(*envp_cp, "PWD", getcwd(buffer, sizeof(buffer)));
    } if (my_strcmp(cmd[1], "") && my_strcmp(cmd[1], "~")
    && my_strcmp(cmd[1], "-")) {
        return_value = simple_cd(cmd[1]);
        *envp_cp = update_env(*envp_cp, "PWD", getcwd(buffer, sizeof(buffer)));
    }
    return return_value;
}

//OK
