NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = ft_printf.c print_str.c print_nbr.c print_nbr_hex.c

OBJ = $(SRC:.c=.o)

# The default rule that builds the library.
all: $(NAME)

# In the context of the make command, the -C option is used to specify a directory where the
# 	makefile should be located and where the build process should take place.
$(NAME): ${OBJ}
	ar -rcs $(NAME) $(OBJ)

$(OBJ):
	$(CC) $(CFLAGS) -c $(SRC)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
