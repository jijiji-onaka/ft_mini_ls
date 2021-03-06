/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:46:33 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/12 01:26:33 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_BONUS_H
# define SORT_BONUS_H

# include "option_flag_bonus.h"

int		sort_by_mtime_from_little(char *s1, char *s2);
void	sort_by_what(char **current_dir_file, t_op *flag, int alloc_size);

#endif
