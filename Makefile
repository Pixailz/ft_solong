# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 01:36:34 by brda-sil          #+#    #+#              #
#    Updated: 2022/05/12 01:23:56 by brda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#  Bash Color

get_random		= $(shell seq 0 256 | shuf | head -n1)
green			:= \033[38;5;82m
blue			:= \033[38;5;75m
red				:= \033[38;5;196m
yellow			:= \033[38;5;226m

blinking		:= \033[5m
reset			:= \033[0m

font_color		:= $(blue)
bold			:= $(green)
ascii_color		:= $(bold)

#font_color		:= \033[38;5;$(get_random)m
#bold			:= \033[38;5;$(get_random)m
#ascii_color		:= \033[38;5;$(get_random)m

# **************************************************************************** #

# **************************************************************************** #
# utils

define ascii_art
███████╗ ██████╗          ██╗      ██████╗ ███╗   ██╗ ██████╗
██╔════╝██╔═══██╗         ██║     ██╔═══██╗████╗  ██║██╔════╝
███████╗██║   ██║         ██║     ██║   ██║██╔██╗ ██║██║  ███╗
╚════██║██║   ██║         ██║     ██║   ██║██║╚██╗██║██║   ██║
███████║╚██████╔╝██╗██╗██╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝██╗
╚══════╝ ╚═════╝ ╚═╝╚═╝╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚═╝
$(reset)
endef
export ascii_art

# **************************************************************************** #

# **************************************************************************** #
# config
CFLAGS			:= -Wall -Wextra -Werror #-g
TARGET			:= blank
RM				:= rm -rf
CC				:= gcc
MAKE			:= make -C
PADDING			:= 30

# DIR
BIN_DIR			:= bin
SRC_DIR			:= src
LIB_DIR			:= lib
OBJ_DIR			:= obj
INC_TMP			:= includes \
				   $(LIB_DIR)/libft/includes \
				   $(LIB_DIR)/ft_printf/includes \
				   $(LIB_DIR)/gnl/includes \
				   $(LIB_DIR)/minilibx-linux
INC_DIR			:= $(addprefix -I,$(INC_TMP))

TARGET			:= $(addprefix $(BIN_DIR)/,$(TARGET))

# LIB
LIBFT			:= $(LIB_DIR)/libft/libft.a
FT_PRINTF		:= $(LIB_DIR)/ft_printf/ft_printf.a
GET_NEXT_LINE	:= $(LIB_DIR)/gnl/get_next_line.a
MINI_LIBX		:= $(LIB_DIR)/minilibx-linux/libmlx_Linux.a

LDFLAGS			:= -Llib/minilibx-linux -L/usr/lib -lXext -lX11 -lm -lbsd -lz

# SRC
SRC_C			:= $(wildcard $(SRC_DIR)/*.c)

# OBJ
OBJ_C			:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))

# LIB DIR
CFLAGS			+= $(INC_DIR)
LIBS			:= $(FT_PRINTF) $(LIBFT) $(GET_NEXT_LINE) $(MINI_LIBX) -Llib/minilibx-linux
# **************************************************************************** #

# **************************************************************************** #
# Rules

all:			setup $(TARGET)

$(OBJ_DIR)/%.o: 		$(SRC_DIR)/%.c
	@printf "   $(font_color)[$(green)+$(font_color)] Creation of $(bold)$^"
	$(eval OBJ_LEN := $(shell printf $^ | wc -c))
	$(eval PAD_LEN := $(shell expr $(PADDING) - $(OBJ_LEN)))
	@printf "%-$(PAD_LEN)s" " "
	@printf "$(blinking)$(font_color)-> $(reset)$(bold)$@ $(reset)"
	@printf "\n"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT):
	@$(MAKE) lib/libft all

$(FT_PRINTF):
	@$(MAKE) lib/ft_printf all

$(GET_NEXT_LINE):
	@$(MAKE) lib/gnl all

$(MINI_LIBX):
	@$(MAKE) lib/minilibx-linux all

$(TARGET):				$(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) $(MINI_LIBX) $(OBJ_C)
	@printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)$@$(reset)\n"
	@$(CC) $(CFLAGS) -o $@ $(OBJ_C) $(LIBS) $(LDFLAGS)

setup:					call_logo $(OBJ_DIR) $(BIN_DIR)

call_logo:
	@printf "$(ascii_color)$$ascii_art"

$(OBJ_DIR):
	@printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)$(OBJ_DIR)$(reset)\n"
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)$(BIN_DIR)$(reset)\n"
	@mkdir -p $(BIN_DIR)

clean_lib:
	@$(MAKE) lib/libft clean
	@$(MAKE) lib/ft_printf clean
	@$(MAKE) lib/minilibx-linux clean
	@$(MAKE) lib/gnl clean

clean:					clean_lib
	@printf "$(font_color)[$(red)-$(font_color)] Deleting $(bold)$(OBJ_DIR)$(reset)\n"
	@$(RM) $(OBJ_DIR)

fclean_lib:
	@$(MAKE) lib/libft fclean
	@$(MAKE) lib/ft_printf fclean
	@$(MAKE) lib/minilibx-linux clean
	@$(MAKE) lib/gnl fclean

fclean:					fclean_lib clean
	@printf "$(font_color)[$(red)-$(font_color)] Deleting $(bold)$(TARGET)$(reset)\n"
	@$(RM) $(TARGET)
	@printf "$(font_color)[$(red)-$(font_color)] Deleting $(bold)$(BIN_DIR)$(reset)\n"
	@$(RM) -rf $(BIN_DIR)

re_lib:
	@$(MAKE) lib/libft re
	@$(MAKE) lib/ft_printf re
	@$(MAKE) lib/minilibx-linux re
	@$(MAKE) lib/gnl re

re:						fclean re_lib all

rre:					fclean all

.PHONY:					all clean fclean re setup lib call_logo

# **************************************************************************** #
