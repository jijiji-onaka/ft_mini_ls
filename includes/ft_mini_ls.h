/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:44:28 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/02 05:37:26 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H

# include <stdio.h>
# include <dirent.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <time.h>
# include "error.h"
# include "display.h"
# include "sort.h"
# include "../utils/Libft/srcs/libft.h"

int		mini_ls(void);
int		dir_in_file_num(DIR *dir, int *hidden_file_num);
int		input_dir_file(char **current_dir_file, \
			char *directory);

#endif
