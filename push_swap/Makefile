CC = gcc
SRCS = push_swap.c rules1.c rules2.c rules3.c swap_utils.c lst_utils.c convert.c control.c
OBJ = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRCS) -o push_swap

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re push_swap