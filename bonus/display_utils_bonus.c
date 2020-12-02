/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 23:12:16 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/03 03:31:49 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

void	print_file_dir(char *file)
{
	write(1, file, ft_strlen(file));
	write(1, "\n", 1);
}

int		color_print(char *file, struct stat stat_buf)
{
	if (lstat(file, &stat_buf) != 0)
		return (perror_message(ERR_STAT));
	if (ft_isdir(stat_buf.st_mode) > 0)
		putstr_blue(file);
	else if (ft_issymbolic_link(stat_buf.st_mode) > 0)
		putstr_magent(file);
	else if (ft_isexe_file(stat_buf.st_mode) > 0)
		putstr_red(file);
	else if (ft_ischaracter_device(stat_buf.st_mode) > 0)
		putstr_blue_back_yellow(file);
	else if (ft_isblock_device(stat_buf.st_mode) > 0)
		putstr_blue_back_cyaan(file);
	else
		print_file_dir(file);
	return (SUCCESS_RETURN);
}
