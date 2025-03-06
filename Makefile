NAME	= so_long
LIBFT	= libft/libft.a
SRCDIR	= source
SRCLIT	= main.c utils.c map_check.c map.c flood.c visual.c objects.c move.c 
SRCS	= $(addprefix $(SRCDIR)/,$(SRCLIT))
OBJ		= $(SRCS:.c=.o)
CC		= cc
INCLUDE	= -I ./include -I libft/ -I MLX42/include
LIBS	= -L MLX42/build -lmlx42 -ldl -lglfw -pthread -lm
CFLAGS	= -Wall -Wextra -Werror

all: MLX42_BUILD $(NAME)

$(NAME): $(LIBFT) $(OBJ) MLX42
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBS) -o $(NAME) 

MLX42_BUILD:
	@cd MLX42 && cmake -B build && cmake --build build -j4

MLX42_CLEAN:
	@cd MLX42 && cmake --build build --target clean

$(LIBFT): 
	$(MAKE) -C libft

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean: MLX42_CLEAN
	@rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re

# Use: git clone --recurse-submodules ,to import MLX42 alongside