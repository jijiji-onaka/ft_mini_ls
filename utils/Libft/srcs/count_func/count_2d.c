/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:33:56 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/11 21:30:44 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/count_func.h"

int	count_2d(char **ss)
{
	int i;

	i = 0;
	while (ss[i])
		i++;
	return (i);
}