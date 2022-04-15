/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:59:50 by zezzine           #+#    #+#             */
/*   Updated: 2022/03/01 17:59:54 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	free(fr1->arr);
	free(fr2->arr);
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
}

static void	fill_stack_b(t_stack *stack, int ac)
{
	int	i;

	i = -1;
	while (++i < ac)
		stack->arr[i] = 999999999;
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
	(*a)->count = ac;
	(*b)->count = 0;
	(*a)->mid = ac / 2;
	(*a)->ac = ac;
	(*b)->ac = ac;
	check_offset(ac, *a, *b);
	fill_stack_b(*b, ac);
}
