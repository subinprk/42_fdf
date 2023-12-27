# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: subpark <subpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 15:58:17 by subpark           #+#    #+#              #
#    Updated: 2023/08/21 15:13:51 by subpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CCFLAGS		= -Wall -Werror -Wextra

RM			= rm

SOURCE_DIR	= source

LIBFT		= libft.a
LIBFT_DIR	= libft
LIBFT_PATH	= $(LIBFT_DIR)/$(LIBFT)

MLX			= libmlx.a
MLX_DIR		= minilibx-linux
MLX_PATH	= $(MLX_DIR)/$(MLX)
MLX_FLAGS	= -lmlx -framework OpenGL -framework AppKit

HEADERS		= -I $(SOURCE_DIR) -I $(LIBFT_I_DIR) -I $(MLX_I_DIR)
LINUX_LINK	= -Lmlx -lmlx -framework OpenGL -framework AppKit

NAME 		= fdf
SRC_NAME 	= source/load_map.c source/get_next_line.c source/alloc_array.c\
			source/vect_cal.c source/make_line.c source/visualise.c\
			source/modify_arr.c source/find_index.c
OBJ_NAME 	= $(SRC_NAME:.c=.o)

# Main Command

all: $(NAME)

clean:
		@make clean -C $(LIBFT_DIR)
		@$(RM) -rf $(MLX_DIR)
		@$(RM) -f $(SOURCE_DIR)/$(OBJ_NAME)
		@$(RM) -f source/load_map.o

fclean: clean
		@make fclean -C $(LIBFT_DIR)
		@$(RM) -f $(LIBFT)
		@$(RM) -rf $(MLX_DIR)
		@$(RM) -f $(MLX)
		@$(RM) -f $(SOURCE_DIR)/$(OBJ_NAME)
		@$(RM) -f source/load_map.o
		@$(RM) -f $(NAME)

re: fclean all


# Sub Command

%.o: %.c
		@$(CC) $(CCFLAGS) -Imlx -c -o $@ $< $(HEADERS)

$(LIBFT):
		@make -C $(LIBFT_DIR)
		@mv $(LIBFT_DIR)/$(LIBFT) .

$(MLX):
		@git clone git@github.com:42Paris/minilibx-linux.git
		@make -C $(MLX_DIR)
		@mv $(MLX_DIR)/$(MLX) .

$(NAME): $(OBJ_NAME) $(LIBFT) $(MLX)
		@$(CC) $(CCFLAGS) -o $@ $^ -lm -lXext -lX11

# Phony target

.PHONY: all clean fclean re