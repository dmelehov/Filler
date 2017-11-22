# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/17 10:09:53 by dmelehov          #+#    #+#              #
#    Updated: 2017/10/20 20:16:31 by dmelehov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==== Editable ====
NAME:= filler

HEAD = filler.h

FILES:= filler filler2 filler3 filler4
# ==================

# ==== Standard ====
CC:=gcc
CCHPATH:=cache/
LIBFT:=ft_printf/libft.a
PRINTF:=ft_printf/ft_printf.a
LINKER:= ar rc
#SRCPATH:=src/
HDRPATH:=includes/
CFLAGS:=-Wall -Wextra -Werror -I $(HDRPATH)
# ==================

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
END:="\033[0;0m"
YELLOW = "\x1b[33m"
# ==================

# ====== Auto ======
SRC:=$(addsuffix .c,$(FILES))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
# ==================
CCHF:=.cache_exists

all: $(NAME)

$(NAME): $(OBJ)
#@echo "\n"
#@make -C libft/
	@make -C ft_printf/
	@echo $(YELLOW) " - Compiling $@" $(RED)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) -o visual visualizer.c $(LIBFT) $(PRINTF)
#@ar rc $(NAME) $(OBJ)
#@ranlib $(NAME)
	@echo $(GREEN) "\t$@\t\t- has been made\n" $(END)

$(CCHPATH)%.o: %.c $(CCHF)
	@echo $(PURPLE) "\tCompiling $< into $@" $(END)
	@$(CC) $(CFLAGS) -c $< -o $@

$(CCHF):
	@mkdir -p $(CCHPATH)
	@touch $(CCHF)

cleanlib:
	@make clean -C ./ft_printf
	@make clean -C ./libft

clean: cleanlib
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)

fclean: clean
	@make fclean -C ./ft_printf
	@make fclean -C ./libft
	@rm -f $(NAME)
	@rm -f visual

re: fclean
	@$(MAKE) all