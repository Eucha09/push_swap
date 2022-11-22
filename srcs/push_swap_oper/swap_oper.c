/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:42:54 by eujeong           #+#    #+#             */
/*   Updated: 2022/11/08 13:53:48 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_oper.h"

void	swap(t_stack *stack)
{
	int	element[2];

	if (ft_stack_size(stack) < 2)
		return ;
	element[0] = ft_stack_pop(stack);
	element[1] = ft_stack_pop(stack);
	ft_stack_push(stack, element[0]);
	ft_stack_push(stack, element[1]);
}

void	sa(t_stack_pair *s)
{
	swap(s->a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack_pair *s)
{
	swap(s->b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack_pair *s)
{
	swap(s->a);
	swap(s->b);
	ft_putstr_fd("ss\n", 1);
}
