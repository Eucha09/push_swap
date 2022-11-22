/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_bottom.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:17:59 by eujeong           #+#    #+#             */
/*   Updated: 2022/11/08 14:17:01 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stack_bottom_first(t_stack *stack)
{
	if (ft_stack_size(stack) < 1)
		return (0);
	return (stack->arr[stack->bottom]);
}

int	ft_stack_bottom_second(t_stack *stack)
{
	if (ft_stack_size(stack) < 2)
		return (0);
	return (stack->arr[(stack->bottom + 1) % stack->capacity]);
}
