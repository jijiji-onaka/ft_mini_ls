/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_large_r_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:53:39 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/04 21:52:57 by tjinichi         ###   ########.fr       */
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

static int	opendir_func(char *current_dir, DIR **dir)
{
	errno = 0;
	if ((*dir = opendir(current_dir)) == NULL)
		return (perror_message(ERR_OPENDIR));
	return (SUCCESS_RETURN);
}

int			do_recursive(char **current_dir_file, t_op *flag)
{
	int			i;
	int			rc1;
	int			rc2;
	struct stat	stat_buf;

	i = -1;
	while (current_dir_file[++i])
	{
		if (lstat(current_dir_file[i], &stat_buf) != 0)
			perror_message(ERR_STAT);
		if (is_dir(stat_buf.st_mode) == 1)
		{
			if ((rc1 = check_file_tail(current_dir_file[i], ".")) == -1)
				return (perror_message(ERR_MALLOC));
			if ((rc2 = check_file_tail(current_dir_file[i], "..")) == -1)
				return (perror_message(ERR_MALLOC));
			if (flag->small_a && flag->large_r && (rc1 == 1 || rc2 == 1))
				continue ;
			if (mini_ls_option_large_r(flag, current_dir_file[i]) == \
					ERROR_RETURN && errno != EACCES)
				ft_putstr_fd(current_dir_file[i], 1);
		}
	}
	return (SUCCESS_RETURN);
}

int			mini_ls_option_large_r(t_op *flag, char *current_dir)
{
	DIR				*dir;
	char			**current_dir_file;
	int				alc_size;
	size_t			hidden_file;
	int				return_value;

	if (opendir_func(current_dir, &dir) == ERROR_RETURN)
		return (ERROR_RETURN);
	if ((alc_size = dir_in_file_num(dir, &hidden_file) - hidden_file + 1) == -1)
		return (ERROR_RETURN);
	if (flag->small_a == true)
		alc_size += hidden_file;
	if (closedir(dir) == -1)
		return (perror_message(ERR_CLOSEDIR));
	if (!(current_dir_file = malloc(sizeof(char *) * (alc_size))))
		return (perror_message(ERR_MALLOC));
	if (input_dir_file(current_dir_file, current_dir, flag->small_a) != 0)
		return (ERROR_RETURN);
	sort_by_what(current_dir_file, flag);
	put_dir_title(current_dir);
	if ((return_value = display_2d(current_dir_file, flag)) == ERROR_RETURN)
		return (free_return(&current_dir_file, alc_size));
	return_value = do_recursive(current_dir_file, flag);
	array_free_2d((void ***)&current_dir_file, alc_size);
	return (return_value);
}
