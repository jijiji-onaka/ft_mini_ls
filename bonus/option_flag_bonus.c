/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_flag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:43:34 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/02 19:40:48 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static int	option_check(char option, t_op *flag)
{
	if (option == 'G')
		flag->large_g = true;
	else if (option == 'a')
		flag->small_a = true;
	else
		return (ERROR_RETURN);
	return (SUCCESS_RETURN);
}

static int	each_option_check(char *option, t_op *flag)
{
	int	i;

	i = 0;
	while (option[i])
	{
		if (option_check(option[i], flag) == ERROR_RETURN)
			return (ERROR_RETURN);
		i++;
	}
	return (SUCCESS_RETURN);
}

static int	on_option_flag(char *arg, t_op *flag)
{
	size_t	len;

	len = ft_strlen(arg);
	if (len == 1)
		return (option_check(arg[0], flag));
	else
		return (each_option_check(arg, flag));
}

int			count_option(char **arg, t_op *flag)
{
	int		i;

	i = 1;
	while (arg[i])
	{
		if (arg[i][0] == '-')
		{
			if (on_option_flag(arg[i] + 1, flag) == ERROR_RETURN)
				return (ERROR_RETURN);
		}
		else
			return (ERROR_RETURN);
		i++;
	}
	return (SUCCESS_RETURN);
}
