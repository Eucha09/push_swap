/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push_top.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:46:26 by eujeong           #+#    #+#             */
/*   Updated: 2022/11/01 14:11:50 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_push(t_stack *stack, int value)
{
	ft_stack_push_top(stack, value);
}

void	ft_stack_push_top(t_stack *stack, int value)
{
	if (ft_stack_size(stack) + 1 >= stack->capacity)
		ft_stack_resize(stack);
	if (ft_stack_size(stack) + 1 < stack->capacity)
	{
		stack->arr[stack->top] = value;
		stack->top = (stack->top + 1) % stack->capacity;
	}
}

void	ft_stack_push_bottom(t_stack *stack, int value)
{
	if (ft_stack_size(stack) + 1 >= stack->capacity)
		ft_stack_resize(stack);
	if (ft_stack_size(stack) + 1 < stack->capacity)
	{
		stack->bottom = (stack->bottom - 1 + stack->capacity) % stack->capacity;
		stack->arr[stack->bottom] = value;
	}
}
