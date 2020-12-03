/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:46:00 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/03 21:28:56 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_BONUS_H
# define ERROR_BONUS_H

# include <stdlib.h>
# define ERROR_RETURN 1
# define SUCCESS_RETURN 0
# define ERR_OPENDIR "Fail to opendir "
# define ERR_MALLOC "Fail to malloc "
# define ERR_STAT "Fail to lstat "
# define ERR_ARG "usage : ./ft_mini_ls || ./ft_mini_ls -[a/ s/ S/ u/ U/ R]\n"

int	put_error_message(char *s, size_t len);
int	perror_message(char *s);
int	perror_message_free(char ***ptr, char *error_message);

#endif
