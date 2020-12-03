/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_flag_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:44:46 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/03 22:38:21 by tjinichi         ###   ########.fr       */
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
/*
** option -s
*/
int				put_total(char **array2d, int f, blkcnt_t *width);
void			put_blocks(blkcnt_t blocks, blkcnt_t blocks_width);
/*
** option -R
*/
// void			put_dir_title(char *s);
void			do_recursive(char **current_dir_file, t_op *flag);
int				mini_ls_option_large_r(t_op *flag, char *current_dir);

#endif
