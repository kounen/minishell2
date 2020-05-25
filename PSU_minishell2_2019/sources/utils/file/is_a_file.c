/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** is_a_file
*/

#include <sys/stat.h>

int is_a_file(char *target)
{
    struct stat sb;

    stat(target, &sb);
    return S_ISREG(sb.st_mode);
}
