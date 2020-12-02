/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:44:28 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/02 22:34:17 by tjinichi         ###   ########.fr       */
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
int				dir_in_file_num(DIR *dir, int *hidden_file_num);
int				input_dir_file(char **current_dir_file, \
					char *directory);
int				ft_isdir(mode_t st_mode);
int				ft_issymbolic_link(mode_t st_mode);
int				ft_isexe_file(mode_t st_mode);
int				ft_ischaracter_device(mode_t st_mode);
int				ft_isblock_device(mode_t st_mode);

#endif
