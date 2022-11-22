/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:01:28 by eujeong           #+#    #+#             */
/*   Updated: 2022/11/18 15:55:08 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include "validator.h"

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack_pair	*s;

	if (!is_valid(argc, argv))
		return (print_error());
	s = stack_pair_new();
	if (s == NULL)
		return (-1);
	if (!arg_to_stack(argc, argv, s->a))
		return (print_error());
	if (!is_sorted(s->a))
		sort(s, ft_stack_size(s->a), ASC);
	stack_pair_clear(s);
	return (0);
}
