# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/23 20:15:31 by tjinichi          #+#    #+#              #
#    Updated: 2020/12/08 17:32:46 by tjinichi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm

SRCFILE =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strjoinch.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_isspace.c \
		ft_stoi.c \
		ft_stod.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_check_file_tail.c \
		count_2d.c \
		array_free_2d.c \
		ft_numlen.c \
		create_file_name.c \
		ft_stov.c \
		ft_strcmp.c \
		joint_number.c \
		file_tail_number.c \
		ft_swap.c \
		ft_strsort.c \
		ft_two_2d_ptr_free.c \
		ft_ptr_free.c \
		ft_str3join.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_lstdelone.c \
		ft_lstmap.c \

SRCDIR = ./srcs/

SRCS = $(addprefix $(SRCDIR), $(SRCFILE))

SRC_TMP	= $(notdir $(SRCS))


OBJ_TMP = $(SRC_TMP:.c=.o)

OBJDIR = $(SRCDIR)objs/

OBJS	= $(addprefix $(OBJDIR), $(OBJ_TMP))

# ============================ COLOR =========================
RESET		= \033[0m
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENT		= \033[0;35m
CYAAN		= \033[0;36m
WHITE		= \033[0;37m
B_RESET		= \033[0;49m
B_YELLOW	= \033[0;43m
B_CYAAN		= \033[0;46m
BOLD		= \033[1m
UNDER_LINE	= \033[0;4m

# ============================================================

# ============================ Increment % ===================

T		=	$(words ${OBJS})
N		=	0
# words = 文字列の個数を数えます
# eval = 文字列を評価します
C		=	$(words $N)${eval N += 1}
ECHO	=	"[`expr $C  '*' 100 / $T`%]"

# ============================================================

$(OBJDIR)%.o : $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf " %-100b\r" "$(YELLOW)$(ECHO) Compiling  $(RESET)$(UNDER_LINE)"$@"$(RESET)"


$(NAME): $(OBJS)
	@make -C ./srcs/libvec3D
	@cp ./srcs/libvec3D/libvec.a $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@printf "\r                                                             \r$(GREEN)$(BOLD)created libft.a$(RESET)\n"

all:	$(NAME)

clean:
	@make clean -C ./srcs/libvec3D
	@$(RM) -rf $(OBJDIR)

fclean: clean
	@make fclean -C ./srcs/libvec3D
	@$(RM) -f $(NAME)


re:	fclean all

.PHONY:	all clean fclean re
