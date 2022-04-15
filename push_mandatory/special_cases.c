/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:59:26 by zezzine           #+#    #+#             */
/*   Updated: 2022/03/01 18:24:49 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *s)
{
	if (s->count == 3)
	{
		if (s->arr[0] > s->arr[1] && s->arr[0] > s->arr[2])
		{
			ft_putstr(1, "ra\n");
			r_direction(s, 1);
		}
		else if (s->arr[0] < s->arr[1] && s->arr[1] > s->arr[2])
		{
			ft_putstr(1, "rra\n");
			r_direction(s, -1);
		}
	}
	if (s->arr[0] > s->arr[1])
	{
		ft_putstr(1, "sa\n");
		swap(s);
	}
}

int	sort_five_help(t_stack *a, t_stack *b, int size)
{
	int	*array;

	array = bubblesort(a->arr, size, -1);
	while (size > 3)
	{
		if (a->arr[0] == array[0] || (a->ac == 5 && a->arr[0] == array[1]))
		{
			pb(a, b);
			size--;
		}
		else
		{
			ft_putstr(1, "ra\n");
			r_direction(a, 1);
		}
	}
	free(array);
	return (size);
}

void	sort_five(t_stack *a, t_stack *b, int size)
{
	int	s_size;

	s_size = sort_five_help(a, b, size);
	sort_three(a);
	if (s_size == 3)
	{
		pa(a, b);
		pa(a, b);
	}
	if (a->arr[0] > a->arr[1])
	{
		ft_putstr(1, "sa\n");
		swap(a);
	}
}
