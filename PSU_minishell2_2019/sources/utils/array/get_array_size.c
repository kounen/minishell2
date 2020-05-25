/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** get_array_size
*/

int get_array_size(char *array[])
{
    int array_size = 0;

    if (!array)
        return -1;
    while (array[array_size])
        array_size++;
    return array_size;
}

//OK
