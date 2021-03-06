/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:59:01 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/04 01:17:48 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

int			display_2d(char **array2d, t_op *flag)
{
	int			i;
	struct stat	stat_buf;
	blkcnt_t	blocks_width;

	if (flag->small_s && array2d[0] != NULL)
		if (put_total(array2d, 0, &blocks_width) == ERROR_RETURN)
			return (ERROR_RETURN);
	i = 0;
	while (array2d[i])
	{
		if (lstat(array2d[i], &stat_buf) != 0)
			return (perror_message(ERR_STAT));
		if (flag->small_s == true)
			put_blocks(stat_buf.st_blocks, blocks_width);
		if (flag->large_g == true)
			color_print(array2d[i], stat_buf);
		else
			print_file_dir(array2d[i]);
		i++;
	}
	return (SUCCESS_RETURN);
}

void		default_display_2d(char **array2d)
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
