/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** put_pipe
*/

#include <unistd.h>
#include "minishell2.h"
#include "utils.h"

static void fill_pipe_array(int **pipefd, int index, int file_descriptor[2])
{
    (*pipefd)[index] = file_descriptor[0];
    (*pipefd)[index + 1] = file_descriptor[1];
    (*pipefd)[index + 2] = 0;
}

int put_pipe(int file_descriptor[2], input_t *input, int **pipefd, int index)
{
    if (pipe(file_descriptor) == -1) {
        my_puterr("Error : pipe returns -1.\n");
        return 1;
    }
    input->stdout = file_descriptor[1];
    fill_pipe_array(pipefd, index, file_descriptor);
    return 0;
}

//OK
