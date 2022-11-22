/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:43:06 by eujeong           #+#    #+#             */
/*   Updated: 2022/11/11 14:32:44 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "push_swap_oper.h"
# define ASC	0
# define DESC	1

void	sort(t_stack_pair *s, int size, int order);
void	sort_size2(t_stack_pair *s, int size, int order);
void	sort_size3(t_stack_pair *s, int size);

void	push_swap_sort(t_stack_pair *s, int size, int order);
void	move_stack(t_stack_pair *s, int from, int to, int size);
void	merge(t_stack_pair *s, int *size, int order);

#endif