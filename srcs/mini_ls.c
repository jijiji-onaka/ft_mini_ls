/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:18:49 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/02 05:30:46 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls.h"

int		mini_ls_start(void)
{
	DIR				*dir;
	char			**current_dir_file;
	int				alloc_size;
	int				hidden_file_num;

	if ((dir = opendir(".")) == NULL)
		return (perror_message(ERR_OPENDIR));
	alloc_size = dir_in_file_num(dir, &hidden_file_num) - hidden_file_num + 1;
	closedir(dir);
	if (!(current_dir_file = malloc(sizeof(char *) * \
			(alloc_size))))
		return (perror_message(ERR_MALLOC));
	if (input_dir_file(current_dir_file, ".") == ERROR_RETURN)
		return (ERROR_RETURN);
	ft_strsort(current_dir_file, &sort_by_mtime_from_little);
	display_2d(current_dir_file);
	free(current_dir_file);
	return (SUCCESS_RETURN);
}
