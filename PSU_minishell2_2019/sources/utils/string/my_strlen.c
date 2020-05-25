/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_strlen
*/

int my_strlen(char const *string)
{
    int i = 0;

    while (string[i])
        i++;
    return i;
}

//OK
