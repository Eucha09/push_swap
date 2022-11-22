/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:12:20 by eujeong           #+#    #+#             */
/*   Updated: 2022/11/08 14:16:54 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stack_top_first(t_stack *stack)
{
	if (ft_stack_size(stack) < 1)
		return (0);
	return (stack->arr[(stack->top - 1 + stack->capacity) % stack->capacity]);
}

int	ft_stack_top_second(t_stack *stack)
{
	if (ft_stack_size(stack) < 2)
		return (0);
	return (stack->arr[(stack->top - 2 + stack->capacity) % stack->capacity]);
}
