# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 02:40:46 by tjinichi          #+#    #+#              #
#    Updated: 2020/12/02 05:32:56 by tjinichi         ###   ########.fr        #
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

SRCDIR = ./srcs/

SRCS = $(addprefix $(SRCDIR), $(SRCFILE))

OBJS = $(SRCS:.c=.o)

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

.PHONY: all clean fclean re FORCE
