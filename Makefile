NAME	= so_long
LIBFT	= libft/libft.a
SRCDIR	= source
SRCLIT	= main.c utils.c map_check.c map.c flood.c visual.c objects.c move.c 
SRCS	= $(addprefix $(SRCDIR)/,$(SRCLIT))
OBJ		= $(SRCS:.c=.o)
CC		= cc
INCLUDE	= -I ./include -I libft/ -I MLX42/include
LIBS	= -L MLX42/build -lmlx42 -ldl -lglfw -pthread -lm
CFLAGS	= -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBS) -o $(NAME) 

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