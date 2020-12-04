/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_flag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:43:34 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/04 05:57:41 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

static void	for_u(char option, t_op *flag)
{
	if (option == 'u')
	{
		flag->small_u = true;
		flag->large_u = false;
	}
	else if (option == 'U')
	{
		flag->large_u = true;
		flag->small_u = false;
	}
}

static int	option_check(char option, t_op *flag)
{
	if (option == 'G')
		flag->large_g = true;
	else if (option == 'R')
		flag->large_r = true;
	else if (option == 's')
		flag->small_s = true;
	else if (option == 'S')
		flag->large_s = true;
	else if (option == 'u' || option == 'U')
		for_u(option, flag);
	else if (option == 'a')
		flag->small_a = true;
	else if (ft_strchr("@ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1%", option) \
				!= NULL)
		return (NOT_SUPPORTED);
	else
	{
		write(2, "ls: illegal option -- ", 22);
		ft_putchar_fd(option, 2);
		return (put_error_message("\n", 1));
	}
	return (SUCCESS_RETURN);
}

static int	each_option_check(char *option, t_op *flag)
{
	int	i;
	int	ret;

	i = 0;
	while (option[i])
	{
		if ((ret = option_check(option[i], flag)) >= ERROR_RETURN)
			return (ret);
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
	int		ret;

	i = 1;
	while (arg[i])
	{
		if (arg[i][0] == '-')
		{
			if ((ret = on_option_flag(arg[i] + 1, flag)) >= ERROR_RETURN)
				return (ret);
		}
		else
			return (ERROR_RETURN);
		i++;
	}
	return (SUCCESS_RETURN);
}
