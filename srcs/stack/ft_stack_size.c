/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:48:15 by eujeong           #+#    #+#             */
/*   Updated: 2022/10/27 16:11:51 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stack_size(t_stack *stack)
{
	int	size;

	if (stack->capacity == 0)
		return (0);
	size = (stack->top + stack->capacity - stack->bottom) % stack->capacity;
	return (size);
}
