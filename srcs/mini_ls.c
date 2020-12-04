/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:18:49 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/04 20:12:27 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls.h"

int		mini_ls(void)
{
	DIR				*dir;
	char			**current_dir_file;
	int				alloc_size;
	int				hidden_file_num;

	if ((dir = opendir(".")) == NULL)
		return (perror_message(ERR_OPENDIR));
	alloc_size = dir_in_file_num(dir, &hidden_file_num) - hidden_file_num + 1;
	if (alloc_size == -1)
		return (ERROR_RETURN);
	if (closedir(dir) == -1)
		return (perror_message(ERR_CLOSEDIR));
	if (!(current_dir_file = malloc(sizeof(char *) * \
			(alloc_size))))
		return (perror_message(ERR_MALLOC));
	if (input_dir_file(current_dir_file, ".") != SUCCESS_RETURN)
		return (ERROR_RETURN);
	ft_strsort(current_dir_file, &sort_by_mtime_from_little);
	display_2d(current_dir_file);
	array_free_2d((void ***)&current_dir_file, alloc_size);
	return (SUCCESS_RETURN);
}
