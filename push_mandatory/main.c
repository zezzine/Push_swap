/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:25:53 by zezzine           #+#    #+#             */
/*   Updated: 2022/03/01 18:25:58 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	ac--;
	if (ac > 0)
	{
		init_stack(&a, &b, ac);
		check_argv(ac, av + 1, a, b);
		if (ac > 1)
			choose_sort(a, b, ac);
	}
	return (0);
}
