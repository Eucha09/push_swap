/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_oper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:22:55 by eujeong           #+#    #+#             */
/*   Updated: 2022/11/08 13:53:00 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_oper.h"

void	reverse_rotate(t_stack *stack)
{
	if (ft_stack_size(stack) < 2)
		return ;
	ft_stack_push(stack, ft_stack_pop_bottom(stack));
}

void	rra(t_stack_pair *s)
{
	reverse_rotate(s->a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack_pair *s)
{
	reverse_rotate(s->b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack_pair *s)
{
	reverse_rotate(s->a);
	reverse_rotate(s->b);
	ft_putstr_fd("rrr\n", 1);
}
