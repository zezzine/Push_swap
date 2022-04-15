/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 22:38:15 by zezzine           #+#    #+#             */
/*   Updated: 2022/03/01 16:29:32 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long	ft_atoi(const char *str)
{
	long	r;
	int		i;
	long	sg;

	sg = 1;
	r = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sg = sg * (-1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (r <= ((9223372036854775807 - (str[i] - 48)) / 10))
			r = r * 10 + (str[i] - 48);
		else
		{
			r = 9223372036854775807;
			break ;
		}
		i++;
	}
	return (r * sg);
}

static int	checkatoi(char *str, t_stack *a, t_stack *b)
{
	long	i;
	long	j;

	i = 0;
	if (!str || !*str)
		exit_error(a, b);
	if (str[0] == '-' && str[1] != '\0')
		i++;
	j = i;
	while (str[j] == '0')
		j++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			exit_error(a, b);
		i++;
	}
	if (i - j > 11)
		exit_error(a, b);
	i = ft_atoi(str);
	if (i > 2147483647 || i < -2147483648)
		exit_error(a, b);
	return (i);
}

void	check_argv(int ac, char **av, t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		a->arr[i] = checkatoi(av[i], a, b);
		i++;
	}
	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
		{
			if (a->arr[i] == a->arr[j])
				exit_error(a, b);
			j++;
		}
		i++;
	}
}
