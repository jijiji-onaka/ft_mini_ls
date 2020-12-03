/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:55:39 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/03 18:06:52 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls.h"

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

int	perror_message_free(char ***ptr, char *error_message)
{
	array_free_2d((void ***)ptr, count_2d(*ptr) + 1);
	return (perror_message(error_message));
}
