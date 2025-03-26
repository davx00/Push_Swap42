# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: despanol <despanol@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 18:05:05 by despanol          #+#    #+#              #
#    Updated: 2025/03/24 12:54:03 by despanol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = ./main ./else
SRC_FILES = $(shell find $(SRC_DIR) -name "*.c")
OBJ_FILES = $(SRC_FILES:.c=.o)
DEP_FILES = $(SRC_FILES:.c=.d)

INCLUDES = ./main ./libft

NAME = push_swap  # Nombre del ejecutable

all: banner_before $(NAME) banner_after

banner_before:
	@echo "─────────────────────────────────────────────────────"
	@echo "  ██████╗  █████╗ ██╗   ██╗██╗  ██╗"
	@echo "  ██╔══██╗██╔══██╗██║   ██║╚██╗██╔╝"
	@echo "  ██║  ██║███████║██║   ██║ ╚███╔╝ "
	@echo "  ██║  ██║██╔══██║ ██║ ██║  ██╔██╗ "
	@echo "  ██████╔╝██║  ██║  ╚██╔╝  ██╗  ██"
	@echo "  ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝" WELCOME
	@echo "\n─────────────────────────────────────────────────────"
	@echo "Working..."

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME)

banner_after:
	@echo "─────────────────────────────────────────────────────"
	@echo "  ██████╗  █████╗ ██╗   ██╗██╗  ██╗"
	@echo "  ██╔══██╗██╔══██╗██║   ██║╚██╗██╔╝"
	@echo "  ██║  ██║███████║██║   ██║ ╚███╔╝ "
	@echo "  ██║  ██║██╔══██║ ██║ ██║  ██╔██╗ "
	@echo "  ██████╔╝██║  ██║  ╚██╔╝  ██╗  ██"
	@echo "  ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝" PUSH_SWAP
	@echo "\n─────────────────────────────────────────────────────"
	@echo "Compilation completed: $(NAME) OK."

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(CFFLAGS) $(addprefix -I, $(INCLUDES)) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ_FILES) $(DEP_FILES)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

-include $(DEP_FILES)

.PHONY: all clean fclean re banner_before banner_after
