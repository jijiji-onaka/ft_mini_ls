/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 04:04:52 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/04 02:09:45 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls.h"

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
