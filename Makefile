# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/30 17:23:06 by evocatur          #+#    #+#              #
#    Updated: 2024/04/06 15:02:35 by edoardo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		  	= cub3d

CC			  	= gcc 
FLAGS		  	= -Wall -Wextra -Werror 
RM			  	= rm -rf

OBJDIR        	= .objFiles

MAIN_SRC		= src/cub3d
INIT_CUB3D 		= src/init/init_cub3d
UTILS 			= src/utils/error src/utils/exit src/utils/string_utils src/utils/game_utils src/utils/safe_free src/utils/texture
WINDOW			= src/window/window
KEY 			= src/key/key
CAMERA 			= src/camera/camera
IMAGES 			= src/images/images
PLAYER 			= src/player/player src/player/player_movement
GAME_LOGIC		= src/game_logic/main_loop
RENDERING 		= src/rendering/raycasting src/rendering/draw src/rendering/draw_utils
MAP_READ 		= src/map_read/map_read src/map_read/map_read_utils src/map_read/parse_map  src/map_read/init_map

FILES 			= $(INIT_CUB3D) $(UTILS) $(WINDOW) $(KEY) $(GAME_LOGIC) $(LIBFT_SRC) $(MAP_READ) $(GAME_ENGINE) $(MAIN_SRC) $(IMAGES) $(CAMERA) $(PLAYER) $(RENDERING)

SRC			  	= $(FILES:=.c)
OBJ			  	= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		  	= lib/cub3d.h lib/vector/vector.h

NONE			="\033[0m"
GREEN			="\033[32m"
GRAY			="\033[2;37m"
CURSIVE			="\033[3m"
YELLOW			="\033[1;33"

MAP				=map/test1.cub

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
LINKS = -Lmlx_linux ./mlx_linux/libmlx.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
FLAGS += -I/usr/include -Imlx_linux -O3
endif

ifeq ($(UNAME_S),Darwin)
LINKS = -lmlx -framework OpenGL -framework AppKit
endif

LINKS += -Llib/libft/ -Llib/vector/ -lft -l:vector.a

.PHONY: all clean fclean re leaks

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo $(CURSIVE) $(GRAY) "     - Compiling libft library ..." $(NONE)
	@cd lib/libft  && make > /dev/null 2>&1 && make clean > /dev/null 2>&1
	@echo $(CURSIVE) $(GRAY) "     - Compiling vector library ..." $(NONE)
	@cd lib/vector && make > /dev/null 2>&1 && make clean > /dev/null 2>&1
	@echo $(CURSIVE) $(GRAY) "     - Compiling mlx library ..." $(NONE)
	@cd mlx_linux/ && make > /dev/null 2>&1
	@echo $(CURSIVE)$(GRAY) "      - Making object files..." $(NONE)
	@echo $(CURSIVE) $(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@$(CC)  $(FLAGS) $(OBJ) $(LINKS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJDIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

run:
	@./$(NAME)

play:
	@./$(NAME) $(MAP)

compile_and_run: re
	@./$(NAME)
	
compile_and_play: re
	@./$(NAME) $(MAP)

leaks: re
	@valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all --log-file=leaks.txt ./$(NAME) map/test.cub 

leaks_arg: re
	@valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all --log-file=leaks.txt ./$(NAME) $(MAP)

clean:
	@$(RM) $(OBJDIR) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norm:
	@norminette src/
	@norminette lib/
