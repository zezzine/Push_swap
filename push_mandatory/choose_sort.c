/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:26:37 by zezzine           #+#    #+#             */
/*   Updated: 2022/03/01 18:24:33 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a, t_stack *b)
{
	int	i;

	i = 1;
	if (b->count > 0)
		return (0);
	while (i < a->count)
	{
		if (a->arr[i - 1] > a->arr[i])
			return (0);
		i++;
	}
	return (1);
}

void	choose_sort(t_stack *a, t_stack *b, int ac)
{
	if (is_sorted(a, b))
		exit(0);
	else if (ac <= 3)
		sort_three(a);
	else if (ac <= 5)
		sort_five(a, b, ac);
	else if (ac >= 6)
		repeat_sort(a, b);
}
