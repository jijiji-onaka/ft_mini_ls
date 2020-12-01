# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 02:40:46 by tjinichi          #+#    #+#              #
#    Updated: 2020/12/02 05:42:22 by tjinichi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_mini_ls

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

LIBS = utils/Libft/
LIBFT = utils/Libft/libft.a

SRCFILE =	main.c \
			error.c \
			mini_ls.c \
			ls_utils.c \
			display.c \
			sort.c \

BONUS_SRCFILE =	main.c \
			error.c \
			mini_ls.c \
			ls_utils.c \
			display.c \
			sort.c \

SRCDIR = ./srcs/
BONUS_DIR = ./bonus/

SRCS = $(addprefix $(SRCDIR), $(SRCFILE))
BONUS_SRCS = $(addprefix $(BONUS_DIR), $(BONUS_SRCFILE))

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)


$(LIBFT):FORCE
	@make -C $(LIBS)

clean:
	@make clean -C $(LIBS)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBS)
	rm -f $(NAME)

re: fclean all

bonus: $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJS) $(LIBFT)

.PHONY: all clean fclean re FORCE
