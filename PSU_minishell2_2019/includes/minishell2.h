/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** minishell2
*/

#ifndef MINISHELL2_H_
#define MINISHELL2_H_

//DEFINES
/********************************command_status********************************/
#define ERROR_COMMAND (1)
#define SUCCESS_COMMAND (0)
#define OTHER_COMMAND (-1)
#define FORK_USED (10)

/******************************redirection_status******************************/
#define ON_VALUE (1)
#define OFF_VALUE (0)

/*********************************shell_status*********************************/
#define RUNNING (1)

/********************************malloc_status*********************************/
#define MALLOC_ERROR (-1)

/********************************stream_status*********************************/
#define DEFAULT_VALUE (-1)

/*********************************pipe_status**********************************/
#define PIPE_OR_REDIRECTION_ERROR (2)

/**********************************open_flags**********************************/
#define L_FLAGS (O_RDONLY)
#define LL_FLAGS ()
#define H_FLAGS (O_CREAT | O_RDWR | O_TRUNC)
#define HH_FLAGS (O_CREAT | O_RDWR | O_APPEND)

/**********************************open_mode***********************************/
#define MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

/*****************************extrem's_pipe_number*****************************/
#define PIPE (2)


//GLOBAL VARIABLE
char **envp_cpy;


//STRUCTURES
typedef struct redirection_s
{
    char **cmd;
    int lower;
    int lower_lower;
    int higher;
    int higher_higher;
} redirection_t;

typedef struct input_s input_t;
struct input_s
{
    char **command;
    int file_descriptor;
    int stdin;
    int stdout;
    int redirections_number;
    redirection_t **redirection;
    input_t *next;
    input_t *previous;
};

typedef struct chain_s
{
    input_t *head;
    input_t *feet;
} chain_t;


//FUNCTION PROTOTYPES
/***********************************builtins***********************************/
int my_builtins(input_t *input, char ***envp_cpy);
int my_cd(char **cmd, char ***envp_cp);
int my_echo(char *argv[]);
int my_env(char ***envp_cpy);
int my_exit(char **command, char ***envp_cpy);
int my_setenv(char **command, char ***envp_cpy);
int my_unsetenv(char **command, char ***envp_cpy);
/***********************************command************************************/
int run_command(input_t *input, char ***envp_cpy, int *pipefd);
/************************************execve************************************/
int my_execve(input_t *input, char **envp_cpy, int *pipefd);
/********************************father_process********************************/
int run_father_process(int fork_number, int return_value);
/************************************input*************************************/
void initialise_input_array(input_t **input, char **cmd, int *a, int *b);
int parse_input(char *input, char ***envp_cpy, char **error_redirection);
/*************************************list*************************************/
int fill_list_of_pipe(chain_t *list, input_t *input, int **pipefd, char **cmd);
void initialise_list(chain_t *list);
/***********************************messages***********************************/
void display_goodbye_message(void);
void display_welcome_message(void);
/*************************************pipe*************************************/
int engine_pipe(chain_t *list, int **pipefd, char **input_array);
int parse_from_pipe(char *input, chain_t *list, int **pipefd, char **message);
int put_pipe(int file_descriptor[2], input_t *input, int **pipefd, int index);
/************************************prompt************************************/
void display_prompt(char *envp_cpy[]);
/*********************************redirection**********************************/
int engine_redirection(input_t **input, char **input_array);
void implement_redirection(input_t *input);
void initialise_input_redirection_structure(input_t **input_settings);
int initialise_redirection_structure(input_t **input, int index);
int parse_from_redirection(input_t **input, char **message);
/**********************************semicolon***********************************/
int parse_from_semicolon(char *input, char ***envp_cpy);
/************************************shell*************************************/
int run_shell(char **envp_cpy);
/************************************signal************************************/
void handle_signal(void);

#endif /* !MINISHELL2_H_ */

//OK
