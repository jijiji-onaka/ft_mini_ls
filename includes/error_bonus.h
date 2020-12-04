/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:46:00 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/04 21:12:36 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_BONUS_H
# define ERROR_BONUS_H

# include <stdlib.h>
# define ERROR_RETURN 1
# define SUCCESS_RETURN 0
# define NOT_SUPPORTED 2
# define ERR_OPENDIR "ls: no_permission"
# define ERR_READDIR "Fail to readdir "
# define ERR_CLOSEDIR "Fail to closedir "
# define ERR_MALLOC "Fail to malloc "
# define ERR_STAT "Fail to lstat "
# define ERR_ARG "usage : ./ft_mini_ls || ./ft_mini_ls -[asSuUR]\n"
# define ERR "usage: ls [-@ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1%] [file ...]\n"

int	put_error_message(char *s, size_t len);
int	perror_message(char *s);
int	perror_message_free(char ***ptr, char *error_message, int cur);
int	free_return(char ***ptr, int cur);

#endif
