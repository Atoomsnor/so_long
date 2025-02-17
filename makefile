NAME	= so_long
LIBFT	= libft/libft.a
PRINTF	= libft/printf/printf.a
GNL		= libft/get_next_line/get_next_line.a
SRCDIR	= source
SRCLIT	= My_test.c
SRCS	= $(addprefix $(SRCDIR)/,$(SRCLIT))
OBJ		= $(SRCS:.c=.o)
CC		= cc
INCLUDE	= -I ./include
LIBS	= -L MLX42/build -lmlx42 -ldl -lglfw -pthread -lm
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(GNL) $(LIBS) -o $(NAME)

$(LIBFT): 
	$(MAKE) -C libft

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re