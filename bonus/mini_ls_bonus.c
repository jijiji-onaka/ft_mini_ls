/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_ls_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:18:49 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/03 06:44:57 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

int			mini_ls(void)
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
	if (input_dir_file(current_dir_file, ".", false) == ERROR_RETURN)
		return (ERROR_RETURN);
	ft_strsort(current_dir_file, &sort_by_mtime_from_little);
	default_display_2d(current_dir_file);
	array_free_2d((void ***)&current_dir_file, alloc_size);
	return (SUCCESS_RETURN);
}

static int	other_option(t_op *flag)
{
	DIR				*dir;
	char			**current_dir_file;
	int				alloc_size;
	int				hidden_file_num;
	int				return_value;

	if ((dir = opendir(".")) == NULL)
		return (perror_message(ERR_OPENDIR));
	alloc_size = dir_in_file_num(dir, &hidden_file_num) - hidden_file_num + 1;
	if (flag->small_a == true)
		alloc_size += hidden_file_num;
	closedir(dir);
	if (!(current_dir_file = malloc(sizeof(char *) * \
			(alloc_size))))
		return (perror_message(ERR_MALLOC));
	if (input_dir_file(current_dir_file, ".", flag->small_a) == ERROR_RETURN)
		return (ERROR_RETURN);
	sort_by_what(current_dir_file, flag);
	return_value = display_2d(current_dir_file, flag);
	array_free_2d((void ***)&current_dir_file, alloc_size);
	return (return_value);
}

static int	option_large_r(t_op *flag, char *current_dir)
{
	DIR				*dir;
	char			**current_dir_file;
	int				alloc_size;
	int				hidden_file_num;
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
	return_value = display_2d(current_dir_file, flag);
	// each
	array_free_2d((void ***)&current_dir_file, alloc_size);
	return (return_value);
}

int			mini_ls_option(char **arg)
{
	t_op	flag;

	flag = (t_op){0};
	if (count_option(arg, &flag) == ERROR_RETURN)
		return (put_error_message(ERR_ARG, 21));
	if (flag.large_r == true)
		return (option_large_r(&flag, "."));
	return (other_option(&flag));
}
