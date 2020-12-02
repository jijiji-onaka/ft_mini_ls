/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:59:01 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/02 21:01:32 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static int	print_file_dir(char *file)
{
	write(1, file, ft_strlen(file));
	write(1, "\n", 1);
	return (SUCCESS_RETURN);
}

static int	color_print(char *file)
{
	struct stat stat_buf;

	if (lstat(file, &stat_buf) != 0)
		return (perror_message(ERR_STAT));
	if (ft_isdir(stat_buf.st_mode) == 1)
		write(1, BLUE, 5);
	else if (ft_issymbolic_link(stat_buf.st_mode) == 1)
		write(1, MAGENT, 5);
	else if (ft_isexe_file(stat_buf.st_mode) == 1)
		write(1, RED, 5);
	print_file_dir(file);
	write(1, RESET, 4);
	return (SUCCESS_RETURN);
}

int			display_2d(char **array2d, int flag_large_g)
{
	int	i;

	i = 0;
	while (array2d[i])
	{
		if (flag_large_g == true)
		{
			if (color_print(array2d[i]) == ERROR_RETURN)
				return (ERROR_RETURN);
		}
		else
		{
			if (print_file_dir(array2d[i]) == ERROR_RETURN)
				return (ERROR_RETURN);
		}
		i++;
	}
	return (SUCCESS_RETURN);
}
