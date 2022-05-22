# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 01:36:34 by brda-sil          #+#    #+#              #
#    Updated: 2022/05/22 11:32:24 by brda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# config
CFLAGS			:= -Wall -Wextra
TARGET			:= so_long
RM				:= rm -rf
CC				:= gcc
MAKE			:= make -C
VERSION			:= 2.2.3
$(eval export MAIN=1)

ifneq ($(PADDING),30)
PADDING			:= 30
endif

ifeq ($(DEBUG),)
CFLAGS			+= -Werror
else
CFLAGS			+= -g
endif

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

#  Bash Color / unicode char

#get_random		= $(shell seq 0 256 | shuf | head -n1)
green			:= \033[38;5;82m
blue			:= \033[38;5;75m
red				:= \033[38;5;196m
orange			:= \033[38;5;214m

blinking		:= \033[5m
reset			:= \033[0m

font_color		:= $(blue)
bold			:= $(green)
ascii_color		:= $(bold)

green_plus		:= $(font_color)[$(green)+$(font_color)]
red_minus		:= $(font_color)[$(red)-$(font_color)]
orange_star		:= $(font_color)[$(orange)*$(font_color)]
blinking_arrow	:= $(blinking)$(font_color)->
#font_color		:= \033[38;5;$(get_random)m
#bold			:= \033[38;5;$(get_random)m
#ascii_color		:= \033[38;5;$(get_random)m

UL="\xe2\x95\x94"
HO="\xe2\x95\x90"
UR="\xe2\x95\x97"
VE="\xe2\x95\x91"
LL="\xe2\x95\x9a"
LR="\xe2\x95\x9d"

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

get_length_str = $(shell )

define print_padded
	@printf '   $(orange_star) $(font_color)Creation of $(bold)$1'
	$(eval OBJ_LEN := $(shell printf $1 | wc -c))
	$(eval PAD_LEN := $(shell expr $(PADDING) - $(OBJ_LEN)))
	@printf '%-$(PAD_LEN)s' ' '
	@printf '$(blinking_arrow) $(reset)$(bold)$2 $(reset)'
	@printf '\n'
endef

define usage
	@printf '$(orange_star) $(bold)$(TARGET)$(font_color):\n\n'
	@printf '    $(font_color)./$(TARGET) $(bold)<PATH_TO_MAP>\n\n'
	@printf '        $(font_color)A folder map is given within the $(bold)res/map'
	@printf '$(font_color) folder.\n'
	@printf '        $(bold)Feel free$(font_color) to test the test map in the $(bold)'
	@printf 'res/map/test$(font_color), for\n'
	@printf '        the parsing or with $(bold)10.000 $(font_color)enemy :)\n\n'
	@printf '        The number of the map can be $(bold)unlimited$(font_color)'
	@printf ', meaning that the \n        $(bold)argv$(font_color)'
	@printf '[$(bold)1$(font_color)] is the first "$(bold)level$(font_color)"'
	@printf ' and so on\n\n'
	@printf '$(font_color)Version: $(bold)$(VERSION)$(reset)\n'

endef
# **************************************************************************** #

# **************************************************************************** #
# Rules

all:			setup $(TARGET) usage

usage:
	$(call usage)

$(OBJ_DIR)/%.o: 		$(SRC_DIR)/%.c
	$(call print_padded,$^,$@)
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
	@printf "$(green_plus) $(font_color)Creation of $(bold)$@$(reset)\n"
	@$(CC) $(CFLAGS) -o $@ $(OBJ_C) $(LIBS) $(LDFLAGS)

setup:					call_logo $(OBJ_DIR) $(BIN_DIR)

call_logo:
	@printf "$(ascii_color)$$ascii_art"

$(OBJ_DIR):
	@printf "$(green_plus) $(font_color)Creation of $(bold)$(OBJ_DIR)$(reset)\n"
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@printf "$(green_plus) $(font_color)Creation of $(bold)$(BIN_DIR)$(reset)\n"
	@mkdir -p $(BIN_DIR)

clean_all:				clean
	@$(MAKE) lib/libft clean
	@$(MAKE) lib/ft_printf clean
	@$(MAKE) lib/minilibx-linux clean
	@$(MAKE) lib/gnl clean

clean:
	@printf "$(red_minus) $(font_color)Deleting $(bold)$(OBJ_DIR)$(reset)\n"
	@$(RM) $(OBJ_DIR)

fclean_all:				fclean
	@$(MAKE) lib/libft fclean
	@$(MAKE) lib/ft_printf fclean
	@$(MAKE) lib/minilibx-linux clean
	@$(MAKE) lib/gnl fclean

fclean:					clean
	@printf "$(red_minus) $(font_color)Deleting $(bold)$(TARGET)$(reset)\n"
	@$(RM) $(TARGET)
	@printf "$(red_minus) $(font_color)Deleting $(bold)$(BIN_DIR)$(reset)\n"
	@$(RM) -rf $(BIN_DIR)

re_lib:
	@$(MAKE) lib/libft re
	@$(MAKE) lib/ft_printf re
	@$(MAKE) lib/minilibx-linux re
	@$(MAKE) lib/gnl re

re:						fclean all

re_all:					re_lib re

.PHONY:					all clean fclean re setup lib call_logo

# **************************************************************************** #
