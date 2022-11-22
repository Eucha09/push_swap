/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:54:53 by eujeong           #+#    #+#             */
/*   Updated: 2022/11/01 14:10:35 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stdlib.h>

typedef struct s_stack
{
	int	*arr;
	int	capacity;
	int	top;
	int	bottom;
}	t_stack;

t_stack	*ft_stack_new(void);
void	ft_stack_clear(t_stack *stack);
int		ft_stack_size(t_stack *stack);

void	ft_stack_push(t_stack *stack, int value);
void	ft_stack_push_top(t_stack *stack, int value);
void	ft_stack_push_bottom(t_stack *stack, int value);

int		ft_stack_pop(t_stack *stack);
int		ft_stack_pop_top(t_stack *stack);
int		ft_stack_pop_bottom(t_stack *stack);

int		ft_stack_top_first(t_stack *stack);
int		ft_stack_top_second(t_stack *stack);
int		ft_stack_bottom_first(t_stack *stack);
int		ft_stack_bottom_second(t_stack *stack);

void	ft_stack_resize(t_stack *stack);

#endif