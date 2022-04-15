/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:38:55 by zezzine           #+#    #+#             */
/*   Updated: 2022/03/01 14:47:38 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_or_not(t_stack *a, t_stack *b)
{
	int	i;

	i = a->start;
	while (i < a->end)
	{
		if (a->arr[0] == a->arr_sorted[i])
		{
			pb(a, b);
			if (b->count > 0 && b->arr[0] < a->mid_value)
			{	
				r_direction(b, 1);
				ft_putstr(1, "rb\n");
			}
			return ;
		}
		i++;
	}
	r_direction(a, 1);
	ft_putstr(1, "ra\n");
}

void	update_total(t_stack *a)
{
	a->start -= a->offset;
	a->end += a->offset;
	if (a->start < 0)
		a->start = 0;
	if (a->end > a->ac)
		a->end = a->ac;
	a->total = a->end - a->start;
}

int	indexing(t_stack *b)
{
	int	i;

	i = 0;
	while (i < b->count)
	{
		if (b->arr_sorted[b->lk_for] == b->arr[i])
			return (i);
		i++;
	}
	return (-1);
}

void	rotate_from_down(t_stack *a, t_stack *b)
{
	r_direction(a, -1);
	ft_putstr(1, "rra\n");
	b->lk_for--;
	b->count_down--;
}

void	rotate_or_down(t_stack *a, t_stack *b)
{
	if (b->count_down == 0 || b->arr[0] > a->arr[a->count - 1])
	{
		pa(a, b);
		r_direction(a, 1);
		ft_putstr(1, "ra\n");
		b->count_down++;
	}
	else
	{
		r_direction(b, 1);
		ft_putstr(1, "rb\n");
	}
}
