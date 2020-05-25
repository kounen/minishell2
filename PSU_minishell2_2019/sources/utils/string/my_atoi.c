/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_atoi
*/

int my_atoi(char const *string)
{
    int number = 0;
    int symbol = 1;
    int i = 0;

    if (string[0] == '-') {
        symbol = -1;
        i += 1;
    }
    while (string[i]) {
        if (string[i] < '0' || string[i] > '9')
            return 0;
        number = number * 10 + string[i] - 48;
        i++;
    }
    return symbol * number;
}

//OK
