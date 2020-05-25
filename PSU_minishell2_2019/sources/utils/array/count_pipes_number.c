/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** count_pipes_number
*/

int count_pipes_number(char **input_array)
{
    int pipes_number = 0;

    while (input_array[pipes_number])
        pipes_number++;
    pipes_number -= 1;
    return pipes_number;
}

//OK
