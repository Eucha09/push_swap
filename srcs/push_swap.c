/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:00:34 by eujeong           #+#    #+#             */
/*   Updated: 2022/11/11 15:41:33 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_top(t_stack_pair *s, int pos)
{
	if (pos == 0)
		return (ft_stack_top_first(s->a));
	if (pos == 1)
		return (ft_stack_top_first(s->b));
	if (pos == 2)
		return (ft_stack_bottom_first(s->b));
	if (pos == 3)
		return (ft_stack_bottom_first(s->a));
	return (0);
}

void	move_stack(t_stack_pair *s, int from, int to, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (from == 3)
			rra(s);
		if (from == 2)
			rrb(s);
		if ((from == 0 || from == 3) && (to == 1 || to == 2))
			pb(s);
		if (to == 2)
			rb(s);
		if ((from == 1 || from == 2) && (to == 0 || to == 3))
			pa(s);
		if (to == 3)
			ra(s);
		i++;
	}
}

void	merge(t_stack_pair *s, int *size, int order)
{
	int	value;
	int	p;
	int	i;
	int	next;

	while (size[0] > 0 || size[1] > 0 || size[2] > 0)
	{
		i = 0;
		value = INT32_MIN;
		if (order == DESC)
			value = INT32_MAX;
		while (i < 3)
		{
			next = 1 + i;
			if (size[i] > 0 && ((order == ASC && pos_top(s, next) >= value)
					|| (order == DESC && pos_top(s, next) <= value)))
			{
				value = pos_top(s, next);
				p = i;
			}
			i++;
		}
		move_stack(s, 1 + p, 0, 1);
		size[p]--;
	}
}

void	push_swap_sort(t_stack_pair *s, int size, int order)
{
	int	seg_size[3];

	if (size <= 2)
		return (sort_size2(s, size, order));
	seg_size[1] = size / 3;
	seg_size[0] = (size - (seg_size[1])) / 2;
	seg_size[2] = size - seg_size[0] - seg_size[1];
	push_swap_sort(s, seg_size[0], order);
	move_stack(s, 0, 1, seg_size[0]);
	push_swap_sort(s, seg_size[1], order);
	move_stack(s, 0, 2, seg_size[1]);
	push_swap_sort(s, seg_size[2], order);
	move_stack(s, 0, 3, seg_size[2]);
	merge(s, seg_size, order);
}
