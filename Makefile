# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/04/19 16:37:18 by aplat        #+#   ##    ##    #+#        #
#    Updated: 2019/05/27 23:35:08 by aplat       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fdf

SRC = main.c ft_error.c ft_check_validity.c ft_window.c ft_data_file.c\
		ft_data_iso.c ft_data_para.c ft_print.c ft_bresenham.c\
		ft_init_value.c ft_bind_keys.c ft_utils.c ft_zoom.c ft_center_iso.c\
		ft_translate.c ft_elevation.c ft_center_para.c ft_color.c\
		ft_color_effects.c

CC = cc

DEPENDENCES = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

HEADERS = fdf.h

LIB = libft/libft.a 

LIBX = minilibx_macos/libmlx.a

FRAMEWORK = -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(LIB) $(LIBX) $(DEPENDENCES)
	@$(CC) $(CFLAGS) -I $(HEADERS) -o $(NAME) $(SRC) -L./libft -lft $(LIBX) $(FRAMEWORK)
	@echo "\033[32mCompilation ==> DONE\033[0m"

$(LIB) :
	@make -C libft

$(LIBX) :
	@make -C minilibx_macos

clean:
	@rm -f $(DEPENDENCES)
	@make clean -C libft
	@make clean -C minilibx_macos
	@echo "\033[32mSuppression .o ==> DONE\033[0m"

fclean:clean
	@rm -f $(NAME)
	@make fclean -C libft
	@echo "\033[32mSuppression binaires ==> DONE"

re:fclean $(NAME)

.PHONY: all clean fclean re

.SILENT: $(DEPENDENCES)
