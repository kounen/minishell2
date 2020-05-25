/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** create_process
*/

#include <sys/types.h>
#include <unistd.h>

pid_t create_process(void)
{
    pid_t pid;

    do {
        pid = fork();
    } while (pid == -1);
    return pid;
}

//OK
