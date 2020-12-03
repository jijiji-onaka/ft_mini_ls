/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:44:28 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/04 03:58:30 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_BONUS_H
# define FT_MINI_LS_BONUS_H

# include <stdio.h>
# include <dirent.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <time.h>
# include "error_bonus.h"
# include "display_bonus.h"
# include "sort_bonus.h"
# include "option_flag_bonus.h"
# include "color.h"
# include "../utils/Libft/srcs/libft.h"

int				mini_ls(void);
int				mini_ls_option(char **arg);
size_t			dir_in_file_num(DIR *dir, size_t *hidden_file_num);
int				input_dir_file(char **current_dir_file, \
					char *directory, int flag_small_a);
int				is_dir(mode_t st_mode);
int				is_symbolic_link(mode_t st_mode);
int				is_exe_file(mode_t st_mode);
int				is_character_device(mode_t st_mode);
int				is_block_device(mode_t st_mode);

#endif
