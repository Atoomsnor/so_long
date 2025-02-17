NAME = so_long
LIBFT = libft/libft.a
PRINTF = libft/printf/printf.a
SRCDIR = source
SRCLIT = main.c handling_stack.c sorting.c ins_swap.c ins_rotate.c ins_reverse.c ins_push.c
SRCS	= $(addprefix $(SRCDIR)/,$(SRCLIT))
OBJ		= $(SRCS:.c=.o)
CC = cc
INCLUDE = -I ./include
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

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