/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_echo
*/

#include <stdbool.h>
#include <string.h>
#include <unistd.h>

int my_echo(char *argv[]);

static int is_not_enough_arguments(char *argv[]);

static void display_backslash_format(char *string, int *index);

static char set_specified_format(char format);

int my_echo(char *argv[])
{
    bool is_a_newline;

    if (is_not_enough_arguments(argv)) {
        return 0;
    }
    is_a_newline = strcmp(argv[1], "-n");
    for (int i = 1 + !is_a_newline; argv[i]; i++) {
        for (int j = 0; argv[i][j]; j++) {
            if ('\\' == argv[i][j]) {
                display_backslash_format(argv[i], &j);
            } else {
                write(1, &argv[i][j], 1);
            }
        }
        if (argv[i + 1]) {
            write(1, " ", 1);
        }
    }
    if (is_a_newline) {
        write(1, "\n", 1);
    }
    return 0;
}

static int is_not_enough_arguments(char *argv[])
{
    if (!argv[1]) {
        write(1, "\n", 1);
        return 1;
    }
    return 0;
}

static void display_backslash_format(char *string, int *index)
{
    char format;

    if (string[*index + 1]) {
        format = set_specified_format(string[*index + 1]);
        if (format) {
            write(1, &format, 1);
            (*index) += 2;
        } else {
            write(1, &string[*index], 2);
            (*index) += 2;
        }
    } else {
        write(1, "\\", 1);
        (*index) += 1;
    }
}

static char set_specified_format(char format)
{
    return (format == '\\' ? '\\' :
	format == 'a' ? '\a' :
	format == 'b' ? '\b' :
	format == 'f' ? '\f' :
	format == 'n' ? '\n' :
	format == 'r' ? '\r' :
	format == 't' ? '\t' :
	format == 'v' ? '\v' : 0);
}
