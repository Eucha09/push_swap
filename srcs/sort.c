/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:27:44 by eujeong           #+#    #+#             */
/*   Updated: 2022/11/11 15:43:16 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_size3(t_stack_pair *s, int size)
{
	int	value[3];

	if (size != 3)
		return ;
	value[0] = ft_stack_top_first(s->a);
	value[1] = ft_stack_top_second(s->a);
	value[2] = ft_stack_bottom_first(s->a);
	if (value[1] < value[0] && value[0] < value[2])
		sa(s);
	else if (value[2] < value[1] && value[1] < value[0])
	{
		sa(s);
		rra(s);
	}
	else if (value[1] < value[2] && value[2] < value[0])
		ra(s);
	else if (value[0] < value[2] && value[2] < value[1])
	{
		sa(s);
		ra(s);
	}
	else if (value[2] < value[0] && value[0] < value[1])
		rra(s);
}

void	sort_size2(t_stack_pair *s, int size, int order)
{
	int	first;
	int	second;

	if (size != 2)
		return ;
	first = ft_stack_top_first(s->a);
	second = ft_stack_top_second(s->a);
	if ((order == ASC && first > second) || (order == DESC && first < second))
		sa(s);
}

void	sort(t_stack_pair *s, int size, int order)
{
	int	seg_size[3];

	if (size <= 2)
		return (sort_size2(s, size, order));
	if (size == 3)
		return (sort_size3(s, size));
	seg_size[1] = size / 3;
	seg_size[0] = (size - (seg_size[1])) / 2;
	seg_size[2] = size - seg_size[0] - seg_size[1];
	push_swap_sort(s, seg_size[1], !order);
	move_stack(s, 0, 1, seg_size[1]);
	push_swap_sort(s, seg_size[0], order);
	move_stack(s, 0, 1, seg_size[0]);
	push_swap_sort(s, seg_size[2], order);
	merge(s, seg_size, order);
}
