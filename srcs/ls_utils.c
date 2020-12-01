/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:34:11 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/02 05:13:57 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls.h"

int		dir_in_file_num(DIR *dir, int *hidden_file_num)
{
	struct dirent	*dp;
	int				file_num;

	while ((dp = readdir(dir)) != NULL)
	{
		if (ft_memcmp(dp->d_name, ".", 1) == 0)
			(*hidden_file_num)++;
		file_num++;
	}
	return (file_num);
}

int		input_dir_file(char **current_dir_file, \
			char *directory)
{
	DIR				*dir;
	struct dirent	*dp;
	int				i;

	if ((dir = opendir(directory)) == NULL)
		return (perror_message_free(&current_dir_file, ERR_OPENDIR));
	i = 0;
	while ((dp = readdir(dir)) != NULL)
	{
		if (ft_memcmp(dp->d_name, ".", 1) == 0)
			continue ;
		current_dir_file[i++] = dp->d_name;
	}
	current_dir_file[i] = NULL;
	closedir(dir);
	return (0);
}
