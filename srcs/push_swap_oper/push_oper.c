/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:12:38 by eujeong           #+#    #+#             */
/*   Updated: 2022/11/08 13:52:29 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_oper.h"

void	push(t_stack *a, t_stack *b)
{
	if (ft_stack_size(b) == 0)
		return ;
	ft_stack_push(a, ft_stack_pop(b));
}

void	pa(t_stack_pair *s)
{
	push(s->a, s->b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack_pair *s)
{
	push(s->b, s->a);
	ft_putstr_fd("pb\n", 1);
}
