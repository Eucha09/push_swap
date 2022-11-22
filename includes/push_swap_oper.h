/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_oper.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:41:32 by eujeong           #+#    #+#             */
/*   Updated: 2022/11/08 14:12:13 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_OPER_H
# define PUSH_SWAP_OPER_H

# include "ft_stack.h"
# include "libft.h"

typedef struct s_stack_pair
{
	t_stack	*a;
	t_stack	*b;
}	t_stack_pair;

t_stack_pair	*stack_pair_new(void);
void			stack_pair_clear(t_stack_pair *s);

void			sa(t_stack_pair *s);
void			sb(t_stack_pair *s);
void			ss(t_stack_pair *s);
void			pa(t_stack_pair *s);
void			pb(t_stack_pair *s);
void			ra(t_stack_pair *s);
void			rb(t_stack_pair *s);
void			rr(t_stack_pair *s);
void			rra(t_stack_pair *s);
void			rrb(t_stack_pair *s);
void			rrr(t_stack_pair *s);

#endif