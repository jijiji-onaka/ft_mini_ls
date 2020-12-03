/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 04:04:52 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/03 15:54:37 by tjinichi         ###   ########.fr       */
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
	struct stat	stat_buf1;
	struct stat	stat_buf2;

	if (lstat(s1, &stat_buf1) != 0)
		return (INT_MIN);
	if (lstat(s2, &stat_buf2) != 0)
		return (INT_MIN);
	if (stat_buf1.st_mtimespec.tv_sec != stat_buf2.st_mtimespec.tv_sec)
		return (stat_buf1.st_mtimespec.tv_sec - stat_buf2.st_mtimespec.tv_sec);
	else if (stat_buf1.st_mtimespec.tv_nsec != stat_buf2.st_mtimespec.tv_nsec)
		return (stat_buf1.st_mtimespec.tv_nsec - \
				stat_buf2.st_mtimespec.tv_nsec);
	else
		return (-ft_strcmp(s1, s2));
}

int		sort_by_createtime_from_little(char *s1, char *s2)
{
	struct stat	stat_buf1;
	struct stat	stat_buf2;

	if (lstat(s1, &stat_buf1) != 0)
		return (INT_MIN);
	if (lstat(s2, &stat_buf2) != 0)
		return (INT_MIN);
	if (stat_buf1.st_birthtime != stat_buf2.st_birthtime)
		return ((stat_buf1.st_birthtime - stat_buf2.st_birthtime));
	else if (stat_buf1.st_birthtimespec.tv_nsec != \
					stat_buf2.st_birthtimespec.tv_nsec)
		return (stat_buf1.st_birthtimespec.tv_nsec - \
				stat_buf2.st_birthtimespec.tv_nsec);
	else
		return (-ft_strcmp(s1, s2));
}

int		sort_by_atime_from_little(char *s1, char *s2)
{
	struct stat	stat_buf1;
	struct stat	stat_buf2;

	if (lstat(s1, &stat_buf1) != 0)
		return (INT_MIN);
	if (lstat(s2, &stat_buf2) != 0)
		return (INT_MIN);
	if (stat_buf1.st_atime != stat_buf2.st_atime)
		return (stat_buf1.st_atime - stat_buf2.st_atime);
	else if (stat_buf1.st_atimespec.tv_nsec != stat_buf2.st_atimespec.tv_nsec)
		return (stat_buf1.st_atimespec.tv_nsec - \
				stat_buf2.st_atimespec.tv_nsec);
	else
		return (-ft_strcmp(s1, s2));
}

int		sort_by_filesize_from_little(char *s1, char *s2)
{
	struct stat	stat_buf1;
	struct stat	stat_buf2;

	if (lstat(s1, &stat_buf1) != 0)
		return (INT_MIN);
	if (lstat(s2, &stat_buf2) != 0)
		return (INT_MIN);
	if (stat_buf1.st_size != stat_buf2.st_size)
		return (stat_buf1.st_size - stat_buf2.st_size);
	else
		return (-ft_strcmp(s1, s2));
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
