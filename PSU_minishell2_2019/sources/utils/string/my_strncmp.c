/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_strncmp
*/

int my_strncmp(char const *string1, char const *string2, int n)
{
    int i = 0;

    n = n - 1;
    while (string1[i] && string2[i] && (i < n) && (string1[i] == string2[i]))
        i++;
    return string1[i] - string2[i];
}

//OK
