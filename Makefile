# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/30 17:23:06 by evocatur          #+#    #+#              #
#    Updated: 2024/05/21 18:51:17 by edoardo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		  	= cub3d

CC			  	= gcc 
FLAGS		  	= -Wall -Wextra -Werror 
RM			  	= rm -rf

OBJDIR        	= .objFiles

MAIN_SRC		= src/cub3d
INIT_CUB3D 		= src/init/init_0 src/init/init_1
UTILS 			= src/utils/error src/utils/exit src/utils/string_utils src/utils/game_utils src/utils/safe_mlx_free src/utils/texture
WINDOW			= src/window/window
KEY 			= src/key/key
CAMERA 			= src/camera/camera
IMAGES 			= src/images/images
PLAYER 			= src/player/player src/player/player_movement
GAME_LOGIC		= src/main_loop/main_loop
TIME			= src/time/time
RENDERING 		= src/rendering/render_wall
DRAW			= src/draw/draw src/draw/draw_utils 
MAP_READ 		= src/map_read/map_read src/map_read/map_read_utils src/map_read/parse_map  src/map_read/init_map
RAYCASTING		= src/raycasting/raycasting src/raycasting/raycasting_utils

FILES 			= $(INIT_CUB3D) $(UTILS) $(WINDOW) $(KEY) $(GAME_LOGIC) \
				  $(LIBFT_SRC) $(MAP_READ) $(GAME_ENGINE) $(MAIN_SRC) \
				  $(IMAGES) $(CAMERA) $(PLAYER) $(RENDERING) $(TIME) \
				  $(DRAW) $(RAYCASTING)

SRC			  	= $(FILES:=.c)
OBJ			  	= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		  	= lib/cub3d.h lib/vector/vector.h lib/libft/libft.h

NONE			="\033[0m"
GREEN			="\033[32m"
GRAY			="\033[2;37m"
CURSIVE			="\033[3m"
YELLOW			="\033[1;33"

MAP				=map/test1.cub

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
LINKS = -Llib/mlx_linux lib/mlx_linux/libmlx.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif

ifeq ($(UNAME_S),Darwin)
LINKS = -lmlx -framework OpenGL -framework AppKit
endif

LINKS += -Llib/libft/ -Llib/vector/ -lft -l:vector.a -lm

.PHONY: all clean fclean re leaks

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo $(CURSIVE) $(GRAY) "     - Compiling libft library ..." $(NONE)
	@cd lib/libft  && make > /dev/null 2>&1 && make clean > /dev/null 2>&1
	@echo $(CURSIVE) $(GRAY) "     - Compiling vector library ..." $(NONE)
	@cd lib/vector && make > /dev/null 2>&1 && make clean > /dev/null 2>&1
	@echo $(CURSIVE) $(GRAY) "     - Compiling mlx library ..." $(NONE)
	@cd lib/mlx_linux/ && make > /dev/null 2>&1
	@echo $(CURSIVE)$(GRAY) "      - Making object files..." $(NONE)
	@echo $(CURSIVE) $(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@$(CC)  $(FLAGS) $(OBJ) $(LINKS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJDIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

run:
	@./$(NAME) map/test.cub 

play:
	@./$(NAME) $(MAP)

compile_and_run: re
	@./$(NAME)
	
compile_and_play: re
	@./$(NAME) $(MAP)

leaks: re
	@valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all --log-file=leaks.txt ./$(NAME) map/test1.cub 

leaks_arg: re
	@valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all --log-file=leaks.txt ./$(NAME) $(MAP)

clean:
	@$(RM) $(OBJDIR) $(OBJ)
	@$(RM) leaks.txt

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norm:
	@norminette src/
	@norminette lib/libft
	@norminette lib/vector
	@norminette lib/cub3d.h