# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 02:40:46 by tjinichi          #+#    #+#              #
#    Updated: 2020/12/03 01:57:45 by tjinichi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST_DIR = ./42_ft_mini_ls_test/

NAME = ft_mini
BONUS_NAME = ft_mini_ls

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBS = utils/Libft/
LIBFT = utils/Libft/libft.a

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
			display_utils_bonus.c \
			option_small_s_bonus.c \

SRCDIR = ./srcs/
BONUS_DIR = ./bonus/

SRCS = $(addprefix $(SRCDIR), $(SRCFILE))
BONUS_SRCS = $(addprefix $(BONUS_DIR), $(BONUS_SRCFILE))

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

TEST = $(addprefix $(TEST_DIR), test.sh)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):FORCE
	@make -C $(LIBS)

clean:
	@make clean -C $(LIBS)
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@make fclean -C $(LIBS)
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(LIBFT)

bonus_re: fclean bonus

test: bonus
	bash $(TEST)

.PHONY: all clean fclean re FORCE test bonus
