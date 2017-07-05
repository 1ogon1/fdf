#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 19:25:28 by mkyianyt          #+#    #+#              #
#    Updated: 2017/03/15 12:20:13 by rkonoval         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = fdf

SRC = fdf.c\
	  fdf2.c\
	  ft_add_list.c\
	  ft_copy_list.c\
	  ft_key_init.c\
	  ft_line.c\
	  ft_other.c\
	  ft_rot.c\
	  ft_error.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

ATTACH = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\x1b[35mCompile libft.\x1b[0m"
	@make -C libft
	@echo "\x1b[32mOK\x1b[0m"
	@echo "\x1b[35mCompile fdf.\x1b[0m"
	@gcc $(CFLAGS) -o $(NAME) -L libft -lft $(OBJ) $(ATTACH)
	@echo "\x1b[32mOK\x1b[0m"

.c.o:
	@gcc $(CFLAGS) -c $< -o $@ \

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)
	@echo "\x1b[32mClean OK\x1b[0m"

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "\x1b[32mFClean OK\x1b[0m"

re: fclean all
