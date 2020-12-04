/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:55:39 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/04 19:26:59 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls_bonus.h"

int	put_error_message(char *error_message, size_t len)
{
	write(2, error_message, len);
	return (ERROR_RETURN);
}

int	perror_message(char *error_message)
{
	perror(error_message);
	return (ERROR_RETURN);
}

int	perror_message_free(char ***ptr, char *error_message, int cur)
{
	array_free_2d((void ***)ptr, cur);
	return (perror_message(error_message));
}

int	free_return(char ***ptr, int cur)
{
	array_free_2d((void ***)ptr, cur);
	return (ERROR_RETURN);
}
