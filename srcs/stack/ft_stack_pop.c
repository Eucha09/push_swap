/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:45:38 by eujeong           #+#    #+#             */
/*   Updated: 2022/11/01 14:11:17 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stack_pop(t_stack *stack)
{
	return (ft_stack_pop_top(stack));
}

int	ft_stack_pop_top(t_stack *stack)
{
	if (ft_stack_size(stack) == 0)
		return (0);
	stack->top = (stack->top - 1 + stack->capacity) % stack->capacity;
	return (stack->arr[stack->top]);
}

int	ft_stack_pop_bottom(t_stack *stack)
{
	int	i;

	if (ft_stack_size(stack) == 0)
		return (0);
	i = stack->bottom;
	stack->bottom = (stack->bottom + 1) % stack->capacity;
	return (stack->arr[i]);
}
