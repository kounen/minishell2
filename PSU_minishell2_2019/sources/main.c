/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** main
*/

#include "utils.h"
#include "minishell2.h"
#include "unused.h"

int main(UNUSED int argc, UNUSED char *argv[], char *envp[])
{
    int return_value;

    if (duplicate_array(envp, &envp_cpy))
        return 84;
    display_welcome_message();
    handle_signal();
    return_value = run_shell(envp_cpy);
    free_array(envp_cpy);
    display_goodbye_message();
    return return_value;
}

//OK
