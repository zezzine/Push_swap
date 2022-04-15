/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:51:18 by zezzine           #+#    #+#             */
/*   Updated: 2022/02/09 20:06:40 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_direction(t_stack *s, int direction)
{
	int	x;
	int	i;
	int	last;

	if (s->count == 0)
		return ;
	last = s->count;
	x = s->arr[last - 1];
	i = 0;
	if (direction == -1)
	{
		while (--last > 0)
			s->arr[last] = s->arr[last - 1];
		s->arr[0] = x;
	}
	else if (direction == 1)
	{
		x = s->arr[i];
		while (i < last - 1)
		{
			s->arr[i] = s->arr[i + 1];
			i++;
		}
		s->arr[last - 1] = x;
	}
}

void	rr(t_stack *a, t_stack *b)
{
	r_direction(a, 1);
	if (b->count == 0)
		return ;
	r_direction(b, 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	r_direction(a, -1);
	if (b->count == 0)
		return ;
	r_direction(b, -1);
}
