/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 21:54:29 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/03 04:32:32 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

int		is_dir(mode_t st_mode)
{
	return (S_ISDIR(st_mode));
}

int		is_symbolic_link(mode_t st_mode)
{
	return (S_ISLNK(st_mode));
}

int		is_exe_file(mode_t st_mode)
{
	if (is_symbolic_link(st_mode) == 1)
		return (ERROR_RETURN);
	return (st_mode & S_IXUSR);
}

int		is_character_device(mode_t st_mode)
{
	return (S_ISCHR(st_mode));
}

int		is_block_device(mode_t st_mode)
{
	return (S_ISBLK(st_mode));
}
