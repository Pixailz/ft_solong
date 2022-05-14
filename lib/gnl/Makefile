# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 01:36:34 by brda-sil          #+#    #+#              #
#    Updated: 2022/05/14 16:00:49 by brda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# config
CFLAGS			:= -Wall -Wextra -Werror #-g
NAME			:= get_next_line.a
RM				:= rm -rf
CC				:= gcc
PADDING			:= 30

# DIR
SRC_DIR			:= src
INC_DIR			:= includes
OBJ_DIR			:= obj

# SRC
SRC_C			:= $(wildcard $(SRC_DIR)/*.c)

# OBJ
OBJ_C			:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))

# LIB DIR
CFLAGS			+= -I$(INC_DIR)

#  Bash Color
green			:= \033[38;5;82m
blue			:= \033[38;5;75m
red				:= \033[38;5;196m
yellow			:= \033[38;5;226m

blinking		:= \033[5m
reset			:= \033[0m

font_color		:= $(blue)
bold			:= $(green)
ascii_color		:= $(bold)

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

# **************************************************************************** #

# **************************************************************************** #
# Rules

all:			setup $(NAME)

$(OBJ_DIR)/%.o: 		$(SRC_DIR)/%.c
	@printf "   $(font_color)[$(green)+$(font_color)] Creation of $(bold)$<"
	$(eval OBJ_LEN := $(shell printf $^ | wc -c))
	$(eval PAD_LEN := $(shell expr $(PADDING) - $(OBJ_LEN)))
	@printf "%-$(PAD_LEN)s" " "
	@printf "$(blinking)$(font_color)-> $(reset)$(bold)$@ $(reset)"
	@printf "\n"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):			$(OBJ_DIR) $(OBJ_C)
	@printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)$(NAME)$(reset)\n"
	@ar rcs $(NAME) $(OBJ_C)

setup:					call_logo

call_logo:
	@printf "$(ascii_color)$$ascii_art"

$(OBJ_DIR):
	@printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)$(OBJ_DIR)$(reset)\n"
	@mkdir -p $(OBJ_DIR)

clean:
	@printf "$(font_color)[$(red)-$(font_color)] Deleting $(bold)$(OBJ_DIR)$(reset)\n"
	@$(RM) $(OBJ_DIR)

fclean:					clean
	@printf "$(font_color)[$(red)-$(font_color)] Deleting $(bold)$(NAME)$(reset)\n"
	@$(RM) $(NAME)

re:						call_logo fclean $(OBJ_DIR) all

.PHONY:					all clean fclean re setup call_logo

# **************************************************************************** #
