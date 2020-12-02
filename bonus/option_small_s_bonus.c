/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_small_s_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 23:51:53 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/02 23:52:27 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

int		put_total(char **array2d, int f)
{
	struct stat	stat_buf;
	int			i;
	blkcnt_t	total;

	i = 0;
	total = 0;
	while (array2d[i])
	{
		if (lstat(array2d[i], &stat_buf) != 0)
			return (ERROR_RETURN);
		total += stat_buf.st_blocks;
		i++;
	}
	write(1, "total ", 6);
	ft_putnbr_fd((int)total / (int)(f + 1), 1);
	write(1, "\n", 1);
	return (SUCCESS_RETURN);
}

void	put_blocks(blkcnt_t blocks, int f)
{
	long long	width;

	width = ft_numlen((long long)blocks / (long long)(f + 1));
	write(1, "   ", 3 - width);
	ft_putnbr_fd((int)blocks / (int)(f + 1), 1);
	write(1, " ", 1);
}
