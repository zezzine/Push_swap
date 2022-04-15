/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:15:02 by zezzine           #+#    #+#             */
/*   Updated: 2022/03/01 14:05:53 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(int fd, char *s)
{
	int	i;

	i = 0;
	if (!s || !fd)
		return ;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}

void	exit_error(t_stack *fr1, t_stack *fr2)
{
	if (fr1 && fr2)
	{
		free(fr1->arr);
		free(fr2->arr);
	}
	free(fr1);
	free(fr2);
	ft_putstr(2, "Error\n");
	exit(1);
}

static void	check_offset(int ac, t_stack *a, t_stack *b)
{
	if (ac < 150 && ac >= 8)
		a->offset = ac / 8;
	if (ac >= 150)
		a->offset = ac / 18;
	b->offset = a->offset;
	b->mid = a->mid;
	a->start = a->mid - a->offset;
	a->end = a->mid + a->offset;
	a->total = a->end - a->start;
	b->lk_for = a->ac - 1;
	b->count_down = 0;
}

static void	fill_stack_b(t_stack *stack, int ac)
{
	int	i;

	i = -1;
	while (++i < ac)
		stack->arr[i] = 0;
}

void	init_stack(t_stack **a, t_stack **b, int ac)
{
	*a = (t_stack *)malloc(sizeof(t_stack));
	*b = (t_stack *)malloc(sizeof(t_stack));
	if (!a || !b)
		exit_error(NULL, NULL);
	(*a)->arr = (int *)malloc(sizeof(int) * ac);
	(*b)->arr = (int *)malloc(sizeof(int) * ac);
	if (!(*a)->arr || !(*b)->arr)
		exit_error(*a, *b);
	(*a)->arr_sorted = (int *)malloc(sizeof(int) * ac);
	(*b)->arr_sorted = (*a)->arr_sorted;
	if (!(*a)->arr_sorted)
		exit_error(*a, *b);
	(*a)->count = ac;
	(*b)->count = 0;
	(*a)->mid = ac / 2;
	(*a)->ac = ac;
	(*b)->ac = ac;
	check_offset(ac, *a, *b);
	fill_stack_b(*b, ac);
}
