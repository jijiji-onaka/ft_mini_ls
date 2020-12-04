/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_print2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:34:43 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/04 20:49:12 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

void	putstr_yellow(char *s)
{
	write(1, YELLOW, 5);
	write(1, s, ft_strlen(s));
	write(1, RESET, 4);
	write(1, "\n", 1);
}

void	putstr_green(char *s)
{
	write(1, GREEN, 5);
	write(1, s, ft_strlen(s));
	write(1, RESET, 4);
	write(1, "\n", 1);
}
