# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 02:40:46 by tjinichi          #+#    #+#              #
#    Updated: 2020/12/08 17:41:00 by tjinichi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST_DIR = ./42_ft_mini_ls_test/

NAME = ft_mini_ls
# BONUS_NAME = ft_mini_ls

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBS = ./utils/Libft/
LIBFT = ./utils/Libft/libft.a
LFLAGS = -L $(LIBS) -lft

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

BONUS_SRC	= $(notdir $(BONUS_SRCS))
# OBJ = $(BONUS_SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

OBJDIR		= $(BONUS_DIR)objs/
BONUS_OBJS	= $(addprefix $(OBJDIR), $(BONUS_OBJ))

TEST = $(addprefix $(TEST_DIR), test.sh)
LEAK = $(addprefix $(TEST_DIR), leak.sh)

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
UNDER_LINE	= \033[4m

# ============================================================

# ============================ Increment % ===================

T		=	$(words ${BONUS_OBJS})
N		=	0
# words = 文字列の個数を数えます
# eval = 文字列を評価します
C		=	$(words $N)${eval N += 1}
ECHO	=	"[`expr $C  '*' 100 / $T`%]"

# ============================================================

all: $(NAME)

$(NAME): $(LIBFT) $(BONUS_OBJS)
	@printf "\r                                                             \r$(GREEN)$(BOLD)created $(notdir $(BONUS_OBJS))$(RESET)\n"
	@$(CC) $(CFLAGS) $^ $(LFLAGS) -o $@
	@echo "\n$(GREEN)$(BOLD)$(UNDER_LINE)Finished.\nYou can use $@$(RESET)"

$(LIBFT):FORCE
	@$(MAKE) -C $(LIBS)

$(OBJDIR)%.o : $(BONUS_DIR)%.c
	@printf " %-100b\r" "$(YELLOW)$(ECHO) Compiling  $(RESET)$(UNDER_LINE)"$@"$(RESET)"
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@echo "$(RED)$(BOLD)[Deleted] \n$(LIBS)objs$(RESET)\n"
	@$(MAKE) -C $(LIBS) clean
	@echo "$(RED)$(BOLD)[Deleted] \n$(BONUS_OBJ)$(RESET)"
	@rm -rf $(OBJDIR)

fclean:
	make clean
	@echo "\n$(RED)$(BOLD)[Deleted] \n$(LIBFT)$(RESET)\n"
	@$(MAKE) -C $(LIBS) fclean
	@echo "$(RED)$(BOLD)[Deleted] \n$(NAME)$(RESET)"
	@rm -f $(NAME)


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
