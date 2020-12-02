/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 04:04:52 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/03 03:24:55 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

/*
** I should have written return (-(s1_time - s2_time));
** because it is the smaller one,
** but in this case I wrote return ((s1_time - s2_time));
** because of the option -r
*/

int		sort_by_mtime_from_little(char *s1, char *s2)
{
	struct stat	stat_buf;
	time_t		s1_time;
	time_t		s2_time;

	if (lstat(s1, &stat_buf) != 0)
		return (INT_MIN);
	s1_time = stat_buf.st_mtimespec.tv_sec;
	if (lstat(s2, &stat_buf) != 0)
		return (INT_MIN);
	s2_time = stat_buf.st_mtimespec.tv_sec;
	if (s1_time - s2_time == 0)
	{
		if (lstat(s1, &stat_buf) != 0)
			return (INT_MIN);
		s1_time = stat_buf.st_mtimespec.tv_nsec;
		if (lstat(s2, &stat_buf) != 0)
			return (INT_MIN);
		s2_time = stat_buf.st_mtimespec.tv_nsec;
	}
	return ((s1_time - s2_time));
}

int		sort_by_createtime_from_little(char *s1, char *s2)
{
	struct stat	stat_buf;
	time_t		s1_time;
	time_t		s2_time;

	if (lstat(s1, &stat_buf) != 0)
		return (INT_MIN);
	s1_time = stat_buf.st_birthtime;
	if (lstat(s2, &stat_buf) != 0)
		return (INT_MIN);
	s2_time = stat_buf.st_birthtime;
	if (s1_time - s2_time == 0)
	{
		if (lstat(s1, &stat_buf) != 0)
			return (INT_MIN);
		s1_time = stat_buf.st_birthtimespec.tv_nsec;
		if (lstat(s2, &stat_buf) != 0)
			return (INT_MIN);
		s2_time = stat_buf.st_birthtimespec.tv_nsec;
	}
	return ((s1_time - s2_time));
}

int		sort_by_atime_from_little(char *s1, char *s2)
{
	struct stat	stat_buf;
	time_t		s1_time;
	time_t		s2_time;

	if (lstat(s1, &stat_buf) != 0)
		return (INT_MIN);
	s1_time = stat_buf.st_atime;
	if (lstat(s2, &stat_buf) != 0)
		return (INT_MIN);
	s2_time = stat_buf.st_atime;
	if (s1_time - s2_time == 0)
	{
		if (lstat(s1, &stat_buf) != 0)
			return (INT_MIN);
		s1_time = stat_buf.st_atimespec.tv_nsec;
		if (lstat(s2, &stat_buf) != 0)
			return (INT_MIN);
		s2_time = stat_buf.st_atimespec.tv_nsec;
	}
	return ((s1_time - s2_time));
}

int		sort_by_filesize_from_little(char *s1, char *s2)
{
	struct stat	stat_buf;
	off_t		s1_size;
	off_t		s2_size;

	if (lstat(s1, &stat_buf) != 0)
		return (INT_MIN);
	s1_size = stat_buf.st_size;
	if (lstat(s2, &stat_buf) != 0)
		return (INT_MIN);
	s2_size = stat_buf.st_size;
	if (s1_size - s2_size == 0)
	{
		if (lstat(s1, &stat_buf) != 0)
			return (INT_MIN);
		s1_size = stat_buf.st_birthtimespec.tv_nsec;
		if (lstat(s2, &stat_buf) != 0)
			return (INT_MIN);
		s2_size = stat_buf.st_birthtimespec.tv_nsec;
		return (-(s1_size - s2_size));
	}
	return ((s1_size - s2_size));
}

void	sort_by_what(char **current_dir_file, t_op *flag)
{
	if (flag->large_s)
		ft_strsort(current_dir_file, &sort_by_filesize_from_little);
	else if (flag->large_u)
		ft_strsort(current_dir_file, &sort_by_createtime_from_little);
	else if (flag->small_u)
		ft_strsort(current_dir_file, &sort_by_atime_from_little);
	else
		ft_strsort(current_dir_file, &sort_by_mtime_from_little);
}
