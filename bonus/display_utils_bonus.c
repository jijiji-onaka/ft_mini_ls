/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 23:12:16 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/03 01:45:50 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

int		print_file_dir(char *file)
{
	// struct stat stat_buf;
	// if (lstat(file, &stat_buf) != 0)
	// 	return (perror_message(ERR_STAT));
	write(1, file, ft_strlen(file));
	write(1, RESET, 4);
	write(1, B_RESET, 5);
	write(1, "\n", 1);
	// printf("ctime : %s", (char*)ctime(&stat_buf.st_ctimespec.tv_nsec));
	fflush(stdout);
	return (SUCCESS_RETURN);
}

int		color_print(char *file, struct stat stat_buf)
{
	if (lstat(file, &stat_buf) != 0)
		return (perror_message(ERR_STAT));
	if (ft_isdir(stat_buf.st_mode) > 0)
		write(1, BLUE, 5);
	else if (ft_issymbolic_link(stat_buf.st_mode) > 0)
		write(1, MAGENT, 5);
	else if (ft_isexe_file(stat_buf.st_mode) > 0)
		write(1, RED, 5);
	else if (ft_ischaracter_device(stat_buf.st_mode) > 0)
	{
		write(1, B_YELLOW, 5);
		write(1, BLUE, 5);
	}
	else if (ft_isblock_device(stat_buf.st_mode) > 0)
	{
		write(1, B_CYAAN, 5);
		write(1, BLUE, 5);
	}
	print_file_dir(file);
	return (SUCCESS_RETURN);
}
