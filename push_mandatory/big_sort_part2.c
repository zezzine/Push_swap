/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_part2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:34:02 by zezzine           #+#    #+#             */
/*   Updated: 2022/03/01 14:39:07 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_rot(t_stack *a, t_stack *b)
{
	int	index;

	index = indexing(b);
	if (index == -1)
		return (rotate_from_down(a, b));
	if (index > b->count / 2)
	{
		while (index < b->count)
		{
			r_direction(b, -1);
			ft_putstr(1, "rrb\n");
			index++;
		}
	}
	else
	{
		while (index > 0)
		{
			rotate_or_down(a, b);
			index--;
		}
	}
	pa(a, b);
	b->lk_for--;
}

void	repeat_sort(t_stack *a, t_stack *b)
{
	while (a->count > 0)
	{
		while (b->count < a->total)
			push_or_not(a, b);
		update_total(a);
	}
	while (b->count + b->count_down > 0)
	{
		push_rot(a, b);
	}
}
