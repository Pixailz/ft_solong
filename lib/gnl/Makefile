# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 01:36:34 by brda-sil          #+#    #+#              #
#    Updated: 2022/05/17 07:15:55 by brda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# config
CFLAGS			:= -Wall -Wextra
TARGET			:= get_next_line.a
RM				:= rm -rf
CC				:= gcc
VERSION			:= 1.0.0

ifneq ($(PADDING),30)
PADDING			:= 30
endif

ifeq ($(DEBUG),)
CFLAGS			+= -Werror
else
CFLAGS			+= -g
endif

# DIR
SRC_DIR			:= src
OBJ_DIR			:= obj
INC_DIR			:= includes

# SRC
SRC_C			:= $(wildcard $(SRC_DIR)/*.c)

# OBJ
OBJ_C			:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))

CFLAGS			+= -I$(INC_DIR)

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
 ██████╗ ███████╗████████╗    ███╗   ██╗███████╗██╗  ██╗████████╗    ██╗     ██╗███╗   ██╗███████╗
██╔════╝ ██╔════╝╚══██╔══╝    ████╗  ██║██╔════╝╚██╗██╔╝╚══██╔══╝    ██║     ██║████╗  ██║██╔════╝
██║  ███╗█████╗     ██║       ██╔██╗ ██║█████╗   ╚███╔╝    ██║       ██║     ██║██╔██╗ ██║█████╗
██║   ██║██╔══╝     ██║       ██║╚██╗██║██╔══╝   ██╔██╗    ██║       ██║     ██║██║╚██╗██║██╔══╝
╚██████╔╝███████╗   ██║       ██║ ╚████║███████╗██╔╝ ██╗   ██║       ███████╗██║██║ ╚████║███████╗
 ╚═════╝ ╚══════╝   ╚═╝       ╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝   ╚═╝       ╚══════╝╚═╝╚═╝  ╚═══╝╚══════╝
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
	@printf '$(orange_star) $(bold)$(TARGET)$(font_color): $(bold)needed_args '
	@printf '$(font_color)[$(bold)optional_args$(font_color)]$(reset)\n'
	@printf '        $(bold)arg$(font_color): eplanation\n'
	@printf '        $(bold)arg$(font_color): eplanation\n'
	@printf '        $(bold)arg$(font_color): eplanation, $(bold)WARNING$(reset)\n'
	@printf '$(font_color)Version: $(bold)$(VERSION)$(reset)\n'
endef
# **************************************************************************** #

# **************************************************************************** #
# Rules

all:			setup $(TARGET) usage

usage:
ifneq ($(MAIN),1)
	$(call usage)
endif

$(OBJ_DIR)/%.o: 		$(SRC_DIR)/%.c
	$(call print_padded,$^,$@)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(TARGET):				$(OBJ_C)
	@printf "$(green_plus) $(font_color)Creation of $(bold)$@$(reset)\n"
	@ar rcs $(TARGET) $(OBJ_C)

setup:					call_logo $(OBJ_DIR)

call_logo:
	@printf "$(ascii_color)$$ascii_art"

$(OBJ_DIR):
	@printf "$(green_plus) $(font_color)Creation of $(bold)$(OBJ_DIR)$(reset)\n"
	@mkdir -p $(OBJ_DIR)

clean:
	@printf "$(red_minus) $(font_color)Deleting $(bold)$(OBJ_DIR)$(reset)\n"
	@$(RM) $(OBJ_DIR)

fclean:					clean
	@printf "$(red_minus) $(font_color)Deleting $(bold)$(TARGET)$(reset)\n"
	@$(RM) $(TARGET)

re:						fclean all

.PHONY:					all clean fclean re setup lib call_logo

# **************************************************************************** #
