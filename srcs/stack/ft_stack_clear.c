/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:49:33 by eujeong           #+#    #+#             */
/*   Updated: 2022/10/27 15:52:20 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_clear(t_stack *stack)
{
	if (stack == NULL)
		return ;
	free(stack->arr);
	free(stack);
}
