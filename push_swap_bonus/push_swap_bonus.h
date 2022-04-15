/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:56:21 by zezzine           #+#    #+#             */
/*   Updated: 2022/03/01 16:38:36 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		*arr;
	int		*arr_sorted;
	int		count;
	int		mid;
	int		offset;
	int		ac;
	int		j;
}				t_stack;

void	exit_error(t_stack *fr1, t_stack *fr2);

long	ft_atoi(const char *str);

void	check_argv(int ac, char **av, t_stack *st_a, t_stack *st_b);

void	ft_putstr_fd(int fd, char *str);

void	init_stack(t_stack **a, t_stack **b, int ac);

void	pa(t_stack *a, t_stack *b);

void	pb(t_stack *a, t_stack *b);

void	r_direction(t_stack *s, int direction);

void	rrr(t_stack *a, t_stack *b);

void	rr(t_stack *a, t_stack *b);

void	swap(t_stack *a);

void	ss(t_stack *a, t_stack *b);

void	ft_putstr(int fd, char *s);

#endif