/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:47:47 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/04 20:07:42 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdlib.h>
# define ERROR_RETURN 1
# define SUCCESS_RETURN 0
# define ERR_OPENDIR "Fail to opendir "
# define ERR_READDIR "Fail to readdir "
# define ERR_CLOSEDIR "Fail to closedir "
# define ERR_MALLOC "Fail to malloc "
# define ERR_STAT "Fail to lstat "
# define ERR_ARG "usage : ./ft_mini_ls\n"

int	put_error_message(char *s, size_t len);
int	perror_message(char *s);
int	perror_message_free(char ***ptr, char *error_message, int cur);

#endif
