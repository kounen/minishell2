/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_puterr
*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "utils.h"

void my_puterr(char const *string)
{
    if (string) {
        if (write(2, string, my_strlen(string)) == -1)
            perror("write");
    } else
        my_puterr("Error : my_puterr doesn't work with a NULL string.\n");
}

//OK
