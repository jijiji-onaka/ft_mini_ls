/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:34:11 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/04 21:07:50 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

int			dir_in_file_num(DIR *dir, size_t *hidden_file_num)
{
	struct dirent		*dp;
	size_t				file_num;

	file_num = 0;
	*hidden_file_num = 0;
	errno = 0;
	while ((dp = readdir(dir)) != NULL)
	{
		if (ft_memcmp(dp->d_name, ".", 1) == 0)
			(*hidden_file_num)++;
		file_num++;
	}
	if (errno != 0 && dp == NULL)
	{
		perror_message(ERR_READDIR);
		return (-1);
	}
	return (file_num);
}

static char	*input_current_dir_file(char *directory, struct dirent *dp)
{
	char	*res;

	if (ft_strcmp(directory, ".") == 0)
		res = ft_strdup(dp->d_name);
	else
		res = ft_str3join(directory, "/", dp->d_name);
	return (res);
}

int			input_dir_file(char **current_dir_file, \
			char *directory, int flag_small_a)
{
	DIR				*dir;
	struct dirent	*dp;
	int				i;

	errno = 0;
	if ((dir = opendir(directory)) == NULL)
		return (perror_message_free(&current_dir_file, ERR_OPENDIR, 0));
	i = 0;
	while ((dp = readdir(dir)) != NULL)
	{
		if (flag_small_a == false)
			if (ft_memcmp(dp->d_name, ".", 1) == 0)
				continue ;
		if (!(current_dir_file[i] = input_current_dir_file(directory, dp)))
			return (perror_message_free(&current_dir_file, ERR_MALLOC, i));
		i++;
	}
	current_dir_file[i] = NULL;
	if (errno != 0 && dp == NULL)
		return (perror_message_free(&current_dir_file, ERR_READDIR, i));
	if (closedir(dir) == -1)
		return (perror_message_free(&current_dir_file, ERR_CLOSEDIR, i));
	return (SUCCESS_RETURN);
}
