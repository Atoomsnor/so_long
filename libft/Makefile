# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roversch <roversch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 15:49:19 by roversch          #+#    #+#              #
#    Updated: 2025/02/17 14:10:25 by roversch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_atol.c ft_bzero.c ft_putstr.c ft_split.c ft_strmapi.c \
ft_striteri.c ft_calloc.c ft_itoa.c ft_putstr_fd.c ft_putnbr_fd.c \
ft_putnbr.c ft_putendl_fd.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c \
ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c \
ft_toupper.c

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ./include

PRINTF_DIR = printf
PRINTF_NAME = printf.a

GNL_DIR = get_next_line
GNL_NAME = get_next_line.a

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(MAKE) -C $(GNL_DIR)
	@ar rc $(NAME) $(OBJ)

%.o: %.c
	@$(CC) -c $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re