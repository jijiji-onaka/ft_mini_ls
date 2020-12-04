# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 02:40:46 by tjinichi          #+#    #+#              #
#    Updated: 2020/12/05 00:42:02 by tjinichi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST_DIR = ./42_ft_mini_ls_test/

NAME = ft_mini_ls
# BONUS_NAME = ft_mini_ls

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBS = ./utils/Libft/
LIBFT = ./utils/Libft/libft.a

SRCFILE =	main.c \
			error.c \
			mini_ls.c \
			ls_utils.c \
			display.c \
			sort.c \

BONUS_SRCFILE =	main_bonus.c \
			error_bonus.c \
			mini_ls_bonus.c \
			ls_utils_bonus.c \
			display_bonus.c \
			sort_bonus.c \
			option_flag_bonus.c \
			file_check_bonus.c \
			file_check2_bonus.c \
			display_utils_bonus.c \
			option_small_s_bonus.c \
			option_large_r_bonus.c \
			color_print_bonus.c \
			color_print2_bonus.c \

SRCDIR = ./srcs/
BONUS_DIR = ./bonus/

SRCS = $(addprefix $(SRCDIR), $(SRCFILE))
BONUS_SRCS = $(addprefix $(BONUS_DIR), $(BONUS_SRCFILE))

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

TEST = $(addprefix $(TEST_DIR), test.sh)
LEAK = $(addprefix $(TEST_DIR), leak.sh)

all: $(NAME)

$(NAME): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJS) $(LIBFT)

$(LIBFT):FORCE
	@make -C $(LIBS)

clean:
	@make clean -C $(LIBS)
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@make fclean -C $(LIBS)
	rm -f $(NAME)

re: fclean all

# bonus: $(LIBFT) $(BONUS_OBJS)
# 	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJS) $(LIBFT)

# bonus_re: fclean bonus

test: $(LIBFT) $(BONUS_OBJS)
	$(CC) -g -fsanitize=address $(CFLAGS) -o $(NAME) $(BONUS_OBJS) $(LIBFT)
	bash $(TEST)

OP =

leak: all
	bash $(LEAK) $(OP)

valgrind: all
	valgrind --leak-check=full -s ./$(NAME) $(OP)
	rm -rf $(NAME).dSYM

.PHONY: all clean fclean re FORCE test leak valgrind
