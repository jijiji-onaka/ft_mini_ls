/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:45:32 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/02 23:17:21 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_BONUS_H
# define DISPLAY_BONUS_H

# include "option_flag_bonus.h"
# include <sys/stat.h>

int			display_2d(char **array2d, t_op *flag);
void		default_display_2d(char **array2d);
int			print_file_dir(char *file);
int			color_print(char *file, struct stat stat_buf);

#endif
