/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:01:02 by eujeong           #+#    #+#             */
/*   Updated: 2022/11/08 14:03:23 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_oper.h"

void	stack_pair_clear(t_stack_pair *s)
{
	if (s == NULL)
		return ;
	ft_stack_clear(s->a);
	ft_stack_clear(s->b);
	free(s);
}
