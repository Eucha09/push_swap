/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:55:33 by eujeong           #+#    #+#             */
/*   Updated: 2022/11/08 15:46:55 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_oper.h"

t_stack_pair	*stack_pair_new(void)
{
	t_stack_pair	*s;

	s = (t_stack_pair *)malloc(sizeof(t_stack_pair));
	if (s == NULL)
		return (NULL);
	s->a = ft_stack_new();
	s->b = ft_stack_new();
	if (s->a == NULL || s->b == NULL)
	{
		stack_pair_clear(s);
		return (NULL);
	}
	return (s);
}
