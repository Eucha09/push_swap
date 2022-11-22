/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_oper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:19:07 by eujeong           #+#    #+#             */
/*   Updated: 2022/11/08 13:53:24 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_oper.h"

void	rotate(t_stack *stack)
{
	if (ft_stack_size(stack) < 2)
		return ;
	ft_stack_push_bottom(stack, ft_stack_pop(stack));
}

void	ra(t_stack_pair *s)
{
	rotate(s->a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack_pair *s)
{
	rotate(s->b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack_pair *s)
{
	rotate(s->a);
	rotate(s->b);
	ft_putstr_fd("rr\n", 1);
}
