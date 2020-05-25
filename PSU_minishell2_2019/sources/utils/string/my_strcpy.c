/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_strcpy
*/

char *my_strcpy(char *destination, char const *source)
{
    int i;

    for (i = 0; source[i]; i++)
        destination[i] = source[i];
    destination[i] = '\0';
    return destination;
}

//OK
