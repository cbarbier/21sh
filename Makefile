# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/04 14:32:18 by cbarbier          #+#    #+#              #
#    Updated: 2017/12/06 11:50:43 by cbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 21sh
LIB				= libft/libft.a
TERMCAP			= -ltermcap
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g
HDR				= includes/21sh.h
SRCS 			= srcs/main.c \
 				  srcs/core_21sh.c \
 				  srcs/init_21sh.c \
 				  srcs/fr33.c \
 				  srcs/line_edit/init_term.c \
 				  srcs/line_edit/key_is1.c \
 				  srcs/line_edit/key_is2.c \
 				  srcs/line_edit/key_is3.c \
 				  srcs/line_edit/key_is4.c \
 				  srcs/line_edit/key_is5.c \
				  srcs/line_edit/key_dump.c \
				  srcs/line_edit/ctrl_d_handler.c \
				  srcs/line_edit/cursor_left.c \
				  srcs/line_edit/cursor_right.c \
				  srcs/line_edit/del_char.c \
				  srcs/line_edit/go_end.c \
				  srcs/line_edit/go_home.c \
				  srcs/line_edit/go_last_line.c \
				  srcs/line_edit/go_last_word.c \
				  srcs/line_edit/go_next_line.c \
				  srcs/line_edit/go_next_word.c \
				  srcs/line_edit/history_back.c \
				  srcs/line_edit/history_next.c \
				  srcs/line_edit/ins_char.c \
				  srcs/line_edit/ret_handler.c \
				  srcs/line_edit/tab_handler.c \
				  srcs/line_edit/do_cut.c \
				  srcs/line_edit/do_copy.c \
				  srcs/line_edit/do_paste.c \
				  srcs/line_edit/selection.c \
				  srcs/line_edit/resize_handling.c \
				  srcs/parser/tools.c \
				  srcs/parser/quoting.c

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
