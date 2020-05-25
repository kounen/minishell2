/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** utils
*/

#ifndef UTILS_H_
#define UTILS_H_

//FUNCTION PROTOTYPES
/************************************array*************************************/
int count_pipes_number(char **input_array);
int count_words_from_turner(char const *string, char turner1, char turner2);
int duplicate_array(char *source[], char ***destination);
char *fill_element(char const *src, int *index, char turner1, char turner2);
void free_array(char *array[]);
int get_array_size(char *array[]);
int my_str_to_word_array(char const *string, char ***array);
int split_from_redirection(char **src, char ***dest);
int turn_str_into_array(char *string, char ***array, char turner);
/*********************************environment**********************************/
char *find_functional_path(char **envp_cpy, char **command);
int get_variable_position(char **envp_cpy, char *environment_variable);
char *my_getenv(char *envp_cpy[], char const *name_variable);
char **remove_environment_variable(char **envp_cpy, char *variable_name);
char **update_env(char **envp_cp, char *name, char *content);
/*************************************file*************************************/
void close_file_descriptor(int const *pipefd);
int is_a_file(char *target);
/***********************************process************************************/
void display_process_error(int status);
/************************************string************************************/
int clean_input(char **input);
int my_atoi(char const *string);
void my_puterr(char const *string);
void my_putstr(char const *string);
int my_str_isnum(char const *string);
char *my_strcat(char *string_one, char *string_two);
int my_strcmp(char const *string1, char const *string2);
char *my_strcpy(char *destination, char const *source);
char *my_strdup(char const *source);
int my_strlen(char const *string);
int my_strncmp(char const *string1, char const *string2, int n);
char *my_strndup(char *source, int size);

#endif /* !UTILS_H_ */

//OK
