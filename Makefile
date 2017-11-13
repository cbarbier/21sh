# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/04 14:32:18 by cbarbier          #+#    #+#              #
#    Updated: 2017/11/13 14:16:13 by cbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 21sh
LIB				= libft/libft.a
TERMCAP			= -ltermcap
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g
HDR				= includes/21sh.h
SRCS 			= srcs/main.c

OBJS			= $(SRCS:.c=.o)

all: $(NAME)
	@echo " / \   / \   / \   / \ "
	@echo "( \033[0;32m2\033[0m ) ( \033[0;32m1\033[0m ) ( \033[0;32mS\033[0m ) ( \033[0;32mH\033[0m )"
	@echo " \_/   \_/   \_/   \_/ "

%.o:%.c $(HDR)
	@$(CC) $(CFLAGS) -c $< -o $@ -Iincludes

$(NAME): $(LIBMLX) $(LIB) $(OBJS) $(HDR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft $(TERMCAP) 
	@echo "21SH BUILT\t\t\033[0;32m✓\033[0m"

ifneq ($(shell make -q -C libft;echo $$?), 0)
.PHONY: $(LIB)
endif

$(LIB):
	@make -C libft

clean:
	@/bin/rm -rf $(OBJS)
	@/bin/rm -rf $(NAME).dSYM
	@make -C libft clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
