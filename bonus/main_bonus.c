/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:42:02 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/04 20:10:51 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

int	main(int argc, char *argv[])
{
	(void)argv;
	errno = 0;
	if (argc == 1)
		return (mini_ls());
	else
		return (mini_ls_option(argv));
}
