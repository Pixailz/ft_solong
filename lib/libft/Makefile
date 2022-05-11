# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 01:36:34 by brda-sil          #+#    #+#              #
#    Updated: 2022/05/12 00:08:54 by brda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# config
CFLAGS			:= -Wall -Wextra -Werror
NAME			:= libft.a
RM				:= rm -rf
CC				:= gcc
NASM			:= nasm
PADDING			:= 30

# DIR
SRC_DIR			:= src
INC_DIR			:= includes
OBJ_DIR			:= obj

# SRC
SRC_C			:= $(wildcard $(SRC_DIR)/*.c)
SRC_A			:= $(wildcard $(SRC_DIR)/*.s)

# OBJ
OBJ_C			:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))
OBJ_A			:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_A:%.s=%.o))

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
██╗     ██╗██████╗ ███████╗████████╗
██║     ██║██╔══██╗██╔════╝╚══██╔══╝
██║     ██║██████╔╝█████╗     ██║
██║     ██║██╔══██╗██╔══╝     ██║
███████╗██║██████╔╝██║        ██║
╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝
$(reset)
endef
export ascii_art

# **************************************************************************** #

# **************************************************************************** #
# Building rules

all:			setup $(NAME)

$(OBJ_DIR)/%.o: 		$(SRC_DIR)/%.c
	@printf "  $(font_color)[$(green)+$(font_color)] Creation of $(bold)$<"
	$(eval OBJ_LEN := $(shell printf $^ | wc -c))
	$(eval PAD_LEN := $(shell expr $(PADDING) - $(OBJ_LEN)))
	@printf "%-$(PAD_LEN)s" " "
	@printf "$(blinking)$(font_color)-> $(reset)$(bold)$@ $(reset)"
	@printf "%-30s" " "
	@printf "\n"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR)/%.o: 		$(SRC_DIR)/%.s
	@printf "  $(font_color)[$(green)+$(font_color)] Creation of $(bold)$<"
	$(eval OBJ_LEN := $(shell printf $^ | wc -c))
	$(eval PAD_LEN := $(shell expr $(PADDING) - $(OBJ_LEN)))
	@printf "%-$(PAD_LEN)s" " "
	@printf "$(blinking)$(font_color)-> $(reset)$(bold)$@ $(reset)"
	@printf "%-30s" " "
	@printf "\n"
	@$(NASM) -f elf64 -o $@ $<

$(NAME):				$(OBJ_C) $(OBJ_A)
	@printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)$(NAME)$(reset)\n"
	@ar rcs $(NAME) $(OBJ_C) $(OBJ_A)

setup:					call_logo $(OBJ_DIR)

$(OBJ_DIR):
	@printf "$(font_color)[$(green)+$(font_color)] Creation of $(bold)$(OBJ_DIR)$(reset)\n"
	@mkdir -p $(OBJ_DIR)

clean:
	@printf "$(font_color)[$(red)-$(font_color)] Deleting $(bold)$(OBJ_DIR)$(reset)\n"
	@$(RM) $(OBJ_DIR)

fclean:					clean
	@printf "$(font_color)[$(red)-$(font_color)] Deleting $(bold)$(NAME)$(reset)\n"
	@$(RM) $(NAME)

re:						call_logo fclean $(OBJ_DIR) $(NAME)

call_logo:
	@printf "$(ascii_color)$$ascii_art"

.PHONY:					all clean fclean re setup lib call_logo

# **************************************************************************** #
