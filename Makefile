
NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES =	0_tools_split.c		1_fd_cmd_envp.c		\
		2_ft_execute.c		3_ft_execve.c 		\
		4_clean_up.c		pipex.c

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o : %.c header.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all clean fclean re

clean : 
	-rm -f $(OBJECTS)

fclean : clean
	-rm -f $(NAME)

re : fclean all
