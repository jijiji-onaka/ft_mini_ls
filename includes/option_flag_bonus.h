/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_flag_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:44:46 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/02 23:53:16 by tjinichi         ###   ########.fr       */
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

# include <sys/stat.h>

int				count_option(char **arg, t_op *flag);

int				put_total(char **array2d, int f);
void			put_blocks(blkcnt_t blocks, int f);

#endif
