/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_flag_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:44:46 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/02 19:01:35 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTION_FlAG_BONUS_H
# define OPTION_FlAG_BONUS_H

typedef struct	s_op
{
	int			large_g;
	int			large_r;
	int			small_s;
	int			large_s;
	int			small_u;
	int			large_u;
	int			small_a;
}				t_op;

int				count_option(char **arg, t_op *flag);

#endif
