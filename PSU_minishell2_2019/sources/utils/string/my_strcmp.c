/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_strcmp
*/

int my_strcmp(char const *string1, char const *string2)
{
    int i = 0;

    while (string1[i] && string2[i] && (string1[i] == string2[i]))
        i++;
    return string1[i] - string2[i];
}

//OK
