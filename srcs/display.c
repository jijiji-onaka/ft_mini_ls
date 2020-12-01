/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:59:01 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/02 04:01:22 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls.h"

void	display_2d(char **array2d)
{
	int	i;

	i = 0;
	while (array2d[i])
	{
		write(1, array2d[i], ft_strlen(array2d[i]));
		write(1, "\n", 1);
		i++;
	}
}
