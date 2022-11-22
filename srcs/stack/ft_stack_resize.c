/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_resize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:49:13 by eujeong           #+#    #+#             */
/*   Updated: 2022/10/27 16:10:52 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_resize(t_stack *stack)
{
	int	re_capacity;
	int	*new_arr;
	int	i;

	if (stack == NULL)
		return ;
	re_capacity = 2;
	if (stack->capacity > 0)
		re_capacity = stack->capacity * 2;
	new_arr = (int *)malloc(sizeof(int) * re_capacity);
	if (new_arr == NULL)
		return ;
	i = 0;
	while (i < ft_stack_size(stack))
	{
		new_arr[i] = stack->arr[(stack->bottom + i) % stack->capacity];
		i++;
	}
	stack->top = ft_stack_size(stack);
	stack->bottom = 0;
	stack->capacity = re_capacity;
	free(stack->arr);
	stack->arr = new_arr;
}
