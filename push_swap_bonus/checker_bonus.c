/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:56:02 by zezzine           #+#    #+#             */
/*   Updated: 2022/03/01 18:07:25 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s01;
	unsigned char	*s02;
	size_t			i;

	s01 = (unsigned char *)s1;
	s02 = (unsigned char *)s2;
	i = 0;
	while ((s01[i] || s02[i]) && i < n)
	{
		if (s01[i] != s02[i])
			return (s01[i] - s02[i]);
		i++;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

void	sort_stack(t_stack *a, t_stack *b, char *line)
{
	if (ft_strncmp(line, "sa", 2) == 0)
		swap(a);
	else if (ft_strncmp(line, "sb", ft_strlen(line) - 1) == 0)
		swap(b);
	else if (ft_strncmp(line, "ss", ft_strlen(line) - 1) == 0)
		ss(a, b);
	else if (ft_strncmp(line, "pa", ft_strlen(line) - 1) == 0)
		pa(a, b);
	else if (ft_strncmp(line, "pb", ft_strlen(line) - 1) == 0)
		pb(a, b);
	else if (ft_strncmp(line, "ra", ft_strlen(line) - 1) == 0)
		r_direction(a, 1);
	else if (ft_strncmp(line, "rb", ft_strlen(line)- 1) == 0)
		r_direction(b, 1);
	else if (ft_strncmp(line, "rr", ft_strlen(line) - 1) == 0)
		rr(a, b);
	else if (ft_strncmp(line, "rra", ft_strlen(line) - 1) == 0)
		r_direction(a, -1);
	else if (ft_strncmp(line, "rrb", ft_strlen(line) - 1) == 0)
		r_direction(b, -1);
	else if (ft_strncmp(line, "rrr", ft_strlen(line) - 1) == 0)
		rrr(a, b);
	else
		ft_putstr(1, "Error\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	b = NULL;
	a = NULL;
	if (ac == 1)
		return (0);
	ac--;
	init_stack(&a, &b, ac);
	check_argv(ac, av + 1, a, b);
	line = get_next_line(0);
	while (line)
	{
		sort_stack(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(a, b))
		ft_putstr(1, "OK\n");
	else
		ft_putstr(1, "KO\n");
}
