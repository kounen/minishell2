/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_str_isnum
*/

int my_str_isnum(char const *string)
{
    for (int i = 0; string[i]; i++)
        if (string[i] < '0' || string[i] > '9')
            return 0;
    return 1;
}

//OK
