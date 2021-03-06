/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 23:12:16 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/08 17:12:58 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

void	print_file_dir(char *file)
{
	char	*file_tmp;

	if ((file_tmp = ft_strrchr(file, '/')) != NULL)
		file = file_tmp + 1;
	write(1, file, ft_strlen(file));
	write(1, "\n", 1);
}

int		color_print(char *file, struct stat stat_buf)
{
	if (lstat(file, &stat_buf) != 0)
		return (perror_message(ERR_STAT));
	if (is_dir(stat_buf.st_mode) > 0 && is_w_authority(stat_buf.st_mode) > 0)
	{
		puts("1");
		putstr_back_yellow(file);
	}
	else if (is_dir(stat_buf.st_mode) > 0)
		putstr_blue(file);
	else if (is_symbolic_link(stat_buf.st_mode) > 0)
		putstr_magent(file);
	else if (is_fifo(stat_buf.st_mode) > 0)
		putstr_yellow(file);
	else if (is_socket(stat_buf.st_mode) > 0)
		putstr_green(file);
	else if (is_exe_file(stat_buf.st_mode) > 0)
		putstr_red(file);
	else if (is_character_device(stat_buf.st_mode) > 0)
		putstr_blue_back_yellow(file);
	else if (is_block_device(stat_buf.st_mode) > 0)
		putstr_blue_back_cyaan(file);
	else
		print_file_dir(file);
	return (SUCCESS_RETURN);
}
