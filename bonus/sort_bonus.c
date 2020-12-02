/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 04:04:52 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/02 18:13:52 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

/*
** I should have written return ((s1_time - s2_time));
** because it is the smaller one,
** but in this case I wrote return (-(s1_time - s2_time));
** because of the option -r
*/

int		sort_by_mtime_from_little(char *s1, char *s2)
{
	struct stat	stat_buf;
	time_t		s1_time;
	time_t		s2_time;

	if (lstat(s1, &stat_buf) != 0)
		return (INT_MIN);
	s1_time = stat_buf.st_mtime;
	if (lstat(s2, &stat_buf) != 0)
		return (INT_MIN);
	s2_time = stat_buf.st_mtime;
	return ((s1_time - s2_time));
}
