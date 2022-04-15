/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:59:14 by zezzine           #+#    #+#             */
/*   Updated: 2022/03/01 16:28:37 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	int		mid_value;
	int		start;
	int		end;
	int		total;
	int		count_down;
	int		lk_for;
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

void	*bubblesort(int *arr, int n, int i);

void	sort_three(t_stack *s);

void	sort_five(t_stack *a, t_stack *b, int size);

void	rotate_push_sort(t_stack *a, t_stack *b, int size, int offset);

void	push_or_not(t_stack *a, t_stack *b);

void	choose_sort(t_stack *a, t_stack *b, int ac);

void	repeat_sort(t_stack *a, t_stack *b);

void	update_total(t_stack *a);

void	rotate_from_down(t_stack *a, t_stack *b);

void	rotate_or_down(t_stack *a, t_stack *b);

int		indexing(t_stack *b);

void	push_rot(t_stack *a, t_stack *b);

void	repeat_sort(t_stack *a, t_stack *b);

#endif
