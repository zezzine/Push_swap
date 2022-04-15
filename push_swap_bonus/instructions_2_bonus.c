/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:48:39 by zezzine           #+#    #+#             */
/*   Updated: 2022/02/23 14:55:08 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_stack *a)
{
	int	tmp;

	tmp = a->arr[0];
	a->arr[0] = a->arr[1];
	a->arr[1] = tmp;
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	pb(t_stack *a, t_stack *b)
{
	int	i;
	int	tmp;

	if (!a->count)
		return ;
	tmp = a->arr[0];
	i = 1;
	while (i < a->count)
	{
		a->arr[i - 1] = a->arr[i];
		i++;
	}
	a->arr[i - 1] = 0;
	i = b->count;
	while (i > 0)
	{
		b->arr[i] = b->arr[i - 1];
		i--;
	}
	b->arr[0] = tmp;
	b->count++;
	a->count--;
}

void	pa(t_stack *a, t_stack *b)
{
	int	i;
	int	tmp;

	if (!b->count)
		return ;
	tmp = b->arr[0];
	i = 1;
	while (i < b->count)
	{
		b->arr[i - 1] = b->arr[i];
		i++;
	}
	b->arr[i - 1] = 0;
	i = a->count;
	while (i > 0)
	{
		a->arr[i] = a->arr[i - 1];
		i--;
	}
	a->arr[0] = tmp;
	a->count++;
	b->count--;
}
