# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/06/20 17:10:19 by tbroggi      #+#   ##    ##    #+#        #
#    Updated: 2018/06/23 11:37:20 by tbroggi     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME	= fdf

SRC		= src/main.c \
		  src/map.c \
		  src/line.c \
		  src/image.c \
		  src/events.c \
		  src/init_del.c \
		  src/color.c \
		  src/utils.c

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx_macos/
	gcc -Wall -Wextra -Werror -L libft/ -lft -g -L ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)
	printf '\033[4m'
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create FdF"

obj/%.o: src/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf obj/
	make -C libft/ clean
	make -C minilibx_macos/ clean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean FdF"

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean
	make -C minilibx_macos/ clean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean FdF"

re: fclean all

all: $(NAME)
.PHONY: clean fclean re all test
