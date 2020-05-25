##
## EPITECH PROJECT, 2020
## PSU_minishell2_2019
## File description:
## Makefile
##

NAME		=	mysh

TESTS_NAME	=	unit_tests

CC			=	gcc

RM			=	rm -f

SRCS		=	./sources/builtins/my_builtins.c \
				./sources/builtins/my_cd.c \
				./sources/builtins/my_echo.c \
				./sources/builtins/my_env.c \
				./sources/builtins/my_exit.c \
				./sources/builtins/my_setenv.c \
				./sources/builtins/my_unsetenv.c \
				./sources/command/run_command.c \
				./sources/execve/my_execve.c \
				./sources/father_process/run_father_process.c \
				./sources/input/initialise_input_array.c \
				./sources/input/parse_input.c \
				./sources/list/engine_list.c \
				./sources/list/initialise_list.c \
				./sources/main.c \
				./sources/messages/display_goodbye_message.c \
				./sources/messages/display_welcome_message.c \
				./sources/pipe/engine_pipe.c\
				./sources/pipe/parse_from_pipe.c \
				./sources/pipe/put_pipe.c \
				./sources/prompt/display_prompt.c \
				./sources/redirection/engine_redirection.c \
				./sources/redirection/implement_redirection.c \
				./sources/redirection/initialise_input_redirection_structure.c \
				./sources/redirection/initialise_redirection_structure.c \
				./sources/redirection/parse_from_redirection.c \
				./sources/semicolon/parse_from_semicolon.c \
				./sources/shell/run_shell.c \
				./sources/signal/handle_signal.c \
				./sources/utils/array/count_pipes_number.c \
				./sources/utils/array/count_words_from_turner.c \
				./sources/utils/array/duplicate_array.c \
				./sources/utils/array/fill_array_element.c \
				./sources/utils/array/free_array.c \
				./sources/utils/array/get_array_size.c \
				./sources/utils/array/my_str_to_word_array.c \
				./sources/utils/array/split_from_redirection.c \
				./sources/utils/array/turn_str_into_array.c \
				./sources/utils/environment/find_functional_path.c \
				./sources/utils/environment/get_variable_position.c \
				./sources/utils/environment/my_getenv.c \
				./sources/utils/environment/remove_environment_variable.c \
				./sources/utils/environment/update_env.c \
				./sources/utils/file/close_file_descriptor.c \
				./sources/utils/file/is_a_file.c \
				./sources/utils/process/create_process.c \
				./sources/utils/process/display_process_error.c \
				./sources/utils/string/clean_input.c \
				./sources/utils/string/get_input.c \
				./sources/utils/string/my_atoi.c \
				./sources/utils/string/my_puterr.c \
				./sources/utils/string/my_putstr.c \
				./sources/utils/string/my_str_isnum.c \
				./sources/utils/string/my_strcat.c \
				./sources/utils/string/my_strcmp.c \
				./sources/utils/string/my_strcpy.c \
				./sources/utils/string/my_strdup.c \
				./sources/utils/string/my_strlen.c \
				./sources/utils/string/my_strncmp.c \
				./sources/utils/string/my_strndup.c

TESTS_SRCS	=	./sources/utils/string/my_strlen.c \
				./sources/utils/string/my_strncmp.c \
				./sources/utils/array/count_pipes_number.c \
				./tests/test_count_pipes_number.c \
				./sources/utils/array/count_words_from_turner.c \
				./tests/test_count_words_from_turner.c \
				./sources/utils/array/get_array_size.c \
				./tests/test_get_array_size.c \
				./sources/utils/environment/get_variable_position.c \
				./tests/test_get_variable_position.c \
				./sources/utils/string/my_atoi.c \
				./tests/test_my_atoi.c \
				./sources/utils/string/my_str_isnum.c \
				./tests/test_my_str_isnum.c \
				./sources/utils/string/my_strcmp.c \
				./tests/test_my_strcmp.c \
				./sources/utils/string/my_strcpy.c \
				./tests/test_my_strcpy.c

OBJS		=	$(SRCS:.c=.o)

TESTS_OBJS	=	$(TESTS_SRCS:.c=.o)

LDFLAGS		=

CFLAGS		=	-I ./includes/
CFLAGS		+=	-Wall -Wextra
CFLAGS		+=	-g3

ifeq ($(MAKECMDGOALS), tests_run)
LDFLAGS		+=	-lcriterion
CFLAGS		+=	--coverage
endif

all			:	$(NAME)

$(NAME)		:	$(OBJS)
	 		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(CFLAGS)

tests_run	:	$(TESTS_OBJS)
			$(CC) $(TESTS_OBJS) -o $(TESTS_NAME) $(LDFLAGS) $(CFLAGS)
			./$(TESTS_NAME)

tests_clean:
			$(RM) $(TESTS_NAME)
			$(RM) $(TESTS_OBJS)
			$(RM) $(wildcard */*.gc*) $(wildcard */*/*/*.gc*)

clean		:	tests_clean
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all tests_run tests_clean clean fclean re

#OK
