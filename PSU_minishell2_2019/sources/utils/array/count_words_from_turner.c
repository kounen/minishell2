/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** count_words_from_turner
*/

int count_words_from_turner(char const *string, char turner1, char turner2)
{
    int i = 0;
    int words_number = 0;

    while (string[i]) {
        while (string[i] && (string[i] == turner1 || string[i] == turner2))
            i++;
        words_number += (string[i]) ? 1 : 0;
        i += (string[i]) ? 1 : 0;
    }
    return words_number;
}

//OK
