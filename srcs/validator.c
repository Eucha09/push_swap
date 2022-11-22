/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:35:48 by eujeong           #+#    #+#             */
/*   Updated: 2022/11/11 15:44:03 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"

int	is_int(char *str)
{
	long long	num;
	long long	sign;
	size_t		i;
	size_t		len;

	len = ft_strlen(str);
	i = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	num = 0;
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
			return (0);
		num = num * 10 + (long long)(str[i] - '0');
		i++;
	}
	num *= sign;
	if (num < INT32_MIN || INT32_MAX < num)
		return (0);
	return (1);
}

int	is_valid(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_int(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_stack *a, int value)
{
	int	i;
	int	size;
	int	ret;

	ret = 0;
	i = 0;
	size = ft_stack_size(a);
	while (i < size)
	{
		if (a->arr[i] == value)
			ret = 1;
		i++;
	}
	return (ret);
}

int	arg_to_stack(int argc, char *argv[], t_stack *a)
{
	int	i;
	int	duplicated;
	int	value;

	duplicated = 0;
	i = argc - 1;
	while (i > 0)
	{
		value = ft_atoi(argv[i]);
		if (is_duplicate(a, value))
			duplicated = 1;
		ft_stack_push(a, value);
		i--;
	}
	if (duplicated == 1)
		return (0);
	return (1);
}

int	is_sorted(t_stack *a)
{
	int	i;
	int	size;
	int	sorted;

	sorted = 1;
	i = 0;
	size = ft_stack_size(a);
	while (i < size - 1)
	{
		if (a->arr[i] < a->arr[i + 1])
			sorted = 0;
		i++;
	}
	return (sorted);
}
