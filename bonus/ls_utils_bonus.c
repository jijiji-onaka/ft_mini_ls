/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:34:11 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/03 18:51:23 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

size_t		dir_in_file_num(DIR *dir, size_t *hidden_file_num)
{
	struct dirent		*dp;
	size_t				file_num;

	file_num = 0;
	*hidden_file_num = 0;
	while ((dp = readdir(dir)) != NULL)
	{
		if (ft_memcmp(dp->d_name, ".", 1) == 0)
			(*hidden_file_num)++;
		file_num++;
	}
	return (file_num);
}

int			input_dir_file(char **current_dir_file, \
			char *directory, int flag_small_a)
{
	DIR				*dir;
	struct dirent	*dp;
	int				i;

	if ((dir = opendir(directory)) == NULL)
		return (perror_message_free(&current_dir_file, ERR_OPENDIR));
	i = 0;
	while ((dp = readdir(dir)) != NULL)
	{
		if (flag_small_a == false)
			if (ft_memcmp(dp->d_name, ".", 1) == 0)
				continue ;
		if (ft_strcmp(directory, ".") == 0)
			current_dir_file[i] = ft_strdup(dp->d_name);
		else
			current_dir_file[i] = ft_str3join(directory, "/", dp->d_name);
		i++;
	}
	current_dir_file[i] = NULL;
	closedir(dir);
	return (SUCCESS_RETURN);
}
