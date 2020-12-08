/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:29:09 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/08 17:09:15 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

int		is_fifo(mode_t st_mode)
{
	return (S_ISFIFO(st_mode));
}

int		is_socket(mode_t st_mode)
{
	return (S_ISSOCK(st_mode));
}

int		is_w_authority(mode_t st_mode)
{
	int	f;

	f = 0;
	if ((st_mode & S_IWUSR) > 0)
		f++;
	if ((st_mode & S_IWGRP) > 0)
		f++;
	if ((st_mode & S_IWOTH) > 0)
		f++;
	return (f >= 2);
}
