/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_large_r_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:53:39 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/04 01:18:15 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static void	put_dir_title(char *s)
{
	if (ft_strcmp(s, ".") != 0)
	{
		write(1, "\n./", 3);
		ft_putstr_fd(s, 1);
		write(1, ":\n", 2);
	}
}

void		do_recursive(char **current_dir_file, t_op *flag)
{
	int			i;
	struct stat	stat_buf;

	i = 0;
	while (current_dir_file[i])
	{
		if (lstat(current_dir_file[i], &stat_buf) != 0)
			perror_message(ERR_STAT);
		if (is_dir(stat_buf.st_mode) == 1)
		{
			if (mini_ls_option_large_r(flag, current_dir_file[i]) == \
					ERROR_RETURN)
				ft_putstr_fd(current_dir_file[i], 1);
		}
		i++;
	}
}

int			mini_ls_option_large_r(t_op *flag, char *current_dir)
{
	DIR				*dir;
	char			**current_dir_file;
	int				alloc_size;
	size_t			hidden_file_num;
	int				return_value;

	if ((dir = opendir(current_dir)) == NULL)
		return (perror_message(ERR_OPENDIR));
	alloc_size = dir_in_file_num(dir, &hidden_file_num) - hidden_file_num + 1;
	if (flag->small_a == true)
		alloc_size += hidden_file_num;
	closedir(dir);
	if (!(current_dir_file = malloc(sizeof(char *) * \
			(alloc_size))))
		return (perror_message(ERR_MALLOC));
	if (input_dir_file(current_dir_file, current_dir, flag->small_a) \
			== ERROR_RETURN)
		return (ERROR_RETURN);
	sort_by_what(current_dir_file, flag);
	put_dir_title(current_dir);
	return_value = display_2d(current_dir_file, flag);
	do_recursive(current_dir_file, flag);
	array_free_2d((void ***)&current_dir_file, alloc_size);
	return (return_value);
}
