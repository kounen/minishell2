/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** display_prompt
*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell2.h"
#include "utils.h"
#include "colours.h"

static void display_end_prompt(void)
{
    my_putstr(HI_YELLOW);
    if (write(1, "]", 1) == -1)
        perror("write");
    my_putstr(HI_RED);
    if (write(1, "$ ", 2) == -1)
        perror("write");
}

static void display_current_folder(char const *pwd)
{
    int number_of_folders = 0;
    int i;

    my_putstr(HI_CYAN);
    if (write(1, " ", 1) == -1)
        perror("write");
    for (i = 1; pwd[i]; i++)
        if (pwd[i] == '/')
            number_of_folders++;
    for (i = 1; pwd[i] && number_of_folders; i++)
        if (pwd[i] == '/')
            number_of_folders--;
    while (pwd[i]) {
        if (write(1, &pwd[i], 1) == -1)
            perror("write");
        i++;
    }
}

static void display_machine(char const *machine)
{
    for (int i = 0; machine[i] && machine[i] != '.'; i++)
        if (write(1, &machine[i], 1) == -1)
            perror("write");
}

static void display_user(char *user)
{
    my_putstr(B_BLUE);
    my_putstr(user);
    my_putstr(HI_YELLOW);
    if (write(1, "@", 1) == -1)
        perror("write");
}

void display_prompt(char *envp_cpy[])
{
    char *user = my_getenv(envp_cpy, "USER");
    char *pwd = my_getenv(envp_cpy, "PWD");
    char *machine = my_getenv(envp_cpy, "HOSTNAME");

    my_putstr(HI_YELLOW);
    if (write(1, "[", 1) == -1)
        perror("write");
    if (user)
        display_user(user);
    my_putstr(B_HI_RED);
    if (machine)
        display_machine(machine);
    else
        my_putstr("michel");
    if (pwd)
        display_current_folder(pwd);
    display_end_prompt();
    my_putstr(DEFAULT);
    free(user);
    free(machine);
    free(pwd);
}

//OK
