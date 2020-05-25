/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** display_process_error
*/

#include <string.h>
#include <sys/wait.h>
#include "utils.h"

static void display_process_error3(int status)
{
    switch (WTERMSIG(status)) {
    case 29:
        my_puterr("Pollable event occured");
        break;
    default:
        my_puterr(strsignal(WTERMSIG(status)));
        break;
    }
}

static void display_process_error2(int status)
{
    switch (WTERMSIG(status)) {
    case 16:
        my_puterr("Stack limit exceeded");
        break;
    case 24:
        my_puterr("Cputime limit exceeded");
        break;
    case 25:
        my_puterr("Filesize limit exceeded");
        break;
    case 26:
        my_puterr("Virtual time alarm");
        break;
    case 27:
        my_puterr("Profiling time alarm");
        break;
    default :
        display_process_error3(status);
        break;
    }
}

void display_process_error(int status)
{
    switch (WTERMSIG(status)) {
    case 5:
        my_puterr("Trace/BPT trap");
        break;
    case 6:
        my_puterr("Abort");
        break;
    case 8:
        my_puterr("Floating exception");
        break;
    case 10:
        my_puterr("User signal 1");
        break;
    case 12:
        my_puterr("User signal 2");
        break;
    default:
        display_process_error2(status);
        break;
    }
}

//OK
