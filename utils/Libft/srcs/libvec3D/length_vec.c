/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:57:35 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/23 14:57:44 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

double	length_vec(t_p3 a)
{
	double	k;

	k = dotproduct(a, a);
	return (sqrt(k));
}
