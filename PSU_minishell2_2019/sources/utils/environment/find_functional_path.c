/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** find_functional_path
*/

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

static int get_size_path(char const *element_path)
{
    int i = 0;

    while (element_path[i] && element_path[i] != ':')
        i++;
    return i;
}

char *find_functional_path(char **envp_cpy, char **command)
{
    char *all_path = my_getenv(envp_cpy, "PATH");
    char *current_path = NULL;
    char *copy_current;
    int i = 0;

    while (all_path && all_path[i] && !current_path) {
        current_path = my_strndup(all_path + i, get_size_path(all_path + i));
        copy_current = my_strcat(current_path, "/");
        free(current_path);
        current_path = my_strcat(copy_current, command[0]);
        free(copy_current);
        if (!access(current_path, X_OK))
            break;
        free(current_path);
        current_path = NULL;
        i += get_size_path(all_path + i) + 1;
    }
    free(all_path);
    return current_path;
}

//OK
