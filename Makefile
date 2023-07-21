CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# targets
NAME1 = server
NAME2 = client
BONUS_NAME1 = server_bonus
BONUS_NAME2 = client_bonus

PRINTF = libftprintf.a
FT_PRINTF_DIR = ft_printf
INCLUDE = -I include

# source files
SRC1 = utils.c server.c
SRC2 = utils.c client.c
BONUS_SRC1 = utils.c server_bonus.c
BONUS_SRC2 = utils.c client_bonus.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
BONUS_OBJ1 = $(BONUS_SRC1:.c=.o)
BONUS_OBJ2 = $(BONUS_SRC2:.c=.o)

# Compile source files into object files
%.o: %.c minitalk.h minitalk_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

# Build both targets: server and client
all: $(NAME1) $(NAME2)

# The command 'make -C FT_PRINTF_DIR' is used to invoke the make utility to build a target in a specified directory 
$(NAME1): $(OBJ1)
	make -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJ1) $(INCLUDE) $(FT_PRINTF_DIR)/$(PRINTF) -o $(NAME1)

$(NAME2): $(OBJ2)
	make -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJ2) $(INCLUDE) $(FT_PRINTF_DIR)/$(PRINTF) -o $(NAME2)

bonus: $(BONUS_NAME1) $(BONUS_NAME2)

$(BONUS_NAME1): $(BONUS_OBJ1)
	make -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(BONUS_OBJ1) $(INCLUDE) $(FT_PRINTF_DIR)/$(PRINTF) -o $(BONUS_NAME1)

$(BONUS_NAME2): $(BONUS_OBJ2)
	make -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(BONUS_OBJ2) $(INCLUDE) $(FT_PRINTF_DIR)/$(PRINTF) -o $(BONUS_NAME2)

clean:
	make clean -C $(FT_PRINTF_DIR)
	$(RM) $(OBJ1) $(OBJ2) $(BONUS_OBJ1) $(BONUS_OBJ2)

fclean: clean
	make fclean -C $(FT_PRINTF_DIR)
	$(RM) $(NAME1) $(NAME2) $(BONUS_NAME1) $(BONUS_NAME2)

re: fclean all

.PHONY: all clean fclean re bonus
