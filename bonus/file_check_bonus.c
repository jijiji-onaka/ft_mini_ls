/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 21:54:29 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/03 00:47:17 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

int		ft_isdir(mode_t st_mode)
{
	return (S_ISDIR(st_mode));
}

int		ft_issymbolic_link(mode_t st_mode)
{
	return (S_ISLNK(st_mode));
}

int		ft_isexe_file(mode_t st_mode)
{
	if (ft_issymbolic_link(st_mode) == 1)
		return (ERROR_RETURN);
	return (st_mode & S_IXUSR);
}

int		ft_ischaracter_device(mode_t st_mode)
{
	return (S_ISCHR(st_mode));
}

int		ft_isblock_device(mode_t st_mode)
{
	return (S_ISBLK(st_mode));
}
