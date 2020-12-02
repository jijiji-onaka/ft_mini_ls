/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:59:01 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/02 23:56:14 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

int			display_2d(char **array2d, t_op *flag)
{
	int			i;
	struct stat	stat_buf;

	i = -1;
	if (flag->small_s)
		if (put_total(array2d, 0) == ERROR_RETURN)
			return (ERROR_RETURN);
	while (array2d[++i])
	{
		if (lstat(array2d[i], &stat_buf) != 0)
			return (perror_message(ERR_STAT));
		if (flag->small_s == true)
			put_blocks(stat_buf.st_blocks, 0);
		if (flag->large_g == true)
		{
			if (color_print(array2d[i], stat_buf) == ERROR_RETURN)
				return (ERROR_RETURN);
		}
		else
		{
			if (print_file_dir(array2d[i]) == ERROR_RETURN)
				return (ERROR_RETURN);
		}
	}
	return (SUCCESS_RETURN);
}

void	default_display_2d(char **array2d)
{
	int	i;

	i = 0;
	while (array2d[i])
	{
		write(1, array2d[i], ft_strlen(array2d[i]));
		write(1, "\n", 1);
		i++;
	}
}
